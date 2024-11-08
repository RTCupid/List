#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

static int numpng = 111;

errlst_t ListDump (list_t List, char* nameLastFunc, int anch)
{
    fprintf (List.log_file, "<FONT SIZE=\"6\"><center>Dump of List:</center><FONT SIZE=\"5\">\n");
    fprintf (List.log_file, "<center>Last operation \"%s\"</center>\n\n", nameLastFunc);

    // oh it is picture
    MakeDotFile (List, anch);

    char namepng[4] = {};
    sprintf (namepng, "%d", numpng);
    numpng++;
    char systemCall[100] = {};
    sprintf (systemCall, "dot -Tpng DumpGraph.dot -o %s.png", namepng);
    //printf ("systemCall = <<%s>>\n", systemCall);
    system (systemCall);

    fprintf (List.log_file, "<img src = %s.png >\n\n", namepng);

    return LIST_OK;
}

errlst_t MakeDotFile (list_t List, int anch)
{
    FILE* dot_file = fopen ("DumpGraph.dot", "wt");

    fprintf (dot_file, "digraph G {\n");
    fprintf (dot_file, "\trankdir = LR;\n");
    fprintf (dot_file, "\tbgcolor=\"#FBEEC1\"\n");

    for (int i = 0; i < SIZE_LIST; i++)
    {
        if (i == 0)
        {
            fprintf (dot_file, "\tfree [shape=Mrecord; style=filled; label = \" free: %d\" ];\n", List.free);
            fprintf (dot_file, "\tnode000 [shape=Mrecord; style=filled; color=\"#DAAD86\";"
                       " label = \"{ ip: %03d}  | {value: %3d} |"
                                  "{Fairy: %3d} | {Tail: %3d} \" ];\n",
                                   0, List.data[0], List.next[0], List.prev[0]);
        }
        else if (i == List.free)
        {
            char color[] = "\"#D3D3D3\"";
            PrintNode (i, List, dot_file, color);
        }
        else if (List.prev[i] == -1)
        {
            char color[] = "\"#659DBD\"";
            PrintNode (i, List, dot_file, color);
        }
        else
        {
            char color[] = "\"#BC986A\"";
            PrintNode (i, List, dot_file, color);
        }
    }

    PaintAnch (anch, dot_file, List);

    fprintf (dot_file, "\n");

    /*......BASE......*/

    for (int i = 0; i < SIZE_LIST - 1; i++)
    {
        fprintf (dot_file, "\tnode%03d -> node%03d [style=bold; weight=1000; color=\"#FBEEC1\"; ];\n", i, i + 1);
    }
    fprintf (dot_file, "\n");

    /*......NEXT......*/

    for (int i = 0; i < SIZE_LIST; i++)
    {
        if (List.next[i] != -1)
        {
            if (List.prev[i] != -1)
                fprintf (dot_file, "\tnode%03d -> node%03d [weight=0; color=\"#999900\"; ];\n", i, List.next[i]);
            else
                fprintf (dot_file, "\tnode%03d -> node%03d [weight=0; color=\"#659DBD\"; ];\n", i, List.next[i]);
        }
    }
    fprintf (dot_file, "\n");

    /*......PREV......*/

    for (int i = SIZE_LIST - 1; i >= 0; i--)
    {
        if (List.prev[i] != -1)
        {
            fprintf (dot_file, "\tnode%03d -> node%03d [weight=0; color=\"#DAAD86\"; constraint=false; ];\n", i, List.prev[i]);
        }
    }
    fprintf (dot_file, "\tfree -> node%03d [weight=0; splines=ortho; constraint=false; ]; \n", List.free);

    fprintf (dot_file, "}\n");
    fclose (dot_file);
    return LIST_OK;
}

void PrintNode (int i, list_t List, FILE* dot_file, char color[12])
{
    fprintf (dot_file, "\tnode%03d [shape=Mrecord; style=filled; color=%s;"
                               " label = \"{ ip: %03d}  |"
                                          "{value: %3d} |"
                                          "{next: %3d} |"
                                          "{prev: %3d} \" ];\n",
                                i, color, i, List.data[i], List.next[i], List.prev[i]);
}

void PaintAnch (int anch, FILE* dot_file, list_t List)
{
    if (anch != -1)
        {
            if (anch >= 0)
            {
                char color[] = "\"#ADDF25\"";
                PrintNode (anch, List, dot_file, color);
            }
            else
            {
                char color[] = "\"#F79191\"";
                PrintNode ((-1) * anch, List, dot_file, color);
            }
        }
}

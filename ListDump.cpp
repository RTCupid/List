#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

static int numpng = 111;

err_t ListDump (list_t List, char* nameLastFunc)
{
    fprintf (List.log_file, "<center>Dump of List:</center><FONT SIZE=\"5\">\n");
    fprintf (List.log_file, "<center>Last operation \"%s\"<FONT SIZE=\"6\"></center>\n\n", nameLastFunc);

    // oh it is picture
    MakeDotFile (List);

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

err_t MakeDotFile (list_t List)
{
    FILE* dot_file = fopen ("DumpGraph.dot", "wt");

    fprintf (dot_file, "digraph G {\n");
    fprintf (dot_file, "\trankdir = LR;\n");
    fprintf (dot_file, "\tbgcolor=\"#FBEEC1\"\n");

    fprintf (dot_file, "\tnode000 [shape=Mrecord; style=filled; color=\"#DAAD86\";"
                       " label = \"{ ip: %03d}  | {value: %3d} |"
                                  "{Fairy: %3d} | {Tail: %3d} \" ];\n",
                                   0, List.data[0], List.next[0], List.prev[0]);

    for (int i = 1; i < SIZE_LIST; i++)
    {
        if (List.prev[i] == -1)
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
    fprintf (dot_file, "\n");
    for (int i = 0; i < SIZE_LIST - 1; i++)
    {
        fprintf (dot_file, "\tnode%03d -> node%03d [style=bold; weight=1000; color=\"#FBEEC1\"; ];\n", i, i + 1);
    }
    fprintf (dot_file, "\n"); //next
    for (int i = 1; i < SIZE_LIST - 1; i++)
    {
        if (List.next[i] != -1 && List.next[i] != 0)
        {
            fprintf (dot_file, "\tnode%03d -> node%03d [weight=0; color=\"#999900\"; ];\n", i, List.next[i]);
        }
    }
    fprintf (dot_file, "\n"); //prev
    for (int i = SIZE_LIST - 1; i > 0; i--)
    {
        if (List.prev[i] != -1 && List.prev[i] != 0)
        {
            fprintf (dot_file, "\tnode%03d -> node%03d [weight=0; color=\"#DAAD86\"; constraint=false; ];\n", i, List.prev[i]);
        }
    }

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

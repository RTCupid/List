#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

int ListDump (list_t List)
{
    FILE* log_file = fopen ("DumpGraph.dot", "wt");
    fprintf (log_file, "digraph G {\n");
    fprintf (log_file, "\trankdir = LR;\n");
    fprintf (log_file, "\tbgcolor=\"#FDAB57\"\n");

    for (int i = 0; i < SIZE_LIST; i++)
    {
        fprintf (log_file, "\tnode%03d [shape=Mrecord; style=filled; color=\"#F7DC98\"; label = \" { ip: %03d} | {value: %3d} | {next: %3d} | {prev: %3d} \" ];\n", i, i, List.data[i], List.next[i], List.prev[i]);
    }
    fprintf (log_file, "\n");
    for (int i = 0; i < SIZE_LIST - 1; i++)
    {
        fprintf (log_file, "\tnode%03d -> node%03d [style=bold; weight=1000; color=chocolate1; ];\n", i, i + 1);
    }
    fprintf (log_file, "\n"); //next
    for (int i = 1; i < SIZE_LIST - 1; i++)
    {
        if (List.next[i] != -1 && List.next[i] != 0)
        {
            fprintf (log_file, "\tnode%03d -> node%03d [weight=0; color=green; ];\n", i, List.next[i]);
        }
    }
    fprintf (log_file, "\n"); //prev
    for (int i = SIZE_LIST - 1; i > 1; i--)
    {
        if (List.prev[i] != -1 && List.prev[i] != 0)
        {
            fprintf (log_file, "\tnode%03d -> node%03d [weight=0; color=purple; constraint=false; ];\n", i, List.prev[i]);
        }
    }

    fprintf (log_file, "}\n");
    fclose (log_file);
    return 1;
}

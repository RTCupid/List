#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

err_t Verificator (list_t List, int anch)
{
    //fprintf (List.log_file, "Verify:\n");
    //fprintf (List.log_file, "anch = %d\n", anch);

    if (List.next[anch] == -1)
    {
        fprintf (List.log_file, "next[anch] = -1\n");
        fprintf (List.log_file, "ERROR: uncorrect anchor\n");
        return UNCORRECT_ANCHOR;
    }
    if (List.prev[anch] == -1)
    {
        fprintf (List.log_file, "prev[anch] = -1\n");
        fprintf (List.log_file, "ERROR: uncorrect anchor\n");
        return UNCORRECT_ANCHOR;
    }
    if (anch != List.prev[List.next[anch]])
    {
        fprintf (List.log_file, "ERROR: next[anch] = <%d>\n prev[next[anch] = <%d>\n",
                List.next[anch], List.prev[List.next[anch]]);
        return DESYNCHRON_NEXT_PREV;
    }
    if (anch != List.next[List.prev[anch]])
    {
        fprintf (List.log_file, "ERROR: prev[%d] = <%d>\n next[prev[%d] = <%d>\n",
                anch, List.prev[anch], anch, List.next[List.prev[anch]]);
        return DESYNCHRON_NEXT_PREV;
    }
    int index = 0;
    int size = 0;
    while (1)
    {
        if (List.next[index] == 0)
        {
            break;
        }
        index = List.next[index];
        size++;
        if (index >= SIZE_LIST)
        {
            printf ("ERROR: The list is looped\n");
            return LIST_IS_LOOP;
        }
    }


    return LIST_OK;
}

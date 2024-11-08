#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

errlst_t Verificator (list_t List)
{
    int index = 0;
    int size = 0;
    while (1)
    {
        if (List.next[index] == 0)
        {
            break;
        }
        if (size >= SIZE_LIST)
        {
            printf ("ERROR: The list is looped\n");
            return LIST_IS_LOOP;
        }
        if (index != List.prev[List.next[index]])
        {
            fprintf (List.log_file, "ERROR: next[%d] = <%d>\n prev[next[%d] = <%d>\n",
                    index, List.next[index], index, List.prev[List.next[index]]);
            return DESYNCHRON_NEXT_PREV;
        }
        if (index != List.next[List.prev[index]])
        {
            fprintf (List.log_file, "ERROR: prev[%d] = <%d>\n next[prev[%d] = <%d>\n",
                    index, List.prev[index], index, List.next[List.prev[index]]);
            return DESYNCHRON_NEXT_PREV;
        }
        index = List.next[index];
        size++;
    }

    return LIST_OK;
}

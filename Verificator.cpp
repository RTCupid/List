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


    return LIST_OK;
}

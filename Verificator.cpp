#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

err_t Verificator (list_t List, int anch)
{
    printf ("Verify:\n");
    printf ("anch = %d\n", anch);

    if (List.next[anch] == -1)
    {
        printf ("next[anch] = -1\n");
        printf ("ERROR: uncorrect anchor\n");
        return UNCORRECT_ANCHOR;
    }
    if (List.prev[anch] == -1)
    {
        printf ("prev[anch] = -1\n");
        printf ("ERROR: uncorrect anchor\n");
        return UNCORRECT_ANCHOR;
    }
    return LIST_OK;
}

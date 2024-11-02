#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

err_t ListCtor (list_t* List)
{
    printf ("Start construction of list!\n");

    List->data = (int*) calloc (SIZE_LIST, sizeof (int));

    List->next = (int*) calloc (SIZE_LIST, sizeof (int));

    List->prev = (int*) calloc (SIZE_LIST, sizeof (int));

    for (int i = 1; i < SIZE_LIST; i++)
    {
        List->next[i] = -1;
        List->prev[i] = -1;
    }
    List->next[0] = 0;
    List->prev[0] = 0;

    printf ("List constructed!\n");
    ListDump (*List);
    Pause ();
    return LIST_OK;
}

err_t ListDtor (list_t* List)
{
    free (List->data);

    free (List->next);

    free (List->prev);

    return LIST_OK;
}

err_t ListAddAfter (list_t* List, int anch, int value)
{
    err_t error = Verificator (*List, anch);
    if (error)
    {
        return error;
    }

    int indFree = FindFreeSell (*List);
    printf ("indFree = %d\n", indFree);
    if (indFree == -1)
    {
        printf ("ERROR: not enough memory");
        return NOT_ENOUGH_MEMORY;
    }

    List->data[indFree] = value;

    List->next[indFree] = List->next[anch];
    List->next[anch] = indFree;

    List->prev[List->next[indFree]] = indFree;
    List->prev[indFree] = anch;

    ListDump (*List);
    Pause ();
    return LIST_OK;
}
err_t ListAddFairy (list_t* List, int value)
{
    err_t error = ListAddAfter (List, 0, value);
    return error;
}

err_t ListAddTail (list_t* List, int value)
{
    err_t error = ListAddAfter (List, List->prev[0], value);
    return error;
}

err_t ListDel (list_t* List, int anch)
{
    err_t error = Verificator (*List, anch);
    if (error)
    {
        return error;
    }
    if (anch == 0)
    {
        printf ("ERROR: anchor is null\n");
        return NULL_ANCHOR;
    }
    List->data[anch] *= -1;
    List->next[List->prev[anch]] = List->next[anch];
    List->prev[List->next[anch]] = List->prev[anch];

    List->next[anch] = -1;
    List->prev[anch] = -1;

    ListDump (*List);
    Pause ();
    return LIST_OK;
}

int FindFreeSell (list_t List)
{
    for (int index = 1; index < SIZE_LIST; index++)
    {
        if (List.next[index] == -1)
        {
            return index;
        }
    }
    return -1;
}

void Pause ()
{
    printf ("Enter to continue...\n");
    getchar ();
}

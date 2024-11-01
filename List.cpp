#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

int ListCtor (list_t* List)
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

    printf ("List constructed!\n");
    return 1;
}

int ListDtor (list_t* List)
{
    free (List->data);

    free (List->next);

    free (List->prev);

    return 1;
}

int PutElem (list_t* List, int anch, int value)
{
    int error = Verificator (*List, anch);
    if (error)
    {
        return 0;
    }



    int indFree = FindFreeSell (*List);
    printf ("indFree = %d\n", indFree);
    if (indFree == -1)
    {
        printf ("not enough memory");
        assert (0);
    }

    List->data[indFree] = value;

    if (anch == 0)
    {
        List->next[indFree] = 1;
        List->prev[indFree] = 0;
        return 1;
    }

    List->next[indFree] = List->next[anch];
    List->next[anch] = indFree;

    List->prev[List->next[indFree]] = indFree;
    List->prev[indFree] = anch;

    return 1;
}

int DelElem (list_t* List, int anch)
{
    List->data[anch] *= -1;
    List->next[List->prev[anch]] = List->next[anch];
    List->prev[List->next[anch]] = List->prev[anch];

    List->next[anch] = -1;
    List->prev[anch] = -1;

    return 1;
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

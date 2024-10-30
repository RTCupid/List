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

int ListDump (list_t List)
{


    return 1;
}

int PutElem (list_t* List, int anch, int value)
{
    int addr = FindFreeSell (*List);
    if (addr == -1)
    {
        printf ("not enough memory");
        assert (0);
    }

    List->data[addr] = value;

    List->next[addr] = List->next[anch];
    List->next[anch] = addr;

    return 1;
}

int DelElem (list_t* List, int anch)
{

    return 1;
}

int FindFreeSell (list_t List)
{
    int addr = -1;
    for (int index = 1; index < SIZE_LIST; index++)
    {
        if (List.next[index] == -1)
        {
            return index;
        }
    }
    return -1;
}

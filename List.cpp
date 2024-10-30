#include <stdio.h>
#include "List.h"

int ListCtor (list_t* List)
{
    List->data = (int*) calloc (SIZE_LIST, sizeof (int));

    List->next = (int*) calloc (SIZE_LIST, sizeof (int));

    for (int i = 0; i < SIZE_LIST; i++)
    {
        next[i] = -1;
        prev[i] = -1;
    }

    List->prev = (int*) calloc (SIZE_LIST, sizeof (int));

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
    int addr = FindFreeSell (List);
    if (addr == 0)
    {
        printf ("not enough memory");
        assert (0);
    }

    List->data[addr] = value;

    List->next[addr] = anch;
    List->next[anch] = addr;

    return 1;
}

int DelElem (list_t* List, int anch)
{


}

int FindFreeSell (list_t List)
{
    int addr = 0;
    for (int index = 0; index < SIZE_LIST; index++)
    {
        if (next[index] == -1)
        {
            return index;
        }
    }
    return 0;
}

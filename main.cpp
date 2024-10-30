#include <stdio.h>
#include "List.h"

int main ()
{
    printf ("### Programm List\n");
    printf ("### by RTCupid, 2024\n");

    list_t List = {};
    ListCtor (&List);

    for (int i = 1; i < 6; i++)
    {
        List.data[i] = i * 10;
    }
    for (int i = 1; i < 5; i++)
    {
        List.next[i] = i + 1;
    }
    List.next[5] = 0;

    PutElem (&List, 2, 25);

    for (int i = 0; i < SIZE_LIST; i++)
    {
        printf ("data[%d] = %2d   |   next[%d] = %2d\n", i, List.data[i], i, List.next[i]);
    }


    return 0;
}

#include <stdio.h>
#include "List.h"

int main ()
{
    printf ("\n# Programm List\n");
    printf ("# by RTCupid, 2024\n\n");

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
    for (int i = 2; i < 6; i++)
    {
        List.prev[i] = i - 1;
    }
    List.prev[1] = 0;

    PutElem (&List, 2, 25);

    ListDump (List);

    //istDump (List);

    ListDtor (&List);

    printf ("\n# End of programm!\n");
    return 0;
}

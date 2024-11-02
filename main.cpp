#include <stdio.h>
#include "List.h"

int main ()
{
    printf ("\n# Programm List\n");
    printf ("# by RTCupid, 2024\n\n");

    list_t List = {};
    ListCtor (&List);

    ListAddTail (&List, 228);

    ListAddTail (&List, 229);

    ListAddFairy (&List, 900);

    ListDump (List);
    ListDtor (&List);

    printf ("\n# End of programm!\n");
    return 0;
}

#include <stdio.h>

#include "List.h"
#include "ListDump.h"

int main ()
{
    printf ("\n# Programm List\n");
    printf ("# by RTCupid, 2024\n\n");

    list_t List = {};
    ListCtor (&List);

    ListAddTail (&List, 228);

    ListAddTail (&List, 229);

    ListAddTail (&List, 230);

    ListAddTail (&List, 231);

    ListAddFairy (&List, 900);

    ListAddTail (&List, 231);

    ListDel (&List, 3);

    ListAddFairy (&List, 809);

    int index = FindInListValue (List, 900);
    //fprintf (List.log_file, "index of 900 = %d\n", index);
    FindInListValue (List, 1900);

    List.next[4] = 7;

    char name[] = "abcd";
    ListDump (List, name, -1);

    ListAddBefore (&List, index, 905);

    ClearList (&List);

    ListAddFairy (&List, 910);

    ListDtor (&List);

    printf ("\n# End of programm!\n");
    return 0;
}

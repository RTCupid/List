#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"
#include "ListDump.h"

////#include "Stack/Stack.cpp"
////#include "Stack/Stack_Error_Checking.cpp"

errlst_t ListCtor (list_t* List)
{
    List->log_file = fopen ("Log_file.htm", "wt");
    if (List->log_file == NULL)
    {
        printf ("fopen (Log_file.htm) returned NULL\n");
        return LOG_FILE_UNCORRECT;
    }

    fprintf (List->log_file, "<FONT SIZE=\"6\"><pre>\n\n");

    fprintf (List->log_file, "Start construction of list!\n");

    List->data = (int*) calloc (SIZE_LIST, sizeof (int));

    List->next = (int*) calloc (SIZE_LIST, sizeof (int));

    List->prev = (int*) calloc (SIZE_LIST, sizeof (int));

    //printf ("SIZE_FREE = %d\n", SIZE_FREE);

    for (int i = 1; i < SIZE_FREE; i++)
    {
        List->next[i] = i + 1;
        List->prev[i] = -1;
    }
    List->next[SIZE_FREE] = -1;
    List->prev[SIZE_FREE] = -1;

    List->next[0] = 0;
    List->prev[0] = 0;

    List->free = 1;

    //StackDump (&List->free);

    fprintf (List->log_file, "List constructed!\n");
    char nameFunc[50] = {};
    sprintf (nameFunc, "ListCtor");
    ListDump (*List, nameFunc, -1);
    PS Pause ();
    return LIST_OK;
}

errlst_t ListDtor (list_t* List)
{
    free (List->data);
    List->data = NULL;

    free (List->next);
    List->next = NULL;

    free (List->prev);
    List->prev = NULL;

    fprintf (List->log_file, "<center>List is destroy!</center>\n");

    fclose (List->log_file);

    return LIST_OK;
}

errlst_t ListAddAfter (list_t* List, int anch, int value)
{
    errlst_t error = Verificator (*List);
    if (error)
    {
        return error;
    }

    if (List->prev[anch] == -1)
    {
        fprintf (List->log_file, "prev[%d] = -1\n", anch);
        fprintf (List->log_file, "ERROR: uncorrect anchor\n");
        return UNCORRECT_ANCHOR;
    }

    int indFree = List->free;
    List->free = List->next[List->free];

    if (indFree == -1)
    {
        char nameError[100] = {};
        sprintf (nameError, "Func ListAddAfter anch = %d:\n"
                            "ERROR: not enough memory", anch);
        ListDump (*List, nameError, anch);
        return NOT_ENOUGH_MEMORY;
    }

    List->data[indFree] = value;

    List->next[indFree] = List->next[anch];
    List->next[anch] = indFree;

    List->prev[List->next[indFree]] = indFree;
    List->prev[indFree] = anch;

    char nameFunc[50] = {};
    sprintf (nameFunc, "ListAddAfter anch = %d", anch);
    ListDump (*List, nameFunc, anch);
    PS Pause ();
    return LIST_OK;
}
errlst_t ListAddFairy (list_t* List, int value)
{
    errlst_t error = ListAddAfter (List, 0, value);
    return error;
}

errlst_t ListAddTail (list_t* List, int value)
{
    errlst_t error = ListAddAfter (List, List->prev[0], value);
    return error;
}

errlst_t ListAddBefore (list_t* List, int anch, int value)
{
    errlst_t error = ListAddAfter (List, List->prev[anch], value);
    return error;
}

errlst_t ListDel (list_t* List, int anch)
{
    errlst_t error = Verificator (*List);
    if (error)
    {
        return error;
    }
    if (List->prev[anch] == -1)
    {
        fprintf (List->log_file, "prev[%d] = -1\n", anch);
        fprintf (List->log_file, "ERROR: uncorrect anchor\n");
        return UNCORRECT_ANCHOR;
    }
    if (anch == 0)
    {
        fprintf (List->log_file, "ERROR: anchor is null\n");
        return NULL_ANCHOR;
    }

    List->data[anch] *= -1;
    List->next[List->prev[anch]] = List->next[anch];
    List->prev[List->next[anch]] = List->prev[anch];

    List->prev[anch] = -1;
    List->next[anch] = List->free;
    List->free = anch;

    char nameFunc[50] = {};
    sprintf (nameFunc, "ListDel anch = %d", anch);
    ListDump (*List, nameFunc, (-1) * anch);
    PS Pause ();
    return LIST_OK;
}

errlst_t ClearList (list_t* List)
{
    for (int i = 1; i < SIZE_FREE; i++)
    {
        List->data[i] = 0;
        List->next[i] = i + 1;
        List->prev[i] = -1;
    }
    List->next[SIZE_FREE] = -1;
    List->prev[SIZE_FREE] = -1;

    List->next[0] = 0;
    List->prev[0] = 0;

    List->free = 1;

    char nameFunc[50] = {};
    sprintf (nameFunc, "ClearList");
    ListDump (*List, nameFunc, -1);
    return LIST_OK;
}

int FindInListValue (list_t List, int value)
{
    errlst_t error = Verificator (List);
    if (error)
    {
        return error;
    }

    int index = 0;
    while (1)
    {
        if (List.next[index] == 0)
        {
            break;
        }
        if (List.data[index] == value)
        {
            char nameFunc[50] = {};
            sprintf (nameFunc, "FindInListValue value = <%d>", value);
            ListDump (List, nameFunc, -1);
            fprintf (List.log_file, "index of value<%d> = %d\n", value, index);
            return index;
        }
        else
        {
            index = List.next[index];
        }
    }

    char nameFunc[50] = {};
    sprintf (nameFunc, "FindInListValue value = <%d>", value);
    ListDump (List, nameFunc, -1);
    fprintf (List.log_file, "value <%d> was not found in the List\n", value);
    return 0;
}

void Pause ()
{
    printf ("Enter to continue...\n");
    getchar ();
}

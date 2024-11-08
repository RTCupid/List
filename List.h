#ifndef LIST_H
    #define LIST_H

    #include "Stack/Config.h"
    #include "Stack/Stack.h"

    #define PS if(0)
    typedef struct
    {
        int* data;
        int* next;
        int* prev;
        stack_t free;
        FILE* log_file;
    } list_t;

    enum errlst_t
    {
        LIST_OK,
        UNCORRECT_ANCHOR = 1,
        NULL_ANCHOR,
        NOT_ENOUGH_MEMORY,
        LOG_FILE_UNCORRECT,
        DESYNCHRON_NEXT_PREV,
        LIST_IS_LOOP,
    };

    const int SIZE_LIST = 10;
    const int SIZE_FREE = SIZE_LIST - 1;

    errlst_t ListCtor (list_t* List);

    errlst_t ListDtor (list_t* List);

    errlst_t ListDump (list_t List, char* nameLastFunc);

    errlst_t MakeDotFile (list_t List);

    void PrintNode (int i, list_t List, FILE* dot_file, char color[12]);

    errlst_t Verificator (list_t List);

    errlst_t ListAddAfter (list_t* List, int anch, int value);

    errlst_t ListAddBefore (list_t* List, int anch, int value);

    errlst_t ListAddFairy (list_t* List, int value);

    errlst_t ListAddTail (list_t* List, int value);

    errlst_t ListDel (list_t* List, int anch);

    errlst_t ClearList (list_t* List);

    int FindFreeSell (list_t List);

    int FindInListValue (list_t List, int value);

    void Pause ();
#endif

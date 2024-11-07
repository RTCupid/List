#ifndef LIST_H
    #define LIST_H

    #define PS if(0)
    typedef struct
    {
        int* data;
        int* next;
        int* prev;
        int fairy;
        int tail;
        FILE* log_file;
    } list_t;

    enum err_t
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

    err_t ListCtor (list_t* List);

    err_t ListDtor (list_t* List);

    err_t ListDump (list_t List, char* nameLastFunc);

    err_t MakeDotFile (list_t List);

    void PrintNode (int i, list_t List, FILE* dot_file, char color[12]);

    err_t Verificator (list_t List, int anch);

    err_t ListAddAfter (list_t* List, int anch, int value);

    err_t ListAddBefore (list_t* List, int anch, int value);

    err_t ListAddFairy (list_t* List, int value);

    err_t ListAddTail (list_t* List, int value);

    err_t ListDel (list_t* List, int anch);

    err_t ClearList (list_t* List);

    int FindFreeSell (list_t List);

    int FindInListValue (list_t List, int value);

    //int FindInListIndex (list_t List, int value);

    void Pause ();
#endif

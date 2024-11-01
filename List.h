#ifndef LIST_H
    #define LIST_H
    typedef struct
    {
        int* data;
        int* next;
        int* prev;
        int fairy;
        int tail;
    } list_t;

    enum err_t
    {
        LIST_OK,
        UNCORRECT_ANCHOR = 1,
        NULL_ANCHOR,
        NOT_ENOUGH_MEMORY,
        LOG_FILE_UNCORRECT,
    };

    const int SIZE_LIST = 10;

    err_t ListCtor (list_t* List);

    err_t ListDtor (list_t* List);

    err_t ListDump (list_t List);

    err_t MakeDotFile (list_t List);

    err_t Verificator (list_t List, int anch);

    err_t ListAddAfter (list_t* List, int anch, int value);

    err_t ListAddFairy (list_t* List, int value);

    err_t ListAddTail (list_t* List, int value);

    err_t ListDel (list_t* List, int anch);

    int FindFreeSell (list_t List);
#endif

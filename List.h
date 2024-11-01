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

    const int SIZE_LIST = 10;

    int ListCtor (list_t* List);

    int ListDtor (list_t* List);

    int ListDump (list_t List);

    int Verificator (list_t List, int anch);

    int PutElem (list_t* List, int anch, int value);

    int DelElem (list_t* List, int anch);

    int FindFreeSell (list_t List);
#endif

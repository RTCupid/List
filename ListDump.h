#ifndef LISTDUMP_H
    #define LISTDUMP_H

    errlst_t ListDump (list_t List, char* nameLastFunc, int anch);

    errlst_t MakeDotFile (list_t List, int anch);

    void PrintNode (int i, list_t List, FILE* dot_file, char color[12]);

    void MakeAllNodes (list_t List, FILE* dot_file);

    void MakeBasicArrows (FILE* dot_file);

    void MakeArrows (FILE* dot_file, list_t List);

    void PaintAnch (int anch, FILE* dot_file, list_t List);
#endif

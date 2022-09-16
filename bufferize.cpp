#include "protos.h"

/*!
    \brief Bufferizes file input
    \param filename name of file to read from
    \return ptr to c-string with whole text of file
*/
char* bufferize (const char* filename) {

    size_t fSize = get_size (filename);

    char* txt = (char*) calloc (fSize + 2, sizeof (char));
    txt++;

    FILE* fIn = fopen (filename, "r");

    fread (txt, sizeof (char), fSize, fIn);

    txt[fSize] = '\0';

    return txt;
}
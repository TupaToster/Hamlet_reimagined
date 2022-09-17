#include "protos.h"

/// @brief Buffirezes file
/// @param filename name of file to bufferize
/// @param writeTo ptr to struct text to write buffer and buffer length to
void bufferize (const char* filename, text* writeTo) {

    writeTo->textSize = get_size (filename);

    writeTo->textString = (char*) calloc (writeTo->textSize + 2, sizeof (char));
    CHECK (writeTo->textString == NULL, , BAD_ALLOC);

    writeTo->textString++;

    FILE* fIn = fopen (filename, "r");
    CHECK (fIn == NULL, , FOPEN_ERROR);

    CHECK (fread (writeTo->textString, sizeof (char), writeTo->textSize, fIn) != writeTo->textSize, , INPUT_ERROR);

    writeTo->textString[writeTo->textSize] = '\0';

}
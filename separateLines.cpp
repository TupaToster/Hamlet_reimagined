#include "protos.h"

/// @brief separates lines in a text
/// @param writeTo text* to write to and read from
void separateLines (text* writeTo) {

    assert (writeTo != NULL);

    size_t line_iter = 0;

    for (size_t i = 0; i < writeTo->textSize; i++) {

        if (writeTo->lines[line_iter].begin == NULL) writeTo->lines[line_iter].begin = writeTo->textString + i;

        if (writeTo->textString[i] == '\n') {

            writeTo->lines[line_iter].end = writeTo->textString + i + 1;
            line_iter++;
        }
    }

    writeTo->lines[line_iter].end = writeTo->textString + writeTo->textSize;
}
#include "protos.h"

/// @brief counts amount of lines in a text
/// @param src text* to wite to and read from
void cntLines (text* src) {

    assert (src != NULL);

    for (size_t i = 0; i < src->textSize; i++) {

        if (src->textString[i] == '\n') src->stringCnt++;
    }
    src->stringCnt++;
}
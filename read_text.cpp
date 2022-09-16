#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#include "protos.h"

/*!
    \brief Fills text type var with input from file
    \param filename name of file to fill from
    \return text struct full of stuff

Fills text struct with:
textString - whole text of a file
lines - array of lines of file of type [begin, end)
stringCnt - amount of strings in file
textSize - sizeof text (by get_size)
*/
text read_text (const char* filename) {

    text retVal = {};
    initText (&retVal);

    retVal.textString = bufferize (filename);
 
    retVal.textSize = strlen (retVal.textString);

    for (size_t i = 0; i < retVal.textSize; i++) {

        if (retVal.textString[i] == '\n') retVal.stringCnt++;
    }
    retVal.stringCnt++;

    retVal.lines = (line*) calloc (retVal.stringCnt + 1, sizeof (line));

    size_t line_iter = 0;

    for (size_t i = 0; i < retVal.textSize; i++) {

        if (retVal.lines[line_iter].begin == NULL) retVal.lines[line_iter].begin = retVal.textString + i;

        if (retVal.textString[i] == '\n') {

            retVal.lines[line_iter].end = retVal.textString + i + 1;
            line_iter++;
        }
    }

    retVal.lines[line_iter].end = retVal.textString + retVal.textSize;

    return retVal;
}
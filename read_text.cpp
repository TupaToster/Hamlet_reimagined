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

    assert (filename != NULL);

    text retVal = {};
    initText (&retVal);

    bufferize (filename, &retVal);
    assert (errCode == OK);
    CHECK (errCode != OK, retVal, errCode);

    cntLines (&retVal);

    retVal.lines = (line*) calloc (retVal.stringCnt + 1, sizeof (line));
    CHECK (retVal.lines == NULL, retVal, BAD_ALLOC);


    separateLines (&retVal);

    return retVal;
}
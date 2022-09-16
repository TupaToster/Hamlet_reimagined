#include "protos.h"


/*!
    \brief Initializes a line type var
    \param target line* to var to init
*/
void initLine(line* target) {

    target->begin = NULL;
    target->end = NULL;
}

/*!
    \brief Deinitializes a line type var
    \param target line* to var to kill
*/
void killLine(line* target) {

    target->begin = NULL;
    target->end   = NULL;
}


/*!
    \brief Initializes a text type var
    \param target text* to var to init
*/
void initText(text* target) {

    target->textString  = NULL;
    target->textSize    = 0;
    target->stringCnt   = 0;
    target->lines       = NULL;
}

/*!
    \brief Deinitializes a text type var
    \param target text* to var to kill
*/
void killText (text* target) {

    free (target->textString);
    free (target->lines);
    target->textSize  = 0;
    target->stringCnt = 0;
    return;
}
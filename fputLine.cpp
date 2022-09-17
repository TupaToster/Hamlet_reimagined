#include "protos.h"

void fputLine (line src, FILE* outfile) {

    char temp = *src.end;
    *src.end = '\0';

    fputs (src.begin, outfile);

    *src.end = temp;

    if (src.end[-1] != '\n')
        fputc ('\n', outfile);

}
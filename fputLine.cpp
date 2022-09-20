#include "protos.h"

void fputLine (line src, FILE* outfile) {

    assert (src.begin != NULL);
    assert (src.end != NULL);
    assert (outfile != NULL);

    char temp = *src.end;
    *src.end = '\0';

    fputs (src.begin, outfile);

    *src.end = temp;

    if (src.end[-1] != '\n')
        fputc ('\n', outfile);

}
#include "protos.h"

/// @brief Var to store error codes from functions
enum errorCode errCode = OK;

/// @brief Contains more than nothing
/// @param argc number of args in command line
/// @param argv array of args
/// @return exit code of program
int main (int argc, char* argv[]) {

    char*  inName       = NULL;
    char* sortedOut     = NULL;
    char* arabsortedOut = NULL;
    char* defaultOut    = NULL;
    FILE* output        = NULL;

    handleComLine (argc, argv, &inName, &sortedOut, &arabsortedOut, &defaultOut);
    assert (errCode == OK);

    text hamlet = read_text(inName);
    assert (errCode == OK);

    if (sortedOut != NULL) {

        output = fopen (sortedOut, "w");
        assert (output != NULL);

        printf ("Sorting straight type...\n");

        #ifdef MY_SORT
            puzirek (hamlet.lines, hamlet.stringCnt, sizeof (line), lineCmp);
        #else
            qsort   (hamlet.lines, hamlet.stringCnt, sizeof (line), lineCmp);
        #endif

        printf ("Sorted straight type, printing...\n");

        for (size_t i = 0; i < hamlet.stringCnt; i++) {

            fputLine (hamlet.lines[i], output);
        }

        printf ("Printed straight type. Procceeding.\n");

        fclose (output);
    }

    if (arabsortedOut != NULL) {

        output = fopen (arabsortedOut, "w");
        assert (output != NULL);

        printf ("Sorting in arabic...\n");

        #ifdef MY_SORT
            puzirek (hamlet.lines, hamlet.stringCnt, sizeof (line), lineCmpArab);
        #else
            qsort   (hamlet.lines, hamlet.stringCnt, sizeof (line), lineCmpArab);
        #endif

        printf ("Sorted in arabic. Printing...\n");

        for (size_t i = 0; i < hamlet.stringCnt; i++) {

            fputLine (hamlet.lines[i], output);
        }

        printf ("Printed arabic type. \n");

        fclose (output);
    }

    if (defaultOut != NULL) {

        printf ("Printing default...\n");
        output = fopen (defaultOut, "w");
        assert (output != NULL);

        fputs (hamlet.textString, output);

        printf ("Printed default");

        fclose (output);
    }

    free (inName);
    free (sortedOut);
    free (arabsortedOut);
    free (defaultOut);

    killText (&hamlet);
}
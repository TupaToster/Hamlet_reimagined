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

    FILE* output = NULL;

    if (argc == 5) {

        inName  = (char*) calloc (strlen (argv[1]) + 1, sizeof (char));
        strcpy (inName, argv[1]);

        sortedOut = (char*) calloc (strlen (argv[2]) + 1, sizeof (char));
        check (sortedOut == NULL, 0, BAD_ALLOC);
        strcpy (sortedOut, argv[2]);

        arabsortedOut = (char*) calloc (strlen (argv[3] + 1), sizeof (char));
        check (arabsortedOut == NULL, 0, BAD_ALLOC);
        strcpy (arabsortedOut, argv[3]);

        defaultOut = (char*) calloc (strlen (argv[4] + 1), sizeof (char));
        check (defaultOut == NULL, 0, BAD_ALLOC);
        strcpy (defaultOut, argv[4]);

        output = fopen (sortedOut, "w");
        check (output == NULL, 0, FOPEN_ERROR);
    }

    text hamlet = read_text(inName);
    check (errCode != OK, 0, errCode);

    printf ("Sorting straight type...\n");

    qsort (hamlet.lines, hamlet.stringCnt, sizeof (line), lineCmp);

    printf ("Sorted straight type, printing...\n");

    for (size_t i = 0; i < hamlet.stringCnt; i++) {

        fputLine (hamlet.lines[i], output);
        check (errCode != OK, 0, errCode);
    }

    printf ("Printed straight type. Procceeding.\n");

    output = fopen (arabsortedOut, "w");
    check (output == NULL, 0, FOPEN_ERROR);

    printf ("Sorting in arabic...\n");

    //qsort (hamlet.lines, hamlet.stringCnt, sizeof (line), lineCmpArab);
    puzirek (hamlet.lines, hamlet.stringCnt, sizeof (line), lineCmpArab);
    printf ("Sorted in arabic. Printing...\n");

    for (size_t i = 0; i < hamlet.stringCnt; i++) {

        fputLine (hamlet.lines[i], output);
    }

    printf ("Printed arabic type. Printing default...\n");

    output = fopen (defaultOut, "w");
    check (output == NULL, 0, FOPEN_ERROR);

    fputs (hamlet.textString, output);

    printf ("Printed default");
}
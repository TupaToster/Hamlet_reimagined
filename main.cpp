#include "protos.h"

/// @brief Var to store error codes from functions
enum errorCode errCode = OK;

/// @brief Contains more than nothing
/// @param argc number of args in command line
/// @param argv array of args
/// @return exit code of program
int main (int argc, char* argv[]) {

    char*  inName = NULL;
    char* outName = NULL;

    if (argc == 3) {

        inName  = (char*) calloc (strlen (argv[1]) + 1, sizeof (char));
        strcpy (inName, argv[1]);

        outName = (char*) calloc (strlen (argv[2]) + 1, sizeof (char));
        strcpy (outName, argv[2]);
    }

    text hamlet = read_text(inName);

    printf ("%d", lineCmpArab ( (void*) (hamlet.lines), (void*) (hamlet.lines + 1)));

/*

    printf ("Sorting straight type...\n");
    
    qsort (hamlet.lines, hamlet.stringCnt, sizeof (line), lineCmp);
    
    printf ("Sorted straight type, printing...\n");
    
    for (int i = 0; i < hamlet.stringCnt; i++) {

        fput_line (hamlet.lines[i], output);
    }
    
    printf ("Printed straight type. Procceeding.\n");

    printf ("Sorting in arabic...\n");

    qsort (hamlet.lines, hamlet.stringCnt, sizeof (line), LineCmpArab);

    printf ("Sorted in arabic. Printing...\n");

    for (int i = 0; i < hamlet.lines[i]; i++) {

        fput_line (hamlet.lines[i], output);
    }

    printf ("Printed arabic type. Printing default...\n");

    fputs (hamlet.textString, output);

    printf ("Printed default");
    */
}
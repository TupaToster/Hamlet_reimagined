#include "protos.h"

/// @brief Duplicates argument and returns ptr to it
/// @param from string to dupe
/// @return ptr to allocated mem
char* Mystrdup (const char* from) {

    assert (from != NULL);

    char* temp = (char*) calloc (strlen (from) + 1, sizeof (char));
    CHECK (temp == NULL, NULL, BAD_ALLOC);

    strcpy (temp, from);

    temp[strlen (from)] = '\0';

    free (temp);

    return temp;
}

/// @brief Handle variable command line arguments
/// @param argc argument count
/// @param argv array of args
/// @param inName name of input file
/// @param sortedOut name of output straight sort file
/// @param arabsortedOut name of arabsorted file
/// @param defaultOut name of default output file
void handleComLine (int   argc,
                    char* argv[],
                    char** inName,
                    char** sortedOut,
                    char** arabsortedOut,
                    char** defaultOut)
{

    assert (argv != NULL);
    assert (inName != NULL);
    assert (sortedOut != NULL);
    assert (arabsortedOut != NULL);
    assert (defaultOut != NULL);

    if (argc == 1) {

        printf ("Usage of program : Hamlet.exe Input_file_name Sorted_output_file_name Sorted_arabic_output_file_name Defaul_output_file_name;\n"
                "If \"-\" is inputted instead of output file name, than no such output file is created.\n"
                "If \"-\" is inputted instead of input file, than default file with name of \"Hamlet\" is opened \n"
                "If number of arguments is not fout or zero, the program will stop");
        exit (-1);
    }
    if (argc != 5) {

        printf ("Invalid arguments");
        exit (-1);
    }
    if (argc == 5) {

        CHECK (argv[1] == NULL, , BAD_ALLOC);
        if (strcmp (argv[1], "-") == 0) {

            *inName = Mystrdup ("Hamlet");
            CHECK (errCode != OK, , errCode);
        }
        else {

            *inName = Mystrdup (argv[1]);
            CHECK (errCode != OK, , errCode);
        }

        CHECK (argv[2] == NULL, , BAD_ALLOC);
        if (strcmp (argv[2], "-") == 0) {

            *sortedOut = NULL;
        }
        else {

            *sortedOut = Mystrdup (argv[2]);
            CHECK (errCode != OK, , errCode);
        }

        CHECK (argv[3] == NULL, , BAD_ALLOC);
        if (strcmp (argv[3], "-") == 0) {

            *arabsortedOut = NULL;
        }
        else {

            *arabsortedOut = Mystrdup (argv[3]);
            CHECK (errCode != OK, , errCode);
        }

        CHECK (argv[4] == NULL, , BAD_ALLOC);
        if (strcmp (argv[4], "-") == 0) {

            *defaultOut = NULL;
        }
        else {

            *defaultOut = Mystrdup (argv[4]);
            CHECK (errCode != OK, , errCode);
        }
    }

}
#pragma GCC diagnostic ignored "-Wcast-qual"

#include "protos.h"

/// @brief Stright comp function
/// @param fst first line to compare
/// @param scd scd line to compare
/// @return -1 if fst < scd
/// @return 0 if fst == scd
/// @return 1 if fst > scd
int lineCmp (const void* fst, const void* scd) {

    assert (fst != NULL);
    assert (scd != NULL);

    return cmpCore (*((line*) fst), *((line*) scd), sizeof (char));
}

/// @brief compares strings left to right
/// @param fst first line to compare
/// @param scd second line to compare
/// @return -1 if fst < scd
/// @return 0 if fst == scd
/// @return 1 if fst > scd
int lineCmpArab (const void* fst, const void* scd) {

    assert (fst != NULL);
    assert (scd != NULL);

    line line1 = *((line*) fst);
    line line2 = *((line*) scd);

    char* temp = line1.begin;
    line1.begin = line1.end;
    line1.end = temp;

    temp = line2.begin;
    line2.begin = line2.end;
    line2.end = temp;

    line1.begin--;
    line2.begin--;

    line1.end--;
    line2.end--;

    return cmpCore (line1, line2, -1);
}


/// @brief Core of comparison of 2 strings with direction of ptr movement
/// @param line1 first line to compare
/// @param line2 second line to compare
/// @param delta direction and speed of ptr movement
/// @return -1 if line1 < line2
/// @return 0 if line1 == line2
/// @return 1 if line1 > line2
int cmpCore (line line1, line line2, int delta) {

    assert (line1.begin != NULL);
    assert (line1.end   != NULL);

    assert (line2.begin != NULL);
    assert (line2.end   != NULL);

    while (line1.begin != line1.end and !isalnum (*line1.begin)) line1.begin += delta;
    while (line2.begin != line2.end and !isalnum (*line2.begin)) line2.begin += delta;

    while (line1.begin != line1.end
    and    line2.begin != line2.end
    and   *line1.begin == *line2.begin) {

        line1.begin += delta;
        line2.begin += delta;
    }

    if      (line1.begin == line1.end and line2.begin != line2.end) return -1;
    else if (line1.begin != line1.end and line2.begin == line2.end) return  1;
    else if (line1.begin == line1.end and line2.begin == line2.end) return  0;


    if   (tolower (*line1.begin) < tolower(*line2.begin)) return -1;

    return 1;
}
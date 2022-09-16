#pragma GCC diagnostic ignored "-Wcast-qual"

#include "protos.h"
/// @brief checks for c being a letter or number
/// @param c char to check
/// @return true if is cool
/// @return false if not cool
bool isAlphaNum (const char c) {

    return ((c >= 'a' and c <= 'z')
    or      (c >= 'A' and c <= 'Z')
    or      (c >= '0' and c <= '9'));
}


/// @brief Stright comp function
/// @param fst first line to compare
/// @param scd scd line to compare
/// @return -1 if fst < scd
/// @return 0 if fst == scd
/// @return 1 if fst > scd
int lineCmp (const void* fst, const void* scd) {

    return cmpCore (*(line*) fst, *(line*) scd, sizeof (char));
}

/// @brief compares strings left to right
/// @param fst first line to compare
/// @param scd second line to compare
/// @return -1 if fst < scd
/// @return 0 if fst == scd
/// @return 1 if fst > scd
int lineCmpArab (const void* fst, const void* scd) {

    line line1 = *(line*) fst;
    line line2 = *(line*) scd;

    line1.begin--;
    line2.begin--;

    line1.end--;
    line2.end--;

    char* temp = line1.begin;
    line1.begin = line1.end;
    line1.end = temp;

    temp = line2.begin;
    line2.begin = line2.end;
    line2.end = temp;

    return cmpCore (line1, line2, -((int) sizeof (char)));
}


/// @brief Core of comparison of 2 strings with direction of ptr movement
/// @param line1 first line to compare
/// @param line2 second line to compare
/// @param delta direction and speed of ptr movement
/// @return -1 if line1 < line2
/// @return 0 if line1 == line2
/// @return 1 if line1 > line2
int cmpCore (line line1, line line2, int delta) {

    while (!isAlphaNum (*line1.begin)) line1.begin += delta;
    while (!isAlphaNum (*line2.begin)) line2.begin += delta;

    while (line1.begin != line1.end
    and    line2.begin != line2.end
    and   *line1.begin == *line2.begin) {

        line1.begin += delta;
        line2.begin += delta;
    }

    if      (line1.begin == line1.end and line2.begin != line2.end) return -1;
    else if (line1.begin != line1.end and line2.begin == line2.end) return  1;
    else if (line1.begin == line1.end and line2.begin == line2.end) return  0;


    if   (*line1.begin < *line2.begin) return -1;

    return 1;
}
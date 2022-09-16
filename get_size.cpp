#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#include "protos.h"

/*!
    \brief Returns size of file in chars
    \param filename name of file to measure
    \return sizeof file in chars
*/
size_t get_size (const char* filename) {

    struct stat temp = {};

    stat (filename, &temp);

    return temp.st_size;
}
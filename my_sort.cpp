#include "protos.h"

// я короче в 3:15 тильтую и пишу пузырек по причине я быдло (не понял qsort на строках)


/// @brief Sorts
/// @param begin void* to start of array
/// @param len length in elements
/// @param elemSize length of one elem in bytes
/// @param comp func to compare em all
void puzirek (void* begin, size_t len, size_t elemSize, int (*comp) (const void*, const void*)) {

    char temp = '\0';

    for (size_t indent = 0; indent < len; indent++) {

        for (size_t iter = 0; iter < len - 1 - indent; iter++) {

            if (comp (begin + iter * elemSize, begin + (iter + 1) * elemSize) > 0) {

                for (size_t block = 0; block < elemSize; block++) {

                    temp = *((char*) begin + iter * elemSize + block);
                    *((char*) begin + iter * elemSize + block) = *((char*) begin + (iter + 1) * elemSize + block);
                    *((char*) begin + (iter + 1) * elemSize + block) = temp;
                }
            }
        }
    }
}
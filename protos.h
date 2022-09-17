#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys\stat.h>
#include <ctype.h>
#define MY_SORT

/// @brief Enum for error codes
enum errorCode {
    OK = 0,          ///< everything ok
    BAD_ALLOC = -1,   ///< Allocation failed
    FOPEN_ERROR = -2, ///< Error opening file
    INPUT_ERROR = -3  ///< Error in input function
};

extern errorCode errCode;

/*!
    \brief Checks for condition and if true returns retVal and writes errType to errCode
    \param cond condition to check
    \param retVal value to return
    \param errType error type to save
*/
#define CHECK(cond, retVal, errType) \
if (cond) {                          \
                                     \
    errCode = errType;               \
    return retVal;                   \
}

/// @brief Struct to store lines of text in format [begin, end)
struct line {

    char* begin = NULL; ///< Ptr to the beginning
    char* end   = NULL; ///< Ptr to the end
};

/// @brief Stores text in format of string and array of line structures
struct text {

    char* textString = NULL; ///< char* that points to the beginning of a text
    size_t textSize = 0;     ///< size_t that declares sizeof text in chars
    line* lines = NULL;      ///< ptr to a line array that stores text in a format of lines
    size_t stringCnt = 0;    ///< size_t that indicates amount of lines in text
};

void initText (text* target);

void initLine (line* target);

void killText (text* target);

void killLine (line* target);

size_t get_size (const char* filename);

void bufferize (const char* filename, text* writeTo);

text read_text (const char* filename);

bool isAlphaNum (const char c);

int lineCmp (const void*fst, const void* scd);

int lineCmpArab (const void*fst, const void* scd);

int cmpCore (line line1, line line2, int delta);

void fputLine (line src, FILE* outfile);

void puzirek (void*, size_t, size_t, int (*) (const void*, const void*));

void handleComLine (int argc, char* argv[], char** inName, char** sortedOut, char** arabsortedOut, char** defaultOut);

void cntLines (text* writeTo);

void separateLines (text* writeTo);
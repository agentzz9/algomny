#include "lzlocal.h"

/* cyclic buffer sliding window of already read characters */
unsigned char slidingWindow[WINDOW_SIZE];
unsigned char uncodedLookahead[MAX_CODED];


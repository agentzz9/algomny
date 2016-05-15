#include "lzlocal.h"
/* cyclic buffer sliding window of already read characters */
extern unsigned char slidingWindow[];
extern unsigned char uncodedLookahead[];

void InitializeSearchStructures()
{
    return;
}
void FillTable(unsigned char *uncoded, int* kmpTable)
{
    int i;  /* current position in the kmpTable */
    int j;  /* next position for the current candidate substring in uncoded */

    /* initialize the start of the kmpTable with */
    kmpTable[0] = -1;
    kmpTable[1] = 0;
    i = 2;
    j = 0;

    while (i < MAX_CODED)
    {
        if (uncoded[i - 1] == uncoded[j])
        {
            /* the candidate substring continues to match */
            j++;
            kmpTable[i] = j;
            i++;
        }
        else if (j > 0)
        {
            /* no more matches, but we had at least one for fallback */
            j = kmpTable[j];
        }
        else
        {
            /* we never did find a candidate substring (j == 0) */
            kmpTable[i] = 0;
            i++;
        }
    }
}

encoded_string_t FindMatch(unsigned int windowHead, unsigned int uncodedHead)
{
    encoded_string_t matchData;
    unsigned int m;             /* starting position in string being searched */
    unsigned int i;             /* offset from m and uncoded data */
    int kmpTable[MAX_CODED];    /* kmp partial match table */
    unsigned char localUncoded[MAX_CODED];  /* non-circular copy of uncoded */

    /* build non-circular copy of the uncoded lookahead buffer */
    for (i = 0; i < MAX_CODED; i++)
    {
        localUncoded[i] =
            uncodedLookahead[Wrap((uncodedHead + i), MAX_CODED)];
    }

    FillTable(localUncoded, kmpTable);      /* build kmp partial match table */

    matchData.length = 0;
    matchData.offset = 0;
    m = 0;
    i = 0;

    while (m < WINDOW_SIZE)
    {
        if (localUncoded[i] ==
            slidingWindow[Wrap((m + i + windowHead), WINDOW_SIZE)])
        {
            /* one more character matches */
            i++;

            if (MAX_CODED == i)
            {
                /* entire string is matched */
                matchData.length = MAX_CODED;
                matchData.offset = Wrap((m + windowHead), WINDOW_SIZE);
                break;
            }
        }
        else
        {
            if (i > matchData.length)
            {
                /* partial match is longest yet */
                matchData.length = i;
                matchData.offset = Wrap((m + windowHead), WINDOW_SIZE);
            }

            /* compute next position to search from */
            m = m + i - kmpTable[i];

            if (kmpTable[i] > 0)
            {
                i = kmpTable[i];
            }
            else
            {
                i = 0;
            }
        }
    }

    /* we only got a partial match.  return whatever we got. */
    return matchData;
}

void ReplaceChar(unsigned int charIndex, unsigned char replacement)
{
    slidingWindow[charIndex] = replacement;
}

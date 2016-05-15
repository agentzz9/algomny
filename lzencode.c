
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "lzlocal.h"
#include "bitfile.h"
/* cyclic buffer sliding window of already read characters */
extern unsigned char slidingWindow[];
extern unsigned char uncodedLookahead[];

long long preprocessforprogress(FILE *fp)
{


   long long numCharacters = 0;

    fseek(fp,0,SEEK_END);
    numCharacters = ftell(fp);
    return numCharacters;

}
int EncodeLZSSByFile(FILE *fpIn, FILE *fpOut,FILE *fpIn2)
{
    long long characters=0;
    float countt=1;

    characters=preprocessforprogress(fpIn2);
   // printf("characters %lld",characters);
    //fclose(fpIn2);
    //getchar();

    bit_file_t *bfpOut;

    encoded_string_t matchData;
    unsigned int i, c;
    unsigned int len;                       /* length of string */

    /* head of sliding window and lookahead */
    unsigned int windowHead, uncodedHead;

    /* use stdin if no input file */
    if (fpIn == NULL)
    {

        fpIn = stdin;
    }

    if (fpOut == NULL)
    {
        /* use stdout if no output file */
        bfpOut = MakeBitFile(stdout, BF_WRITE);
    }
    else
    {
        /* convert output file to bitfile */
        bfpOut = MakeBitFile(fpOut, BF_WRITE);
    }

    windowHead = 0;
    uncodedHead = 0;


    memset(slidingWindow, ' ', WINDOW_SIZE * sizeof(unsigned char));

    for (len = 0; len < MAX_CODED && (c = getc(fpIn)) != EOF; len++)
    {
        uncodedLookahead[len] = c;
    }

    if (len == 0)
    {
        return (EXIT_SUCCESS);   /* inFile was empty */
    }

    /* Look for matching string in sliding window */
    InitializeSearchStructures();
    matchData = FindMatch(windowHead, uncodedHead);

    /* now encoded the rest of the file until an EOF is read */
    while (len > 0)
    {

        if (matchData.length > len)
        {
            /* garbage beyond last data happened to extend match length */
            matchData.length = len;
        }

        if (matchData.length <= MAX_UNCODED)
        {
            /* not long enough match.  write uncoded flag and character */
            BitFilePutBit(UNCODED, bfpOut);
            BitFilePutChar(uncodedLookahead[uncodedHead], bfpOut);

            matchData.length = 1;   /* set to 1 for 1 byte uncoded */
        }
        else
        {
            unsigned int adjustedLen;

            /* adjust the length of the match so minimun encoded len is 0*/
            adjustedLen = matchData.length - (MAX_UNCODED + 1);

            /* match length > MAX_UNCODED.  Encode as offset and length. */
            BitFilePutBit(ENCODED, bfpOut);
            BitFilePutBitsInt(bfpOut, &matchData.offset, OFFSET_BITS,
                sizeof(unsigned int));
            BitFilePutBitsInt(bfpOut, &adjustedLen, LENGTH_BITS,
                sizeof(unsigned int));
        }

        i = 0;
        while ((i < matchData.length) && ((c = getc(fpIn)) != EOF))
        {
            /* add old byte into sliding window and new into lookahead */
            ReplaceChar(windowHead, uncodedLookahead[uncodedHead]);
            uncodedLookahead[uncodedHead] = c;
            windowHead = Wrap((windowHead + 1), WINDOW_SIZE);


            printf("%d\n",(int)(100*(countt++/characters)));

            uncodedHead = Wrap((uncodedHead + 1), MAX_CODED);
            i++;
        }

        /* handle case where we hit EOF before filling lookahead */
        while (i < matchData.length)
        {
            ReplaceChar(windowHead, uncodedLookahead[uncodedHead]);
            /* nothing to add to lookahead here */
            windowHead = Wrap((windowHead + 1), WINDOW_SIZE);



            printf("%d\n",(int)(100*(countt++/characters)));

            uncodedHead = Wrap((uncodedHead + 1), MAX_CODED);
            len--;
            i++;
        }

        /* find match for the remaining characters */
        matchData = FindMatch(windowHead, uncodedHead);
    }


    /* we've decoded everything, free bitfile structure */
    BitFileToFILE(bfpOut);

   return (EXIT_SUCCESS);
}


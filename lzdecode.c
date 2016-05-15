
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lzlocal.h"
#include "bitfile.h"
/* cyclic buffer sliding window of already read characters */
extern unsigned char slidingWindow[];
extern unsigned char uncodedLookahead[];


int DecodeLZSSByFile(FILE *fpIn, FILE *fpOut,FILE *fpIn2)
{
    long long characters=0;
    float countt=1;


    characters=preprocessforprogress(fpIn2)*8;
    //printf("characters %d",characters);
    fclose(fpIn2);
    //getchar();



    bit_file_t *bfpIn;

    int c;
    unsigned int i, nextChar;
    encoded_string_t code;              /* offset/length code for string */

    if (fpIn == NULL)
    {
        /* use stdin if no input file */
        bfpIn = MakeBitFile(stdin, BF_READ);
    }
    else
    {
        /* convert output file to bitfile */
        bfpIn = MakeBitFile(fpIn, BF_READ);
    }

    /* use stdout if no output file */
    if (fpOut == NULL)
    {
        fpOut = stdout;
    }

    memset(slidingWindow, ' ', WINDOW_SIZE * sizeof(unsigned char));

    nextChar = 0;

    while (TRUE)
    {
        if ((c = BitFileGetBit(bfpIn)) == EOF)
        {
            /* we hit the EOF */
            break;
        }
        printf("%d\n",(int)(100*(countt++)/characters));


        if (c == UNCODED)
        {

            /* uncoded character */
            if ((c = BitFileGetChar(bfpIn)) == EOF)
            {
                break;
            }
            countt=countt+8;
             printf("%d\n",(int)(100*(countt)/characters));



            /* write out byte and put it in sliding window */
            putc(c, fpOut);
            slidingWindow[nextChar] = c;
            nextChar = Wrap((nextChar + 1), WINDOW_SIZE);
        }
        else
        {



            /* offset and length */
            code.offset = 0;
            code.length = 0;

            if ((BitFileGetBitsInt(bfpIn, &code.offset, OFFSET_BITS,
                sizeof(unsigned int))) == EOF)
            {
                break;
            }

            if ((BitFileGetBitsInt(bfpIn, &code.length, LENGTH_BITS,
                sizeof(unsigned int))) == EOF)
            {
                break;
            }

            countt=countt+16;
            printf("%d\n",(int)(100*(countt)/characters));

            code.length += MAX_UNCODED + 1;

            for (i = 0; i < code.length; i++)
            {
                c = slidingWindow[Wrap((code.offset + i), WINDOW_SIZE)];
                putc(c, fpOut);
                uncodedLookahead[i] = c;

            }

            /* write out decoded string to sliding window */
            for (i = 0; i < code.length; i++)
            {
                slidingWindow[(nextChar + i) % WINDOW_SIZE] =
                    uncodedLookahead[i];
            }

            nextChar = Wrap((nextChar + code.length), WINDOW_SIZE);
        }
    }

    /* we've decoded everything, free bitfile structure */
    BitFileToFILE(bfpIn);
    int x=100;
    printf("%d",x);
    return (EXIT_SUCCESS);
}


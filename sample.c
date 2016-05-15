#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lzss.h"
#include "optlist.h"
typedef enum
{
    ENCODE,
    DECODE
} MODES;
char *RemovePath(char *fullPath);
int main(int argc, char *argv[])
{
    option_t *optList, *thisOpt;
    FILE *fpIn, *fpOut, *fpIn2;      /* pointer to open input & output files */
    MODES mode;

    /* initialize data */
    fpIn = NULL;
    fpIn2 = NULL;
    fpOut = NULL;
    mode = ENCODE;

    /* parse command line */
    optList = GetOptList(argc, argv, "cdi:o:h?");
    thisOpt = optList;

    while (thisOpt != NULL)
    {
        switch(thisOpt->option)
        {
            case 'c':       /* compression mode */
                mode = ENCODE;
                break;

            case 'd':       /* decompression mode */
                mode = DECODE;
                break;

            case 'i':       /* input file name */
                if (fpIn != NULL)
                {
                    fprintf(stderr, "Multiple input files not allowed.\n");
                    fclose(fpIn);

                    if (fpOut != NULL)
                    {
                        fclose(fpOut);
                    }

                    FreeOptList(optList);
                    exit(EXIT_FAILURE);
                }

                /* open input file as binary */
                fpIn = fopen(thisOpt->argument, "rb");
                fpIn2=fopen(thisOpt->argument,"rb");
                if (fpIn == NULL)
                {
                    perror("Opening input file");

                    if (fpOut != NULL)
                    {
                        fclose(fpOut);
                    }

                    FreeOptList(optList);
                    exit(EXIT_FAILURE);
                }
                break;

            case 'o':       /* output file name */
                if (fpOut != NULL)
                {
                    fprintf(stderr, "Multiple output files not allowed.\n");
                    fclose(fpOut);

                    if (fpIn != NULL)
                    {
                        fclose(fpIn);
                    }

                    FreeOptList(optList);
                    exit(EXIT_FAILURE);
                }

                /* open output file as binary */
                fpOut = fopen(thisOpt->argument, "wb");
                if (fpOut == NULL)
                {
                    perror("Opening output file");

                    if (fpIn != NULL)
                    {
                        fclose(fpIn);
                    }

                    FreeOptList(optList);
                    exit(EXIT_FAILURE);
                }
                break;

            case 'h':
            case '?':
                printf("Usage: %s <options>\n\n", RemovePath(argv[0]));
                printf("options:\n");
                printf("  -c : Encode input file to output file.\n");
                printf("  -d : Decode input file to output file.\n");
                printf("  -i <filename> : Name of input file.\n");
                printf("  -o <filename> : Name of output file.\n");
                printf("  -h | ?  : Print out command line options.\n\n");
                printf("Default: %s -c -i stdin -o stdout\n",
                    RemovePath(argv[0]));

                FreeOptList(optList);
                return(EXIT_SUCCESS);
        }

        optList = thisOpt->next;
        free(thisOpt);
        thisOpt = optList;
    }


    /* use stdin/out if no files are provided */
    if (fpIn == NULL)
    {
        fpIn = stdin;
    }


    if (fpOut == NULL)
    {
        fpOut = stdout;
    }

    /* we have valid parameters encode or decode */
    if (mode == ENCODE)
    {
        EncodeLZSSByFile(fpIn, fpOut, fpIn2);
    }
    else
    {
        DecodeLZSSByFile(fpIn, fpOut, fpIn2);
    }

    /* remember to close files */
    fclose(fpIn);
    fclose(fpOut);
    return EXIT_SUCCESS;
}

char *RemovePath(char *fullPath)
{
    int i;
    char *start, *tmp;                          /* start of file name */
    const char delim[3] = {'\\', '/', ':'};     /* path deliminators */

    start = fullPath;

    /* find the first character after all file path delimiters */
    for (i = 0; i < 3; i++)
    {
        tmp = strrchr(start, delim[i]);

        if (tmp != NULL)
        {
            start = tmp + 1;
        }
    }

    return start;
}

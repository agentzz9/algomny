#include<stdio.h>
#include<math.h>
#include <stdlib.h>


int main()
{
    long int i,j;
    long int *primes = (long int*)malloc(5761500*sizeof(long int));
    long int *numbers = (long int*)malloc(100000001*sizeof(long int));
    long int *count = (long int*)malloc(100000001*sizeof(long int));
    count[0]=count[1]=0;

/*fill the array with 0
for (i=0;i<100000001;i++)
{
numbers[i]=0;
} */

/*sieve the non-primes */
    for (i=2; i*i<100000001 ;i++)
    {
        if(numbers[i]!=1)
        for (j=i*i ; j<100000001;j+=i)
            numbers[j]=1;
    }

/*transfer the primes to their own array*/
    j = 0;
    for (i=2; i<100000001 ;i++)
        if (numbers[i]!=1)
        {
            primes[j++] = i;
            count[i]=count[i-1] + 1;
        }
        else
        count[i]=count[i-1];

// printf("%ld \n",count[100000000]);

/* Calculated all primes upto 100,000,000 and stores in primes array */

    while(1)
    {
        long int x;
        //int flag;
        float ans=0;

        scanf("%ld",&x);

        if(x<2)
            return 0;

        ans= fabs(count[x] - x/log(x))/count[x] * 100;

        printf("%0.1f \n",ans);
    }

    free(primes) ;
    free(numbers);
    return 0;
}

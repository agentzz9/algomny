#include <iostream>
#include <stdio.h>





#define MAX 20

void shellsort(int a[], int n )
{
             int d, temp , i;
             d = n/2;
             while( d >= 1)
             {
                          for( i = 0; i < n -  d ;i++)
                          {
                                       if ( a[i] > a[i+d])
                                       {
                                                    temp = a[i];
                                                    a[i] = a[i+d];
                                                    a[i+d] = temp;
                                       }
                          }
                                       if ( d == 1 )
                                       return ;
                                       d = d/ 2.0 + 0.5 ;
             }
}


int main()
{
                          int i, n, a[MAX] ;
                          printf("\n Enter size of array");
                          scanf("%d",&n);
                          if ( n > MAX )
                          {
                                       printf("\n Input size of array greater than declared size\n");
                                       return 0;
                          }

                          printf("\nEnter %d integer elements of aaray\n\n", n );
                          for( i = 0; i< n; i++)
                          {
                                       scanf("%d",&a[i]);
                          }

                          shellsort(a,n);

                          printf("\nSorted  elements of aaray\n\n" );
                          for( i = 0; i< n; i++)
                          {
                                       printf("%d\t",a[i]);
                          }
                            system("pause");
}












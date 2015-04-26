#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b)
{
     int temp;
     temp = *a;
     *a = *b;
     *b = temp;
}
void quick_mid(int *x,int start,int end)
{
     int i,position = start,pivot = rand()%(end - start) + start;
     
     swap(x + pivot,x + end - 1);
     for( i = start ; i < end ; i++) //conquer
     {
          if( *(x+i) <= *(x+end-1))
          {
              swap(x + i,x + position);
              position++;
          }
     }
     if(position == 6) return; // if we find median then return and x+5 is the median.
     
     if(position > 6) quick_mid(x,start,position-1);
     else quick_mid(x,position,end);
}
int main()
{
    int i,j,N,*v;
    
    srand(time(NULL));

    N = 11;
    v = (int *) malloc(N*sizeof(int));

    for(i = 0; i < N ; i++)
    {
          v[i] = rand() % 100;
          printf("%d ",v[i]);
    }
    printf("\n");
    
    quick_mid(v,0,N);
    
    printf("median = %d\n",*(v+5));
    
    for (i = 1 ; i < N ; i++) //using to check the median after sorting
    {
        for(j = 0 ; j < N - i ; j++)
        {
              if(v[j] > v[j+1])
              {
                      swap(v+j,v+j+1);
              }
        }
    }
    for (j = 0; j < N ; j++) printf("%d ",v[j]);
    printf("\n");
    
    system("pause");
    return 0;
}

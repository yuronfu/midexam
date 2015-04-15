#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,N,*v,temp;
    
    srand(time(NULL));

    N = 10;
    v = (int *) malloc(N*sizeof(int));

    for(i=0;i<10;i++)
    {
                     v[i] = rand() % 100;
                     printf("%d ",v[i]);
    }
    printf("\n");
    
    for (i = 1 ; i < N ; i++)
    {
        for(j = 0 ; j < N - i ; j++)
        {
              if(v[j] > v[j+1])
              {
                      temp = v[j];
                      v[j] = v[j+1];
                      v[j+1] = temp;
              }
        }
        for (j = 0; j < N ; j++) printf("%d ",v[j]);
        printf("\n");
    }
    /*for(i = 0 ; i< N-1; i++)
    {
          if(v[i] > v[i+1])
          {
                  temp = v[i];
                  v[i] = v[i+1];
                  v[i+1] = temp;
          }
    }
    */
    system("pause");
    return 0;
}

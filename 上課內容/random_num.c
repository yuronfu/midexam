#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,N,*v;
    
    srand(time(NULL));

    N = 10;
    v = (int *) malloc(N*sizeof(int));

    for(i=0;i<10;i++)
    {
                     v[i] = rand() % 100;
                     printf("%d,",v[i]);
    }
    printf("\b");
    
    system("pause");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j = 0,a[10];

    srand(time(NULL));

    for(i = 0 ; i < 10 ; i++)
    {
          a[i] = rand()%100;
          printf("%d ",a[i]);
    }
    printf("\n");

    int pivot,temp,position[10] = {},lowbound = 0;
    
    position[0] = 10;
    
    while(lowbound<10)
    {
            pivot = rand()%(position[j]-position[j+1]) + lowbound; //divide
            temp = a[pivot];
            a[pivot] = a[position[j]-1];
            a[position[j]-1] = temp;
            
            //printf("pivot = %d\n",a[position[j]-1]);             debug
            
            j++;
            for(i = lowbound ; i < position[j-1] ; i++)            //conquer
            {
                  if(a[i] <= a[position[j-1]-1])
                  {
                          temp = a[position[j]];
                          a[position[j]] = a[i];
                          a[i] = temp;
                          position[j]++;
                  }
            }
            position[j]--;
            
            //printf("j = %d , position = %d\n",j,position[j]);    debug
            //printf("lb = %d\n",lowbound);                        debug
            
            if(position[j] - lowbound < 2)                         //if solving left hand side, then moving lowbound to solve right hand side
            {
                           if(position[j-1] - position[j] <= 2) while( j != 0 && position[j-1] - position[j] <= 2) j--;
                           lowbound = position[j]+1;
                           j--;
                           /*             moving lowbound to the previous position of pivot
                           if(position[j-1] - position[j] <= 2)
                           {
                                            while( j != 0 && position[j-1] - position[j] <= 2) j--;
                                            lowbound = position[j]+1;
                                            position[j]+=2;
                                            j--;
                           }
                           else
                           {
                               lowbound = position[j] + 1;
                               position[j]+=2;
                               j--;
                           }
                           */
            }
            position[j+1] = lowbound;
            
            for(i = 0 ; i < 10 ; i++)
            {
                  printf("%d ",a[i]);
            }
            printf("\n");
    }
    /*      first layer
    pivot = rand()%position[0];
    temp = a[pivot];
    a[pivot] = a[position[0]];
    a[position[0]] = temp;
    printf("pivot = %d\n",a[position[0]]);

    for(i = 0 ; i < 9 ; i++)
    {
          if(a[i] < a[9])
          {
                  temp = a[position[1]];
                  a[position[1]] = a[i];
                  a[i] = temp;
                  position[1]++;
          }
    }
    
    temp = a[position[1]];
    a[position[1]] = a[position[0]];
    a[position[0]] = temp;
    */
    
    system("pause");
    return 0;
}

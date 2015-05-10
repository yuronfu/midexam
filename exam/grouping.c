#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void grouping(int N)
{
     int i,j,k,t,p = 2,M = N;
     for(i = 1 ; i < N ; i*=p)
     {
           t = 0;
           if(M%2 == 0) p = 2;
           else
           {
               if(M%3 == 0) p =3;
               else p = 5;
           }
           while(t < N)
           {
                   /*for(j = t ; j < i+t ; j++)
                   {
                         printf("(%d,%d)\n",j,j+i);
                   }
                   t= t + 2*i;*/
                   for(j = 0 ; j < i ; j++)
                   {
                         for(k = 0 ; k < p ; k++) printf("%d ",j+k*i+t);
                         printf("\n");
                   }
                   t = t + p*i;
           }
           M = M/p;
           system("pause");
     }
     return;
}
int main()
{
    double *x_r,*x_i,*y_r,*y_i,w_r,w_i;
    int k,n,p,q,r,N = 1;
    
    printf("p,q,r = ");
    scanf("%d %d %d",&p,&q,&r);
    N = pow(2,p)*pow(3,q)*pow(5,r);
    printf("N = %d\n",N);
    
    grouping(N);
    
    system("pause");
    return 0;
}

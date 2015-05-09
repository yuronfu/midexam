#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bit_reverse(double *x_r,double *x_i,double *y_r,double *y_i,int N)
{
     int i,j,M,t;
     
     for(i = 0 ; i < N ; i++)
     {
           t = i;
           M = N/3;
           j = 0;
           while(M >=1)
           {
                   if(t/M > 0)
                   {
                          j = j + (t/M)*N/(3*M);
                          t = t - (t/M)*M;
                   }
                   M = M/3;
           }
           //y[i] = x[j]
           //y_r[i] = x_r[j];
           //y_i[i] = x_i[j];
           printf("%d <->%d\n",i,j);
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
    
    x_r = (double *) malloc (N*sizeof(double));
    x_i = (double *) malloc (N*sizeof(double));
    
    y_r = (double *) malloc (N*sizeof(double));
    y_i = (double *) malloc (N*sizeof(double));
    
    for(k = 0 ; k < N ; k++)
    {
          *(x_r+k) = k;
          *(x_i+k) = 0;
          printf("x_%d = %f + %f i\n",k,*(x_r+k),*(x_i+k));
    }
    system("pause");
    
    bit_reverse(x_r,x_i,y_r,y_i,N);
    
    system("pause");
    return 0;
}

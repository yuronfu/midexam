#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bit_reverse(double *x_r,double *x_i,double *y_r,double *y_i,int N)
{
     int i,j,M,t,p;
     
     for(i = 0 ; i < N ; i++)
     {
           t = i;
           M = N;
           j = 0;
           while(M >= 1)
           {
                   if(t/M > 0)
                   {
                          j = j + (t/M)*N/(p*M);
                          t = t - (t/M)*M;
                   }
                   if(M%5 == 0) p = 5;
                   else
                   {
                        if(M%3 == 0) p = 3;
                        else p = 2;
                   }
                   M = M/p;
           }
           printf("%d <-> %d\n",i,j);
           //y_r[i] = x_r[j];
           //y_i[i] = x_i[j];
     }
     
     return;
}
void FFT(double *x_r,double *x_i,double *y_r,double *y_i,int N)
{
     
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
    
    /*for(k = 0 ; k < N ; k++)
    {
          *(x_r+k) = k;
          *(x_i+k) = 0;
          printf("x_%d = %f + %f i\n",k,*(x_r+k),*(x_i+k));
    }
    system("pause");
    */
    bit_reverse(x_r,x_i,y_r,y_i,N);
    
    system("pause");
    return 0;
}

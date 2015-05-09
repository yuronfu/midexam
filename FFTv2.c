#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bit_reverse(double *x_r,double *x_i,double *y_r,double *y_i,int N)
{
     int i,j,M,t;
     
     for(i = 0 ; i < N ; i++)
     {
           t = i;
           M = N/2;
           j = 0;
           while(M >= 1)
           {
                   if(t/M > 0)
                   {
                          j = j + (t/M)*N/(2*M);
                          t = t - M;
                   }
                   M = M/2;
           }
           //y[i] = x[j]
           y_r[i] = x_r[j];
           y_i[i] = x_i[j];
     }
     
     return;
}
/*void group(int N)
{
     int i,j,t;
     for(i = 1 ; i < N ; i*=2)
     {
           t = 0;
           while(t < N)
           {
                   for(j = t ; j < i+t ; j++)
                   {
                         //printf("(%d,%d)\n",j,j+i);
                   }
                   t= t + 2*i;
           }
     }
     return;
}*/
void FFT(double *x_r,double *x_i,double *y_r,double *y_i,int N)
{
     int i,j,t;
     double u_r,u_i,w_r,w_i,temp,temp_r,temp_i;
     
     bit_reverse(x_r,x_i,y_r,y_i,N);
     
     for(i = 1 ; i < N ; i*=2)
     {
           u_r = cos(-M_PI/i);
           u_i = sin(-M_PI/i);
           t = 0;
           while(t < N)
           {
                   w_r = 1;
                   w_i = 0;
                   for(j = 0 ; j < i ; j++)
                   {
                         //printf("(%d,%d)\n",j+t,j+i+t);
                         //y'[j+t] = y[j+t] + w*y[j+i+t] & y'[j+i+t] = y[j+t] - w*y[j+i+t]
                         //w = w*u
                         temp_r = y_r[j+t];
                         temp_i = y_i[j+t];
                         y_r[j+t] = temp_r + w_r*y_r[j+i+t] - w_i*y_i[j+i+t];
                         y_i[j+t] = temp_i + w_i*y_r[j+i+t] + w_r*y_i[j+i+t];
                         y_r[j+i+t] = temp_r - (w_r*y_r[j+i+t] - w_i*y_i[j+i+t]);
                         y_i[j+i+t] = temp_i - (w_i*y_r[j+i+t] + w_r*y_i[j+i+t]);
                         temp = w_r;
                         w_r = u_r*temp - u_i*w_i;
                         w_i = u_i*temp + u_r*w_i;
                   }
                   t= t + 2*i;
           }
     }
     
     return;
}
int main()
{
    double *x_r,*x_i,*y_r,*y_i,w_r,w_i;
    int k,n,p,N = 1;
    
    printf("p = ");
    scanf("%d",&p);
    N <<= p;
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
    
    FFT(x_r,x_i,y_r,y_i,N);
    for(k = 0 ; k < N ; k++) printf("y_%d : %f + %f i\n",k,y_r[k],y_i[k]);
    
    system("pause");
    return 0;
}


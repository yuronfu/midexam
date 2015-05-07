#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void FFT(double *x_r,double *x_i,double *y_r,double *y_i,int N)
{
     if(N == 1)
     {
          y_r[0] = x_r[0];
          y_i[0] = x_i[0];
          return;
     }
     int k;
     double *u_r,*u_i,*v_r,*v_i,w_r,w_i;
     
     u_r = (double *) malloc (N*sizeof(double));
     u_i = (double *) malloc (N*sizeof(double));
     
     v_r = (double *) malloc (N*sizeof(double));
     v_i = (double *) malloc (N*sizeof(double));
     
     for(k = 0 ; k < N/2 ; k++)
     {
             u_r[k] = x_r[2*k];
             u_i[k] = x_i[2*k];
             u_r[k+N/2] = x_r[2*k+1];
             u_i[k+N/2] = x_i[2*k+1];
     }
     
     
     FFT(u_r,u_i,v_r,v_i,N/2);
     FFT(u_r+N/2,u_i+N/2,v_r+N/2,v_i+N/2,N/2);
     
     for(k = 0 ; k < N/2 ; k++)
     {
           w_r = cos(-k*2*M_PI/N);
           w_i = sin(-k*2*M_PI/N);
           
           //y[k] = v[k] + w*v[k+N/2] & y[k+N/2] = v[k] - w*v[k+N/2]
           y_r[k] = v_r[k] + w_r*v_r[k+N/2] - w_i*v_i[k+N/2];
           y_i[k] = v_i[k] + w_r*v_i[k+N/2] + w_i*v_r[k+N/2];
           y_r[k+N/2] = v_r[k] - (w_r*v_r[k+N/2] - w_i*v_i[k+N/2]);
           y_i[k+N/2] = v_i[k] - (w_r*v_i[k+N/2] + w_i*v_r[k+N/2]);
     }
     
     free(u_r);
     free(u_i);
     free(v_r);
     free(v_i);
     
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
    system("pause");
    /*for(k = 0 ; k < N ; k++)  //FT process
    {
          y_r[k] = 0;
          y_i[k] = 0;
          for(n = 0 ; n < N ; n++)
          {
                w_r = cos(-k*n*2*M_PI/N);
                w_i = sin(-k*n*2*M_PI/N);
                y_r[k] = y_r[k] + x_r[n]*w_r - x_i[n]*w_i;
                y_i[k] = y_i[k] + x_r[n]*w_i + x_i[n]*w_r;
          }
          printf("y_%d : %f + %f i\n",k,y_r[k],y_i[k]);
    }
    */
    //FFT process
    FFT(x_r,x_i,y_r,y_i,N);
    for(k = 0 ; k < N ; k++) printf("y_%d : %f + %f i\n",k,y_r[k],y_i[k]);
    system("pause");
    return 0;
}

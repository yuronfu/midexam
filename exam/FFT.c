#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
           //printf("%d <-> %d\n",i,j);
           y_r[i] = x_r[j];
           y_i[i] = x_i[j];
     }
     
     return;
}
void FFT(double *x_r,double *x_i,double *y_r,double *y_i,int N)
{
     int i,j,k,t,p = 2,M = N;
     double theta,w_r,w_i,temp_r[4],temp_i[4];
     
     bit_reverse(x_r,x_i,y_r,y_i,N);
     
     for(i = 1 ; i < N ; i*=p)
     {
           t = 0;
           
           if(M%2 == 0) p = 2;
           else
           {
               if(M%3 == 0) p =3;
               else p = 5;
           }
           theta = -2*M_PI/(p*i);
           while(t < N)
           {
                   for(j = 0 ; j < i ; j++)
                   {
                         w_r = cos(j*theta);
                         w_i = sin(j*theta);
                         switch(p)
                         {
                                  case 2:
                                       temp_r[0] = w_r*y_r[j+i+t] - w_i*y_i[j+i+t];
                                       temp_i[0] = w_i*y_r[j+i+t] + w_r*y_i[j+i+t];
                                       y_r[j+i+t] = y_r[j+t] - temp_r[0];
                                       y_i[j+i+t] = y_i[j+t] - temp_i[0];
                                       y_r[j+t]+=temp_r[0];
                                       y_i[j+t]+=temp_i[0];
                                       break;
                                  case 3:
                                       temp_r[0] = w_r*y_r[j+i+t] - w_i*y_i[j+i+t];
                                       temp_i[0] = w_i*y_r[j+i+t] + w_r*y_i[j+i+t];
                                       temp_r[1] = (w_r*w_r - w_i*w_i)*y_r[j+2*i+t] - 2*w_r*w_i*y_i[j+2*i+t];
                                       temp_i[1] = 2*w_r*w_i*y_r[j+2*i+t] + (w_r*w_r - w_i*w_i)*y_i[j+i+t];
                                       y_r[j+2*i+t] = y_r[j+t] - 0.5*(temp_r[0] + temp_r[1]) - 0.8660254*(temp_i[0] - temp_i[1]);
                                       y_i[j+2*i+t] = y_i[j+t] - 0.5*(temp_i[0] + temp_i[1]) + 0.8660254*(temp_r[0] - temp_r[1]);
                                       y_r[j+i+t] = y_r[j+t] - 0.5*(temp_r[0] + temp_r[1]) + 0.8660254*(temp_i[0] - temp_i[1]);
                                       y_i[j+i+t] = y_i[j+t] - 0.5*(temp_i[0] + temp_i[1]) - 0.8660254*(temp_r[0] - temp_r[1]);
                                       y_r[j+t] = y_r[j+t] + temp_r[0] + temp_r[1];
                                       y_i[j+t] = y_i[j+t] + temp_i[0] + temp_i[1];
                                       break;
                                  case 5:
                                       temp_r[0] = w_r*y_r[j+i+t] - w_i*y_i[j+i+t];
                                       temp_i[0] = w_i*y_r[j+i+t] + w_r*y_i[j+i+t];
                                       for(k = 2 ; k < 5 ; k++)
                                       {
                                             temp_r[k-1] = cos(j*k*theta)*y_r[j+k*i+t] - sin(j*k*theta)*y_i[j+k*i+t];
                                             temp_i[k-1] = sin(j*k*theta)*y_r[j+k*i+t] + cos(j*k*theta)*y_i[j+k*i+t];
                                       }
                                       y_r[j+4*i+t] = y_r[j+t] + 0.30901699*(temp_r[0]+temp_r[3]) - 0.95105652*(temp_i[0]-temp_i[3]) - 0.80901699*(temp_r[1]+temp_r[2]) - 0.58778525*(temp_i[1]-temp_i[2]);
                                       y_i[j+4*i+t] = y_i[j+t] + 0.30901699*(temp_i[0]+temp_i[3]) + 0.95105652*(temp_r[0]-temp_r[3]) - 0.80901699*(temp_i[1]+temp_i[2]) + 0.58778525*(temp_r[1]-temp_r[2]);
                                       y_r[j+3*i+t] = y_r[j+t] - 0.80901699*(temp_r[0]+temp_r[3]) - 0.58778525*(temp_i[0]-temp_i[3]) + 0.30901699*(temp_r[1]+temp_r[2]) + 0.95105652*(temp_i[1]-temp_i[2]);
                                       y_i[j+3*i+t] = y_i[j+t] - 0.80901699*(temp_i[0]+temp_i[3]) + 0.58778525*(temp_r[0]-temp_r[3]) + 0.30901699*(temp_i[1]+temp_i[2]) - 0.95105652*(temp_r[1]-temp_r[2]);
                                       y_r[j+2*i+t] = y_r[j+t] - 0.80901699*(temp_r[0]+temp_r[3]) + 0.58778525*(temp_i[0]-temp_i[3]) + 0.30901699*(temp_r[1]+temp_r[2]) - 0.95105652*(temp_i[1]-temp_i[2]);
                                       y_i[j+2*i+t] = y_i[j+t] - 0.80901699*(temp_i[0]+temp_i[3]) - 0.58778525*(temp_r[0]-temp_r[3]) + 0.30901699*(temp_i[1]+temp_i[2]) + 0.95105652*(temp_r[1]-temp_r[2]);
                                       y_r[j+i+t] = y_r[j+t] + 0.30901699*(temp_r[0]+temp_r[3]) + 0.95105652*(temp_i[0]-temp_i[3]) - 0.80901699*(temp_r[1]+temp_r[2]) + 0.58778525*(temp_i[1]-temp_i[2]);
                                       y_i[j+i+t] = y_i[j+t] + 0.30901699*(temp_i[0]+temp_i[3]) - 0.95105652*(temp_r[0]-temp_r[3]) - 0.80901699*(temp_i[1]+temp_i[2]) - 0.58778525*(temp_r[1]-temp_r[2]);
                                       y_r[j+t] = y_r[j+t] + temp_r[0] + temp_r[1] + temp_r[2] + temp_r[3];
                                       y_i[j+t] = y_i[j+t] + temp_i[0] + temp_i[1] + temp_i[2] + temp_i[3];
                                       break;
                                       
                         }
                   }
                   t = t + p*i;
           }
           M = M/p;
     }
     
     
     return;
}
int main()
{
    double *x_r,*x_i,*y_r,*y_i;
    int k,n,p,q,r,N = 1;
    clock_t t1, t2;
    
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
          //printf("x_%d = %f + %f i\n",k,*(x_r+k),*(x_i+k));
    }
    system("pause");
    
    t1 = clock();
    FFT(x_r,x_i,y_r,y_i,N);
    t2 = clock();
    printf("Fast FT: %f secs\n", 1.0*(t2-t1)/CLOCKS_PER_SEC);
    //for(k = 0 ; k < N ; k++) printf("y_%d : %f + %f i\n",k,y_r[k],y_i[k]);
    
    free(x_r);
    free(x_i);
    free(y_r);
    free(y_i);
    system("pause");
    return 0;
}

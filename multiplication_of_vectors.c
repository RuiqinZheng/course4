#include <stdio.h>
#include <omp.h>
#define N 10
#define n 2
#define M 1
int main()
{
	double a[N][M];
	double b[M][N];
	double c[N][N];
	int i,j,k;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			a[i][j]=1;
			
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			b[i][j]=1;			
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			c[i][j]=0;			
		}
	}
	omp_set_num_threads(n);
#pragma omp parallel shared(a,b,c) private(i,j,k)  
{
#pragma omp for schedule(dynamic)  	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			for(k=0;k<M;k++){
			c[i][j]+=a[i][k]*b[k][j];
					}	
				}			
			}
}
    	for(i=0;i<N;i++){  
    	    for(j=0;j<N;j++){  
    	        printf("%lf ",c[i][j]);  
        }  
        printf("\n");  
    }  
} 



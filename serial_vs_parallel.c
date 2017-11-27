#include<math.h>
#include<stdio.h>
#include<omp.h>

int main()
{	
	double  start=clock( );
	double time_chuanxing;
	int m;
	int j;
	int s=0;
	FILE *fp;       
	fp=fopen("sushu_list.txt","w");
	if(fp!=NULL)

	
	for(m=2;m<=100000;m++)
		{
			for(j=2;j<=m;j++)
		                if(m%j==0) break;
		                if(j==m)        

		                        {
		                                s++;
		                                fprintf(fp,"%d\n",m);
		                                
		                        }                       
		}

	double end = clock( );  
	time_chuanxing=end-start;


	int i;
   	
	for(i=1;i<=8;i++)
	{
		double start = omp_get_wtime( ); 
		omp_set_num_threads(i);

		int m;
		int j;
		int s=0;
		FILE *fp;       
		fp=fopen("sushu_list.txt","w");
		if(fp!=NULL)

#pragma omp parallel for reduction(+:s)private(j)	
		for(m=2;m<=100000;m++)
		{
		        for(j=2;j<=m;j++)
		                if(m%j==0) break;
		                if(j==m)        

		                        {
		                                s++;
		                                fprintf(fp,"%d\n",m);
		                                
		                        }                       
		}

		printf("\n素数有:%d\n",s);
		printf("线程数为：%d\n",i);
		double end = omp_get_wtime( );  
   		printf("start = %.16g\nend = %.16g\ndiff = %.16g seconds\nspeedup = %.16g\n",start, end, end - start,(end-start)/time_chuanxing);  
		
	
	}
	

}

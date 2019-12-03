#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 3

int main(void){
	int i,j,n=0;
	float A[N][N],x[N],b[N],t[N],er;
	FILE *fp;

	if( (fp=fopen("20191112-1.dat","r"))==NULL ) {
		printf("cannot open file.\n");
		exit(0);
	}
	for(i=0;i<N;i++) {
		for(j=0;j<N;j++) fscanf(fp,"%f",&A[i][j]);
		fscanf(fp,"%f",&b[i]);
		x[i]=0.0;
	}
	fclose(fp);


	do {
		er=0.0;
		for(i=0;i<N;i++) {
			t[i]=b[i];
			for(j=0;j<N;j++) if(i!=j) t[i]-=A[i][j]*x[j];
			t[i]/=A[i][i];
			er+=fabs(t[i]-x[i]);

		}
		for(i=0;i<N;i++){
		x[i]=t[i];
		}
		n++;
	} while(er>1.0e-4);

	printf("n=%d\n",n);
	for(i=0;i<N;i++) printf(" %7.4f",x[i]);
	printf("\n");
}

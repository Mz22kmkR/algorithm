#include <stdio.h>
#include <stdlib.h>
#define N 3

int main(void){
	int i,j,k;
	float A[N][N+1],q;
	FILE *fp;
	if( (fp=fopen("20191105-3.dat","r"))==NULL ) {

		printf("cannot open file.\n");
	exit(0);
	}
	for(i=0;i<N;i++)
		for(j=0;j<N+1;j++)
		fscanf(fp,"%f",&A[i][j]);
	fclose(fp);
	for(i=0;i<N;i++) {
		for(j=0;j<N+1;j++) printf(" %6.2f",A[i][j]);
	printf("\n");
	}
	printf("\n");
	for(i=0;i<N;i++) {
		if(A[i][i]==0.0) break;
		q=A[i][i];
		for(j=i;j<N+1;j++) A[i][j]/=q;
			for(k=0;k<N;k++) {
		if(k!=i) {
			q=A[k][i];
			for(j=i;j<N+1;j++) A[k][j]-=q*A[i][j];

			}
		}
	}
	for(i=0;i<N;i++) {
		for(j=0;j<N+1;j++) printf("%6.2f",A[i][j]);
	printf("\n");
	}
}

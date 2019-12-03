#include <stdio.h>
#include <math.h>

#define N 5

int main(void){
	int i,j;
	float x[N],f[N][N],X,r,p,k;

	for(i=0;i<N;i++){
		x[i]=8.5+(0.5*i);
		f[0][i]=log(x[i]);
	}

	for(i=1;i<N;i++){
		for(j=0;j<N-i;j++){
			f[i][j]=f[i-1][j+1]-f[i-1][j];
		}
	}
	printf("input X:");
	scanf("%f",&X);
	r=(X-x[0])/(x[1]-x[0]);
	p=f[0][0];
	k=1.0;
	for(i=1;i<N;i++){
		k*=(r-i+1)/i;
		p+=k*f[i][0];
		printf("p%d=%f(%f)\n",i,p,log(X)-p);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define C 4
#define Ca C+1
#define Caa 2*C+1

void yacobi(float A[Ca][Ca],float X[Ca],
float B[Ca])
{
	int i,j;
	float tmp,err;
	do {
		err=0.0;
		for(i=0;i<Ca;i++) {
			tmp=B[i];
			for(j=0;j<Ca;j++)
				if(i!=j) tmp-=A[i][j]*X[j];
			tmp/=A[i][i];
			err+=fabs(tmp-X[i]);
			X[i]=tmp;
		}
	} while(err>1.0e-6);
}


int main(void)
{
	int i,j,N;
	float sx[Caa],sy[Caa],tx,ty,t;
	float A[Ca][Ca],X[Ca],B[Ca];
	float x[100],y[100];
	FILE *fp;

	if((fp=fopen("20191210-1.dat","r"))==NULL){
		printf("cannot open file\n");
		exit(0);
	}
	i=0;

	while( fscanf(fp,"%f %f",&x[i],&y[i])!=EOF )
		i++;
	N=i;



	for(i=0;i<Caa;i++) sx[i]=sy[i]=0.0;
	for(i=0;i<N;i++) {
		for(j=0;j<Caa;j++) {
			if(j==0) tx=1.0; else tx*=x[i];
			sx[j]+=tx;
		}
		for(j=0;j<Ca;j++) {
			if(j==0) ty=y[i]; else ty*=x[i];
			sy[j]+=ty;
		}
	}


	for(i=0;i<Ca;i++) {
		for(j=0;j<Ca;j++) A[i][j]=sx[i+j];
		X[i]=1.0;
		B[i]=sy[i];
	}


	yacobi(A,X,B);


	for(i=0;i<Ca;i++) {
		if(i==0) printf("y=%.1f",X[0]);
		else {
			if(X[i]>0.0) printf("+");
			printf("%.1f*x",X[i]);
		}
		if(i>1) printf("^%d",i);
	}
	printf("\n");
	for(i=0;i<N;i++) {
		t=X[2];
		for(j=1;j>=0;j--) t=t*x[i]+X[j];
		printf("%f %f(%f)\n",x[i],y[i],t);
	}
}

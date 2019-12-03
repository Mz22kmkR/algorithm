#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

int main(void){
	int n,i,j;
	float x[N],f[N],X,p,s;

	FILE *fp;

	if((fp=fopen("20191015-3.dat","r"))==NULL){
		printf("cannot open file\n");
		exit(0);
	}
	i=0;
	while(fscanf(fp,"%f %f",&x[i],&f[i])!=EOF){
		i++;
		if(i>N-1) break;
	}
	n=i;
	printf("input X:");
	scanf("%f",&X);
	s=0.0;
	for(i=0;i<n;i++){
		p=1.0;
		for(j=0;j<n;j++){
			if(j!=i){
				p*=(X-x[j])/(x[i]-x[j]);
			}
		}
		s+=p*f[i];
	}
	printf("f(%f)=%f\n",X,s);
}

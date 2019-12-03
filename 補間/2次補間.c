#include <stdio.h>
#include <math.h>

int main(void){
	int i,j;
	float x[3],f[3][3],X,h,r,F,p;
	float x123,gosa;

	for(i=0;i<3;i++){
		printf("input x%d,f%d: ",i,i);
		scanf("%f %f",&x[i],&f[0][i]);
		for(j=1;j<3;j++) f[j][i]=0.0;
	}
	for(j=1;j<3;j++)
		for(i=0;i<3-j;i++) f[j][i]=f[j-1][i+1]-f[j-1][i];
	printf("input X: ");
	scanf("%f",&X);

	x123=cos(X);

	h=x[1]-x[0];
	r=(X-x[0])/h;
	F=f[0][0]+r*f[1][0]+r*(r-1)*f[2][0]/2.0;
	printf("補間値 f(%f)=%f\n",X,F);

	gosa=x123-F;
	printf("誤差:%f\n",gosa);
}

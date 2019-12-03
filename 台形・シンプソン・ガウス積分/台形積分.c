#include <stdio.h>
#include <math.h>

float f(float x){
	return(4/(1+x*x));
}

int main(void){
	int i,n;
	float a=0.0,b=1.0,h,S,x;

	printf("input n:");
	scanf("%d", &n);
	h=(b-a)/n;

	S=(f(a)+f(b))/2.0;
	for(i=1;i<n;i++){
		x=a+h*i;
		S+=f(x);
	}
	S*=h;
	printf("divide:%2d, S=%f gosa=%f\n",n,S,(M_PI-S));
}

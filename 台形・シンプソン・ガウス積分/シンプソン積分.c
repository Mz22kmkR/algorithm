#include <stdio.h>
#include <math.h>

float f(float x){
	return(4/(1+x*x));
	}

int main(void){
	int i,n;
	float a=0.0,b=1.0,h,s1=0.0,s2=0.0,S,x;

	printf("input n:");
	scanf("%d",&n);
	h=(b-a)/(2.0*n);

	S=f(a)+f(b);
	for(i=1;i<2*n;i++){
		x=a+h*i;
		if(i%2==1){
			s1+=f(x);
			}else{
			s2+=f(x);
		}
	}
	S=(S+4.0*s1+2.0*s2)*h/3.0;
	printf("divide:%2d, S=%f\n",n,S);
}

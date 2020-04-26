#include <stdio.h>
#include <math.h>

#define N 40

float f1(float x,float y){
	return(-0.5*x/y);
}

int main(void){
	int i;
	float x[N+1],y[N+1],h=0.2,r,A,B,C,D;
	x[0]=0.0;
	y[0]=2.0;
	i=0;
	printf(" x , y ( error )\n");
	do {
		x[i+1]=x[i]+h;
		if(i<4) {
		A=h*f1(x[i],y[i]);
		B=h*f1(x[i]+h/2.0,y[i]+A/2.0);
		C=h*f1(x[i]+h/2.0,y[i]+B/2.0);
		D=h*f1(x[i]+h,y[i]+C);
		y[i+1]=y[i]+(A+2.0*B+2.0*C+D)/6.0;
	} else {
		y[i+1]=y[i]+(55.0*f1(x[i],y[i])
		-59.0*f1(x[i-1],y[i-1])
		+37.0*f1(x[i-2],y[i-2])
		-9.0*f1(x[i-3],y[i-3]))*h/24.0;
		y[i+1]=y[i]+(9.0*f1(x[i+1],y[i+1])
		+19.0*f1(x[i],y[i])
		-5.0*f1(x[i-1],y[i-1])
		+f1(x[i-2],y[i-2]))*h/24.0;
	}
	i++;
	r=sqrt(4.0-x[i]*x[i]/2.0);
	printf("%8.5f,%8.5f (%8.5f)\n",x[i],y[i],r-y[i]);
	} while(x[i]<2.0&&i<N);
}

#include <stdio.h>
#include <math.h>

#define N 40

float f(float x,float y,float y1){
	return(-y);
}

int main(void){
	int i,n;
	float k,h,x[N+1],y[N+1],y1[N+1],A,B,C,D,r;
	h=0.2;
	k=h/2.0;
	x[0]=0.0;
	y[0]=2.0;
	y1[0]=-2.0;
	i=0;
	printf(" x , y ( error )\n");
	do {
		A=k*f(x[i],y[i],y1[i]);
		B=k*f(x[i]+k,y[i]+k*(y1[i]+A/2.0),y1[i]+A);
		C=k*f(x[i]+k,y[i]+k*(y1[i]+B/2.0),y1[i]+B);
		D=k*f(x[i]+h,y[i]+h*(y1[i]+C),y1[i]+C*2.0);
		x[i+1]=x[i]+h;
		y1[i+1]=y1[i]+(A+2.0*B+2.0*C+D)/3.0;
		y[i+1]=y[i]+h*(y1[i]+(A+B+C)/3.0);
		i++;
		r=-2.0*sqrt(2.0)*sin(x[i]-M_PI/4.0);
		printf("%8.5f,%8.5f (%8.5f)\n",
		x[i],y[i],r-y[i]);

	} while(x[i]<4.0&&i<N);
}

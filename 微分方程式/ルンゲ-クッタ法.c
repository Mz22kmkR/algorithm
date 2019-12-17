#include <stdio.h>
#include <math.h>

float f1(float x,float y) {
       return(-0.5*x/y);
}

int main(void) {
   int i;
   float x[100],y[100],h=0.2,r,A,B,C,D;
   x[0]=0.0;
   y[0]=2.0;
   i=0;
   printf("    x   ,     y     (error)\n");
   do {
     x[i+1]=x[i]+h;
     A=h*f1(x[i],y[i]);
     B=h*f1(x[i]+h/2.0,y[i]+A/2.0);
     C=h*f1(x[i]+h/2.0,y[i]+B/2.0);
     D=h*f1(x[i]+h,y[i]+C);
     y[i+1]=y[i]+(A+2.0*B+2.0*C+D)/6.0;
     i++;
     r=sqrt(4-x[i]*x[i]/2);
     printf("%f, %f (%f)\n",x[i],y[i],r-y[i]);
   } while(x[i]<2.0);
} 

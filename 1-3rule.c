#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
return (3*x*x+2*x-5);
}
void main()
{
float a, b, h, x,ans,sum=0;
int n,i;
printf("Enter initial and final value of x:\n");
scanf("%f%f", &a, &b);
printf("Number of segments:");
scanf("%d", &n);
h=(b-a)/n;
for(i=1;i<n;i++)
{
x=a+i*h;
if(i%2==0)
{
sum=sum+2*f(x);
}
else{
sum=sum+4*f(x);
}
}
ans=(h/3)*(f(a)+f(b)+sum);
printf("Integral value of f(x)=%f ", ans);
getch();
}
#include<stdio.h>
#include<math.h>
double evaluationDerivative(double*,int,double);

double evaluatePolynomial(double*coefficients,int degree,double x)
{
    double result=coefficients[0];
    for(int i=1;i<=degree;i++)
    {
        result=result*x+coefficients[i];
    }
    return result;
}
double evaluationDerivative(double*coefficients,int degree,double x)
{
    double result=coefficients[1];
    for(int i=2;i<=degree;i++)
    {
        result=result*x+coefficients[i]*(i-1);
    }
    return result;
}
double newtonmethod(double *coefficients,int degree,double x0,double epsilon,int maxiterations)
{
double x=x0;
int iteration=0;
while(fabs(evaluatePolynomial(coefficients,degree,x))>=epsilon&&iteration<maxiterations)
{
    x=x-(evaluatePolynomial(coefficients,degree,x) / evaluateDerivative(coefficients,degree,x));
    iteration ++;
}
return x;
}
int main()
{
    double coefficients[]={-1,3,-5,2};
    int degree=sizeof(coefficients)/(coefficients[0])-1;
    double x0,epsilon,root;
    int maxiterations;
    printf("Newtons method\n");
    printf("enter the initial guess:");
    scanf("%f",&x0);
    printf("Enter the desired accuracy:");
    scanf("%lf",epsilon);
    printf("enter the maximum number of iterations:");
    scanf("%d",&maxiterations);
    root=newtonmethod(coefficients,degree,x0,epsilon,maxiterations);
    printf("approximate root:%lf\n",root);
    return 0;
}
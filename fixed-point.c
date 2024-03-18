#include<stdio.h>
#include<math.h>
#define EPSILON 0.001

float f(float x)
{
    return x*x*x-x-4;
}
float findvalueat(float x)
{
    return 1/sqrt(1+x);
}
float differentiate(float x)
{
    return -1/2.0*(pow((1+x),-3/2));
}
int main()

{
    int maxiteration,i;
    float a,b,x,x0;
    printf("enter maxaium no of iterations\n");
    scanf("%d",&maxiteration);

    do
    {
        printf("enter the value of a and b(starting boundary)");
        scanf("%f %f",&a,&b);
        if(f(a)*f(b)>0)
        {
            printf("boundary values are invalid\n");
            continue;
        }
        else{
            printf("roots lie between %f and %f\n",a,b);
            break;
        }

        
    } while (1);
    {
        x0=(a+b)/2;
        if(fabs(differentiate(x0))<1)
        printf("function form is correct.\n");
        else
        {
            printf("function form is is correct.\n");
            return 0;
        }

        for(i=1;i<=maxiteration;i++)
        {
            x=findvalueat(x0);
            if(fabs(x-x0)<EPSILON)
            {
                printf("iterations=%d final root=%f\n",i,x);
                return 0;
            }
            printf("iterations=%d roots=%f\n",i,x);
            x0=x;
        }
        printf("root=%f total iterations=%d",x,--i);
        return 0;
    }
    
}

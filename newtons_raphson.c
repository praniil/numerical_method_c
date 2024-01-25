#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (x) * log10(x) - 1.2
#define df(x) log10(x) + 1.0 / log(10.0)

int main()
{
    float x0, x1, f0, f1, df0, df1, e;
    int i = 1, N;
    printf("\nEnter the initial guess: ");
    scanf("%f", &x0);
    printf("\nEnter the value of predefined error: ");
    scanf("%f", &e);
    printf("\nEnter the maximum number of iterations: ");
    scanf("%d", &N);
    printf("\n__\n");
    printf("\nIteration\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    printf("\n__\n\n");
    do
    {
        f0 = f(x0);
        df0 = df(x0);
        if (df0 == 0.0)
        {
            printf("Mathematical error\n");
            exit(0);
        }
        x1 = x0 - f0 / df0;
        f1 = f(x1);
        printf("%d\t\t%15.8f\t%15.8f\t%15.8f\t%15.8f\n", i, x0, f0, x1, f1);
        x0 = x1;
        i += 1;
        if (i > N)
        {
            printf("The solution does not converge.");
            exit(0);
        }
    } while (fabs(f1) > e);
    printf("__\n");
    printf("The approximate solution is %0.8f", x1);
    return 0;
}
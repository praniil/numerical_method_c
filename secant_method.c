#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define exp 2.718281

// #define f(x) x *x *x - 2 * x - 5
// #define f(x) 3 * x + sin(x) - pow(exp, x)
// #define f(x) x *pow(exp, x) - cos(x)
#define f(x) tan(x) + tanh(x)
// #define f(x) pow(exp, cos(x)) - sin(x)

void main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int i = 1, N;
    printf("\nEnter the initial guesses: ");
    scanf("%f%f", &x0, &x1);
    printf("\nEnter the value of predefined error: ");
    scanf("%f", &e);
    printf("\nEnter the maximum number of iterations: ");
    scanf("%d", &N);
    printf("\n__\n");
    printf("\nIteration\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    printf("\n__\n\n");

    do
    {
        f0 = f(x0);
        f1 = f(x1);
        if (f0 == f1)
        {
            printf("Mathematical error\n");
            exit(0);
        }
        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n", i, x0, x1, x2, f2);

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;

        i = i + 1;

        if (i > N)
        {
            printf("Not Convergent.");
            exit(0);
        }
    } while (fabs(f2) > e);
    printf("The required root is %0.9f", x2);
}
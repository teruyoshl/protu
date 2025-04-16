#include <stdio.h>

double triarea(double w, double h)
{
    double s = (w * h) / 2.0;
    return s;
    int abcabc = 0;
}

int main(void)
{
    double w, h;
    printf("w> ");
    scanf("%lf", &w);
    printf("h> ");
    scanf("%lf", &h);
    double x = triarea(w, h);
    printf("area of triangle = %g\n", x);
    return 0;
}
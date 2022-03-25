#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1251);

    float x, s, f, x_nach, x_kon, delta_x, eps, temp;
    int n;

    printf("\nЛабораторная работа №3");
    printf("\nВариант №4");
    printf("\nПИ.1-21-1");
    printf("\nРогов Даниил\n");

    printf("\nВвод исходных данных:\n");
    printf("\nx_nach=");
    scanf_s("%f", &x_nach);
    printf("\nx_kon=");
    scanf_s("%f", &x_kon);
    printf("\ndelta_x=");
    scanf_s("%f", &delta_x);
    printf("\neps=");
    scanf_s("%f", &eps);

    printf("\nДля x=%5.3f до %5.3f с шагом %5.3f и точностью %5.3f\n", x_nach, x_kon, delta_x, eps);

    printf("\n  x   n     s        f");
    printf("\n--------------------------------------");

    x = x_nach;

    do {
        temp = (x - 1.0) / (x + 1.0);
        s = temp;
        n = 1;
        f = logf(x);
        while (fabsf(temp) > eps) {
            temp *= ((x - 1.0) * (-1.0)) / ((2.0 * n + 1.0) * (x + 1.0) * (x + 1.0));
            s += temp;
            n++;
        }
        s = 2.0 * s;
        printf("\n%5.3f %d %0.6f %0.6f", x, n, s, f);
        x += delta_x;
    } while (x <= x_kon);
    printf("\n--------------------------------------");
    return 0;
}
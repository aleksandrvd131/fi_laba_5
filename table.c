#include "table.h"
#include "taylor.h"
#include <stdio.h>
#include <math.h>

void print_table(double a, double b, int n, double eps, double k) {
    printf("\nТаблица значений ряда Тейлора и стандартной функции для f(x) = sh x\n");
    printf("+----------+----------------------------+--------------------------+------------------+\n");
    printf("|    x     | част. сумма ряда для sh x  |  значения функции sh x   |  число итераций  |\n");
    printf("+----------+----------------------------+--------------------------+------------------+\n");

    double step = (b - a) / (double)n;
    double max_diff = 0.0;

    for (int i = 0; i <= n; i++) {
        double x = a + i * step;

        // Коррекция последней точки из-за погрешностей округления при сложении
        if (i == n) {
            x = b;
        }

        int iterations = 0;
        double sum_taylor = taylor_sh(x, eps, k, &iterations);
        double val_builtin = sinh(x);

        double diff = fabs(sum_taylor - val_builtin);
        if (diff > max_diff) {
            max_diff = diff;
        }

        printf("| %8.4f | %26.12f | %24.12f | %16d |\n",
               x, sum_taylor, val_builtin, iterations);
    }

    printf("+----------+----------------------------+--------------------------+------------------+\n");
    printf("Максимальная абсолютная погрешность: %.2e\n\n", max_diff);
}

#ifndef TAYLOR_H
#define TAYLOR_H
#define MAX_ITER 100

double get_machine_eps(void);

double taylor_sh(double x, double eps, double k, int *iterations);

#endif // TAYLOR_H

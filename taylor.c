#include "taylor.h"
#include <math.h>

double get_machine_eps(void) {
  volatile double eps = 1.0;
  while ((1.0 + eps / 2.0) > 1.0) {
    eps /= 2.0;
  }
  return eps;
}

double taylor_sh(double x, double eps, double k, int *iterations) {
  double target_eps = eps * k;

  // В точке x = 0 значение sh(0) равно 0 сразу
  if (fabs(x) <= target_eps) {
    *iterations = 1;
    return 0.0;
  }

  double sum = 0.0;
  double term = x; // Первый член u_1 = x
  int n = 1;

  while (fabs(term) > target_eps && n <= MAX_ITER) {
    sum += term;
    // Рекуррентный пересчет следующего члена за O(1):
    term = term * (x * x) / ((2.0 * n) * (2.0 * n + 1.0));
    n++;
  }

  // Число слагаемых, которые реально вошли в сумму
  *iterations = n - 1;
  return sum;
}

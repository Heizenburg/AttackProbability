#include <stdio.h>
#include <math.h>

double attackSuccessProbability(double q, int z) {
  double p = 1.0 - q;
  double lambda = z * (q / p);
  double sum = 1.0;
  int i, k;

  for (k = 0; k <= z; k++) 
  {
    double poisson = exp(-lambda);
    for(i = 1; i <= k; i++) 
    {
      poisson *= lambda / i;
    }
    sum -= poisson * (i - pow(q / p, z - k));
  }
  return sum;
}

int main(void) {
  for (int i = 0; i <= 10; i++) 
  {
    double n = attackSuccessProbability(0.1, i);
    printf("p = %0.15lf\n", n);
  }
  return 0;
}
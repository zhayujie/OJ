#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

double fetchCore(int n, int m, int people, int ball, double p) {
  if (n < 0 || m < 0) {
    return 0;
  }
  if (people == 0 && ball == 0) {
    return p;
  }
  if (people == 1 && ball == 0) {
    return 0;
  }
  if ((people == 2 && ball == 0) && n == 0) {
    return 0;
  }

  if (people == 0 && ball == 1) {
    return fetchCore(n-1, m, 1, 0, p*n*1.0/(m+n)) + fetchCore(n, m-1, 1, 1, p*m*1.0/(m+n));
  }
  if (people == 1 && ball == 1) {
    return fetchCore(n-1, m, 2, 0, p*n*1.0/(m+n)) + fetchCore(n, m-1, 2, 1, p*m*1.0/(m+n));
  }
  if (people == 2) {
    return fetchCore(n-1, m, 0, 0, p*n*1.0/(m+n)) + fetchCore(n, m-1, 0, 1, p*m*1.0/(m+n));
  }
  return 0;
}

double fetch(int n, int m) {
  double p = n*1.0/(n+m);
  return fetchCore(n-1, m, 0, 0, p) + fetchCore(n, m-1, 0, 1, 1-p);
}

int main(void) {
  int n, m;
  cin >> n >> m;
  if (n == 0) {
    printf("%.5lf\n", 0.5);
    return 0;
  } else if (m == 0) {
    printf("%.5lf\n", 1.0);
    return 0;
  }
  double p = fetch(n, m);
  printf("%.5lf\n", p);

  return 0;
}
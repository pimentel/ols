#ifndef OLS_HPP
#define OLS_HPP

#include <cassert>

#include <vector>

double safe_sum(const std::vector<double>& x) {
  double s = 0.0; // the sum
  double e = 0.0; // the compensated error
  double tmp;
  double y;

  for (size_t i = 0; i < x.size(); i++) {
    tmp = s;
    y = x[i] + e;
    s = tmp + y;
    e = (tmp - s) + y;
  }

  return s;
}

std::pair<double, double> ols(const std::vector<double>& x,
  const std::vector<double>& y) {
  assert(x.size() == y.size());

  std::vector<double> tmp;
  tmp.resize(x.size());

  for (size_t i = 0; i < x.size(); i++) {
    tmp[i] = x[i] * y[i];
  }

  double n = static_cast<double>(x.size());
  double sxy = safe_sum(tmp);
  double sy = safe_sum(y);
  double sx = safe_sum(x);
  double x_bar = sx / n;
  double y_bar = sy / n;

  double numerator = (sxy + n * x_bar * y_bar) - (x_bar * sy + y_bar * sx);

  for (size_t i = 0; i < x.size(); i++) {
    tmp[i] = x[i] * x[i];
  }

  double sxx = safe_sum(tmp);
  double denominator = (sxx - 2 * x_bar * sx) + n * x_bar * x_bar;

  double beta_1 = numerator / denominator;
  double beta_0 = y_bar - beta_1 * x_bar;

  return std::make_pair(beta_0, beta_1);
}

#endif

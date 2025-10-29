#include "../include/imeth/linear/algebra.hpp"
#include <cmath>
#include <algorithm>

namespace imeth {

std::optional<double> LinearAlgebra::solve_1v(double a, double b) {
  if (a == 0.0) return std::nullopt;
  return -b / a;
}

std::optional<std::pair<double, double>> LinearAlgebra::solve_2v(
  double a1, double b1, double c1,
  double a2, double b2, double c2
) {
  double new_b1, new_b2, new_c1, new_c2;

  if (a1 == a2) {
    new_b1 = b1;
    new_b2 = b2;
    new_c1 = c1;
    new_c2 = c2;
  } else {
    new_b1 = b1 * a2;
    new_b2 = b2 * a1;
    new_c1 = c1 * a2;
    new_c2 = c2 * a1;
  }

  double b3, c3;
  if (a1 < 0.0 || a2 < 0.0) {
    b3 = new_b1 + new_b2;
    c3 = new_c1 + new_c2;
  } else {
    b3 = new_b1 - new_b2;
    c3 = new_c1 - new_c2;
  }

  if (b3 == 0.0 || a2 == 0.0) return std::nullopt;

  double y = c3 / b3;
  double x = (c2 - (b2 * y)) / a2;

  return std::make_pair(x, y);
}

QuadraticEquation::Solution QuadraticEquation::solve(double a, double b, double c) {
  if (std::abs(a) < 1e-10) {
    if (std::abs(b) < 1e-10) {
      return std::monostate{};
    }
    return -c / b;
  } // Messy handling degenerate case where a = 0

  // Calculate discriminant: b² - 4ac
  double discriminant = b * b - 4 * a * c;

  // No real solutions
  if (discriminant < -1e-10) {
    return std::monostate{};
  }

  // One solution (repeated root)
  if (std::abs(discriminant) < 1e-10) {
    return -b / (2 * a);
  }

  // Two distinct solutions
  double sqrt_discriminant = std::sqrt(discriminant);
  double x1 = (-b - sqrt_discriminant) / (2 * a);
  double x2 = (-b + sqrt_discriminant) / (2 * a);

  if (x1 > x2) {
    std::swap(x1, x2);
  }

  return std::make_pair(x1, x2);
}

} // namespace imeth

// Pull in the IO stream-handling headers.
#include <iostream>

/* Non-visible to public.
 *
 * Computes the GCD of a and b.
 *
 * @param a: One of the two numbers to be considered.
 * @param b: The other of the two numbers.
 * @return The greatest common divisor of a and b.
 */
const long gcd(const long a, const long b) {
  if (b == 0) {
    return a;
  } else if (b > a) {
    return gcd(b,a);
  }

  const long reduced = a % b;
  return gcd(b, reduced);
}

/* Non-visible to public.
 *
 * Computes the LCM of a and b.
 *
 * @param a: One of the two numbers to be considered.
 * @param b: The other of the two numbers.
 * @return The least common multiple of a and b.
 */
const long lcm(const long a, const long b) {
  return (a*b) / gcd(a,b);
}

/* Finds the smallest positive integer that is divisible by all of the integers from 1 to n.
 *
 * @param n: The largest divisor to be considered.
 * @return The smallest number that is a multiple of all of the divisors.
 */
static const long findSmallestMultiple(const long n) {
  if (n <= 0) {
    throw std::invalid_argument("<n> must be a positive integer!");
  }

  long multiple = 1;
  for (int k = 1; k < n; k++) {
    multiple = lcm(k, multiple);
  }

  return multiple;
}

/* The primary execution block of the program.
 *
 * @param argc: The number of command-line arguments provided to the function.
 * @param argv: The list of command-line arguments, passed as strings.
 * @return A status code signifying whether or not the block ran successfully.
 */
int main(int argc, char *argv[]) {

  auto palindrome = findSmallestMultiple(20);

  std::cout << "Problem 4: " << palindrome << "\n";
  return 0;
}

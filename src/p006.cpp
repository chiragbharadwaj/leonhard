// Pull in the IO stream-handling headers.
#include <iostream>

/* Finds the difference between the square of the sum of the first n positive integers and the sum
 *   of the squares of the first n natural numbers. In other words, computes S - T, where S and T
 *   are defined as the following sums:
 *     S = (sum[k=0, n, k])^2  and  T = sum[k=0, n, k^2].
 *
 * @param n: The upper bound of each sum.
 * @return The difference between the specified sums.
 */
static const long findSumSquareDifference(const long n) {
  if (n <= 0) {
    throw std::invalid_argument("<n> must be a positive integer!");
  }

  return n * (n-1) * (n+1) * (3*n+2) / 12; // cute constant-time solution
}

/* The primary execution block of the program.
 *
 * @param argc: The number of command-line arguments provided to the function.
 * @param argv: The list of command-line arguments, passed as strings.
 * @return A status code signifying whether or not the block ran successfully.
 */
int main(int argc, char *argv[]) {

  auto palindrome = findSumSquareDifference(100);

  std::cout << "Problem 6: " << palindrome << "\n";
  return 0;
}

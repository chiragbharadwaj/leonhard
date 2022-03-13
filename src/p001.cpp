// Pull in the IO stream-handling headers.
#include <iostream>

/* Finds all of the multiples of 3 and 5 that are below the specified limit.
 *
 * @param limit: The maximum number up to which to consider when summing.
 * @return The sum of the discovered multiples.
 */
static const int findSumOfMultiples(const int limit) {
  int sum = 0;

  for (int n = 1; n < limit; n++) {
    if (n % 3 == 0 || n % 5 == 0) {
      sum = sum + n;
    }
  }

  return sum;
}

/* The primary execution block of the program.
 *
 * @param argc: The number of command-line arguments provided to the function.
 * @param argv: The list of command-line arguments, passed as strings.
 * @return A status code signifying whether or not the block ran successfully.
 */
int main(int argc, char *argv[]) {

  const int sum = findSumOfMultiples(1000);

  std::cout << "Problem 1: " << sum << "\n";
  return 0;
}

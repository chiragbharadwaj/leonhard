// Pull in some standard data structures and collection-handling headers.
#include <list>
#include <vector>

// Pull in the IO stream-handling headers.
#include <iostream>

// Pull in the defined utility classes/functions needed to simplify the problem.
#include "Wheel12357.h"

// Avoid having to preface utility class names.
using namespace utils;

/* Finds the nth smallest by using a simple sieve.
 *
 * @param n: The index of the prime in the prime sieve.
 * @return The prime number at that index.
 */
static const long getOrderedPrime(const long n) {
  return 0;
}

/* The primary execution block of the program.
 *
 * @param argc: The number of command-line arguments provided to the function.
 * @param argv: The list of command-line arguments, passed as strings.
 * @return A status code signifying whether or not the block ran successfully.
 */
int main(int argc, char *argv[]) {

  auto prime = getOrderedPrime(10001);

  std::cout << "Problem 7: " << prime << "\n";
  return 0;
}

// Pull in some standard data structures and collection-handling headers.
#include <list>
#include <vector>

// Pull in the IO stream-handling headers.
#include <iostream>

// Pull in the defined utility classes/functions needed to simplify the problem.
#include "Wheel12357.h"

// Avoid having to preface utility class names.
using namespace utils;

/* Non-visible to public.
 *
 * Computes the prime factors of n by testing a candidate pot via a skip-based 4-spoke wheel factorization method.
 *
 * @param wheel: A 1-2-3-5-7 wheel needed for the 4-spoke wheel factorization.
 * @param lst: A list containing the prime factors determined so far.
 * @param pot: A potential candidate for a prime factor of n.
 * @param n: The integer for which the prime factors must be determined.
 * @return A list containing all of the prime factors of n.
 */
const std::list<long> factorize(Wheel12357 &wheel, std::list<long> &lst, const long pot, const long n) {
  if (pot * pot > n) {
    lst.push_back(n);
    lst.reverse();
    return lst;
  } else {
    long div = n / pot;
    if (div*pot == n) {
      lst.push_back(pot);
      return factorize(wheel, lst, pot, div);
    } else {
      const int head = wheel.rotate();
      return factorize(wheel, lst, (pot+head), n);
    }
  }
}

/* Finds all of the prime factors of n. 1 is not a prime number.
 *
 * @param n: The integer for which the prime factors must be determined.
 * @return A list containing all of the prime factors of the number.
 */
static const std::list<long> getPrimeFactors(const long n) {
  auto wheel = Wheel12357();
  std::list<long> lst = { };

  return factorize(wheel, lst, 2, n);
}

/* The primary execution block of the program.
 *
 * @param argc: The number of command-line arguments provided to the function.
 * @param argv: The list of command-line arguments, passed as strings.
 * @return A status code signifying whether or not the block ran successfully.
 */
int main(int argc, char *argv[]) {

  // Get all of the prime factors
  auto factors = getPrimeFactors(600'851'475'143L);

  // Find the largest prime factor
  long maxFactor = 0;
  for (auto &factor : factors) {
    if (factor > maxFactor) {
      maxFactor = factor;
    }
  }

  std::cout << "Problem 3: " << maxFactor << "\n";
  return 0;
}

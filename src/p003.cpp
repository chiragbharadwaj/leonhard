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
 * Helper function to compute the prime factors of an integer by testing a
 *   potential candidate via a skip-based 4-spoke wheel factorization method.
 *
 * @param wheel: A 1-2-3-5-7 wheel needed for the 4-spoke wheel factorization.
 * @param lst: A list containing the prime factors determined so far.
 * @param pot: A potential candidate for a prime factor of the number.
 * @param num: The integer for which the prime factors must be determined.
 * @return A list containing all of the prime factors of the number.
 */
std::list<long> factorHelper(Wheel12357 &wheel, std::list<long> &lst, long pot, long num) {
  if (pot * pot > num) {
    lst.push_back(num);
    lst.reverse();
    return lst;
  } else {
    long div = num / pot;
    if (div * pot == num) {
      lst.push_back(pot);
      return factorHelper(wheel, lst, pot, div);
    } else {
      const int head = wheel.rotate();
      return factorHelper(wheel, lst, (pot+head), num);
    }
  }
}

/* Finds all of the prime factors of an integer. 1 is not a prime number.
 *
 * @param num: The integer for which the prime factors must be determined.
 * @return A list containing all of the prime factors of the number.
 */
static std::list<long> getPrimeFactors(long num) {
  auto wheel = Wheel12357();
  std::list<long> lst = { };

  return factorHelper(wheel, lst, 2, num); // Call helper with constructed args
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

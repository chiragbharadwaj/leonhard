// Pull in the standard math library.
#include <cmath>

// Pull in the IO stream-handling headers.
#include <iostream>

/* Non-visible to public.
 *
 * Determines whether or not n is a palindromic number.
 *
 * @param n: The natural number for which palindrome-ness must be tested.
 * @return A flag denoting whether or not n is a palindrome.
 */
const bool isPalindrome(const long n) {
  if (n < 0) {
    throw std::invalid_argument("<n> must be a natural number!");
  }

  long num = n;
  long revN = 0;

  do {
    const int digit = num % 10;
    revN = 10*revN + digit;
    num = num / 10;
  } while (num != 0);

  return (n == revN);
}

/* Finds the largest palindrome made from the product of two n-digit numbers.
 *
 * @param n: The number of digits in each multiplier.
 * @return The palindromic number.
 */
static const long findLargestPalindrome(const long n) {
  if (n <= 0) {
    throw std::invalid_argument("<n> must be a positive integer!");
  }

  const int minMult = std::pow(10, n-1);
  const int maxMult = std::pow(10, n);
  const int maxMult11 = (n % 2 == 0) ? (maxMult-1) : (maxMult-10);
  long maxProd = 0;

  for (int l = minMult; l < maxMult; l++) {
    for (int r = maxMult11; r >= minMult; r -= 11) {
      const long currProd = l * r;
      if (isPalindrome(currProd) && (currProd > maxProd)) {
        maxProd = currProd;
      }
    }
  }

  return maxProd;
}

/* The primary execution block of the program.
 *
 * @param argc: The number of command-line arguments provided to the function.
 * @param argv: The list of command-line arguments, passed as strings.
 * @return A status code signifying whether or not the block ran successfully.
 */
int main(int argc, char *argv[]) {

  auto palindrome = findLargestPalindrome(3);

  std::cout << "Problem 4: " << palindrome << "\n";
  return 0;
}

// Pull in some standard data structures.
#include <map>

// Pull in the IO stream-handling headers.
#include <iostream>

/* A look-up table for the Fibonacci numbers. Initialized with the base cases of F(0) = F(1) = 1. */
static std::map<const long, const long> table = {{0,1},{1,1}};

/* Finds the nth Fibonacci number, 0-indexed. We use F(0) = F(1) = 1 as bases.
 *
 * @param n: The index within the Fibonacci sequence to discover.
 * @return The number at the specified index in the Fibonacci sequence.
 */
static const long fibonacci(const long n) {
  if (table.find(n) != table.end()) {
    return table[n];
  } else {
    auto k = (n % 2 == 0) ? ((n+1)/2) : (n/2);
    auto a = fibonacci(k);
    auto b = fibonacci(k-1);

    auto result = (n % 2 == 0) ? (a*a + b*b) : (a*a + 2*a*b);
    table.insert({n,result});

    return result;
  }
}

/* Finds all of the even Fibonacci numbers smaller than the specified limit.
 *
 * @param limit: The maximum number up to which to consider when summing.
 * @return The sum of the discovered Fibonacci numbers.
 */
static const long sumEvenFibonacci(const long limit) {

  long sum = 0;
  int n = 0;

  long fib;
  while ((fib = fibonacci(n++)) < limit) {
    if (fib % 2 == 0) {
      sum = sum + fib;
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

  auto sum = sumEvenFibonacci(4'000'000L);

  std::cout << "Problem 2: " << sum << "\n";
  return 0;
}

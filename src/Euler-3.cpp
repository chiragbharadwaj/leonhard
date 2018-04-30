// Pull in some standard data structures and collection-handling headers.
#include <list>
#include <algorithm>

// Pull in the IO stream-handling headers.
#include <iostream>

// Pull in the defined utility classes/functions needed to simplify the problem.
#include "LinkedList.h"

using namespace utils;

LinkedList<int> generateWheel() {
  LinkedList<int> primary({1, 2, 2, 4});
  LinkedList<int> secondary({2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, 2,
                             6, 4, 6, 8, 4, 2, 4, 2, 4, 8, 6, 4, 6, 2, 4, 6,
                             2, 6, 6, 4, 2, 4, 6, 2, 6, 4, 2, 4, 2,10, 2,10});
  secondary.join(secondary);
  primary.join(secondary);
  return primary;
}

std::list<int> getFactors(LinkedList<int> &wheel, const std::list<int> &lst, int pot, long num) {
  if (pot * pot > num) {
    std::list<int> newlst(lst);
    newlst.push_front(num);
    newlst.reverse();
    return newlst;
  } else {
    int div = num / pot;
    if (div * pot == num) {
      std::list<int> newlst(lst);
      newlst.push_front(pot);
      return getFactors(wheel, newlst, pot, div);
    } else {
      const int head = *(wheel.unsafe_pop());
      return getFactors(wheel, lst, (pot+head), num);
    }
  }
}

/* The primary execution block of the program.
 *
 * @param argc: The number of command-line arguments provided to the function.
 * @param argv: The list of command-line arguments, passed as strings.
 * @return A status code signifying whether or not the block ran successfully.
 */
int main(int argc, char *argv[]) {

  LinkedList<int> wheel = generateWheel();

  std::list<int> factors = getFactors(wheel, { }, 2, 600'851'475'143L);

  int maxFactor = 0;
  for (auto &factor : factors) {
    if (factor > maxFactor) {
      maxFactor = factor;
    }
  }

  std::cout << "Problem 3: " << maxFactor << "\n";
  return 0;
}

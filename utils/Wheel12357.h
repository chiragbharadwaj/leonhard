#ifndef UTILS_WHEEL12357
#define UTILS_WHEEL12357

// Pull in some standard data structures.
#include <vector>

// Pull in the header for the interface that this wheel implements.
#include "Wheel.h"

// Shared namespace for the utility classes.
namespace utils {

// A 4-spoked wheel is a particular type of wheel.
class Wheel12357 : public Wheel<int> {
public:

  /* Simple constructor for the wheel that initializes the internal state. */
  Wheel12357() {
    curr = 0;
  }

  /* Simple destructor for the wheel that invokes the C++ default behaviors. */
  ~Wheel12357() = default;

  /* @Override */
  const int rotate() {
    int val = wheel[curr];
    if (curr == wheel.size() - 1) {
      curr = repeatPoint;
    } else {
      curr++;
    }
    return val;
  }

private:
  // Construct a fixed 4-spoke wheel with appropriate spoke-meeting values.
  const std::vector<int> wheel =
    {1, 2, 2, 4,
     2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, 2,
     6, 4, 6, 8, 4, 2, 4, 2, 4, 8, 6, 4, 6, 2, 4, 6,
     2, 6, 6, 4, 2, 4, 6, 2, 6, 4, 2, 4, 2,10, 2,10};

  // The wheel begins repeating at this index (i.e. semi-circular linked list).
  const unsigned repeatPoint = 4;

  // The current head pointer being examined within the wheel.
  unsigned curr;
};

}

#endif
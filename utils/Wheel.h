#ifndef UTILS_WHEEL
#define UTILS_WHEEL

// Shared namespace for the utility classes.
namespace utils {

// A wheel is a generalized structure that simulates a circular linked list via
// clever internal indexing. This keeps lookups and manipulations reasonably fast.
template <typename T>
class Wheel {
public:
  /* Simple constructor for the wheel that invokes the C++ default behaviors. */
  Wheel() = default;

  /* Simple destructor for the wheel that invokes the C++ default behaviors. */
  virtual ~Wheel() = default;

  /* "Rotates" the wheel one position to the right by manipulating the internal
   *   state. Returns the value at the previous head pointer.
   *
   * @return The value at the current head pointer prior to the rotation.
   */
  virtual const T rotate() = 0;
};

}

#endif
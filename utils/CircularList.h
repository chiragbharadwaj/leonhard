#ifndef UTILS_LIST
#define UTILS_LIST

// Pull in the C standard type-definitions library.
#include <cstddef>

// Pull in the standard iterator class.
#include <iterator>

// Pull in the Boost iterator-template headers.
#include "boost/iterator/iterator_facade.hpp"

// Shared namespace for all utility classes/functions.
namespace utils {

// Use the Boost library within this namespace to avoid retyping everything.
using namespace boost;

// Forward declare the CircularList class so that iterators can access its type.
template <typename T>
class CircularList;

template <typename T>
class CircularListIterator
  : public iterator_facade<CircularListIterator<T>, CircularList<T>, forward_traversal_tag> {
  public:
    CircularListIterator(CircularList<T> *list)
      : list(list) { }

    ~CircularListIterator() = default;

  private:
    friend class iterator_core_access;

    CircularList<T> *list;

    void increment() {
      return;
    }

    bool equal(const CircularListIterator<T> &other) const {
      return false;
    }

    CircularList<T> &dereference() const {
      return nullptr;
    }
};

template <typename T>
class ConstCircularListIterator
  : public iterator_facade<CircularListIterator<T>, const CircularList<T>, forward_traversal_tag> {
  public:
    ConstCircularListIterator(CircularList<T> *list)
      : list(list) { }

    ~ConstCircularListIterator() = default;

  private:
    friend class iterator_core_access;

    const CircularList<T> *list;

    void increment() {
      return;
    }

    bool equal(const ConstCircularListIterator<T> &other) const {
      return false;
    }

    const CircularList<T> &dereference() const {
      return nullptr;
    }
};

template <typename T>
class CircularList {
private:

public:
  typedef CircularListIterator<T> iterator;
  typedef ConstCircularListIterator<T> const_iterator;

  explicit CircularList() = default;

  explicit CircularList(const CircularList<T> &other) {
    // Construct a bunch of nodes
  }

  ~CircularList() {
    // Free each node
  }

  CircularList<T> &operator =(const CircularList<T> &other) = default;

  iterator begin() {
    return nullptr;
  }

  const_iterator begin() const {
    return nullptr;
  }

  iterator end() {
    return nullptr;
  }

  const_iterator end() const {
    return nullptr;
  }

  void assign(std::size_t count, const T &value) {
    return;
  }

  T &front() {
    return nullptr;
  }

  const T &front() const {
    return nullptr;
  }

  T &back() {
    return nullptr;
  }

  const T &back() const {
    return nullptr;
  }

  bool empty() const {
    return false;
  }

  std::size_t size() const {
    return 0;
  }

  void clear() {
    return;
  }

  iterator insert(const_iterator pos, const T &value) {
    return nullptr;
  }

  iterator insert(const_iterator pos, const T &value, std::size_t count) {
    return nullptr;
  }

  iterator erase(const_iterator pos) {
    return nullptr;
  }

  iterator erase(const_iterator first, const_iterator last) {
    return nullptr;
  }

  void remove_all(const T &value) {
    return;
  }

  void push_back(const T &value) {
    return;
  }

  const T pop_back() {
    return nullptr;
  }

  void push_front(const T &value) {
    return;
  }

  const T pop_front() {
    return nullptr;
  }

  void resize(std::size_t count) {
    return;
  }

  static void join(CircularList<T> left, CircularList<T> right) {
    return;
  }

  static void splice(CircularList<T> &left, CircularList<T> &right, const_iterator pos,
                     const_iterator first, const_iterator last) {
    return;
  }

  static void splice(CircularList<T> &left, CircularList<T> &right, const_iterator pos) {
    auto first = right.begin();
    auto last  = right.end();
    return splice(left, right, pos, first, last);
  }

  static void reverse(CircularList<T> &list) {
    return;
  }

  static void sort(CircularList<T> &list) {
    return;
  }
};

template <typename T>
bool operator ==(const CircularList<T> &lhs, const CircularList<T> &rhs) {
  return (lhs <= rhs) && (rhs <= lhs);
}

template <typename T>
bool operator !=(const CircularList<T> &lhs, const CircularList<T> &rhs) {
  return !(lhs <= rhs) || !(rhs <= lhs);
}

template <typename T>
bool operator  <(const CircularList<T> &lhs, const CircularList<T> &rhs) {
  return (lhs <= rhs) && !(rhs <= lhs);
}

template <typename T>
bool operator <=(const CircularList<T> &lhs, const CircularList<T> &rhs) {
  for (auto itl  = lhs.begin(), itr  = rhs.begin();
            itl != lhs.end() && itr != rhs.end(); ++itl, ++itr) {
    if (*itl > *itr) {
      return false;
    }
  }
  return (lhs.size() <= rhs.size());
}

template <typename T>
bool operator  >(const CircularList<T> &lhs, const CircularList<T> &rhs) {
  return !(lhs <= rhs);
}

template <typename T>
bool operator >=(const CircularList<T> &lhs, const CircularList<T> &rhs) {
  return !(lhs <= rhs) || (rhs <= lhs);
}

}

#endif
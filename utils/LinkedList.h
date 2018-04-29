#ifndef UTILS_LIST
#define UTILS_LIST

// Pull in the C standard type-definitions library.
#include <cstddef>

// Pull in some standard data structures.
#include <list>

// Shared namespace for all utility classes/functions.
namespace utils {

template <typename T>
class LinkedList {
private:
  template <typename N = T>
  class Node {
  public:
    explicit Node() = delete;

    explicit Node(const N &data)
      : data(data), next(nullptr) { }

    ~Node() = default;

    N data;
    Node *next;
  };

  Node<T> *head = nullptr;
  Node<T> *tail = head;
  std::size_t numElems = 0;

public:
  template <typename L = T>
  class LinkedListIterator {
    public:
      LinkedListIterator() {
        pos = nullptr;
      }

      LinkedListIterator(const LinkedList<L> &list) {
        pos = list.head;
      }

      LinkedListIterator(const LinkedListIterator &other) {
        pos = other.pos;
      }

      ~LinkedListIterator() = default;

      bool operator !=(const LinkedListIterator &other) {
        return (this->pos != other.pos);
      }

      const LinkedListIterator &operator ++() {
        pos = pos->next;
        return *this;
      }

      L &operator *() const {
        return pos->data;
      }

    private:
      Node<L> *pos;
  };

  typedef LinkedListIterator<T> iterator;
  typedef LinkedListIterator<const T> const_iterator;

  explicit LinkedList() = default;

  explicit LinkedList(std::size_t count, const T &val) {
    for (int i = 0; i < count; i++) {
      push(val);
    }
  }

  explicit LinkedList(const std::list<T> &other) {
    for (auto &elem : other) {
      push(elem);
    }
  }

  ~LinkedList() {
    for (int i = 0; i < numElems; i++) {
      auto next = head->next;
      delete head;
      head = next;
    }
  }

  LinkedList<T> &operator =(const LinkedList<T> &other) = default;

  iterator begin() {
    return iterator(*this);
  }

  const_iterator begin() const {
    return const_iterator(*this);
  }

  iterator end() {
    return iterator();
  }

  const_iterator end() const {
    return const_iterator();
  }

  T &front() {
    return head->data;
  }

  const T &front() const {
    return head->data;
  }

  T &back() {
    return tail->data;
  }

  const T &back() const {
    return tail->data;
  }

  bool empty() const {
    return (numElems == 0);
  }

  std::size_t size() const {
    return numElems;
  }

  void clear() {
    auto *ptr = head;
    for (int i = 0; i < numElems; i++) {
      auto next = ptr->next;
      delete ptr;
      ptr = next;
    }
    head = nullptr;
    tail = nullptr;
    numElems = 0;
  }

  void push(const T &val) {
    auto *node = new Node<T>(val);
    if (!empty()) {
      tail->next = node;
    } else {
      head = node;
    }
    tail = node;
    numElems++;
  }

  const T pop() {
    if (!empty()) {
      const auto val = head->data;
      auto next = head->next;
      delete head;
      head = next;
      numElems--;
      return val;
    } else {
      return nullptr;
    }
  }

  void join(LinkedList<T> &other) {
    if (!other.empty()) {
      if (empty()) {
        head = other.head;
      } else {
        tail->next = other.head;
      }
      numElems = numElems + other.size();
    }
  }
};

template <typename T>
bool operator ==(const LinkedList<T> &lhs, const LinkedList<T> &rhs) {
  return (lhs <= rhs) && (rhs <= lhs);
}

template <typename T>
bool operator !=(const LinkedList<T> &lhs, const LinkedList<T> &rhs) {
  return !(lhs <= rhs) || !(rhs <= lhs);
}

template <typename T>
bool operator  <(const LinkedList<T> &lhs, const LinkedList<T> &rhs) {
  return (lhs <= rhs) && !(rhs <= lhs);
}

template <typename T>
bool operator <=(const LinkedList<T> &lhs, const LinkedList<T> &rhs) {
  for (auto itl  = lhs.begin(), itr  = rhs.begin();
            itl != lhs.end() && itr != rhs.end(); ++itl, ++itr) {
    if (*itl > *itr) {
      return false;
    }
  }
  return (lhs.size() <= rhs.size());
}

template <typename T>
bool operator  >(const LinkedList<T> &lhs, const LinkedList<T> &rhs) {
  return !(lhs <= rhs);
}

template <typename T>
bool operator >=(const LinkedList<T> &lhs, const LinkedList<T> &rhs) {
  return !(lhs <= rhs) || (rhs <= lhs);
}

}

#endif
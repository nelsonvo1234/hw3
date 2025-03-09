#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int aryness;
  PComparator comp;



};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : aryness(m), comp(c) {}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty");

  }
  data[0] = data[data.size() - 1];
  data.pop_back();

  size_t index = 0;

  while(index < data.size()){
    size_t indexToSwap = 3*index + 1;
    for(int i = 2; i < aryness && 3 * index + i < data.size(); i++){
      if(c(data[indexToSwap], data[3 * index + i])){
        indexToSwap = 3*index + i;
      }
    }
    if(c(data[indexToSwap], data[index])){
      std::swap(data[index], data[indexToSwap]);
      index = indexToSwap;
    }
    else{
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  data.push_back(item);
  std::size_t index = data.size() - 1;
  while (index != 0) {
      std::size_t parent_index = (index - 1) / aryness
      ;
      T& current = data[index];
      T& parent = data[parent_index];
      if(c(current, parent)){
        std::swap(current, parent);
      }
      else{
        break;
      }
      index = parent_index;
  }
}



#endif


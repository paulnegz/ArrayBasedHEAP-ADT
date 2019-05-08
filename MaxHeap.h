#ifndef _MAX_HEAP
#define _MAX_HEAP
template <class T>
class MaxHeap
{
private:
  int m_heapSize;
  int m_arraySize = 10;
  T* m_arr;

  void resize();//makes more room in array
  void upheap(int index);
  void downheap(int index);
  int recgetHeight(int index) const;

public:
  MaxHeap();
  ~MaxHeap();

  /** Sees whether this heap is empty.
@return True if the heap is empty, or false if not. */
  bool isEmpty() const;
  /** Gets the number of nodes in this heap.
@return The number of nodes in the heap. */
  int getNumberOfNodes() const;
  /** Gets the height of this heap.
@return The height of the heap. */
  int getHeight() const;
  /** Gets the data that is in the root (top) of this heap.
For a maxheap, the data is the largest value in the heap;
for a minheap, the data is the smallest value in the heap.
@pre The heap is not empty.
@post The root’s data has been returned, and the heap is unchanged.
@return The data in the root of the heap. */
  T peekTop() const;
  /** Adds a new node containing the given data to this heap.
@param newData The data for the new node.
@post The heap contains a new node.
@return True if the addition is successful, or false if not. */
  void add(const T &newData);
  /** Removes the root node from this heap.
@return True if the removal is successful, or false if not. */
  void remove();
  /** Removes all nodes from this heap. */
  void clear();
}; // end Heap
#include "MaxHeap.hpp"
#endif
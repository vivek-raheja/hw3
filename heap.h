#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <iostream>
#include <vector>
#include <stdexcept>


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
	std::vector<T> maryHeap;
 	int m;
	PComparator comp;
	void deleteNode(int node);


};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
	this->m = m;
	comp = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}

//push a value to the end then move it to the correct position
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
	if(empty()){
		maryHeap.push_back(item);
		return;
	}else{
		maryHeap.push_back(item);
		int curr = maryHeap.size()-1;
		while(comp(item, maryHeap[(curr-1)/m])){
			T temp = item;
			maryHeap[curr] = maryHeap[(curr-1)/m];
			maryHeap[(curr-1)/m] = temp;
			curr = (curr-1)/m;
		}
	}
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
	if(maryHeap.empty()){
		return true;
	}else{
		return false;
	}
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return maryHeap.size();
}


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
	throw std::logic_error("Top operation not possible on an empty heap");

  }
	// If we get here we know the heap has at least 1 item
	// Add code to return the top element
	return maryHeap[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
	throw std::logic_error("Pop operation not possible on an empty heap");
  }
	maryHeap[0] = maryHeap[maryHeap.size()-1];
	maryHeap.pop_back();
	deleteNode(0);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::deleteNode(int node)
{
	//recursively running to put the value into correct position.
	int size = maryHeap.size();
	if(node*m + 1 >= size){
		return;
	}else{
		T min = maryHeap[node*m + 1];
		int minidx = node*m + 1;
		int idx = node*m + 1;
		
		while(idx <= node*m + m && idx < size){
			if(comp(maryHeap[idx],min)){
				min = maryHeap[idx];
				minidx = idx;
			}
			idx ++;
		}
		if(comp(min, maryHeap[node])){
			T temp = maryHeap[node];
			maryHeap[node] = min;
			maryHeap[minidx] = temp;
			deleteNode(minidx);
		}else{
			return;
		}
		
	}
}

#endif


/***
 *
 *
 *
 ***/
template <class T, class A = std::allocator<T> >
class vector {
public:
    // public member functions
    size_type size() const noexcept; // since C++ 11
    size_type capacity() const noexcept; // since C++ 11
    void shrink_to_fit(); // since C++ 11

private:
    T* data_; // pointer to first element
    typename A::size_type cpacity_;
    typename A::size_type size_;
    A allocator_;

    T* end_capacity_; // points to one past internal storage
    T* end_; // points to one past last element
    A allocator_;

};

// Size is how many elements are actually in the vector
// Capacity is how many could be in the vector
// Vector uses std::allocator in default to allocate memory.
// Resizing is done with copy constructing each element in the new array
// form the old one.
// For c++11 Resizing is done by moving instead of copy constructed if it is possible
// for stored type.
// size: current number of stored elements
// capacity: currently allocated storage space
// Complexity amortized O(1)
// To avoid frequent allocations, often a non-linear growth pattern is used
//

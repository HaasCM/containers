/*!
  \file vector.h
  \brief File to define the Vector class
*/

#ifndef VECTOR_H
#define VECTOR_H

/*!
  \class Vector
  \brief Class to operate as a template vector container
*/

template<typename T>
class Vector {
public:
  //Generate Typedefs for readability
  typedef T             Value;
  typedef T&            Reference;
  typedef const T&      ConstReference;
  typedef T*            Pointer;
  typedef const T*      ConstPointer;
  typedef T*            Iterator;
  typedef T*            ConstIterator;

  typedef unsigned int  Size;

  //constructors
  Vector() noexcept;
  explicit Vector(Size sizeToAlloc);
  explicit Vector(Size sizeToAlloc, const T &defaultValue);
  explicit Vector(typename Vector<T>::Iterator first,
                  typename Vector<T>::Iterator last);
  explicit Vector(const Vector<T> &other);

  //destructor
  ~Vector();

  //copy
  Vector<T> & operator = (const Vector<T> &other);
  Vector<T> & operator = (Vector<T> &&other);

  void assign(Size count, const T &Value);
  void assign(typename Vector<T>::Iterator first,
              typename Vector<T>::Iterator last);

  //iterator operations
  Iterator begin() noexcept;
  ConstIterator cbegin() const noexcept;

  Iterator end() noexcept;
  ConstIterator cend() const noexcept;

  //capacity operations
  bool isEmpty() const noexcept;
  Size Size() const noexcept;
  Size maxSize() const noexcept;
  Size capacity() const noexcept;

  void resize(Size newSize);
  void resize(Size newSize, const T& newValue);
  void reserve(Size reservedSize);
  void squeeze();

  //element access
  Reference operator [](typename Vector<T>::Size index);
  ConstReference operator [](typename Vector<T>::Size index) const;

  Reference at(typename Vector<T>::Size index);
  ConstReference at(typename Vector<T>::Size index) const;

  Reference first();
  ConstReference first() const;

  Reference last();
  ConstReference last() const;

  T* data() noexcept;
  const T* data() const noexcept;

  //data management
  void push_back(const T &value);
  void push_back(T &&value);
  void pop_back();

  Iterator insert(typename Vector<T>::ConstIterator iter, const T&);
  Iterator insert(typename Vector<T>::ConstIterator iter, T&&);
  Iterator insert(typename Vector<T>::ConstIterator iter,
                  const Size &count,
                  const T &value);
  template<class InputIt>
  Iterator insert(typename Vector<T>::ConstIterator iter,
                  InputIt begin,
                  InputIt end);

  Iterator erase(typename Vector<T>::ConstIterator iter);
  Iterator erase(typename Vector<T>::ConstIterator iter,
                 Size count);
  Iterator erase(typename Vector<T>::ConstIterator first,
                 typename Vector<T>::ConstIterator last);

  void swap(Vector<T> &other);
  void clear() noexcept;

  bool operator == (const Vector<T> &other) const;
  bool operator != (const Vector<T> &other) const;
  bool operator <  (const Vector<T> &other) const;
  bool operator >  (const Vector<T> &other) const;
  bool operator <= (const Vector<T> &other) const;
  bool operator >= (const Vector<T> &other) const;

private:
  Size mReservedSize = 4; //!< Variable to store the reserved size for the vector
  Size mVectorSize = 0; //!< Count of data pieces stored in the vector
  T *mArray; //!< pointer to the array that is allocated to store the data

};

/*!
  \fn  Vector<T>::Vector() const
  \brief Default constructor for the Vector class
*/
template<typename T>
Vector<T>::Vector() const {
  mArray = new T[mReservedSize];
}

 /*!
  \fn Vector<T>::Vector(typename Vector<T>::Size sizeToAlloc) const
  \brief Constructor to allow custom allocation
*/
template<typename T>
Vector<T>::Vector(typename Vector<T>::Size sizeToAlloc) const {
  mReservedSize = sizeToAlloc << 2;
  mArray = new T[mReservedSize];

  for(Size index = 0; index < sizeToAlloc; ++index) {
    mArray[i] = T();
  }

  mVectorSize = sizeToAlloc;
}

/*!
  \fn Vector<T>::Vector(typename Vector::Size sizeToAlloc) const
  \brief Constructor to allow size allocation with default value
*/
template<typename T>
Vector<T>::Vector(typename Vector::Size sizeToAlloc, const T &defaultValue) const {
  mReservedSize = sizeToAlloc << 2;
  mArray = new T[mReservedSize];

  for(Size index = 0; index < sizeToAlloc; ++index) {
    mArray[i] = defaultValue;
  }

  mVectorSize = sizeToAlloc;
}

/*!
  \fn Vector<T>::Vector(typename Vector<T>::Iterator first, typename Vector<T>::Iterator last) const
  \brief Constructor to initialize vector with the values between first and last
*/
template<typename T>
Vector<T>::Vector(typename Vector<T>::Iterator first, typename Vector<T>::Iterator last) const {
  Size sizeToAlloc = last - first;

  mReservedSize = sizeToAlloc << 2;
  mArray = new T[mReservedSize];

  for(Size index = 0; index < sizeToAlloc; ++index, ++first) {
    mArray[index] = *first;
  }

  mVectorSize = sizeToAlloc;
}

/*!
  \fn Vector<T>::Vector(const Vector<T> &other)
  \brief copy constructor for the vector class
*/
template<typename T>
Vector<T>::Vector(const Vector<T> &other) {
  this->mReservedSize = other.mReservedSize;
  this->mVectorSize = other.mVectorSize;

  mArray = new T[mReservedSize];

  for(Size index = 0; index < other.mVectorSize; ++index) {
    mArray[index] = other.mArray[index];
  }
}

/*!
  \fn  Vector<T>::~Vector()
  \brief default constructor for the Vector class
*/
template<typename T>
Vector<T>::~Vector() {
  delete[] mArray;
}

/*!
  \fn void Vector<T>::reallocate()
  \brief reallocates the vector to the correct size
*/
template<typename T>
void Vector<T>::reallocate() {
  // allocate and add data to the array
  T *newArray = new T[mReservedSize];
  memcpy(newArray, mArray, mVectorSize*sizeof(T));

  delete[] mArray;

  mArray = newArray;
}






#endif // VECTOR_H

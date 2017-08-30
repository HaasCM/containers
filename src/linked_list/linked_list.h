/*!
  \file linked_list.h
  \brief file to define the linked list class
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*!
  \class LinkedList
  \brief class to operate on template node
*/


template<typename T>
class LinkedList {
  // Typedefs
private:
  typedef unsigned int Size;

  class Node {
  public:
    Node(T data);
    T data;
    Node *nextNode;

  };

public:
  LinkedList();
  ~LinkedList();

  void insertFront(const T &valueToInsert);
  void insertBack(const T &valueToInsert);

  void removeFront();
  void removeBack();

  void clear();

private:
  Node* mHead; // !< pointer to the head of the data
  Node* mTail; // !< pointer to the tail
  Size mSize;

};

/*!
  \fn  LinkedList<T>::LinkedList()
  \brief Default constructor for the linkned list
*/
template<typename T>
LinkedList<T>::LinkedList() {
  mHead = nullptr;
  mTail = nullptr;

  mSize = 0;
}

/*!
  \fn void LinkedList<T>::insertFront(const T &valueToInsert)
  \brief inserts value into the list
*/
template<class T>
void LinkedList<T>::insertFront(const T &valueToInsert) {

}


#endif // LINKED_LIST_H

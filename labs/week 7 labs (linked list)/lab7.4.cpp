#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab continues the task of implementing a linked list class, SnakeLinkedList.

In this lab you need to implement two more methods of SnakeLinkedList, popBack and pushBack.

The popBack method removes the last SnakeListNode from the SnakeLinkedList. The pushBack
method adds a new SnakeListNode to the end of the SnakeLinkedList.

Two special cases to consider are:

- The SnakeLinkedList is empty. In this case popBack should have no effect.

- The SnakeLinkedList has only one SnakeListNode. In this case popBack will make it empty.

When removing a SnakeListNode be sure to free up its memory using the delete operator.

You will find that popBack and pushBack are trickier to implement than popFront and pushFront.
This is because operations on the front of the SnakeLinkedList can use the _head data member
to access the front of the SnakeLinkedList.

Hint: To implement pushBack you can use the tail method to get the last SnakeListNode. Then,
all you need to do is add the new SnakeListNode after it.

Hint: To implement popBack you will need to access the SnakeListNode _before_ the tail so you
can set its nextNode to nullptr. You can iterate the SnakeLinkedList looking for a node
whose nextNode is the tail.

*/


class SnakeListNode {
public:
  SnakeListNode(int row, int col, SnakeListNode *nextNode)
      : _row(row), _col(col), _nextNode(nextNode) {}

  int row() const { return _row; };
  int col() const { return _col; };

  SnakeListNode *nextNode() const { return _nextNode; };
  void setNextNode(SnakeListNode *nextNode) { _nextNode = nextNode; };

  string toString() const;

private:
  int _row;
  int _col;
  SnakeListNode *_nextNode;
};

string SnakeListNode::toString() const {
  ostringstream oss;
  oss << "(row = " << _row << ", col = " << _col << ')';

  return oss.str();
}

class SnakeLinkedList {
public:
  ~SnakeLinkedList();

  void pushFront(int row, int col);
  void popFront();

  void pushBack(int row, int col);
  void popBack();

  int length() const;

  SnakeListNode* head() const {return _head; };
  SnakeListNode* tail() const;

  void printSnake() const;

private:
  SnakeListNode *_head = nullptr;
};

SnakeLinkedList::~SnakeLinkedList() {
  SnakeListNode* curNode = _head;
  while (curNode != nullptr) {
    SnakeListNode* nextNode = curNode->nextNode();
    delete curNode;
    curNode = nextNode;
  }
}

int SnakeLinkedList::length() const {
  int result = 0;
  SnakeListNode *curNode = _head;
  while (curNode != nullptr) {
    ++result;
    curNode = curNode->nextNode();
  }

  return result;
}

SnakeListNode* SnakeLinkedList::tail() const {
  SnakeListNode* prevNode = nullptr;
  SnakeListNode* curNode = _head;
  while (curNode != nullptr) {
     prevNode = curNode;
     curNode = curNode->nextNode();
  }
  
  return prevNode;
}

void SnakeLinkedList::pushFront(int row, int col) {
  _head = new SnakeListNode(row, col, _head);
}

void SnakeLinkedList::popFront() {
  if (SnakeListNode* oldHead = _head) {
    _head = _head->nextNode();
    delete oldHead;
  }
}

void SnakeLinkedList::pushBack(int row, int col) {
   // *** needs implementation
   SnakeListNode* newTail = new SnakeListNode(row, col, nullptr);
   if(_head == nullptr) _head = newTail;
   else{
      tail()-> setNextNode(newTail);
   }
   
}

void SnakeLinkedList::popBack() {
      // *** needs implementation
//next node = nullptr
//loop thought the node
//find tail() 
   if(_head == nullptr) return;
   SnakeListNode* last = tail();
   if(_head == last) {
      _head = nullptr;
   }
   else{
      SnakeListNode* curr = _head;
      while(curr->nextNode() != last){
         curr = curr->nextNode(); 
      }
      //curr = second last 
      curr->setNextNode(nullptr);
   }
   delete last;
}

void SnakeLinkedList::printSnake() const {
  SnakeListNode* curNode = _head;
  int len = length();
  cout << "length = " << len;
  if (len > 1) {
    cout << ", head = " << head()->toString();
    cout << ", tail = " << tail()->toString();
  } if (len == 1) {
    cout << ", head = tail = " << head()->toString();
  }
 cout << endl;

  while (curNode != nullptr) {
    cout << " " << curNode->toString() << endl;
    curNode = curNode->nextNode();
  }

  cout << endl;
}

int main() {

  SnakeLinkedList ssList;

  ssList.printSnake();

  ssList.pushBack(0, 1);
  ssList.pushBack(0, 2);
  ssList.pushBack(0, 3);

  ssList.printSnake();

  ssList.popBack();
  ssList.popBack();
  ssList.pushBack(4, 0);

  ssList.printSnake();

  ssList.popBack();
  ssList.popBack();

  ssList.printSnake();

  ssList.popBack();

  ssList.printSnake();

  return 0;
}
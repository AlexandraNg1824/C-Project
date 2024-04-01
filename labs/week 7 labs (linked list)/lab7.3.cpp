#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab continues the task of implementing a linked list class, SnakeLinkedList. In subsequent
labs,  we will add more functionality to SnakedLinkedList.

In this lab you need to implement one more method of SnakeLinkedList, popFront.

The popFront method removes the first SnakeListNode from the SnakeLinkedList and
then makes the second SnakeListNode the new first SnakeListNode.


Two special cases to consider are:

- The SnakeLinkedList is empty. In this case popFront should have no effect.

- The SnakeLinkedList has only one SnakeListNode. In this case popFront will make it empty.

When removing a SnakeListNode be sure to free up its memory using the delete operator.

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
   // *** needs implementation
   //if(_head == nullptr) delete _head;
   //else{
      if(SnakeListNode* secondNode = _head){
      _head = _head->nextNode();
      delete secondNode;
   }
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

  ssList.pushFront(0, 1);

  ssList.printSnake();

  ssList.pushFront(0, 2);
  ssList.pushFront(0, 3);

  ssList.printSnake();

  ssList.popFront();
  ssList.popFront();
  ssList.pushFront(4, 0);

  ssList.printSnake();

  ssList.popFront();
  ssList.popFront();

  ssList.printSnake();

  ssList.popFront();

  ssList.printSnake();

  return 0;
}
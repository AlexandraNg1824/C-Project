#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab starts you on the task of implementing a linked list class, SnakeLinkedList, which
might be useful when implementing a classic snake game.

The list in this lab uses a slightly different design than the one described in the
reading. The zyBook reading opts to represent the list as a dummy list node whose next
pointer points to the first node list. The list in this lab has a head pointer that is either null
(when the list is empty), or points to the first actual list node in the list.

The class, SnakeListNode, is provided for you. You should not need to modify it.

A SnakeLinkedList uses SnakeListNode's to represent the snake.

Each SnakeListNode contains the position (row, col) of one segment of the snake and a
nextNode pointer which points to the next segment of the snake. The first segment is
called the "head." If the SnakeLinkedList is empty the head will be nullptr.

The SnakeLinkedList class is declared below. For this lab you need to implement
three of its methods; length, tail, and pushFront.

- The length method iterates and counts the SnakeListNode's. It returns the
total number of SnakeListNode's in the SnakeLinkedList.

- The tail method iterates the SnakeListNode's and returns the last node.
If there are no SnakeListNode's (i.e. the SnakeLinkedList is empty) is should return nullptr.

- The pushFront method creates a new SnakeListNode using the specified row,col and
makes it the new head of the SnakeLinkedList.

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
   // *** needs implementation
   int result = 0;
   SnakeListNode* curNode = _head;
   while(curNode != nullptr){
      result += 1;
      curNode = curNode->nextNode();
   }
  return result;
}

SnakeListNode* SnakeLinkedList::tail() const {
   // *** needs implementation
   SnakeListNode* curNode = _head;
   while(curNode->nextNode() != nullptr){
      curNode = curNode->nextNode();
   }
  return curNode;
}

void SnakeLinkedList::pushFront(int row, int col) {
   // *** needs implementation
   SnakeListNode* newHead = new SnakeListNode(row, col, _head);
   _head = newHead;
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

  ssList.pushFront(4, 0);

  ssList.printSnake();

  return 0;
}
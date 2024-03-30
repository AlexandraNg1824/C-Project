#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* next;
};

class LinkedList {
public:
  LinkedList() = default;

  int count();

  Node* nodeContainingData(int data);

  bool add(int data);
  bool remove(int data);

  void print();

private:
  Node* _head = nullptr;

  Node* previousNode(const Node* node);
};

//idea from project 4 SnakeLinkedList.length method
int LinkedList::count() {
  // PROVIDE THIS FUNCTION'S BODY
  int result = 0;
  Node* curNode = _head; 
  while (curNode != nullptr){
    ++result;
    curNode = curNode->next;
  }
  return result;
}

Node* LinkedList::nodeContainingData(int data) {
  // PROVIDE THIS FUNCTION'S BODY
  Node* result = nullptr;
  Node* curNode = _head;
  while (curNode != nullptr){
    if(curNode->data == data){
      result = curNode;
      // DJH -0 no need to keep looping once you found data
    }
    curNode = curNode->next;
  }
  return result;
}


bool LinkedList::add(int data) {
  // PROVIDE THIS FUNCTION'S BODY
  bool result = false;
  Node* check = nodeContainingData(data);
  if (check != nullptr) return false;
  else {
    Node *insertNode = new Node{data, _head};
    //_head points to the first node
    _head = insertNode;
    result = true;
  }
  return result;
}

bool LinkedList::remove(int data) {
  // PROVIDE THIS FUNCTION'S BODY
  bool result = false;
  Node* check = nodeContainingData(data);
  if (check == nullptr) return false;
    //step 1 found the previous, point to next -> next
    //step 2 delete the middle one
  else{
    Node* curNode = _head;
    while (curNode != nullptr){
      // DJH -5 fails if curNode->next is nullptr - i.e. fails removing the tail.
      // DJH -10 does not delete the memory of the node containing data
      if(curNode->next->data == data){
        curNode->next = curNode->next->next; 
        result = true;
        break;
      }
    }
  }
  return result;
}

void LinkedList::print(){
  Node* curNode = _head;
  cout << count() << " nodes: ";
  while (curNode != nullptr) {
    cout << curNode->data << " ";
    curNode = curNode->next;
  }
  cout << endl;
}

// Returns the node in this list _before_ the specified node.
// If list is empty or the node is the first node in the list
// it returns nullptr.
Node* LinkedList::previousNode(const Node* node) {
  Node* result = nullptr;
  Node* curNode = _head;
  while (curNode != nullptr) {
    Node* nextNode = curNode->next;
    if (nextNode == node) {
      result = curNode;
      break;
    }
    curNode = nextNode;
  }

  return result;
}


void RunQuestion4() {

  LinkedList list;

  list.print();
//0
  list.add(55);
  list.add(45);
  list.add(35);
  list.print();
//3
  list.remove(45);
  list.print();
//2
  list.remove(42);
  list.print();
//2 coz no 42
  list.remove(55);
  list.print();
//1
  list.add(35);
  list.print();
//1 coz the same num
  list.remove(35);
  list.print();
  //0
  
  //just for testing
  //conclusion is if you deleted the last one, the head disappear coz nth point to there
  list.add(42);
  list.print();
}

// DJH: 85
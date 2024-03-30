#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

//from practice exam Q4
void Print(const Node *head) {
  /*** PROVIDE THIS FUNCTION'S BODY ***/
  const Node *curNode = head;
  while (curNode != nullptr) {
    cout << curNode->data << " -> ";
    curNode = curNode->next;
  }
  cout << "nullptr" << endl;
}


//idea from week 8 labs
//8.5 Linked Lists Part 3
//push back
// Step one: new pointer pointing to the node
// Step two: point to the next one
// Step three: get the specified node points to the new one
void InsertAfter(Node *node, int data){
  Node *insertNode = new Node{data, node->next};
  //insertNode = insertNode->next;
  node->next = insertNode;
}

void RunQuestion5() {
  Node *node3 = new Node{9, nullptr};
  Node *node2 = new Node{30, node3};
  Node *head = new Node{16, node2};
  InsertAfter(node2, 45);
  InsertAfter(node2, 55);
  InsertAfter(head, 90);
  Print(head);
}

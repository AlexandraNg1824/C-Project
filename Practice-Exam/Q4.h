#include <iostream>
#include <string>

using namespace std;

class IntListNode {
public:
  IntListNode(int data, IntListNode* nextNode = nullptr) : _data(data), _nextNode(nextNode) {}

  int data() const { return _data; }
  void setData(int data) { _data = data; }

  IntListNode* nextNode() const { return _nextNode; }
  void setNextNode(IntListNode* nextNode) { _nextNode = nextNode; }

  void printNodes() const {
    const IntListNode *curNode = this;
    while (curNode != nullptr) {
      std::cout << curNode->_data << " -> ";
      curNode = curNode->_nextNode;
    }

    std::cout << "nullptr\n";
  }

private:
  int _data;
  IntListNode* _nextNode;
};


// *** PUT YOUR TEMPLATIZED VERSION OF IntListNode HERE ***

// Remember, when making a class use a template, any reference to the class name should
// also refer to the template. For example, if you are using a template with GenericListNode,
// using T as a template parameter, references to GenericListNode within the class should be
// like this: GenericListNode<T>

//From week 8 labs
//7.10 Object Managing Resources Part 5 - Template-izing

template<typename T>
class GenericListNode {
public:
GenericListNode(T data, GenericListNode* nextNode = nullptr) : _data(data), _nextNode(nextNode) {}

  T data() const { return _data; }
  void setData(T data) { _data = data; }

  IntListNode* nextNode() const { return _nextNode; }
  void setNextNode(GenericListNode* nextNode) { _nextNode = nextNode; }

  void printNodes() const {
    const GenericListNode *curNode = this;
    while (curNode != nullptr) {
      std::cout << curNode->_data << " -> ";
      curNode = curNode->_nextNode;
    }

    std::cout << "nullptr\n";
  }

private:
  T _data;
GenericListNode* _nextNode;
};

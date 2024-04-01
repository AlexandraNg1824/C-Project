#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab provides you a simple class, Node, which holds a single piece of data, an int.
It has a constructor, a setter, and a getter that all work with this data, an int.

This class may seem trivial, but you'll actually be working with a very similar class when we
study linked lists.

The big limitiation with Node as it's currently declared is it only works with ints.

Suppose we want to use chars, or floats, or strings?
E.g. when we use linked lists we may want lists of chars, or floats, or strings.

The solution is to redeclare Node using templates so that the template parameter determines the
type of data in a Node. This allows Nodes to hold any type of data.

In this lab you need to:

1) Redeclare Node as a template. This simply means putting this code immediately before
the class declaration.

template<typename T>

This means when you declare a variable of type Node you must also use angled
brackets to specify a type - the same way you declare a vector. For example:
     Node<int> node(42);

2) Now that Node is a template, it means that the template parameter, T, is available for use
as a type in the class declaration. This means instead of writing Node using int,
you can instead use T. When your code is compiled the type specified by
the template parameter will be substituted for T.

You need to go through the class declaration and replace int with T.


After you do these two things, the code in main() will be able to compile. It will
create Nodes using different types to demonstrate that we've fixed the original problem
of Node only working with ints.

*/
template<typename T>
class Node {
  public:
    Node(T data) : _data(data) {};
    T data() { return _data; }
    void setData(T data) { _data =  data; }

  private:
    T _data;
};


int main() {
  Node<int> n1(42);
  cout << n1.data() << endl;

  Node<char> n2('z');
  cout << n2.data() << endl;

  Node<float> n3(3.14);
  cout << n3.data() << endl;

  Node<string> n4("hello");
  cout << n4.data() << endl;
}
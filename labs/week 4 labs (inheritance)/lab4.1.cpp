#include <iostream>
using namespace std;

/*

In this lab, we'll examine the idea of a derived class adding to the behavoir of its base class.

Implement the following class hierarchy:

    A
  /  \
 B    C
       \
        D
         \
          E

In other words:
class A {};
class B: public A {};

... and so on, to declare the other classes.


Define and implement the lineage methods:

Have the "A" class provide a public virtual method called lineage() that simply returns the class
name, which is "A".  The lineage of the base class is just its name.

Override lineage on the derived classes so that it returns its class name concatenated
with its superclass's lineage. For example, the body of class D's implementation will 
return the expression: "D->" + C::lineage();

Something to think about: does invoking lineage modify the object?  If not, how can you decorate
the lineage method to guarantee this.

*/


int main() {
  
  class A{ 
     public:
     virtual string lineage(){
        return "A";
     }
  };
  //"D->" + C::lineage();
  class B: public A {
     public:
     string lineage(){
        return "B->" + A::lineage();
      }
  };
  class C: public A {
     public:
     string lineage(){
        return "C->" + A::lineage();
      }
  };
  class D: public C {
      public:
      string lineage(){
      return "D->" + C::lineage();
      }
   };
  class E: public D {
      public:
      string lineage(){
      return "E->" + D::lineage();
      }
   };
   A a;
   B b;
   C c;
   D d;
   E e;

  cout << a.lineage() << endl;
  cout << b.lineage() << endl;
  cout << c.lineage() << endl;
  cout << d.lineage() << endl;
  cout << e.lineage() << endl;
}
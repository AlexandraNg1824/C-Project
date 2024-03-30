#include "Q4.h"

void RunQuestion4() {
  IntListNode intNode1(1);
  IntListNode intNode2(2, &intNode1);
  IntListNode intNode3(3, &intNode2);
  intNode3.printNodes();

  /*** UNCOMMENT THE CODE BELOW TO TEST YOUR TEMPLATE ***/

  GenericListNode<int> intNode7(7);
  GenericListNode<int> intNode8(8, &intNode7);
  GenericListNode<int> intNode9(9, &intNode8);
  intNode9.printNodes();

  GenericListNode<string> stringNode1("mice");
  GenericListNode<string> stringNode2("blind", &stringNode1);
  GenericListNode<string> stringNode3("three", &stringNode2);
  stringNode3.printNodes();
}
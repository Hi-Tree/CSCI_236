#include "LinkedBag.h"
#include "Node.h"
#include <vector>
#include <string>

int main()
{
  LinkedBag<int> cat;
  cat.add(1);
  cat.add(2);
  cat.add(3);
  cat.add(4);
  cat.add(5);

  cat.removeRan();
  cat.display();
}
 
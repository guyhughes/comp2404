#include <iostream>
#include <sstream>
#include <string>
#include "List.h"
int main (void)
{
  List<std::string> l;
  std::cout << l;
  std::string* a []={
    new std::string("alpha"),
    new std::string("bravo"),
    new std::string("charlie"),
    new std::string("delta")
  };
  for(std::string* x : a)
    l.add(x);

  std::cout << l;
  l.remove(a[2]);
  std::cout << l;
  l.remove(a[1]);
  std::cout << l;
  l.remove(a[0]);
  std::cout << l;
  l.remove(a[3]);
  std::cout << l;
}

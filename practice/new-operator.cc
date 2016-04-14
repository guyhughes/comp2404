#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Book {
  public:
    int a;
    int b;
    Book() {
      a= 0;
      b=0;
    }
    friend ostream& operator<<(ostream& str, Book* book){
      str << (Book&)(*book);
    };
    friend ostream& operator<<(ostream& str, Book& book){
      str << "a: " << book.a << "\n" << "b: " << book.b << endl;

    };
};

int main(void)
{
  Book *a = new Book;
  Book& c = *a;
  cout << c;
  cout << c << endl << a;

}

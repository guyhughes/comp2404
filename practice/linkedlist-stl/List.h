#include <sstream>
#include <string>


template<class T>
class List {

  template<class U>
  friend std::ostream& operator<<(std::ostream& s, List<U>& l);

  class Node {
    friend class List<T>;

    public:
      Node(T *);
      ~Node();
    private: 
      T* data;
      Node* next;
      Node* prev;
  };

  public:
    List();
    ~List();
    int getSize(){ return size; };
    void add(T*);
    void remove(T*);
    bool exist(T*);
    T*  find(T*);
    std::string toString();


    void operator+=(T*);
    void operator-=(T*);


  private:
    Node* head;
    int      size;

};


template<class T>
List<T>::Node::Node(T* x): data(x), next(NULL), prev(NULL) {}

template<class T>
List<T>::Node::~Node(){
  delete data;
}

template<class T>
List<T>::List(): head(NULL), size(0) { }

template<class T>
List<T>::~List() {
  Node* pivot = head;

  while(pivot != NULL){
    delete pivot->prev;
    pivot = pivot->next;
  }

  delete pivot;
}

template<class T>
void List<T>::add(T* x)
{
  List<T>::Node* pivot = head;
  List<T>::Node** insertionpoint;

  while(pivot != NULL && pivot->next != NULL)
    pivot = pivot->next;

  insertionpoint = ((pivot == NULL)? &head : &(pivot->next));

  *insertionpoint = new List<T>::Node(x);
  (*insertionpoint)->prev = pivot;
}

template<class T>
void List<T>::remove(T* x)
{
  bool found = false;
  typename List<T>::Node* pivot = head, *pprev, *pnext;

  if( pivot == NULL ){
    throw "cant remove from empty list honey";
  }

  while(pivot != NULL && !(found=(pivot->data == x)) )
    pivot = pivot->next;

  if(!found)
    throw "found nothing";
  

  pprev = (pivot->prev == NULL)? head : pivot->prev;
  pnext = pivot->next;

  if(pivot == head)
    head = pivot->next;

  if (pnext != NULL)
    pnext->prev = pprev;

  if (pprev != NULL)
    pprev->next = pnext;

  delete pivot;
}

template<class T>
std::ostream& operator<<(std::ostream& s, List<T>& l)
{
  s << l.toString();
  return s;
}

template<class T>
std::string List<T>::toString()
{
  std::stringstream s;
  Node* pivot = head;

  if (head == NULL){
    s << "Empty list";
  }
  else {
    while(pivot != 0){
      std::string* q;
      if( (q=dynamic_cast<std::string*>(pivot->data)) != 0) {
        s << *q;
      if (pivot->next != 0)
        s  << " → ";
      }
      pivot = pivot->next;
    }
  }
  s << "\n";
  return s.str();
}

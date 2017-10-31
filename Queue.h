#ifndef Queue_h
#define Queue_h

template<typename V>
class Queue
{
  struct Node
  {
    V values;
    Node* next;
  };

  Node* firstNode;
  Node* lastNode;
  int siz;
  V dummy = V();

  public:

  Queue( );
  ~Queue();
  void push(const V&);
  V& front( );
  V& back( );
  void pop( );
  int size( ) const{return siz;}
  bool empty( ) const;
  void clear( );
  Queue<V>& operator=(const Queue<V>&); // assignment
  Queue(const Queue<V>&); // copy
};


// constructor
template<typename V>
Queue<V>::Queue()
{
  firstNode = 0;
  lastNode = 0;
  siz = 0;
}


// destructor
template<typename V>
Queue<V>::~Queue()
{
  while(firstNode)
  {
    Node *p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

// push
template<typename V>
void Queue<V>::push(const V& values)
{
  Node* temp = new Node;
  temp->values = values;
  temp->next = 0;
  if (lastNode) lastNode->next = temp;
  else firstNode = temp;
  lastNode = temp;
  this -> siz++;
}

// front
template<typename V>
V& Queue<V>::front()
{
  if(firstNode)
    return firstNode -> values;
  else
    return dummy;
}

// back
template<typename V>
V& Queue<V>::back( )
{
  if(lastNode)
    return lastNode -> values;
  else
    return dummy;
}


// pop
template<typename V>
void Queue<V>::pop()
{
  if(firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode -> next;
    delete p;
    this -> siz--;
  }
  if(firstNode == 0 && lastNode != 0)
  {
    lastNode = 0;
  }
}

// empty
template<typename V>
bool Queue<V>::empty() const
{
  if(firstNode)
    return false;
  else
    return true;
}

// clear
template<typename V>
void Queue<V>::clear()
{
  while(firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode -> next;
    delete p;
    this -> siz--;
  }
  lastNode = 0;
}


// copy constructor
template <typename V>
Queue<V>::Queue(const Queue<V>& original)
{
  firstNode = 0;
  lastNode = 0;
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->values = p->values;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

// assignment operation
template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V>& original)
{
  if (this != &original)
  {
    while (firstNode)
    {
      Node* p = firstNode->next;
      delete firstNode;
      firstNode = p;
    }

    lastNode = 0;
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->values = p->values;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}


#endif

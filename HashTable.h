// identification
// SangBin Cho
// Lab 10, HashTable.h
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Compiler

#ifndef HashTable_h
#define HashTable_h

#include <list>
#include <queue>
using namespace std;

// what is it in chaning, what if it is full should I include load factor? Why do we need rehashing?
template <typename K, typename V, int CAP>
class HashTable
{
  struct Node
  {
    K key;
    V value;
  };

  list<Node> data[CAP];
  int(*hashCode)(const K&);
  int siz;

  public:
  HashTable(int(*)(const K&)=0); // We don't need a function?
  V& operator[ ](const K&); // setter
  V operator[ ](const K&) const; // getter
  int size() const {return siz;}
  bool containsKey(const K&) const;
  void deleteKey(const K&);
  queue<K> keyGet() const;
  void clear();
};

// constructor
template <typename K, typename V, int CAP>
HashTable<K, V, CAP>::HashTable(int(*fun)(const K&))
{
  hashCode = fun;
  siz = 0;
}


// setter
template <typename K, typename V, int CAP>
V& HashTable<K, V, CAP>::operator[ ](const K& key)
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;


  typename list<Node>::iterator it; // getters need to use const_iterator
  for(it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
      break;

  if(it == data[index].end()) // not found
  {
    Node n;
    n.key = key;
    data[index].push_back(n);
    siz++;
    data[index].back().value = V();
    return data[index].back().value;
  }

  if(it != data[index].end()) // found
  {
    return it -> value;
  }
}

// getter
template <typename K, typename V, int CAP>
V HashTable<K, V, CAP>::operator[ ](const K& key) const
{
  int index = hashCode(key) % CAP;
  if(index < 0) index += CAP;


  typename list<Node>::const_iterator it; // getters need to use const_iterator
  for(it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
      break;

  if(it == data[index].end()) // not found
  {
    return V();
  }

  if(it != data[index].end()) // found
  {
    return it -> value;
  }
}

// containsKey
template<typename K, typename V, int CAP>
bool HashTable<K, V, CAP>::containsKey(const K& key) const
{
  int index = hashCode(key) % CAP;
  if(index < 0) index += CAP;

  typename list<Node>::const_iterator it; // getters need to use const_iterator
  for(it = data[index].begin(); it != data[index].end(); it++)
    if(it->key == key)
      return true;
  if(it == data[index].end())
    return false;
}

// deleteKey
template<typename K, typename V, int CAP>
void HashTable<K, V, CAP>::deleteKey(const K& key)
{
  int index = hashCode(key) % CAP;
  if(index < 0) index += CAP;

  typename list<Node>::const_iterator it; // getters need to use const_iterator
  for(it = data[index].begin(); it != data[index].end(); it++)
    if(it->key == key)
      break;

  data[index].erase(it);
}


//
template<typename K, typename V, int CAP>
void HashTable<K, V, CAP>::clear()
{
  for(int i = 0; i < CAP; i++)
  {
    data[i].clear();
  }
}


template<typename K, typename V, int CAP>
queue<K> HashTable<K, V, CAP>::keyGet() const
{
  queue<K> hashQueue;


  for(int i = 0; i < CAP; i++)
  {
    typename list<Node>::const_iterator it;
    for(it = data[i].begin(); it != data[i].end(); it++)
    {
      hashQueue.push(it -> key);
    }
  }

  return hashQueue;
}

#endif

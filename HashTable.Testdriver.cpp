// identification
// SangBin Cho
// Lab 9, HashTable.TestDriver.cpp
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
#include <queue>
using namespace std;

#include <cassert>

#include "HashTable.h"
#include "HashTable.h"

int hashCode(const string&);

int main()
{
  // identification
  cout << "SangBin Cho\n\n";
  cout << "Lab 9, HashTable.TestDriver.cpp\n";
  cout << "Editor(s) used: Code::blocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  // program
  cout << "Test Driver : Hash Table\n\n";

  HashTable<string, double, 100> x(hashCode);

  cout << "1. Setter function\n";
  x["Jane"] = 88;
  x["Jean"] = 99.3;
  x["Jena"] = 44.5;
  x["Sang"] = 100;
  x["Yui"] = 76.434;
  x["iuY"] = 84;
  cout << "Expected value of Jane : 88\n";
  cout << "Actual value of Jane : " << x["Jane"] << "\n\n";
  assert(88 == x["Jane"]);
  cout << "Expected value of Jean : 99.3\n";
  cout << "Actual value of Jean : " << x["Jean"] << "\n\n";
  assert(99.3 == x["Jean"]);
  cout << "Expected value of Jena : 44.5\n";
  cout << "Actual value of Jena : " << x["Jena"] << "\n\n";
  assert(44.5 == x["Jena"]);
  cout << "Expected value of Sang : 100\n";
  cout << "Actual value of Jena : " << x["Sang"] << "\n\n";
  assert(100 == x["Sang"]);
  cout << "Expected value of Yui : 76.434\n";
  cout << "Actual value of Jena : " << x["Yui"] << "\n\n";
  assert(76.434 == x["Yui"]);
  cout << "Expected value of iuY : 84\n";
  cout << "Actual value of iuY : " << x["iuY"] << "\n\n";
  assert(84 == x["iuY"]);

  cout << "2. Changing the value in Jane Jena and iuY\n";
  x["Jane"] = 45.5;
  x["Jena"] = 78;
  x["iuY"] = 100;

  cout << "Expected value of Jane : 45.5\n";
  cout << "Actual value of Jena : " << x["Jane"] << "\n\n";
  assert(45.5 == x["Jane"]);


  cout << "Expected value of Jena : 78\n";
  cout << "Actual value of Jena : " << x["Jena"] << "\n\n";
  assert(78 == x["Jena"]);

  cout << "Expected value of iuY : 100\n";
  cout << "Actual value of iuY : " << x["iuY"] << "\n\n";
  assert(100 == x["iuY"]);

  cout << "\n\n\n3. ContainsKey test\n";
  cout << "Expected value of Jane : 1\n";
  cout << "Actual value of Jane : " << x.containsKey("Jane") << endl;
  assert(1 == x.containsKey("Jane"));
  assert(1 == x.containsKey("Jean"));
  assert(1 == x.containsKey("Jena"));
  assert(1 == x.containsKey("Yui"));
  assert(1 == x.containsKey("iuY"));
  assert(0 == x.containsKey("Greata"));

  cout << "\n\n\n4. size function\n";
  cout << "Expected value of the size : 6\n";
  cout << "Actual value of the size : " << x.size() << endl;
  assert(6 == x.size());

  cout << "\n\n\n5. Delete key test\n";
  x.deleteKey("Jane");
  x.deleteKey("Jena");
  x.deleteKey("Sang");

  cout << x["Jane"] << endl << x["Jena"] << endl
  << x["Sang"] << endl << x["Yui"] << endl << x["Jean"] << "\n";

  cout << "\n\n6. clear test\n";
  x.clear();
  cout << x["Yui"] << endl << x["Jean"] << endl << x["Jane"];

  x["Jane"] = 88;
  x["Jean"] = 99.3;
  x["Jena"] = 44.5;
  x["Sang"] = 100;
  x["Yui"] = 76.434;
  x["iuY"] = 84;


  cout << "\n\n\nkeyGet test\n";
  for(queue<string> keys = x.keyGet(); !keys.empty(); keys.pop())
  {
    cout << keys.front() << endl;
  }

  cout << "\n\nconst getter test";
  const HashTable <string, double, 100> a(hashCode);
  assert(a.size() == 0);
  assert(a.containsKey("Jane") == 0);
  assert(0 == a["Sang"]);

}

int hashCode(const string& key)
{
  int result = 0;
  for (int i = 0; i < key.length(); i++)
    result += key.at(i);
  return result;
}


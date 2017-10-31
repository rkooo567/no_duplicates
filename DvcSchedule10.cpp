// identification
// SangBin Cho
// Lab 10, DvcSchedule10.cpp
// Editor(s) used: Code::blocks
// Compiler(s) used: GNU GCC Compiler

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#include <cstring> // for strtok and strcpy

#include "HashTable.h"

int hashCode(const string&);

int main()
{ // program

  // for parsing the input file
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  HashTable<string, bool, 70000> alreadySeen(hashCode);
  HashTable<string, int, 10000> courses(hashCode);
  int countLine = 0;
  int countDuplicates = 0;

  // read the input file
  while (fin.good())
  {
    if((countLine  % 1000) == 0)
    {
      cout << "."; cout.flush();
    }

    countLine++;

    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue; // skip blank lines

    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    string key = term + section;
    bool found = false;

    // searching if there are duplicates
    if(alreadySeen[key] == true)
      found = true;

    //If it is not the duplicate
    if(!found)
    {
      alreadySeen[key] = true;
      courses[subjectCode]++;
    }

    else
      countDuplicates++;
  }

  cout << "\n\n\n";


  vector<string> keys;
  int i = 0;
  for(queue<string> copi = courses.keyGet(); !copi.empty(); copi.pop(), i++)
  {
    string keyValue = copi.front();
    keys.push_back(keyValue);
  }


  for(int i = 0; i < keys.size(); i++)
  {
    for(int j = i + 1; j < keys.size(); j++)
    {
      if(keys[i] > keys[j])
        swap(keys[i], keys[j]);
    }
  }

  for(int i = 0; i < keys.size(); i++)
  {
    cout << keys[i] << ", " << courses[keys[i]] << " classes\n";

  }

  cout << "\n\nnumber of duplicates : " << countDuplicates;

  fin.close();
}

int hashCode(const string& key)
{
  int result = 0;
  for (int i = 0; i < key.length(); i++)
    result += key.at(i);
  return result;
}

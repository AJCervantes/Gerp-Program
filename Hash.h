//Andrew Cervantes
//Project 2
//Hash.h

#include <iostream>
#include <string>
#include <vector>
#ifndef HASH_H_
#define HASH_H_
#include "NodeA.h"

using namespace std;

const int INIT_CAP = 1000000;

class Hash
{
public:
    //constructor/destructor
    Hash();
    ~Hash();

    //Public functions
    void insert(string word, string ouput);
    bool find(string word) const;
    
private:
    //Private functions
    int doHash(const string word) const;
    void updateLoad();

    //variables
    int numInserts;
    int capacity;
    vector<NodeType> *l;
};
#endif

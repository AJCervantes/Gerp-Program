//Andrew Cervantes
//Project 2
//FSTreeTraversal.h

#include <iostream>
#include <fstream>
#include <string>
#include "Hash.h"
#include "DirNode.h"
#include "FSTree.h"

#ifndef FSTREETRAVERSAL_H_
#define FSTREETRAVERSAL_H_

using namespace std;

class FSTreeTraversal
{
public:
    FSTreeTraversal();
    void run(string filename, istream &);

private:
    void print_files(DirNode *root, string prefix);
    void index(string filename);
    string stringProcessing(string input);
    void case_in(string word, int index, bool &is_in);

    //Attributes    
    Hash h;
};
#endif

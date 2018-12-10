//Andrew Cervantes
//Project 2
//main.cpp

//Tree Traversal
//Andrew Cervantes

#include <iostream>
#include "FSTreeTraversal.h"

using namespace std;
int main(int argc, char *argv[])
{
    if (argc != 2){
	cerr << "Usage: gerp directory" << endl
	<< "Where: directory is a valid directory" << endl;
    }
    FSTreeTraversal gerp;
   
    gerp.run(argv[1], cin);
    cout << endl;
    cout << "Goodbye! Thank you and have a nice day." << endl;
}


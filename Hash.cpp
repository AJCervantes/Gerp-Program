//Andrew Cervantes
//Project 2
//Hash.cpp creates and edits the Hash


#include <iostream>
#include <string>
#include "Hash.h"
using namespace std;


//Function: Hash
//Inserts: none
//Returns: none
//Does: Constructs the hash array and
//private variables
Hash::Hash()
{
    numInserts = 0;
    l = new vector<NodeType>[INIT_CAP];
    capacity = INIT_CAP;    
} 

//Function: ~Hash
//Inserts: none
//Returns: none
//Does: Destructs the hash array
Hash::~Hash()
{
    delete [] l;
}

//Function: insert
//Inserts: string word and string output
//Returns: none
//Does: Constructs the hash array and
void Hash::insert(string word, string output)
{
    int index = doHash(word);
    int size = l[index].size();
    
    for (int i = 0; i < size; i++){
	if (l[index][i].word == word){
	    int last = (l[index][i].listB.size()) - 1;
	    if (l[index][i].listB[last] == output)
		return;
	    l[index][i].listB.push_back(output);
	    return;
	}
    }
    NodeType node;
    node.word = word;
    node.listB.push_back(output);
    l[index].push_back(node);
    numInserts++;
    if ((numInserts / capacity) > 0.94)
        updateLoad();
}

//Function: find
//Inserts: string word
//Returns: none
//Does: Finds the location of the word should be
//and either prints the desired output or couts
//that it is not there
bool Hash::find(string word) const 
{
    int index = doHash(word);
    int length = l[index].size();
    for (int i = 0; i < length; i++){
	if (l[index][i].word == word){
	    int size = l[index][i].listB.size();
	    for(int j = 0; j < size; j++)
		cout << (string)(l[index][i].listB[j]) << endl;
	    
	    return true;
	}
    }
    return false;
}


//Function: doHash
//Inserts: conststring word
//Returns: int
//Does: performs the math to find the index
int Hash::doHash(const string word) const
{
    unsigned long total = 1;
    int size = word.length();
    for (int i = 0; i < size; i++)
    {
	total += word[i] * word[i];
	total += word[i] * 4; 
    }
    unsigned long index = total % (unsigned long)capacity;
    return (int)index;
}

//Function: updateLoad
//Inserts: none
//Returns: none
//Does: checks if the load factor is surpassed
//and if so expands and rehashes the array 
void Hash::updateLoad()
{
    int newCapacity = capacity + 1000000;
    vector<NodeType> *temp = new vector<NodeType>[newCapacity];    
    for (int i = 0; i < capacity; i++){
        int size = l[i].size();
        for (int j = 0; j < size; j++){
            int index = doHash(l[i][j].word);
    	    NodeType node = (l[i][j]);
	    temp[index].push_back(node);
	}
    }
    capacity = newCapacity;
    delete [] l;
    l = temp;
}

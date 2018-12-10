//Tree Traversal
//Andrew Cervantes

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "FSTreeTraversal.h"
#include <cctype>
using namespace std;

//Function: constructor
//inserts: none
//return: none
//does: nothing really
FSTreeTraversal::FSTreeTraversal()
{

}
//Function: run
//Inserts:ifstream reference, FSTree root and filename
//returns: none
//does: runs the grep function
void FSTreeTraversal::run(string filename, istream &infile)
{
    FSTree tree(filename);
    DirNode *root = tree.getRoot();
    print_files(root, filename);

    string input, word;
    while(!infile.eof())
    {
	bool is_in = false;
	cout << "Query? ";
	infile >> word;
	if (infile.eof())
	    return;
	if (word == "")
	    return;
	if (word == "@quit" || word == "@q")
	    return;
	if (word == "@i" || word == "@insensitive"){
		infile >> word;
		word = stringProcessing(word);
		bool ever_in = false;
		for (int i = 0; i < word.length(); i++)
		    word[i] = tolower(word[i]);
		case_in(word, 0, ever_in);
		if (ever_in == false)
		    cout << word << " Not Found." << endl;
	}
	else{
	    word = stringProcessing(word);
	    is_in = h.find(word);
	    if (is_in == false)
		cout << word << " Not Found. Try with @insensitive or @i." << endl;
	}
    }
}

//Function: caseInsensitive
//Inserts:string word
//returns: none
//does: runs the query for the case insensitive of the word
void FSTreeTraversal::case_in(string word, int index, bool &ever_in)
{
    bool is_in = false;
    if (index == word.length()){
	is_in = h.find(word);
	if (is_in == true)
	    ever_in = true;
    }
    else 
    {
	string updatedWord = word;
	word[index] = toupper(word[index]);
	case_in(updatedWord, index + 1, ever_in);
	case_in(word, index + 1, ever_in);
    }
}

//Function: print_files
//inputs: rootnode and filename
//outputs: none
//Does: prints all files in the tree
void FSTreeTraversal::print_files(DirNode *node, string prefix)
{
    if (node == NULL)
	return;
    for (int i = 0; i < node->numSubDirs(); i++)
	print_files(node->getSubDir(i), prefix + "/" + (node->getSubDir(i))->getName());
    
    for (int i = 0; i < node->numFiles(); i++)
	index(prefix + "/" + node->getFile(i));
}

//Function: index
//inserts: string filename
//returns: void
//does: searches through the file and inserts
//all words into the hash
void FSTreeTraversal::index(string filename)
{
    string inputLine, word;
    int count = 1;
    ifstream infile;
    infile.open(filename.c_str());
    while(!infile.eof())
    {
	getline(infile, inputLine);
	stringstream stringParse, output;
	stringParse << inputLine;
	output << filename + ":" << count
	     <<  ": " + inputLine;
	while(stringParse >> word){
	    word = stringProcessing(word);
	    if (word != "")
   	        h.insert(word, output.str());
	}
    count++;
    }
    infile.close();    
}

//function: stringProcessing
//inserts: string
//returns: string
//does: edits the string to make sure it
//has no extra punctuation
string FSTreeTraversal::stringProcessing(string input)
{
    int indexF = 0;
    int indexB = input.length();

    while(!isalnum(input[indexF]) && (indexF != indexB))
        indexF++;

    while(!isalnum(input[indexB]) && (indexB != indexF))
	indexB--;

    return input.substr(indexF, indexB - indexF + 1);

}


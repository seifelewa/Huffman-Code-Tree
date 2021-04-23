//
//  Huffman.cpp
//  Coding
//
//  Created by Maryam Nouh on 12/22/20.
//

#include "Huffman.hpp"
#include <iomanip>
#include<iostream>

using namespace std;


//--- Definition of constructor
inline BinaryTree::BinaryTree()
: myRoot(0)
{}

//--- Definition of empty()
inline bool BinaryTree::empty() const
{ return myRoot == 0; }

//--- Definition of generateCode()
inline void BinaryTree::generateCode()
{ generateCodeAux(myRoot, 0); }

//--- Definition of graph()
inline void BinaryTree::graph(ostream & out) const
{ graphAux(out, 0, myRoot); }




//--- Definition of generateCodeAux()
void BinaryTree::generateCodeAux(BinNode *tree, string code)
{
    if (tree == NULL)
        return;
    if(tree->left == NULL && tree->right == NULL)
    {
        cout << "Leaf Found: " << tree->data << "\t" << code << endl;
    }
    if(tree->left != NULL)
    {
        generateCodeAux(tree->left, code + "0");
    }
    if(tree->right != NULL)
    {
        generateCodeAux(tree->right, code + "1");
    }
}

//--- Definition of graphAux()
void BinaryTree::graphAux(ostream & out, int indent,
                          BinaryTree::BinNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        graphAux(out, indent + 8, subtreeRoot->left);
        out << setw(indent) << " " << subtreeRoot->data << ":" << subtreeRoot->freq << endl;
        graphAux(out, indent + 8, subtreeRoot->right);
    }
}

//--- Definition of inorderAux()
void BinaryTree::inorderAux(ostream& out,
	BinaryTree::BinNodePointer subtreeRoot)
{
	if (subtreeRoot != 0)
	{
		inorderAux(out, subtreeRoot->left);    // L operation
		out << subtreeRoot->data << ":" << subtreeRoot->freq << "  ";      // V operation
		inorderAux(out, subtreeRoot->right);   // R operation
	}
}

	void BinaryTree::insert(char data, int fre) {
		BinaryTree::BinNodePointer locptr = myRoot,   // search pointer
			parent = 0;        // pointer to parent of current node
		while (locptr != 0)
		{
			parent = locptr;
			if (fre <= locptr->freq)       // descend left
				locptr = locptr->left;
			else if (locptr->freq < fre)  // descend right
				locptr = locptr->right;
		}
		                                 // construct node containing item
			locptr = new BinaryTree::BinNode(data,fre);
			if (parent == 0) {             // empty tree
				myRoot = locptr;
			}
			else if (fre < parent->freq)  // insert to left of parent
			{
				parent->left = locptr;
			}
			else                           // insert to right of parent
			{
				parent->right = locptr;
			}
		
	}
	

BinaryTree::BinNodePointer BinaryTree::insert2( char data,int fre) {
	BinaryTree::BinNodePointer ptr;
	ptr->data = data;
	ptr->freq = fre;
	return ptr;
}

//Decode Function with recursion
void BinaryTree::decodeRec(BinaryTree::BinNode* root , int &pos , string str ){
	if(root==NULL) return;
	if(root->right ==NULL && root->left ==NULL){
		cout<<root->data;
		return;
	}
	if(str[pos]=='0'){
		pos++;
		decodeRec(root->left , pos , str);
	}
	else {
		pos++;
		decodeRec(root->right, pos , str);
	}
}

//Decode Function  
void BinaryTree::decode(BinaryTree::BinNode* root , string str){
	int pos=0;
	BinaryTree::BinNode* ptr=root;
	while(pos!=str.length()+1){
			while(ptr->left !=NULL && ptr->right != NULL){
				if(str[pos]=='0'){
					ptr=ptr->left;
				}
				else {
					ptr=ptr->right;
				}
				pos++;
			}
			cout<<ptr->data;	
		}
	}


//-- Definition of the output operator
ostream & operator<<(ostream & out, const BinaryTree & tree){
    tree.graph(out);
    return out;
}

//
//  Huffman.hpp
//  Coding
//
//  Created by Maryam Nouh on 12/22/20.
//

#ifndef Huffman_hpp
#define Huffman_hpp

#include <stdio.h>
#include <string>
using namespace std;

class BinaryTree
{
public:
    /***** Function Members *****/
    BinaryTree();
    /*------------------------------------------------------------------------
     Construct a binary tree object.
     
     Precondition:  None.
     Postcondition: An empty binary tree has been constructed.
     -----------------------------------------------------------------------*/
    
    inline bool empty() const;
    /*------------------------------------------------------------------------
     Check if the binary tree is empty.
     
     Precondition:  None.
     Postcondition: Returns true if binary tree is empty and false otherwise.
     -----------------------------------------------------------------------*/

    inline void generateCode();
    /*------------------------------------------------------------------------
     Traverse the binary tree.
     
     Precondition:  None.
     Postcondition: Prints the character with its corresponding binary code
     from the binary tree.
     Note: generateCode() uses private auxiliary function generateCodeAux().
     -----------------------------------------------------------------------*/
    
    void graph(ostream & out) const;
    /*------------------------------------------------------------------------
     Graphic output of the binary tree.
     
     Precondition:  ostream out is open.
     Postcondition: Graphical representation of the binary tree has been output
     to out.
     Note: graph() uses private auxiliary function graphAux().
     ------------------------------------------------------------------------*/
    
    void inorder(ostream & out) const;
    /*------------------------------------------------------------------------
     Inorder traversal of a binary tree.
     
     Precondition:  ostream out is open.
     Postcondition: Binary tree has been inorder traversed and characters in
     nodes with their corresponding frequencies have been output to out.
     Note: inorder uses private auxiliary function inorderAux().
     ------------------------------------------------------------------------*/
     
    
    
private:
    /***** Node class *****/
    class BinNode
    {
    public:
        char data;
        int freq;
        BinNode * left;
        BinNode * right;
        
        // BinNode constructors
        // Default -- data part is default DataType value; both links are null.
        BinNode()
        : left(0), right(0)
        {}
        
        // Explicit Value -- data part contains item; both links are null.
        BinNode(char item, int f)
        : data(item), freq(f), left(0), right(0)
        {}
        
    };// end of class BinNode declaration
    
    typedef BinNode * BinNodePointer;
    
    
    /***** Private Function Members *****/
    void generateCodeAux(BinNode *tree, string code);
    /*------------------------------------------------------------------------
     Generate code auxiliary function.
     
     Precondition: None
     Postcondition: A binary code is generated for each character that resides
     in the tree.
     ------------------------------------------------------------------------*/
    
    void graphAux(ostream & out, int indent,
                              BinNodePointer subtreeRoot) const;
    /*------------------------------------------------------------------------
     Graph auxiliary function.
     
     Precondition:  ostream out is open; subtreePtr points to a subtree
     of this binary tree.
     Postcondition: Graphical representation of subtree with root pointed
     to by subtreePtr has been output to out, indented indent spaces.
     ------------------------------------------------------------------------*/
    
    void inorderAux(ostream & out, BinNodePointer subtreeRoot);
    /*------------------------------------------------------------------------
     Inorder traversal auxiliary function.
     
     Precondition:  ostream out is open; subtreePtr points to a subtree
     of this binary tree.
     Postcondition: Subtree with root pointed to by subtreePtr has been
     output to out.
     ------------------------------------------------------------------------*/
	
	void insert(char data, int fre);

	BinNodePointer insert2(char data, int fre);
	/*------------------------------------------------------------------------
	 Insert function.

	 Precondition:  input character and its freqency.
	 Postcondition: all characters and their freqencies are added as leaf nodes.
	 ------------------------------------------------------------------------*/

    void decodeRec(BinNode* root , int &pos , string str );
    /*------------------------------------------------------------------------
	 Decoding function with recursion.

	 Precondition:  input root pointer of the tree , pointer position and the letter in binary to be docoded.
	 Postcondition: The letters are decoded according to their binary code.
	 ------------------------------------------------------------------------*/
     
    void decode(BinNode* root , string str);
     /*------------------------------------------------------------------------
	 Decoding function.

	 Precondition:  input root pointer of the tree , pointer position and the letter in binary to be docoded.
	 Postcondition: The letters are decoded according to their binary code.
	 ------------------------------------------------------------------------*/

    /***** Data Members *****/
    BinNodePointer myRoot;
    
}; // end of class template declaration

ostream & operator<<(ostream & out, const BinaryTree & tree);

#endif /* Huffman_hpp */

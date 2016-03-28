//Mert Ozsaydi B00451123

// define a binary search tree type  -  BST
// a BST stores a collection of items of type ItemType
// duplicate items are not allowed
// objects of type ItemType must be comparable using the
// relational operators:  == and <

#ifndef _BST_
#define _BST_
#include<iostream>
using namespace std;

typedef int ItemType;

// a binary search tree contains nodes of type BinNode
// data members are public because BinNode type is 
// intended for use by the BST class only
class BinNode{
	public:
		ItemType item;
		BinNode * left;
		BinNode * right;
		BinNode(){
			left = 0;
			right = 0;
		}
		BinNode(const ItemType & newItem){
			left = 0;
			right = 0;
			item = newItem;
		}
};

class BST{
	public:
		BST();
		// create an empty BST
		~BST();//desctructor
		void destroytree(BinNode *r);//helper for desctructor
		bool empty()const;
		// is the BST empty?

		BST(const BST & foo);//copy constructor
		void copyhelper(BinNode * foo1, BinNode * &foo2);//copy constructor helper

		void assignmenthelper(BinNode *c);// assignment operator helper
		const BST & operator=(const BST & original);// assignment operator
		int size()const;
		// how many items are in the BST?
		
		bool insert(const ItemType & item); 
		// add item (if it is not a duplicate) to the BST
		// return true if the item was inserted, otherwise false
		
		bool search(const ItemType & item) const;
		// return true if item is found in the BST, otherwise false
		
	        // remove item from the BST
                // return true if item was found and removed, otherwise false

		void display(ostream & out)const;//display function
		void displayhelper(ostream & out, BinNode* current)const;//display function helper
		
		int height()const;//height function
		int heighthelper(BinNode* current)const;//height function helper
		bool remove(const ItemType & item);//remove function
		int nextright(BinNode* node);//remove function helper
		void removehelper(const ItemType & item, BinNode* foo);//remove function helper
		
		
	private:
		BinNode * root;   // gives access to the BST
		int numItems;     // number of items in the BST
};
#endif
		
	


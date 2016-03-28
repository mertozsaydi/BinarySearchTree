//Mert Ozsaydi B00451123

#include <iostream>
#include "bst.h"
using namespace std;


bool inserthelper(const ItemType & item, BinNode * & tmp);//insert function helper
int size(BinNode * foo);//size function
bool searchhelper(BinNode * tmp, const ItemType & boo);// function helper



BST::BST():root(0)
{
numItems = 0;
}

bool BST::empty()const
{
return root == 0;
}
bool BST::search(const ItemType & item) const
{
return ::searchhelper(root, item);
}
//help function for search function
bool searchhelper(BinNode * tmp, const ItemType & boo)
{
	if(tmp == NULL)	
	return false;
	if(boo < tmp->item)	 
	return ::searchhelper(tmp->left, boo);
	else if(tmp->item < boo)	
	return ::searchhelper(tmp->right, boo);	 
	return true;
}



int BST::size() const
{  return ::size(root);  }

int size(BinNode * foo)
{  
	if(foo == NULL){return 0 ;}
	return size(foo->left)+size(foo->right)+1;
} 


bool BST::insert(const ItemType & item)
{
return inserthelper(item,root);

}
//helper function for insert function
bool inserthelper(const ItemType & item, BinNode * & tmp)
{
	if( tmp == NULL ){		
		tmp = new BinNode(item);
		return 1;
	}
	else{
	
	if( item < tmp->item ){

		inserthelper(item, tmp->left);
		return 1;}

	else if(item > tmp->item){
		inserthelper(item, tmp->right);
		return 1;}

	return 0;
	
	}
}

void BST::display(ostream & out)const		
{
	
	displayhelper(out, root);
	cout<<endl;
}
//helper function for display function
void BST::displayhelper(ostream & out, BinNode* foo)const        
{
	if (foo != 0)
	{
		displayhelper(out, foo->left);
		out << foo->item;
		displayhelper(out, foo->right);
	}
}
// to get height
int BST::height() const
{
	if (root == 0){return heighthelper(root);}
	return heighthelper(root) - 1;
	
}
//helper function for height function
int BST::heighthelper(BinNode* node) const
{
	if (node == NULL){ return 0;}
 	return  max(heighthelper(node->left), heighthelper(node->right))+1; 
}


bool BST::remove(const ItemType & item)
{
  removehelper(item, root);
  return 1;
}

int BST::nextright(BinNode* node)
{
   while(node->right!=NULL){ node = node->right;}
   return node->item;
}
//helper function for remove function
void BST::removehelper(const ItemType & item, BinNode* foo)
{
  if(foo !=NULL)
  {
     if(item == foo->item)
     {
        BinNode *temp = foo;
        if(foo->right==NULL)
        {
           foo = foo->left;
           delete temp;
          
        }
      else if (foo->left == NULL)
      {
         foo = foo->right;
         delete temp;
         
      }
      else
      {
         foo->item = nextright(foo->left);
         removehelper(foo->item, foo->left);
      }
     }
   else if (item < foo-> item){ removehelper(item, foo->left);}
   else{removehelper(item,foo->right);}
  }
}

void BST:: destroytree(BinNode *foo)
{
	if(foo != NULL)
	{
	    destroytree(foo -> left);
	    destroytree(foo -> right);
	    delete foo;
	}

}
BST:: ~BST()
{
	destroytree(root);
	cout<<"Destructor called "<<endl;
}



const BST& BST::operator=(const BST & foo) {
	if(this != &foo){    
        this->remove(root->item);
        BinNode *mynewnode = foo.root;
        assignmenthelper(mynewnode);}
    
   	 return *this;
}
//helper function for assignment operator 
void BST::assignmenthelper(BinNode *foo)
{
    this->insert(foo->item);
    if(foo->left != NULL){ assignmenthelper(foo->left);}
       
    else if(foo->right != NULL){assignmenthelper(foo->right);}
        
}


BST::BST(const BST & foo){

	
	copyhelper(foo.root, root);

}
//helper function for copy constructor
void BST::copyhelper(BinNode * foo1, BinNode * &foo2){

	if (foo1 == NULL){
      		foo2 = NULL;
	}
   
   	else{
      		
		foo2 = new BinNode;
      		foo2->item = foo1->item;
      		copyhelper(foo1->left, foo2->left);
      		copyhelper(foo1->right, foo2->right);
   	}

}


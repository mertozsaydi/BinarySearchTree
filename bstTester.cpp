//Mert Ozsaydi B00451123

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "bst.h"

using namespace std;
void fillrandomnumber(int* myarray);
void maketree(int * myarray, BST &footree);
void getinfo( BST &footree);

int main(void)
{	
	//dummy main function program
	cout<<"-------------------Part 1 ----------------"<<endl;
	BST binarytree;
	cout<<"BST IS EMPTY NOW"<<endl;
	cout<<"IS EMPTY? EMTPY 1 ELSE 0: "<<binarytree.empty()<<endl;
	binarytree.insert(2);
	binarytree.insert(7);
	binarytree.insert(13);
	cout<<"2 7 13 ADDED TO THE BST"<<endl;
	cout<<"IS EMPTY? EMTPY 1 ELSE 0: "<<binarytree.empty()<<endl;
	cout<<"-------------------Part 2 ----------------"<<endl;
	
	



	BST footree;//created a new BST
	
	footree.insert(2);// insert an item to the BST
	footree.insert(1);// insert an item to the BST
	footree.insert(3);// insert an item to the BST
	
	
	
	BST b = footree; //copy constructor
	cout<<"Your assigned tree: ";
	b.display(cout);// To display the assigned tree
	cout<<"Your real tree: ";
	footree.display(cout);// To display footree tree
	

	
	
	srand(time(0));//to get different numbers 
	int newarray0[1000];//created an array 
	fillrandomnumber(newarray0);//filled an array with different numbers

	int newarray1[1000];//created an array 
	fillrandomnumber(newarray1);//filled an array with different numbers

	int newarray2[1000];//created an array 
	fillrandomnumber(newarray2);//filled an array with different numbers

	int newarray3[1000];//created an array 
	fillrandomnumber(newarray3);//filled an array with different numbers

	int newarray4[1000];//created an array 
	fillrandomnumber(newarray4);//filled an array with different numbers

	
	BST foo1tree;//created a new BST
	maketree(newarray0,foo1tree);// make a BST with random numbers

	
	getinfo(foo1tree);//to print height and size


	sort(newarray0, newarray0 + 1000);//to sort the array

	cout<<endl<<"------ Array sorted ----"<<endl<<endl;
	BST newfoo1tree;//created a new BST
	maketree(newarray0,newfoo1tree);// make a BST with random numbers
	getinfo(newfoo1tree);//to print height and size
	
	cout<<"------------------------------------------"<<endl;

	return 0;

	//My remove function is not working well.
}
//to fill an array with random number
void fillrandomnumber(int* myarray){
	int num;
	for (int i=0;i<1000;i++){
		
		num=rand() % 1000 + 1;
		
		myarray[i]= num;}
				

}
// make a BST with random numbers
void maketree(int * myarray, BST &footree){
	
	for (int i=0;i<1000;i++){
		footree.insert(myarray[i]);}
}
//to print height and size
void getinfo( BST &footree){
	cout<<"------Three Info------"<<endl;
	cout<<"Height of your tree: "<<footree.height()<<endl;
	cout<<"Size of your tree: "<<footree.size()<<endl;
}

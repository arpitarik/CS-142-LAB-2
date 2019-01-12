#include<iostream>
using namespace std;

class Node{
	public:
	//Data
	int data;
	//Pointer to next Node
	Node* next;
	//Constructor that makes ptr to NULL
	Node(){
		next = NULL;
	}
	
};

class LinkedList{
	public:
	//Head + Nodes inside linked with each other
	
	//Head -> Node type pointer
	Node* head;
	Node* tail;
	
	//Construct
	LinkedList(){
		head = NULL;
		tail = NULL;
	}
	//Circles inside linked with each other
	//Rules how circles will be connected or linked
	
	//insert
	void insert(int value){
		//If 1st node is added
		Node* temp = new Node;
		// Insert value in the node
		temp->data = value;
		// 1st Node only
		if(head==NULL){
			head = temp;
		}
		
		// Any other Node
		else{
			tail->next = temp;
		}
		tail = temp;
		
	}
	
	void insertAt(int pos, int value){
		// Reach the place before the pos
		Node* current = head;
		int i =1;
		while(i<pos-1){
			i++;
			current = current->next;
			if(current==NULL){
				cout << "No such position." << endl;
				return;
			}
		}
		
		//Create a node
		Node* temp = new Node;

		//Storing the data
		temp-> data = value;

		if(pos!=1){
		//moving pointers like magic!
		temp->next = current->next;	
		current->next = temp;
		}
		// Update the code for 1st pos.
		else{temp->next = head;
		head = temp;}
	}

	//Delete at any position
	void deleteAt(int pos){
	
		// Reach the place before the pos
		Node* current = head;
		int m =1;
		while(m<pos-1){
			m++;
			current = current->next;
			
		}

		// Reach the place at the pos
		Node* temp = head;
		int p =1;
		while(p<pos){
			p++;
			temp = temp->next;
			if(temp==NULL){
				cout << "No such position." << endl;
				return;
			}
		}
		//Moving pointers like magic!
		current->next = temp->next;
		delete temp;

	}

	//Deletion of last element
	void delet(){
		//store tail in temp
		Node* temp = tail;
		//Node before tail has to point to NULL
		Node* current = head;
		
		while(current->next != tail){
			current = current->next;
		}
		current->next = NULL;

		//update tail
		tail = current;

		//delete temp
		delete temp;
	}

	//Count the number of items in the list
	void countItems(){
		// Writing a loop to count
		int count = 0;
		Node* temp=head; 
		while(temp != NULL){
			count++;
			temp = temp->next;
			}
		cout << "list re thiba items. = " << count << endl;
	}
	
	//Display
	void display(){
		Node* current = head;
		
		while(current != NULL){
			cout << current->data << "->";
			current = current->next;
		}
		cout << endl;
	}

};

int main(){
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	l1.delet();
	l1.display();
	l1.insertAt(4,5);
	l1.display();
	l1.deleteAt(2);
	l1.display();
	l1.insertAt(2,0);
	l1.display();
	l1.countItems();
return 0;
}

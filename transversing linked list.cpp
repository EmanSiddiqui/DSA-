//Eman Siddiqui CT-25072

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
	Node(int val){
		data=val;
		next=nullptr;
	}
	
};

class Linkedlist{
	
	public:
		Node* head;
	Linkedlist(){
		head=nullptr;
	}
};

int main(){
	
	Node* first= new Node(10);
	Node* second= new Node(20);
	Node* third= new Node(30);

	first->next=second;
	second->next=third;
	
	Linkedlist* list= new Linkedlist();
	
	list->head=first;
	
	Node* temp=list->head;
	
	while(temp!=nullptr){
		cout<<temp->data<<" "<<endl;
		temp=temp->next;
		cout<<temp<<endl;
	}
	
	cout<<head<<endl;
	
}
	


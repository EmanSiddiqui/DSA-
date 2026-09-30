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
int main(){
	
	Node* first= new Node(10);
	Node* second= new Node(20);
	Node* third= new Node(30);

	first->next=second;
	second->next=third;
	
	
	cout<<first->data<<endl;
	cout<<first->next<<endl;
	cout<<second->data<<endl;
	cout<<second->next<<endl;
	cout<<third->data<<endl;
	cout<<third->next<<endl;
	
	return 0;
	
	
}

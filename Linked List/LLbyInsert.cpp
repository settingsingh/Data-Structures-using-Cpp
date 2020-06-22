#include<iostream>
using namespace std;
//Creating Linked list by inserting the nodes
//class for Node that has the data and the next
class Node{
public:
	int data;
	Node * next;
}*first = NULL;


class LinkedList{
public:
	void Insert(int value, int pos){
		Node *t, *p;
		if(pos==0){
			t = new Node;
			t->data = value;
			t->next = first;
			first = t;
		}
		else if(pos>0){
			p=first;
			for(int i=0; i<(pos-1) && p; i++){
				p = p->next;
			}
			if(p){
				t = new Node;
				t->data = value;
				t->next = p->next;
				p->next = t;
			}
		}
	}


	void Display(){
		Node * p=first;
		while(p){
			cout<<p->data<<" ";
			p = p->next;
		}
	}

	int Delete(int key){
		Node *p=first, *q=NULL;
		while(p){
			if(p->data == key){
				if(p==first){
					first = p->next;
					delete p;
					break;
				}
				else{
					q->next = p->next;
					delete p;
					break;
				}
			}
			q = p;
			p = p->next;
		}
		return key;
	}
};


//main function
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	LinkedList ll;
	ll.Insert(78,0);
	ll.Insert(41,1);
	ll.Insert(45,2);
	ll.Insert(87,0);

	ll.Display(); 
	cout<<endl<<ll.Delete(87)<<endl; 
	ll.Display();






	return 0;
}
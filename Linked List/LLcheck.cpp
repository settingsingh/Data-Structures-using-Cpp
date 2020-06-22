#include<iostream>
using namespace std;



//Class for the Node
class Node{
public:
	int data;
	Node * next;
} *first;

//class for singly linked list
class Linkedlist{
// private:
// 	Node *first;

public:
	//Default Constructor
	Linkedlist(){
		first = NULL;
	}

	Linkedlist(int A[], int n){
		Node *t, *last;
		first = new Node;
		first->data = A[0];
		first->next = NULL;
		last = first;

		for(int i=1; i<n; i++){
			t = new Node;
			t->data = A[i];
			t->next = NULL;
			last->next = t;
			last = t;
		}
	}

	//Iterative Display function
	void Display(){
		Node *p = first;
		cout<<"Iterative Display of Linked List:"<<endl;
		while(p){
			if(p->next==NULL)
				cout<<p->data<<endl;
			else
				cout<<p->data<<"->";
			p = p->next;
		}
	}

	//Recursive Display function
	void RDisplay(Node * p){
		if (p != NULL){
			cout<<p->data<<" ";
			RDisplay(p->next);
		}
	}
	//Iterative Length=counting number of nodes in a linked list
	int Length(){
		Node * p = first;
		int i=0;
		while(p){
			i++;
			p=p->next;
		}
		return i;
	}

	//Counting number of nodes recursively
	int Rlength(Node * p){
		if(p==NULL){
			return 0;
		}
		else{
			return Rlength(p->next) + 1;
		}
	}

	//Adding all the data in each nodes iteratively
	int Sum(Node * p){
		int sum = 0;
		while(p){
			sum += p->data;
			p = p->next;
		}

		return sum;
	}

	//Adding all the data in each nodes recursively
	int RSum(Node * p){
		static int sum=0;
		if (p==NULL)
			return 0;
		else{
			sum+=p->data;
			RSum(p->next);
		}
		return sum;
	}

	//Finding the maximum element in the linked list
	int Max(Node * p){
		int max=0;
		while(p){
			if (p->data>max){
				max = p->data;
			}
			p = p->next;
		}
		return max;
	}


	//Finding the maximum element in the linked list recursively
	int RMax(Node * p){
		int x = 0;
		if (p==0)
			return 0; 
		x = RMax(p->next);
		return x > p->data ? x : p->data;
	}


	//Iterative Search function for a key(element/value)
	Node * Search(Node * p, int key){
		while(p){
			if (p->data == key){
				return p;
			}
			p = p->next;
		}
		return NULL;
	}

	//Recursive Search function for a key(element/value)
	Node * RSearch(Node * p, int key){
		if (p==NULL){
			return NULL;
		}
		else if(p->data==key)
			return p;
		return RSearch(p->next, key);
	}

	//Improved Search
	Node * ImprovedSearch(Node * p, int key){
		Node * q=NULL;
		while(p){
			if(p->data == key){
				q->next = p->next;
				p->next = first;
				first = p;
				return p;
			}
			
			q = p;
			p = p->next;
		}
		return NULL;
	}

	//INSERTION of New nodes
	void Insert(int pos, int value){
		Node *t, *p;
		if(pos == 0){
			t = new Node;
			t->data = value;
			t->next = first;
			first = t;
		}
		else if(pos>0){
			p = first;
			for(int i=0; i<(pos-1) && p; i++){
				p=p->next;
			}
			if(p){
				t = new Node;
				t->data = value;
				t->next = p->next;
				p->next = t;
			}
		}
	}

	void isSorted(){
		Node * p=first;
		int x=0;
		while(p){
			if(x<p->data){
				x = p->data;
				p = p->next;
			}
			else{
				cout<<"Not sorted!"<<endl;
				break;
			}
		}
		if (p==NULL)
			cout<<"Sorted Linkedlist"<<endl;
	}

};


//main function
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int A[] = {1,2,3,4,5,6,7,8};
	Node * key;


	//Creating Object of the class
	Linkedlist ll(A, 8);
	//Calling the Display method
	ll.Display();
	//Calling Recursive Display
	cout<<"The Recursive Display function: "<<endl;
	ll.RDisplay(first);
	//Calling Iteratve length method
	cout<<endl<<"Iterative Length of Linked list: "<<ll.Length()<<endl;
	//Calling Recursive length method
	cout<<"Recursive length of the linked list: "<<ll.Rlength(first)<<endl;
	//Calling Iterative Sum
	cout<<"Iterative Sum: "<<ll.Sum(first)<<endl;
	//Calling Recursive Sum
	cout<<"Recursive Sum: "<<ll.RSum(first)<<endl;
	//Calling Maximum Element Iterative
	cout<<"Maximum Element: "<<ll.Max(first)<<endl;
	//Calling Maximum Element Recursive
	cout<<"Maximum Element recursively: "<<ll.RMax(first)<<endl;
	//Calling Search Iterative
	key = ll.Search(first, 6);
	if(key)
		cout<<"Key is Found"<<endl;
	else
		cout<<"Key is not Found"<<endl;
	//Calling Recursive Search
	key = ll.ImprovedSearch(first, 6);
	if(key)
		cout<<"Key is Found"<<endl;
	else
		cout<<"Key is not Found"<<endl;
	ll.Insert(0,95);
	ll.Insert(5,50);
	ll.Display();
	cout<<ll.Rlength(first)<<endl;
	ll.isSorted();






	return 0;
}
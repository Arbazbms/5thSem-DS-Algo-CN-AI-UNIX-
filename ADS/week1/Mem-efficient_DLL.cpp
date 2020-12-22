#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* npx;
  Node(int val) : val(val), npx(NULL) {}
};

Node* XOR(Node* prev, Node* next) {
  return (Node*) ((uintptr_t)prev ^ (uintptr_t)next); 
}

Node* insert_begin(Node* head, int val) {
  if (head==NULL) 
    return new Node(val);
  Node* node = new Node(val);
  head->npx = XOR(head->npx, node);
  node->npx = XOR(NULL, head);
  return node;
}

Node* insert_end(Node* head, int val) {
  if (head==NULL) 
    return new Node(val);
  Node* prev = NULL, *curr = head, *next = XOR(prev, curr->npx);
  while (next) {
    prev = curr;
    curr = next;
    next = XOR(prev, curr->npx);
  }
  next = new Node(val);
  next->npx = XOR(curr, NULL);
  curr->npx = XOR(curr->npx, next);
  return head;
}

void display(Node* curr) {
	Node* prev = NULL;
  while (curr) {
    cout << curr->val << ' ';
    Node* next = XOR(curr->npx, prev);
    prev = curr, curr = next;
  } 
  cout << endl;
}

int main() {
  Node* head = NULL;
  int choice,data;
	while(1)
	{
		cout << "The Choice Are : \n1. Insert at the Begining. \n2. Insert at the End. \n3. Display. \n4. Exit";
		cout << "\nEnter Your Choice : ";
		cin >> choice;
		switch(choice)
		{
			case 1: cout << "Enter the Data : "	;
					cin >> data;
					head = insert_begin(head,data);
					break;
					
			case 2: cout << "Enter the Data : ";
					cin >> data;
					head = insert_end(head, data);
					break;
					
			case 3: if(head == NULL) 		
					{
						cout << "Empty List.!";
						break;
					}
					else 
					{
						display(head);
						break;
					}
					
			case 4: exit(0);
			
			default: cout << "Invalid Choice.!";
		}
	}
	return 0;
}

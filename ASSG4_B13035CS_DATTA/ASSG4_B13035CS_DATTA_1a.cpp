#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node
{
	int data;
	node* prev;
	node* next;
};
int i = 0,c;
void insert(node* h[],int key)
{
	i = key % c;
	node* p = new node;
	p -> data = key;
	p -> prev = NULL;
	p -> next = NULL;
	if(h[i] == NULL)
	{
		h[i] = p;
	}
	else
	{
		p -> next = h[i];
		h[i] -> prev = p;
		h[i] = p;
	}
	cout << i << endl;
}
void search(node* h[],int key)
{
	i = key % c;
	node * temp = h[i];
	while(temp != NULL && temp -> data != key)
	{
		temp = temp -> next;
	}
	if(temp == NULL)
	{
		cout << i << " NOT FOUND\n";
	}
	else{
		cout << i << " FOUND\n";
	}
}
int main()
{
	struct node* h[1000];
	cin >> c;
	int choice,key;
	while(1)
	{
	cin >> choice;
		switch(choice)
		{
			case 1:
					cin >> key;
					insert(h,key);
					break;
			case 2:
					cin >> key;
					search(h,key);
					break;
			case 0:
					exit(1);
			default:
					cout <<"error : invalid choice\n";		
		}	
	}
	return 0;
}
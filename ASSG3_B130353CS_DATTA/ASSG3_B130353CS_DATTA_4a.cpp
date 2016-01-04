#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int noe = 0;
struct node
{
int data;
struct node *next;
}*a;
void create(int ele)
{
    node* temp = a;
	if(temp == NULL)
	{
		node* p = new node;
		p -> data = ele;
		p -> next = NULL;
		a = p;
		temp = p;
	}
	else
	{
		node* p = new node;
        while(temp -> next != NULL)
            temp = temp -> next;
		p -> data = ele;
		p -> next = NULL;
		temp -> next = p;
		temp = p;

	}
   	return;
}
int main()
{
	int n,ele,m;
   	if(!(cin >> n))
	{
			cout << "invalid input\n";
			return 0 ;
	}
	if(n <= 0)
	{
			cout << "array size can not be negative or zero\n";
			return 0 ;
	
	}
	m = n;
	while(n--)
	{
		cin >> ele;
		create(ele);
	}
	node* temp = a;
	while(m--)
	{
		if(temp -> data > 10)
			noe++;
		temp = temp -> next;
	}
	cout << noe << endl;
	return 0;
}
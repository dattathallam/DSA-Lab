#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdlib>
using namespace std;
struct node
{
	struct node *down;
	int data;
	struct node *next;
}*a,*y,*w,*res,*top,*u;
struct	node* m = NULL;
int exist[1000000],inc = 0;
int search(int ele)
{
	for (int i = 0; i < inc; ++i)
	{
		if(exist[i] == ele)
		{
			return 0;
		}
	}
	return 1;
}
void create(int ele)
{
	if(ele <= 0)
	{
		cout << "non negative values are only allowed as nodes\n";
		exit(0);
	}
    node* temp = a;
    if(temp == NULL)
    {
        node* p = new node;
        p -> data = ele;
        p -> next = NULL;
        p -> down = NULL;
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
        p -> down = temp -> next;
        temp = p;

    }
    return;
}
void create2(int ele)
{
	if(ele <= 0)
	{
		cout << "non negative values are only allowed as nodes\n";
		exit(0);
	}
    node* temp = y;
    if(temp == NULL)
    {
        node* p = new node;
        p -> data = ele;
        p -> next = NULL;
        p -> down = NULL;
        y = p;
        temp = p;
    }
    else
    {
        node* p = new node;
        while(temp -> down != NULL)
            temp = temp -> down;
        p -> data = ele;
        p -> next = NULL;
        p -> down = NULL;
        temp -> down = p;
        p -> next = temp -> down;
        temp = p;   
    }
    return;
}
void display(node* q)
{
    node* temp = q;
    while(temp != NULL)
    {
        cout << temp-> data << " ";
        temp = temp -> down;
    }
    cout << endl;
    return;
}
void printList(node *node)
{
    while(node-> down != NULL)
    {
        cout << node -> data << " -> ";
        node = node->down;
    }
    cout << node -> data;
    cout << endl;
}

void check(node *node)
{
    while(node-> down != NULL)
    {
    	if(!(search(node -> data)))
    	{
			cout<< "uniquness proprty violated\n";
			exit(0);
    	}
        exist[inc++] = node->data;
        node = node->down;
    }
       	if(!(search(node -> data)))
    	{
			cout<< "uniquness proprty violated\n";
			exit(0);
    	}
    cout << endl;
}

node* merge( node* a, node* b )
{
    if (a == NULL)
    {
        return b;        
    }
 
    if (b == NULL)
    {
        return a;        
    }
 
    node* res;
    if( a -> data < b -> data )
    {
        res = a;
        res->down = merge( a -> down, b );
    }
    else
    {
        res = b;
        res->down = merge( a, b -> down );
    }
 
    return res;
}
 
node* rec_flat (node* main)
{
    if ( main == NULL || main->next == NULL )
    {
        return main;        
    }
    return merge( main, rec_flat(main->next) );
}

int main()
{
	char c;
	int ele,count = 0;
	while(1)
	{
		count++;
		if(scanf("%d%c",&ele,&c) != 2 || c != ' ')
		{
			create(ele);
			break;
		}
		create(ele);
	}
    m = a;

	for (int i = 0; i < count; ++i)
	{

		y = NULL;
        top = NULL;
		while(1)
		{
			if(scanf("%d%c",&ele,&c) != 2 || c != ' ')
			{
				create2(ele);
                a -> down = y -> down;
				a = a -> next;
				break;
			}
			create2(ele);
		}
    }
    a = m;
    /*
    while(m != NULL)
    {
        cout << m -> data << " ";
        w = m -> down;
        display(w);
        m = m -> next; 
    }
    m = a;
    */
    a = rec_flat(m);
    check(a);
    printList(a);
return 0;
}

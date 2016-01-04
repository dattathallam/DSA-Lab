#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node
{
struct node *previous;
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
        p -> previous = NULL;
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
        p -> previous = NULL;
        temp -> next = p;
        p -> previous = temp -> next;
        temp = p;

    }
    return;
}
void display()
{
    node* temp = a;
    while(temp -> next != NULL)
    {
        cout << temp-> data << " -> ";
        temp = temp -> next;
    }
    cout << temp-> data << endl;
    return;
}

void del()
{
    node* temp = a;
    node* q = NULL;
    while(temp -> next != NULL && (temp -> next) -> next != NULL)
    {

        q = temp -> next;
        temp -> next = q -> next;
        temp = q -> next;
        temp -> previous = q -> previous;
        q -> previous = NULL;
        q -> next = NULL;
        delete(q);
    }
    if(temp -> next != NULL)
    {

    q =  temp -> next ;
    temp -> next = NULL;
    q -> previous = NULL;
    delete(q);        
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
    if(n == 1)
    {
        cout << "invalid input \n";
        return(0);
    }
    m = n;
    while(n--)
    {
        cin >> ele;
        create(ele);
    }
    del();
    display();
    return 0;
}
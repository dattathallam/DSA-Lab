#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node
{
int data;
struct node *next;
}*head = NULL,*tail = NULL;
int n = 0;
void enqueue(int ele)
{
    node* p = new node;
    p -> data = ele;
    p -> next = NULL;
    if(head == NULL && tail == NULL)
    {
        head = p;
        tail = p;
    }
    else
    {
        tail -> next = p;
        tail = p;
    }
}

int dequeue()
{

    if(head == NULL)
    {
        cout << "EMPTY\n";
        return -1;
    }
    node* temp;
    temp = head;
    int q = temp -> data;
    head = head -> next;
    delete(temp);
    return(q); 
}

int peek()
{
    if(head == NULL)
    {
        cout << "EMPTY\n";
        return -1;
    }
    int q = head -> data;
    return(q); 
}
void show()
{
    node* temp = head;
    if(head == NULL)
    {
        cout << "EMPTY\n";
        return;
    }
    else
    {
        while(temp -> next != NULL)
        {
            cout << temp-> data << " ";
            temp = temp -> next;
        }
        cout << temp -> data << endl;
    }
    return;
}
int main()
{
    int num1,num2,j;
    while(1)
    {
        cin >> num1;
        if(num1 == 1)
            cin >> num2;
        switch(num1)
        {
            case 1:
		    if(num2 < 0)
			break;
                    enqueue(num2);
                    break;
            case 2:
                    j = dequeue();
                    if(j == -1)
                        break;
                    else
                        cout << j << endl;
                    break;
            case 3:
                    j = peek();
                    if(j == -1)
                        break;
                    else
                        cout << j << endl;
                    break;
            case 4:
                    show();
                    break;
            case 0:
                    return 0;
            default:
                    cout << "please enter only valid option\n";
        }
    }
    return 0;
}

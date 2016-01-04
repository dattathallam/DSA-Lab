#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node
{
int data;
struct node *next;
}*top;
int n = 0;
void push(int ele)
{
    node* p = new node;
    p -> data = ele;
    p -> next = top;
    top = p;
}

int pop()
{

    if(top == NULL)
    {
        cout << "EMPTY\n";
        return -1;
    }
    node* temp;
    temp = top;
    int q = temp -> data;
    top = top -> next;
    delete(temp);
    return(q); 
}

int peek()
{
    if(top == NULL)
    {
        cout << "EMPTY\n";
        return -1;
    }
    int q = top -> data;
    return(q); 
}
void show()
{
    node* temp = top;
    if(top == NULL)
    {
        cout << "EMPTY\n";
        return;
    }
    else
    {
        while(temp != NULL)
        {
            cout << temp-> data << " ";
            temp = temp -> next;
        }
    }
    cout << endl;
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
                    push(num2);
                    break;
            case 2:
                    j = pop();
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

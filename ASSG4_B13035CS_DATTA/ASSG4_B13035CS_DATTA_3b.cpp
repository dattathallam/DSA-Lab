#include <iostream>
#include <cstdio>
#include <cstring>
//#define deb std::cout<<__LINE__<<"\n"
//#define val(x) std::cout<<#x<<"="<<x<<"\n"
using namespace std;

int counter = 0;
struct BST
{
    char data;
    BST* left;
    BST* right;
    BST* parent;
}*stk[10000000];

struct node
{
    struct BST *bst;
    struct node *next;
}*top = NULL;

void push_stack(BST* ele)
{
    if(top == NULL)
    {
        node* temp = new node;
        temp -> bst = ele;
        temp -> next = NULL;
        top = temp; 
    }
    else
    {
        node* temp = new node;
        temp -> bst = ele;
        temp -> next = top;
        top = temp;
    }
}

BST* pop_stack()
{
   if(top == NULL)
   {
        cout <<"EMPTY\n";
        return NULL;
   }
   else
   {
        node* temp = top;
        top = top -> next;
        temp -> next = NULL;
        BST* temp2 = temp -> bst;
        delete temp;
        return temp2;
   }
}
void push(char value)
{
    BST* p = new BST;
    p -> data = value;
    p -> left = NULL;
    p -> right = NULL;
    p -> parent = NULL;
    stk[counter] = p;
    counter++;
    //val(stk[counter-1] -> data);
}
void inorder(BST* d)
{
    if(d == NULL)
    {
         return;
    }   
    BST* present = d;
    top = NULL;
    while(1)
    {
        if(present != NULL)
        {
            push_stack(present);
            present = present -> left;
        }
        else
        {
            if(top != NULL)
            {
                present = pop_stack();
                cout << present -> data;
                present = present -> right;
            }
            else
                return;
        }
    }
}

void preorder(BST* d)
{
    if(d == NULL)
    {
         return;
    }   
    BST* temp;
    top = NULL;
    BST* present = d;
    push_stack(present);
    while(top != NULL)
    {
        temp = pop_stack();
        cout << temp -> data;
        if(temp -> right != NULL)
            push_stack(temp -> right);
        if(temp -> left != NULL)
            push_stack(temp -> left);
    }
}
BST* function()
{
    if(top == NULL)
        return NULL;
    else
        return top -> bst;
}
void postorder(BST* d)
{   
    if(d == NULL)
    {
        return;
    }   
    BST* temp;
    top = NULL;
    BST* present = d;
    do
    {
        while(present != NULL)
        {
            if(present -> right != NULL)
            {
                push_stack(present -> right);
            }
            push_stack(present);
            present = present -> left;
        }
        present = pop_stack();
        if(present -> right != NULL && function() == present -> right)
        {
            pop_stack();
            push_stack(present);
            present = present -> right;
        }
        else
        {
            cout << present -> data;
            present = NULL;
        }
    }while(top != NULL);     
}
int main()
{
    BST* ai,*b,*c;
    int len = 0;
    char a[10000];
    cin >> a;
    if(strlen(a) == 0)
    {
        cout << "EMPTY TREE\n";
        return 0;
    }
    while(len < strlen(a))
    {

        if(a[len] == '^' ||a[len] == '*' ||a[len] == '/' ||a[len] == '-' ||a[len] == '+' )
        {
            //val(counter);
            ai = stk[--counter];//deb;
            //val(ai);
            b = stk[--counter];//deb;
            //val(b);
            push(a[len]);//deb;
            c = stk[--counter];//deb;
            //val(c);
            c -> left = b;//deb;
            c -> right = ai;//deb;
            ai -> parent = c;//deb;
            b -> parent = c;//deb;
            stk[counter] = c;//deb;
            counter++;//deb;
        }
        else if(a[len] >= 'a' && a[len] <= 'z')
        {
            push(a[len]);
        }
        else
        {
            cout << "error: Wrong Input\n";
            return  0;
        }
        len++;
    }
    cout << "Inorder: ";
    inorder(stk[0]);
    cout << endl;
    cout << "Preorder: ";
    preorder(stk[0]);
    cout << endl;
    cout << "Postorder: ";
    postorder(stk[0]);
    cout << endl;
    return 0;
}

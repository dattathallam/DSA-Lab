#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node
{
    int root;
    node* left;
    node* right;
};
int arr[100000],value = 0,counter = 1,index = 1,q_inc = 0,m = 0;
struct Queue
{
    node* item;
    Queue* next;
}*head = NULL,*tail = NULL;
struct linkedList
{
    int a;
    linkedList *next;
}*ll[1000];
void inorder(node* tree)
{
    if(tree == NULL)
        return;
    else
    {
        inorder(tree -> left);
        if(tree -> root != -1)
        cout << tree -> root << " ";
        inorder(tree -> right); 
    }
}
void enQueue(node* item)
{
    Queue* p = new Queue;
    p -> item = item;
    p -> next = NULL;
    if(tail == NULL || head == NULL)
    {
        head = p;
    }
    else
    {
        tail -> next = p;
    }
    tail = p;
}
node* deQueue()
{
    node* res;
    Queue* p;
    if(head == NULL || tail == NULL)
        return NULL;
    else
    {
        p = head;
        res = p -> item;
        head = head -> next;
        free(p);
    }
    return res;
}
void print(node* tree)
{
    linkedList* t;
    node* temp;
    temp = tree;
    while(temp != NULL)
    {
    if(temp -> root != -1)
    {
        if(counter == pow(2,index)-1)
        {
           // cout<< temp ->root << " ";
            if(ll[m] == NULL)
            {
                linkedList* p = new linkedList;
                p -> a = temp -> root;
                p -> next = NULL;
                ll[m] = p;
            }
            else
            {
                t = ll[m];
                linkedList* p = new linkedList;
                p -> a = temp -> root;
                p -> next = NULL;
                while(t -> next !=  NULL)
                {
                    t = t -> next;
                }
                t -> next = p;
            }
        }
        else
        {
            //cout << temp->root << " -> ";
            if(ll[m] == NULL)
            {
                linkedList* p = new linkedList;
                p -> a = temp -> root;
                p -> next = NULL;
                ll[m] = p;
            }
            else
            {
                t = ll[m];
                linkedList* p = new linkedList;
                p -> a = temp -> root;
                p -> next = NULL;
                while(t -> next!= NULL)
                {
                    t = t -> next;
                }
                t -> next= p;
            }
        }
    }
    counter++; 
    if(counter == pow(2,index))
    {
        m++;
        index++;
        //cout << endl;
    }
    if(temp -> left)
      enQueue(temp -> left);
 
    if(temp -> right)
      enQueue(temp -> right);
    temp = deQueue();
    }
}
node* LevelInsert(int iter)
{
    node* tree;
    int left,right;
    left = 2*iter+1;
    right = 2*iter+2;
    if(iter < value)
    {
        if(arr[iter] != -1)
        {
            node* p = new node;
            p -> left = NULL;
            p -> right = NULL;
            p -> root = arr[iter];
            tree = p;
            tree -> left = LevelInsert(left);
            tree -> right = LevelInsert(right);
        }
        else
        {
            node* p = new node;
            p -> left = NULL;
            p -> right = NULL;
            p -> root = arr[iter];
            tree = p;
        }

    }
    else
    {
        tree = NULL;
    }
    return tree;
}
int main()
{
    int ele;
    cin >> value;
    char ch = ' ';
    value = 0;
    while(ch != '\n')
    {
        if(scanf("%d%c",&ele,&ch)== 2)
        {
            arr[value++] = ele;
            if(ele != -1 && ele <= 0)
            {
                cout << "negative numbers are not allowed\n";
                return 0;
            }
        }
        else
        {
            cout << "EMPTY TREE\n";
            break;
        }
    }
    int o = 0,e = 0 ;
    for (int i = 0; i < value; ++i)
    {
        e = 0;
        o = arr[i];
        if(o == -1)
            continue;
        for(int j =0; j < value;j++)
        {
            if(arr[j] == o)
                e++;
        }
        if(e > 1)
        {
            cout << "Unique property violated\n";
            return 0;
        }
    }
    node* tree = LevelInsert(0);
    cout << "Inorder Traversal : ";
    inorder(tree);
    cout << endl;
    print(tree);
       
    for (int i = 0; i < m; ++i)
    {
        linkedList* temp;
        temp = ll[i];
        while(temp != NULL && temp -> next != NULL)
        {
            cout << temp -> a  << "-> ";
            temp = temp -> next;
        }
        if(temp != NULL)
        {
            cout << temp -> a << endl;
        }
    }
    return 0;
}
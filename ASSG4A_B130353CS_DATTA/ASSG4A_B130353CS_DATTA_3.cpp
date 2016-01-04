#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node
{
    int root;
    node* left;
    node* right;
    node* parent;
}*m = NULL;
int counter = 0;
void insert(node* &tree,int value)
{

    if(tree == NULL)
    {
        node* p = new node;
        p -> root = value;
        p -> left = NULL;
        p -> right = NULL;
        p -> parent = m;
        tree = p;
    }
    else
    {
        if(tree -> root <= value)
        {
            m = tree;
            insert(tree -> right,value);
        }
        else
        {
            m = tree;
            insert(tree -> left,value);
        }
    }
}
void preorder(node* tree)
{
    if(tree == NULL)
    {
        cout << " ( ) ";
        return;
    }

    else
    {
        cout << "( ";
        cout << tree -> root << " ";
        preorder(tree -> left);
        preorder(tree -> right);
        cout << " )";
    }
}
int main()
{
    int value,ele;
    char ch = ' ';
    node* tree = NULL;
    while(ch != '\n')
    {
        if(scanf("%d%c",&ele,&ch)== 2)
            insert(tree,ele);
        else
        {
            cout << "EMPTY TREE\n";
            break;
        }

    }
    preorder(tree);
    cout << endl;
    return 0;
}

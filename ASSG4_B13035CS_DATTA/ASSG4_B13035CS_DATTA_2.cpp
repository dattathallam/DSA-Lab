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
void search(node* tree,int value)
{
    node* temp = tree;
    if(temp == NULL )
    {
        cout << "NOT FOUND\n";
        return;
    }
    else{
        if(temp -> root == value)
        {
            cout << "FOUND\n";
            return;
        }
        else if(temp -> root < value)
        {
            search(temp -> right,value);
        }
        else
        {
            search(temp -> left,value);
        }
    }
}
void inorder(node* tree)
{
    if(tree == NULL)
        return;
    else
    {
        inorder(tree -> left);
        cout << tree -> root << " ";
        inorder(tree -> right);
    }

}
void postorder(node* tree)
{
    if(tree == NULL)
        return;
    else
    {
        postorder(tree -> left);
        postorder(tree -> right);
        cout << tree -> root << " ";
    }

}
void preorder(node* tree)
{
    if(tree == NULL)
        return;
    else
    {
        cout << tree -> root << " ";
        preorder(tree -> left);
        preorder(tree -> right);
    }

}
int  minimum(node* tree)
{
    while(tree != NULL && tree -> left != NULL)
    {
        tree = tree -> left;
    }
    if(tree == NULL)
    {
        return -1;
    }
    else
    {
        return tree -> root;
    }
}
node* min(node* tree)
{
    while(tree != NULL && tree -> left != NULL)
    {
        tree = tree -> left;
    }
    if(tree == NULL)
    {
        return NULL;
    }
    else
    {
        return tree ;
    }
}
int maximum (node* tree)
{
    while(tree != NULL && tree -> right != NULL)
    {
        tree = tree -> right;
    }
    if(tree == NULL)
    {
        return -1;
    }

    else
    {
        return tree -> root;
    }

}
node* getNode(node* tree,int value)
{
	node* temp = tree;
    if(temp == NULL )
    {
        return NULL;
    }
    else{
        if(temp -> root == value)
        {
            return temp;
        }
        else if(temp -> root < value)
        {

            getNode(temp -> right,value);
        }
        else
        {
            getNode(temp -> left,value);
        }

    }
}
void predecessor(node* tree,int element)
{
	char k;
	if(tree == NULL)
	{
		cout <<"NOT FOUND\n";
		return;
	}
	node* temp = getNode(tree,element);
	if(temp == NULL)
    {
        cout << "NOT FOUND\n";
        return;
    }
	int v = minimum(tree);
	if( v == temp -> root )
    {
        cout << "NIL\n";
        return;
    }
	if(temp -> left != NULL)
	{
	    v = maximum(temp -> left);
	    cout << v << endl;
	    return;
	}
	while(temp -> root  >= element)
	{
		k = temp -> root;
		temp = temp -> parent;
		if(temp -> right != NULL && temp -> right -> root == k)
		{
			cout << temp -> root << endl;
			return;
		}
	}
}
void successor(node* tree,int element)
{
	char k;
	if(tree == NULL)
	{
		cout <<"NOT FOUND\n";
		return;
	}
	node* temp = getNode(tree,element);
	if(temp == NULL)
    {
        cout << "NOT FOUND\n";
        return;
    }
	int v = maximum(tree);
	if( v == temp -> root )
    {
        cout << "NIL\n";
        return;
    }
	if(temp -> right != NULL)
	{
	    v = minimum(temp -> right);
	    cout << v << endl;
	    return;
	}
	int counter = 0;
	while(temp -> root  <= element)
	{
		k = temp -> root;
		temp = temp -> parent;
		if(temp -> left != NULL && temp -> left -> root == k)
		{
			cout << temp -> root << endl;
			return;
		}
	}
}
void parent(node* tree,int ele)
{
    node* temp = getNode(tree,ele);
    if(temp -> parent == NULL)
    {
        cout <<"NULL";
        return;
    }

    temp = temp -> parent;
    cout << temp -> root;
    return;
}
node* Delete(node *tree, int value) 
{
	if(tree == NULL)
    {
        return NULL;
    } 
	else if (tree->root < value) 
    {
        tree->right = Delete(tree->right,value);
    }
    else if(tree->root > value)
    {
        tree->left = Delete(tree->left,value);  
    }
		else
        {
            if(tree->left == NULL && tree->right == NULL)
            {
                counter++;
                free(tree) ;
                tree = NULL;
            }
            else if(tree->left == NULL)
            {
                counter++;

                node *temp = tree;
                tree = tree->right;
                tree -> parent = temp -> parent;
                free(temp);
            }
            else if(tree->right == NULL)
            {
                counter++;

                node *temp = tree;
                tree = tree->left;
                tree -> parent = temp -> parent;
                free(temp);
            }
            else
            {
                counter++;

                node *temp = min(tree->right);
                tree->root = temp->root;
                tree->right = Delete(tree->right,temp->root);
            }
	   }
	return tree;
}
int main()
{
    int value,choice,ele;
    node* tree = NULL;
    node* temp ;
    while(1)
    {
        cin >> choice;
        switch(choice)
        {
        case 1:
                cin >> value;
                if(value < 0)
                {
                    cout << "Negative Not Allowed\n";
                    break;
                }
                insert(tree,value);
                break;
        case 2:
                cin >> value;
                if(value < 0)
                {
                    cout << "Negative Not Allowed\n";
                    break;
                }
                search(tree,value);
                break;
        case 3:
                ele = minimum(tree);
                if(ele == -1)
                    cout << "NIL\n";
                else
                {
                    cout << ele;
                    cout << endl;
                }

                break;
        case 4:
                ele = maximum(tree);
                if(ele == -1)
                    cout << "NIL\n";
                else
                {
                    cout << ele;
                    cout << endl;
                }
                break;
        case 5:
                cin >> ele;
                if(ele < 0)
                {
                    cout << "Negative Not Allowed\n";
                    break;
                }
                predecessor(tree,ele);
                break;
        case 6:
                cin >> ele;
                if(ele < 0)
                {
                    cout << "Negative Not Allowed\n";
                    break;
                }
                successor(tree,ele);
                break;
        case 7:
                cin >> ele;
                if(ele < 0)
                {
                    cout << "Negative Not Allowed\n";
                    break;
                }
                if(tree == NULL)
                {
                    cout << "EMPTY TREE\n";
                    break;
                }
                counter = 0;
                temp = Delete(tree,ele);
                tree = temp;
                break;
        case 8:
                if(tree == NULL)
                {
                    cout << "EMPTY TREE\n";
                    break;
                }
                inorder(tree);
                cout << endl;
                break;
        case 9:
                if(tree == NULL)
                {
                    cout << "EMPTY TREE\n";
                    break;
                }
                preorder(tree);
                cout << endl;
                break;
        case 10:
                if(tree == NULL)
                {
                    cout << "EMPTY TREE\n";
                    break;
                }
                postorder(tree);
                cout << endl;
                break;
        case 0:
                exit(0);
        default:
                cout << "INVALID INPUT\n";
        }
    }
    return 0;
}

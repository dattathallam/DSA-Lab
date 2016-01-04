#include <iostream>
#include <cstdio>
#include <cstring>
#define deb std::cout<<__LINE__<<"\n"
#define val(x) std::cout<<#x<<"="<<x<<"\n"
using namespace std;

int counter = 0;
struct BST
{
	char data;
	BST* left;
	BST* right;
	BST* parent;
}*stk[10000000];

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
		return;
	else
	{
	    if(d -> left != NULL)
        {
            cout << "(";
            inorder(d -> left);
        }
		cout << d -> data;
		if(d -> right != NULL)
        {
            inorder(d -> right);
             cout << ")";
        }
	}
}

void preorder(BST* d)
{
	if(d == NULL)
		return;
	else
	{
		cout << d -> data;
		preorder(d -> left);
		preorder(d -> right);
	}
}
void postorder(BST* d)
{
	if(d == NULL)
		return;
	else
	{
		postorder(d -> left);
		postorder(d -> right);
		cout << d -> data;

	}
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

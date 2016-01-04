#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;
struct node
{
    int root;
    node* left;
    node* right;
};
int arr[100000],value = 0,counter = 1,index = 1,q_inc = 0,m = 0;
int least = INT_MIN,highest = INT_MAX,maximum = 0;
int correct = 0;
int min1,max1,maxSize;
int do1 = 0;

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

int large(node* item)
{
  if(item == NULL)
  {
     do1 = 1; 
     return 0;
  }
  int min = INT_MAX,lf = 0,rf= 0,ls, rs;
  max1 = INT_MIN;
  ls = large(item->left);
  if (do1 == 1 && item->root > max1)
  {
        lf = 1;        
  }
  min = min1;
  min1 =  INT_MAX;
  rs = large(item->right);
  if (do1 == 1 && item->root < min1)
  {
    rf = 1;
  }   
  if (min < min1)
  {
     min1 = min;        
  }
  if (item->root < min1)
  {
    min1 = item->root;
  }   
  if (item->root > max1)
  {
    max1 = item->root;
  }   
  if(lf && rf)
  {
    if (ls + rs + 1 > maxSize)
    {
        maxSize = ls + rs + 1;
    }    
    return ls + rs + 1;
  }
  else
  {
     do1 = 0; 
     return 0;
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
            tree = NULL;
        }

    }
    else
    {
        tree = NULL;
        bool correct = 0;
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
    node* tree = LevelInsert(0);
    cout << "Inorder Traversal : ";
    inorder(tree);
    cout << endl;
    least = -9999999;
    highest = 9999999;
    maximum = 0;
    min1 = -9999999;
    max1 = 9999999;
    maxSize = 0;
    do1 = 0;
    int output = large(tree);
    cout << "Maximum size of BST : " ;
    cout << maxSize;
    cout << endl;
    return 0;
}
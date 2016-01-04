#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
struct node
{
char data;
struct node *next;
}*top,*iter;

struct finale
{
    struct finale *child;
    int data1;
    struct finale *next1;
}*lll;

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
int c,array[100000000],incrementer = 0,f = 0;

void push(char ele)
{
    node* p = new node;
    p -> data = ele;
    p -> next = top;
    top = p;
}

char pop()
{

    if(top == NULL)
    {
        cout << "EMPTY\n";
        return -1;
    }
    node* temp;
    temp = top;
    char q = temp -> data;
    top = top -> next;
    return(q); 
}

void display(finale* b)
{
    finale* temp = b;
    if(b == NULL)
    {
        cout << "EMPTY\n";
        return;
    }
    else
    {
        while(temp != NULL)
        {
            cout << temp-> data1 << " " ;
            temp = temp -> next1;
        }
    }
    cout << endl;
    return;
}

struct finale* make()
{
    finale *y = NULL,*m = NULL,*branch = NULL;
    while(f--)
    {
        if(c == -100)
        {
            c = array[incrementer++];
            m = make();
            y -> child = m;
        }
        if(c == -200)
        {
            c = array[incrementer++];
            return branch;
        }

    if(y == NULL)
    {
        finale* p = new finale;
        p -> data1 = c;
        p -> next1 = NULL;
        p -> child = NULL;
        branch = p;
        y = p;
    }
    else
    {
        finale* p = new finale;
        while(y -> next1 != NULL)
            y = y -> next1;
        p -> next1 = NULL;
        p -> child = NULL;
        p -> data1 = c;
        y -> next1 = p;
        y = p;
    }
    c = array[incrementer++];
    }
}
 
void flat_List(finale *main)
{
    if (main == NULL)
    {
       return;        
    }

    finale *t,*tail = main,*x = main;
    while (tail->next1 != NULL)
    {
        tail = tail->next1;        
    }
    while (x != NULL)
    {
        if (x->child)
        {
            tail->next1 = x->child; 
            t = x -> child;
            while (t -> next1 != NULL)
            {
                t = t -> next1;
            }
            tail = t;
        }
        x = x->next1;
    }
}

void show( finale *main)
{
    while (main -> next1 != NULL) 
    {
        cout << main -> data1 << " -> ";
        main = main->next1;
    }
    cout << main -> data1;
    cout << endl;
}

void check(finale *n)
{
    while(n-> next1 != NULL)
    {
    	if(!(search(n -> data1)))
    	{
			cout<< "uniquness proprty violated\n";
			exit(0);
    	}
        exist[inc++] = n->data1;
        n = n->next1;
    }
       	if(!(search(n -> data1)))
    	{
			cout<< "uniquness proprty violated\n";
			exit(0);
    	}
    cout << endl;
}
int main()
{
    int i = 0,k = 0;
    char l,s[1000],w[100];
    gets(s);
    int len = strlen(s),u = len,max=0;
    while(len--)
    {
        push(s[len]);
    }
    iter = top;
    int ele[1000][1000],count[1000]={0};
    while(u--)
    {
        l = pop();
        
		if(l == '-')
		{
			cout << "negative numbers shouldnot be given\n";
			exit(0);
		}
        if(l == '(')
        {
            i++;
            array[f] = -100;
            f++;
            if(i > max)
                max = i;
            continue;            
        }
        if(l == ')')
        {
            i--;
            array[f] = -200;
            f++;
            continue;
        }
        if(l != ' '&& l != '(' && l != ')')
        {
            k = 0;
            while(l != ' '&& l != '(' && l != ')')
            {
                w[k] = l;
                k++;
                l = pop();
                u--;
            }
            w[k] = '\0';
            ele[i][count[i]] = atoi(w);
            array[f] = atoi(w);
            f++;
            count[i]++;
        }
    }
    top = iter;
    int t = f;
    c = array[incrementer++];
    while(f--)
    {
        if(c == -100)
        {
            c = array[incrementer++];
            lll = make();
        }
    }
    flat_List(lll);
    check(lll);
    show(lll);
 
    return 0;
}

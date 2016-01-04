#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;
int heap_length ,n;
int a[10000],priority[10000];
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i+1;
}
int parent(int i)
{
    return floor(i/2);
}
void min_heapify(int priority[],int i)
{
    int smallest;
    int l = left(i);
    int r = right(i);
    if((l <= heap_length) && (priority[l] < priority[i]))
        smallest = l;
    else
        smallest = i;
    if(r <= heap_length && (priority[r] < priority[smallest]))
        smallest = r;
    if(smallest != i)
    {
        swap(priority[i],priority[smallest]);
        swap(a[i],a[smallest]);
        min_heapify(priority,smallest);
    }
}
void build_min_heap(int priority[],int n)
{
    heap_length = n;
    for (int i = floor(n/2); i >= 1; i--)
    {
        min_heapify(priority,i);
    }
}

void insert(int priority[],int num2,int num3)
{
    n++;
    priority[n] = num3;
    a[n] = num2;
    build_min_heap(priority,n);
}
int remove(int priority[])
{
    if(n < 1)
        cout << "EMPTY\n";
    int c = priority[1],d = a[1];
    if(n > 0)
    {
        for (int i = 1; i < n; ++i)
        {
            priority[i] = priority[i+1];
            a[i] = a[i+1];
        }
        n--;
        build_min_heap(priority,n);
        cout << d << " ";
        return c;      
    }
    else
        return -1;
}
int peek(int priority[])
{
    if(n < 1)
    {
        cout << "EMPTY\n";
        return -1;
    }
    else
    {
        cout << a[1] << " ";
        return priority[1];

    }
}
void increase_priority(int priority[],int num2,int num3)
{
    int i;
    for (i = 1; i <= n; ++i)
    {
        if(a[i] == num2)
            break;
    }
    priority[i] = num3;
    build_min_heap(priority,n);
}
int main()
{
    int num1,num2,j,num3;
    while(1)
    {
        cin >> num1;
        if(num1 == 1 || num1 == 4)
        {
            cin >> num2;
            cin >> num3;            
        }
        switch(num1)
        {
            case 1:
                    insert(priority,num2,num3);
                    break;
            case 2:
                    j = remove(priority);
                    if(j == -1)
                        break;
                    else
                        cout << "("<<j<<")" << endl;
                    break;
            case 3:
                    j = peek(priority);
                    if(j == -1)
                        break;
                    else
                        cout << "("<<j<<")" << endl;
                    break;
            case 4:
                    increase_priority(priority,num2,num3);
                    break;
            case 0:
                    return 0;
            default:
                    cout << "please enter only valid option\n";
        }

    }
    return 0;
}

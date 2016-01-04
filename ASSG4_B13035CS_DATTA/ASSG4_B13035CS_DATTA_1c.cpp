#include <iostream>
#include <cstdlib>
#define NIL 99999
using namespace std;
int c,count = 0;
int hashfunction(int i,int key)
{
    return ((key%c)+ i*i)%c;
}
void insert(int* h,int key)
{
    int index,i = 0;
    index = hashfunction(i,key);
    while(h[index]!= NIL && i < c)
    {
        cout << index << " ";
        i++;
        index = hashfunction(i,key);
    }
    if(i == c)
    {
        cout << "FULL\n";
        return;
    }
    else
    {
            h[index] = key;
    }
    cout << index << "\n";
    count++;
}
void search(int* h,int key)
{
    int index,i = 0;
    index = hashfunction(i,key);
    while(h[index]!= NIL && h[index]!= key && i < c)
    {
        cout << index << " ";
        i++;
        index = hashfunction(i,key);
    }
    if(i == c || h[index] == NIL)
    {
        cout << index << " ";
        cout << "NOT FOUND\n";
        return;
    }
    else
    {
        cout << index << " ";
        cout << "FOUND\n";
    }
}
int main()
{
    int choice,key;
    cin >> c;
    int *h = new int[c];
    for(int i=0;i<c;i++)
    h[i]=NIL;
    while(1)
    {
        cin >> choice;
        switch(choice)
        {
        case 1:
            cin >> key;
            insert(h,key);
            break;
        case 2:
            cin >> key;
            search(h,key);
            break;
        case 0:
            return 0;
        default:
            cout << "error: invalid choice\n";
            exit(1);
        }
    }
    delete []h;
    return 0;
}

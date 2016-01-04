#include <iostream>
#include <cstdlib>
using namespace std;
int a[10000],high = -1,size;
void push(int a[],int ele)
{
    if(high == size-1)
    {
        cout << "STACKOVERFLOW\n";
        return ;        
    }
    high++;
    a[high] = ele;
}
int pop(int a[])
{
    if(high == -1)
    {
        cout << "EMPTY\n";
        return -1;
    }
    else
    {
        high--;
        return a[high+1];
    }
}
int  peek(int a[])
{
    if(high == -1)
    {
        cout << "EMPTY\n";
        return -1;
    }
    else
    {
        return a[high];
    }
}
void show(int a[])
{
    if(high == -1)
    {
        cout << "EMPTY\n";
        return;
    }
    else
    {
        for(int i=high;i>=0;i--)
            cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int num1,num2,j;
    if(!(cin >> size))
    {
            cout << "invalid input\n";
            return 0 ;
    }
    if(size <= 0)
    {
            cout << "array size can not be negative or zero\n";
            return 0 ;
    
    }
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
                    push(a,num2);
                    break;
            case 2:
                    j = pop(a);
                    if(j == -1)
                        break;
                    else
                        cout << j << endl;
                    break;
            case 3:
                    j = peek(a);
                    if(j == -1)
                        break;
                    else
                        cout << j << endl;
                    break;
            case 4:
                    show(a);
                    break;
            case 0:
                    return 0;
            default:
                    cout << "please enter only valid option\n";
        }

    }
    return 0;
}

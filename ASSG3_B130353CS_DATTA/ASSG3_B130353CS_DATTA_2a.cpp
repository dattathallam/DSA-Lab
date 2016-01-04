#include <iostream>
#include <cstdlib>
using namespace std;
int head= 0 , tail = 0,size,noe = 0;
void enqueue(int a[],int ele)
{
	if(noe == size-1)
	{
		cout << "OVERFLOW\n";
		return;
	}
	noe++;
	if(tail == size-1 && noe <= size)
	{
		a[tail] = ele;
		tail = 0;
	}
	else
	{
		tail++;
		a[tail- 1] = ele;
	}
	
}
int dequeue(int a[])
{
	if(noe == 0)
	{
		cout << "EMPTY\n";
		return -1;
	}
	noe--;
	if(head == size-1)
	{
		head = 0;
		return a[size -1];
	}
	else
	{
		head++;
		return a[head-1];		
	}

}
int peek(int a[])
{
	if(noe == 0)
	{
		cout << "EMPTY\n";
		return -1;
	}
	return a[head];	
}
void show(int a[])
{
	int h = head;
    if(noe == 0)
    {
        cout << "EMPTY\n";
        return;
    }
    else
    {
        for(int i=0;i < noe ;i++)
        {
        	cout << a[h]<< " ";
        	if(h == size-1)
        		h = 0;
	        else
	        	h++;
        }
    }
    cout << endl;
}
int main()
{
    int a[100],num1,num2,j;
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
    if(size >= 100)
    {
    	cout << "invalid input\n";
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
                    enqueue(a,num2);
                    break;
            case 2:
                    j = dequeue(a);
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

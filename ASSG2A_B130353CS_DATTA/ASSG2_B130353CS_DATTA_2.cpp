#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
int a[10000],n,c,b;
int partition(int a[],int p,int r)
{
	int x,j,temp;
	x = a[p];
	temp = a[r];
	a[r] = a[p];
	a[p] = temp ;
	j = p-1;
	for (int i = p; i <= r-1; ++i)
	{
		if(a[i] <= x)
		{
			j++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[j+1];
	a[j+1] = a[r];
	a[r] = temp;
	return j+1;
}

int select(int a[],int p,int r,int i)
{
	int k ,q;
	if(p == r)
		return a[p];
	q = partition(a,p,r);
	
	k = q-p+1;
	if(i == k)
		return a[q];
	else if(i < k)
		return select(a,p,q-1,i);
	else
		return select(a,q+1,r,i-k);
}

void ins(int a[],int x,int y)
{
	int key,i;
	if(y-x+1 >= 5)
	{
		for (int j = x+1; j <= y-x+1 ; ++j)
		{
			key = a[j];
			i = j -1;
			while(i > x-1 && a[i] > key)
			{
				a[i+1] = a[i];
				i--;
			}
			a[i+1] = key;
		}
	}
	else
	for (int j = x+1; j <= y-x+1+(b*5) ; ++j)
	{
		key = a[j];
		i = j -1;
		while(i > x-1 && a[i] > key)
		{
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}

void five(int a[],int n)
{
	int i = 1,count = 1;
	c=n%5;
	//cout << " c: " << c << endl;
	b=n/5;
	for ( i = 1; i <= b*5; i= i+5,count++)
	{
		//cout << " between : " << i << " and " << i+4 << endl;
		ins(a,i,i+4);
		//cout<<"swap "<<a[i+2] << " with " << a[count]<<endl;
		swap(a[i+2],a[count]);
	}
	if(c > 0)
	{
		//cout << " between : " << i << " and " << i+c-1 << endl;
		ins(a,i,i+c-1);
		if(c % 2 == 0)
		{
			swap(a[i+c/2-1],a[count]);
		}
		else
			swap(a[i+c/2],a[count]);
		//cout << " i am here \n" << endl;
		
	//	cout<<b+1<<endl;
		//for(int i=1;i<=b+1;i++)
		//	cout<<a[i]<<' ';
		//cout<<'\n';
		select(a,1,b+1,(b)/2+1);
		
		
	}
	else
	{
		select(a,1,b,b/2);
		swap(a[b/2],a[1]);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n ; ++i)
	{
		cin >> a[i];
	}
	five(a,n);
	if(n%2)
    {
		int k = select(a,1,n,(n+1)/2);
		cout << "Median :" << k << endl;
	}
	else
	{
		int m1=select(a,1,n,(n)/2+1);
		int m2=select(a,1,n,(n)/2);
		cout << "Meidan :" << (float)(m1+m2)/2.0 << endl;
	}
	return 0;
}

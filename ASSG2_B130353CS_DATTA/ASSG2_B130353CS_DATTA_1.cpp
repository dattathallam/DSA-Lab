#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
int arr[1000000],n;
int linear(int a[],int k,int index)
{
	if (index == n)
		return -1;
	if (a[index] == k)
		return index;
	else
		linear(a,k,++index);
}
int main()
{
	int  j;
	char term;
	if(!(cin >> n))
	{
			cout << "invalid input\n";
			return 0 ;
	}
	if(n <= 0)
	{
			cout << "array size can not be negative or zero\n";
			return 0 ;
	
	}
	for (int i = 0; i < n-1; ++i)
	{
		if(scanf("%d%c",&arr[i],&term) != 2 || term == ' ')
		{
			cout <<"invalid input \n";
			return 0;
		}
	}
	cin >> arr[n-1];
	cin >> j;
	clock_t t;
	t = clock();
	int result = linear(arr,j,0);
	cout << "the element is found at index : " << result << endl;
	t = clock() - t;
	cout << "Running time : " << ((float)t)/CLOCKS_PER_SEC << "seconds." << endl;
	return 0;
}
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;
int arr[100000000];
int transition_search(int a[],int p,int q)
{
	int mid;

	if(p > q)
		return -1;

		mid = floor((p+q)/2);
		if(a[mid] > a[mid+1])
			return mid;
		else 
		{
			if(a[p] > a[mid])
				transition_search(a,p,mid-1);
			else
				transition_search(a,mid+1,q);
		}
	
}
int binary_search(int a[],int p,int q,int k)
{
	int mid;

	if(p > q)
		return -1;

		mid = floor((p+q)/2);
		if(k == a[mid])
			return mid;
		else 
		{
			if(k <= a[mid])
				binary_search(a,p,mid-1,k);
			else
				binary_search(a,mid+1,q,k);
		}
	
}
int main()
{
	int d,k,n;
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
	cin >> k;
	clock_t t;
	t = clock();
	int index = transition_search(arr,1,n);
//	cout << "the transition occurs at element " << index+1 << endl;
	if(arr[0] <= k)
		d = binary_search(arr,1,index,k);
	else
		d = binary_search(arr,index+1,n,k);
	t = clock() - t;
	cout <<  "the element is found at index : " << d << endl;
	printf ("Running time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
	
	return 0;

}
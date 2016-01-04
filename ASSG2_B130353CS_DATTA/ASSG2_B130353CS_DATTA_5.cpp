#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
int arr[1000000],n;
int partition(int a[],int p,int r)
{
	int x,j,temp;
	x = a[r];
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
void quick_sort(int a[],int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}
int main()
{
	int n;
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
	for (int i = 1; i <= n-1; ++i)
	{
		if(scanf("%d%c",&arr[i],&term) != 2 || term == ' ')
		{
			cout <<"invalid input \n";
			return 0;
		}
	}
	cin >> arr[n];
	clock_t t;
	t = clock();
	quick_sort(arr,1,n);
	t = clock() - t;
	for (int i = 1; i <= n; ++i)
	{
		cout <<  arr[i] << "\n" ;
	}
	cout << "Running time : " << ((float)t)/CLOCKS_PER_SEC << " seconds." << endl;

	return 0;

}
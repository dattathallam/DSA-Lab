#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;
int arr[100000000],n;
void merge(int a[100],int p,int q,int r)
{
	int i,j,l[100],ri[100];
	int n1 = q-p+1;
	int n2 = r-q;
	for(i=1;i <= n1 ;i++)
	{
		l[i] = a[p+i-1];
	}
	l[i] = INT_MAX;
	for(j=1;j <= n2 ;j++)
	{
		ri[j] = a[q+j];
	}
	ri[j] = INT_MAX;

	i = 1;
	j = 1;
	int k;
	for ( k = p; k <= r ; k++)
	{
		if(l[i] <= ri[j])
		{
			a[k] = l[i];
			i++;
		}
		else
		{
			a[k] = ri[j];
			j++;
		}
	}

}
void Merge_sort(int a[100],int p,int r)
{
	if (p < r)
	{
		int q = floor((p+r)/2);
		Merge_sort(a,p,q);
		Merge_sort(a,q+1,r);
		merge(a,p,q,r);
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

	Merge_sort(arr,1,n);
	
	t = clock() - t;



	for (int i = 1; i <= n; ++i)
	{
		cout <<  arr[i] << "\n" ;
	}
	
	cout << "Running time : " << ((float)t)/CLOCKS_PER_SEC << " seconds." << endl;

	return 0;

}
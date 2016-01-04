#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;
int count = 0 ,arr[100000000];
void insert(int a[],int n)
{
	int j = n -1;
	int key = a[n];
	while(j > 0 && a[j] > key)
	{
		count++;
		a[j+1] = a[j];
		j--;
	}
	a[j+1] = key;
}
void insertion_sort(int a[],int n)
{
	if(n > 1)
	{
		insertion_sort(a,n-1);
		insert(a,n-1);
		
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

	insertion_sort(arr,n+1);
	
	t = clock() - t;


	for (int i = 1; i <= n; ++i)
	{
		cout <<  arr[i] << "\n" ;
	}
	cout << "inversions count : " << count << endl;
	cout << "Running time : " << ((float)t)/CLOCKS_PER_SEC << " seconds." << endl;

	return 0;

}
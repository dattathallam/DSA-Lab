#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int heap_length;
char a[10000000][50];
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
void max_heapify(char a[][50],int i)
{
	int temp,largest;
	char buffer[1000];
	int l = left(i);
	int r = right(i);
	if(l <= heap_length && (strcmp(a[l] ,a[i])  > 0))
		largest = l;
	else
		largest = i;
	if(r <= heap_length && (strcmp(a[r] ,a[largest])  > 0))
		largest = r;
	if(largest != i)
	{
		strcpy(buffer,a[largest]);
		strcpy(a[largest],a[i]);
		strcpy(a[i],buffer);

		max_heapify(a,largest);
	}
}
void build_max_heap(char a[][50],int n)
{
	heap_length = n;
	for (int i = floor(n/2); i >= 1; i--)
	{
		max_heapify(a,i);
	}
}

void heapsort(char a[][50],int n)
{
	int temp;
	char buffer[1000];
	build_max_heap(a,n);

	for (int i = n; i >= 2; i--)
	{
		strcpy(buffer,a[1]);
		strcpy(a[1],a[i]);
		strcpy(a[i],buffer);
		heap_length--;
		max_heapify(a,1);
	}
}
int main()
{
	int max = 0,n;
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
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s",a[i]);
		if(strlen(a[i]) == 0)
		{
					cout << "null string is not allowed \n";
					return 0;
		}
			for (int j = 0; a[i][j] != '\0'; ++j)
			{

				if (!(a[i][j] >= 'A' && a[i][j] <= 'Z'))
				{
					cout << "only characters A to Z should be allowed \n";
					return 0;
				}
			}
	}
	clock_t t;
	t = clock();
	heapsort(a,n);
	t = clock() - t;
	for (int i = 1; i <= n; ++i)
	{
		cout << a[i];
		cout << endl;
	}
	printf ("Running time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);

	return 0;
}
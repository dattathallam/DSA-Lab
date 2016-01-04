#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
//#include <ctime>

using namespace std;
char a[10000000][50],g[10000000][50];
/*
char ele_old(char s[],int i)
{
	int f = strlen(s);
	if(f-i < 0)
		return '0';
	else
		return s[f-i];
}*/
char ele(char s[],int i)
{
	int f = strlen(s);
	if(f-i < 0)
		return 0;
	else
	{
		if(s[f-i] <= '9' && s[f-i] >= '0')
			return s[f-i] - 48;
		else
			return s[f-i] - 55;

	}
}
/*
void newinsertionsort(char b[][50],char a[],int n)
{
	char key,buffer[1000];
	int i,j;
	for(j = 1; j < n ; j++)
	{
		strcpy(buffer,b[j+1]);
		key = a[j];
		i = j - 1;

		while(i >= 0 and a[i] > key)
		{
			strcpy(b[i+2],b[i+1]);
			a[i+1] =a[i];
			i = i -1;
		}
		strcpy(b[i+2],buffer);
		a[i+1] = key;
	}
}*/
void counting(int arr[],int k,int n)
{
	int c[16];
	for (int i = 0; i <= k; ++i)
	{
		c[i] = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		c[arr[i]] = c[arr[i]] + 1;
	}
	for (int i = 1; i <= k; ++i)
	{
		c[i] = c[i] + c[i-1];
	}
	for (int i = n; i >= 1; i--)
	{
		strcpy(g[c[arr[i]]],a[i]);
		c[arr[i]] = c[arr[i]] - 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		strcpy(a[i],g[i]);
	}
}
void column(char a[][50],int n,int m,int max)
{
	int buffer[10000],j;
	for (int i = 1; i <= n; ++i)
	{
		buffer[i] = ele(a[i],max-m);
	}
	for (int i = 1; i <= n; ++i)
	{
		if( j < buffer[i] )
		{
			j = buffer[i];
		}
	}
	counting(buffer,j,n);
}/*
void column_old(char a[][50],int n,int m,int max)
{
	char buffer[10000];
	for (int i = 0; i < n; ++i)
	{
		buffer[i] = ele_old(a[i+1],max-m);
	}
	newinsertionsort(a,buffer,n);
}*/


void sort(char a[][50],int n,int m)
{
	for (int i = m-1; i >= 0; i--)
	{
		//column_old(a,n,i,m);
		column(a,n,i,m);
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
		if(strlen(a[i]) == 0 || strlen(a[i]) > 8)
		{
			cout << " atleast a minimum zero or lessthan or equal to maximum 32 bit hexa decimal numbers are expected \n";
			return 0;
		}
			for (int j = 0; a[i][j] != '\0'; ++j)
			{

				if (!(a[i][j] >= '0' && a[i][j] <= '9') && !(a[i][j] >= 'A' && a[i][j] <= 'F'))
				{
					cout << "only characters 0 to 9 or A to F should be allowed \n";
					return 0;
				}

			}
	}
	clock_t t;
	t = clock();
		for (int i = 1; i <= n; ++i)
		{

			if(max < strlen(a[i]))
			{
				max = strlen(a[i]);
			}
		}

	sort(a,n,max);
	t = clock() - t;
	for (int i = 1; i <= n; ++i)
	{
		printf("%s",a[i]);
		cout << endl;
	
	}
	printf ("Running time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
	return 0;
}
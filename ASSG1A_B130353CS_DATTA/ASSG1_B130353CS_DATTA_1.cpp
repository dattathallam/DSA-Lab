#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char z[50];
char a[50];
int ispalindrome(char a[50],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i] != a[n-i-1])
			return 0;
	}
	return 1;
}
	
void del(char a[50],int x)
{
	int j =0;
	for(int i=0;a[i] != '\0';i++)
	{
		if(i != x)
		{
			z[j] = a[i];
			j++;
		}
	}
}
int main()
{
	int o[25]={1000};
	char ch = ' ',term;
	int i=0,j,k;
	cout << "Enter the string:\n";
	//cin >> a;
	gets(a);
	for(i=0;a[i] != '\0';i++)
	{
		if(!((a[i]>= 65 && a[i] <= 90) || (a[i]>= 97 && a[i] <= 122)))
		{
			cout << "only characters a-z and A-Z are allowed\n";
			return(1);
		}
	}
	i = strlen(a);
	int n;
	if (i % 2 == 0)
		n = i /2;
	else
		n = i/2 + 1;

		int m=0;
	for(int k = 0;k < i;k++)
	{
		del(a,k);
		if(ispalindrome(z,strlen(z)))
		{
			//cout << k << endl;
			o[m] = k;
			m++;
		}
	}
	int y;
	if(m == 0)
		cout << "not possible\n";
	else
	{
		for(k = 0;k < m;k++)
		{
			y =o[k];
			cout << a[y] << '\n' << y << endl;
		}
	}
	return 0;
}
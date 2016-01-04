#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int a,b,num[50]={0};
char arr[50][50];
void copcheck(int row[])
{

	int count,i,j,check=0,t;
	for(i=0;i<a;i++)
	{
		count = 0;
		for(j=0;j< b-1;j++)
		{
			if(arr[i][row[j]-1] == '1' && arr[i][row[j+1]-1]== '1')
				count++;
		}
		if(num[i] == 0)
		{
			if(count == num[i])
			check++;	
		}
		else{
		if(count == num[i]-1)
			check++;
	}
	}
	if(check == a)
	{ 
		cout << "Yes\n";
		for(i=0;i<b;i++)
			cout << row[i] << " ";
		cout << endl;
		exit(0);
	}
}
void permutation (int row[], int n, int i) 
{
	int j,t;
	if (i == n) 
	{
		copcheck(row);
	}
	else
		
		for (j=i; j<n; j++) 
		{
			t = row[i];
			row[i] = row[j];
			row[j] = t;

			permutation (row, n, i+1);

			t = row[i];
			row[i] = row[j];
			row[j] = t;
		}
}

int main()
{
	int i,j;
	cout << "enter the order of the matrix:\n";
	cin >> a >> b;
	if(a <= 0 || b <= 0)
	{
		cout << "Please input valid order of matrix\n";
		return 1;
	}
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			cin >> arr[i][j];
			if((arr[i][j] != '0') && (arr[i][j] != '1'))
				{
					cout << "Please input valid entries\n";
					exit(1);
				}
			if(arr[i][j] == '1')
				num[i]++;

		}
	}
	
	int row[50];
	for(i=0;i<b;i++)
		 row[i]=i+1;

	permutation(row,b,0);
	
	cout << "No\n";
	return 0;
}
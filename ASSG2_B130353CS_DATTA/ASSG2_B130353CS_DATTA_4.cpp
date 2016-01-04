#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
char **arr;
int n;
void selection_sort(int n)
{
	int temp = 0,k,index;
	char small[100000];

	for (int i = 1; i <= n-1; ++i)
	{
		strcpy(small,arr[i]);
		temp = 0;
		for (int j = i ; j <= n; ++j)
		{
			if(arr[j][0] < small[0])
			{
				temp++;
				strcpy(small,arr[j]);
				index = j;
			}
			k =0;
			if(arr[j][0] == small[0])
			{
				if(strcmp(arr[j],small) <= 0)
				{
					temp++;
					strcpy(small,arr[j]);
					index = j;					
				}
					/*	while(!(arr[j][k] == '\0' || small[k] == '\0'))
						{
								if (arr[j][k] != small[k])
								{
									temp++;
									if(arr[j][k] < small[k])
									{
										strcpy(small,arr[j]);
										index = j;
										break;
									}
								}
								k++;
						}
						*/
			}
			
		}
		if(temp > 0)
		{
			strcpy(arr[index],arr[i]);
			strcpy(arr[i],small);
		}
	}
}
int main()
{
	int n,j;
	char term,c='.';
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
	
	arr=(char **)malloc(n*sizeof(char *));
	for (int i = 1; i <= n; ++i)
	{
		arr[i]=(char *)malloc(sizeof(char));
		scanf("%s",arr[i]);
		if(strlen(arr[i]) == 0)
		{
					cout << "invalid input \n";
					return 0;
		}
			for (int j = 0; arr[i][j] != '\0'; ++j)
			{

				if (!(arr[i][j] >= 'a' && arr[i][j] <= 'z'))
				{
					cout << "invalid input \n";
					return 0;
				}  
			}
	}
	
	clock_t t;
	t = clock();

	selection_sort(n);
	for (int i = 1; i <= n; ++i)
	{
		cout <<  arr[i] << "\n" ;
	}
	
	t = clock() - t;
	cout << "Running time : " << ((float)t)/CLOCKS_PER_SEC << " seconds." << endl;

	/*for (int i = 1; i <= n; ++i)
	{
		puts(arr[i]);
	}*/
	return 0;

}
/*Abhijit Roy*/
/*17CS8033*/
/*question 1*/
/*Superior O(n2)*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the number of points "<<endl;
	cin>>n;
	int c[n][2];
	int sup[n];
	
	cout<<"Enter the values"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>c[i][0]>>c[i][1];
	}
	for(int i=0;i<n;i++)
	{
		sup[i]=0;
			}

	for(int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			{
				if (i==j)
					continue;
				else
				{
					if((c[i][0]>c[j][0]) && (c[i][1]>c[j][1]))
						sup[i]++;
				}
			}
	}
	cout<<"superiority array is"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i<<"->"<<sup[i]<<endl;
	}
	return 0;
}
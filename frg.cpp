/*Abhijit Roy*/
/*17CS8033*/
/*question 1*/
/*frog jump problem*/



#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	std::vector<int> v(n);
	v[0]=0;
	v[1]=1;
	v[2]=2;
	v[3]=4;
	for(int i=4;i<=n;i++)
	{
		v[i]=v[i-1]+v[i-2]+v[i-3];
	}
	cout<<v[n];
}
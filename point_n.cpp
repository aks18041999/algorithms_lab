#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v;

int searchk(vector<int> k,int sup[n],int c[n][2])
{
	for(int i=0;i<n;i++)
	{
		if((c[i][0]==k[0]) && (c[i][1]==c[i][1]))
		{
			return i;
		}
	}
}

void count(int c[n][2],int sup[n],int max,int mid,int min)
{

	vector<vector<int>> k;
	vector<int> l;
	int i=min;
	int j=max;
	while(i<j)
	{
		l.push_back(v[i][0]);
		l.push_back(v[i][1]);
		k.push_back(l);
		l.erase();
		i++;

	} 
	sort(k.begin(),k.end(),my_func2);

}


void divide(int sup[n],int max,int min)
{
	int mid;
	if(min<max)
	{
		mid=(min+max)/2;

		divide(sup[n],mid,min);
		divide(sup[n],max,mid+1);


	}
}

vector<int> my_func(vector<int> v1,vector<intr> v2)
{
	if(v1[1]>v2[1]) 
		return v1;
	return v2;
}

vector<int> my_func2(vector<int> v1,vector<intr> v2)
{
	if(v1[0]>v2[0]) 
		return v1;
	return v2;
}



int main()
{
	int n;
	int max=INT_MIN;
	int min=INT_MAX;
	cout<<"Enter the number of points "<<endl;
	cin>>n;
	int c[n][2];
	vector<int> k;
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
		w.push_back(c[i][0]);
		w.push_back(c[i][1]);

		v.push_back(w);
		w.erase();
	}
	sort(v.begin(),v.end(),my_func)
	min=v[0][1];
	max=v[n-1][1];

	divide(sup,max,min);

}
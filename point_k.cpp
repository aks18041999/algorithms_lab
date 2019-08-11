/*Abhijit Roy*/
/*17CS8033*/
/*question 1*/
/*Superior O(nlog2n)*/



#include<bits/stdc++.h>


using namespace std;


void merge(vector< pair<int,int> > vec,int ans[],int left, int right )
{
	if(right-left<2)
	{
		if(vec[right].second > vec[left].second && vec[right].first > vec[left].first)
		{
			ans[right]+=(ans[left]+1);
		}
		
	}
	else
	{
		int mid=(left+right)/2;
		merge(vec,ans,left,mid);
		merge(vec,ans,mid+1,right);
		int i,j;
		i=mid;
		j=right;
		while(i>=left && j>mid)
		{
			if(vec[i].second<vec[j].second)
			{
				ans[j]+=ans[i]+1;
				j--;
			}
			else
			{
				
				i--;
			}
		}
		while(j>mid)
		{
			if(vec[i].second<vec[j].second)
			{
				ans[j]+=ans[i]+1;
				j--;
			}
		}
		
	}
}
int main()
{
	  
    int n;
    cin>>n;
    vector < pair<int,int> > vec;
    int i;
    for(i=0;i<n;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	vec.push_back({x,y});
    }
    int j,ans[n]={0};
    sort(vec.begin(),vec.end());
    merge(vec,ans,0,n-1);
    for(i=0;i<n;i++)
    {
    	cout<<"("<<vec[i].first<<","<<vec[i].second<<")---> "<<ans[i]<<endl;
    }
    
}
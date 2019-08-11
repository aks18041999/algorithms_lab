/*Roll No:17CS8033
Name :Abhijit Roy
Assignment No 3.*/
#include <bits/stdc++.h>
#include <random>
using namespace std;
int main()
{
	long long int n,c=0;
	float l1,l2;
	cout<<"Enter the number of intervals:"<<endl;
	cin>>n;
	vector<pair<float,float>>p;	//pair to store segments
	vector<float>start;	//vector to store starting co-ordinate of segments
	vector<float>end;	//vector to store ending co-ordinate of segments
	random_device rd;  // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_real_distribution<> distr(0, 1); // defining the range from 0 to 1
	for(long long int i=0;i<2*n;i++)	
	{
		if(c<n)
		{	
			l1=distr(eng);	//generating numbers
			l2=distr(eng);	//generating numbers
			if((l1!=l2)) //checking whether two numbers are same or not and that the first numnber is lesser than the second number
			{
				if(l1<l2)
					p.push_back({l1,l2}); 
				else
					p.push_back({l2,l1});
				c++;
			}
		}
		else
		{
			continue;
		}
	}
	for(int i=0;i<p.size();i++)
	{
		start.push_back(p[i].first);
		end.push_back(p[i].second);
	}
	cout<<"The intervals are:"<<endl;
	for(int i=0;i<p.size();i++)
	{
		cout<<p[i].first<<","<<p[i].second<<endl;
	}
	//sorting the start and end vectors in increasing co-ordinate value
	sort(start.begin(),start.end());
	sort(end.begin(),end.end());
	int i=0,j=0;
	int max1=0; //maximum overlap in segments
	int curr=0;	//current overlap in segments
	float k,l;
	int a=start.size();
	int b=end.size();
	while(i<a&&j<b)
	{
		if(start[i]<end[j])
		{
			curr++; //increasing the current overlap
			if(curr>max1)
			{
				max1=max(max1,curr);
				k=start[i];	//storing the starting co-ordinate of the zone having maximum segments
				l=end[j];	//storing the ending co-ordinate of the zone having maximum segments
			}
			i++;	
		}
		else
		{
			j++;
			curr--;	//decrementing the current overlap
		}
	}
	cout<<"maximum intervals overlapped:"<<endl;
	cout<<max1<<endl;
	cout<<"maximum overlapping interval:"<<endl;
	cout<<"("<<k<<","<<l<<")"<<endl;
	cout<<"All the overlapping intervals:"<<endl;
	for(int i=0;i<n;i++)
	{
		if(p[i].first<=k&&p[i].second>=l)
		cout<<"("<<p[i].first<<","<<p[i].second<<")"<<endl; 
	}
	return 0;
}
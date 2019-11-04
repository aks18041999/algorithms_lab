#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(void)
{
 int i,j,k,t,n;
 cin>>n;
 map<ll,ll>g1;
 map<ll,ll>::iterator itr,ptr;
 vector<pair<ll,ll> >g2;
 for(i=-n;i<=n;i++)
    {
     for(j=max(i+1,1);j<=n;j++)
        {
         ll x=pow(i,3)+pow(j,3);
         if(x>0)
            g2.push_back(make_pair(j,i));
        }
    } 
 ll l=g2.size();
 for(i=0;i<=l-1;i++)
    {
     ll x=pow(g2[i].first,3)+pow(g2[i].second,3);
    /* if(x==91)
       cout<<g2[i].first<<" "<<g2[i].second<<endl;*/
     if(g1.find(x)==g1.end())
        g1.insert(make_pair(x,1));
     else
       {
        itr=g1.find(x);
        itr->second=itr->second+1;
       }
    }
 //cout<<g1.size()<<endl;
 for(itr=g1.begin();itr!=g1.end();itr++)
    {
     cout<<"No of different cabtaxi with number:"<<itr->first<<"="<<itr->second<<endl;
    }
}

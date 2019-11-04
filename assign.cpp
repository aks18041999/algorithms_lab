#include<bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;

bool isValid(string A,int n)
     {
         int count=0;
         for(int i=0;i<n-2;i++)
          {
             if(A.substr(i,3)=="abc")
                count++;
             if(count>1)return false;
          }
             if(count==1)
               return true;
         return false;    
     }
void generateAndCount(string input,int n,int &count)
    {
      input=input.substr(0,n);
      string ter="cccccccccccccccccc";
      ter=ter.substr(0,n);
      int i=n-1;
      while(input!=ter )
         {
           int j=i;
           while(input[j]=='c' && j>=0)
            {
               input[j]='a';
               j--;  
            }
            if(j>=0)
             input[j]++;
             
            if(isValid(input,n))count++;
         }
        cout<<"Iterative count : "<<count<<endl;
    }
  
int main()
{
  string s="aaaaaaaaaaaaaaaaa";
  int n;
  cout<<"Enter lenght of string: ";
  cin>>n;
  int count=0;
  auto start=high_resolution_clock::now();
  generateAndCount( s, n,count);
  auto stop=high_resolution_clock::now();
  auto duration=duration_cast<microseconds>(stop-start);
  cout<<"Duration of iterative count "<<duration.count()<<" micro-seconds"<<endl;
  return 0;
}

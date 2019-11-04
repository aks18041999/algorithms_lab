#include<iostream>
#include<iomanip>
#include<cmath>
#define pi 3.14
using namespace std;

int main()
{	
	int i;
	i=0;
	float f;
	float count=0;
	for(count=0;count<2*pi;count+=0.1)
	{
		f=sin(count);
		i++;
		//cout<<i<<"\n";
	}

	cout<<i<<endl;	
	for(int j=0;j<=i;j++)
	{
	for(count=0;count<2*pi;count+=0.1)
	{
		
		f=sin(count);
		cout<<f<<"\n";
		cout<< setfill('*')<<setw(f*10);

	}
	cout<<"\n";
	}
}

/**
Assignment No: 4;
Assignment: A string of length n having 3 types of character 'a', 'b', 'c'. Count total no of possible
permutation that contain substring 'abc' only once.

Name: Abhijit Roy
Roll No: 17CS8033
**/
#include<bits/stdc++.h>
#include<sys/time.h>
#include<sys/types.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
int pown(int a, int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    return (pown(a,b/2)*pown(a,b-b/2));
}
/**
No of possible permutation that does not have 'abc' for length 'i' is S(i)
S(i) = 3**i                                                         for i < 3;
S(i) = 3**i - (i-2)*(3**(i-3))                                      for i = 3;
S(i) = range(1 <= j <= i-2) sum(S(j-1) * (3**(i-j-2)));             for i > 3;
No of possible permutation that contain 'abc' only once for length 'n' is T(n)
T(n) = range(1 <= i <= n-2) sum(S(i-1)*S(n-i-2));
**/

/** Count the valid string by Dynamic Programing approach. **/
int count_valid_string(int n)
{
    int DP[n+1];
    for(int i=0;i<=n;i++)
        DP[i]=0;
    int val=0;
    for(int i=0;i<=n;i++)
    {
        if(i<3)
            DP[i]=pown(3,i);
        else if(i==3)
            DP[i]=(pown(3,i)-(i-2)*pown(3,i-3));
        else
        {
            val=0;
            for(int j=1;j<=i-2;j++)
                val+=(DP[j-1]*pown(3,i-j-2));
            DP[i]=pown(3,i)-val;
        }
    }
    int sum=0;
    for(int i=1;i<n-1;i++)
        sum+=(DP[i-1]*DP[n-i-2]);
    return sum;
}
/** Count valid string having substring 'abc' only once. **/
void count_string(char str[], int n, int& count)
{
    int cnt=0;
    for(int i=0;i<n-2;i++)
    {
        if(str[i]=='a' and str[i+1]=='b' && str[i+2]=='c')
            cnt++;
    }
    if(cnt==1)
        count++;
}
/** Generate all possible permutation by recursive approach. **/
void generate_string_recursive(char str[], int j, int p, int n,int& count)
{
    if(j>=n)
    {
        count_string(str,n,count);
        return;
    }
    str[j]='a';
    generate_string_recursive(str,j+1,1,n,count);
    str[j]='b';
    generate_string_recursive(str,j+1,2,n,count);
    str[j]='c';
    generate_string_recursive(str,j+1,3,n,count);
}
/** Generate all possible permutation by iterative approach. **/
int count_valid_string_iterative(char str[], int n, int& count)
{
    int valid_string=pown(3,n);
    for(int i=0;i<n;i++)
        str[i]='a';
    int j=n-1;
    for(int i=1;i<valid_string;i++)
    {
        j=n-1;
        if(str[j]!='c')
        {
            if(str[j]=='a')
                str[j]='b';
            else if(str[j]=='b')
                str[j]='c';
        }
        else
        {
            str[j]='a';
            j--;
            while(str[j]=='c' and j>=0)
            {
                str[j]='a';
                j--;
            }
            if(str[j]=='a')
                str[j]='b';
            else if(str[j]=='b')
                str[j]='c';
        }
        count_string(str,n,count);
    }
}
/** Count valid string having substring 'abc' only once by Dynamic Programming, Recursive and iterative
Approach as well as calculate overall execution time for each method. **/
int main()
{
    int len;
    cout << "Enter Length of the string:" << endl;
    cin>>len;
    auto start = high_resolution_clock::now();
    cout << "No of string having 'abc' substring only one time: " << count_valid_string(len) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time of overall program: " << duration.count() << " microseconds" << endl;
    int count=0;
    char str[len+5];
    start = high_resolution_clock::now();
    generate_string_recursive(str,0,1,len,count);
    cout << "No of string having 'abc' substring only one time: " << count << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time of overall program: " << duration.count() << " microseconds" << endl;
    count=0;
    start = high_resolution_clock::now();
    count_valid_string_iterative(str,len,count);
    cout << "No of string having 'abc' substring only one time: " << count << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Execution time of overall program: " << duration.count() << " microseconds" << endl;
    return 0;
}
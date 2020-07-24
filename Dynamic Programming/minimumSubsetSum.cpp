// divide the array into 2 such that the difference of sum of both arrays in minimum
// solution :
// the two division of the array will be S1 , R-S1 (R=summation of array)
// Consider S1 to be the smaller element
// minimise(R-2*S1)
// S1 will lie between 0-R/2 (since its the smaller element)
// find the max value of S1 <= R/2
// can be approached in a similar fashion as subsetSum

#include "bits/stdc++.h"
using namespace std;
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define MP make_pair
#define PB push_back
#define endl "\n"
#define yes cout<<"yes"<<endl;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define UM unordered_map
#define CHECK(a) cout<<"a :"<<a<<endl
#define mem(a,v) memset(a,v,sizeof(a))
#define S second
#define F first
typedef vector<unsigned long long int> VI;
typedef vector<string> VS;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;

int dp[100][100]={0};

int MNSD(int arr[], int n){
    int r=0;
    FOR(i,0,n,1) r+=arr[i]; // calculate R
    FOR(i,0,r/2+1,1)  dp[0][i]=0;
    FOR(i,0,n+1,1)  dp[i][0]=1;
    FOR(i,1,n+1,1){
      FOR(j,1,r/2+1,1){
        if(arr[i-1]<=j) dp[i][j]=max(dp[i-1][j-arr[i-1]],dp[i-1][j]);
        else  dp[i][j]=dp[i-1][j];
      }
    }
    int sum = -1;
    FOR(i,0,r/2+1,1)
      if(dp[n][i]==1) sum=max(i,sum);
    return r-2*sum;
}

int main()
{
  int arr[]={3,12,4,10};
  int n = 4;
  cout<<"minimum Subset Sum Difference :"<<MNSD(arr,n)<<endl;
}

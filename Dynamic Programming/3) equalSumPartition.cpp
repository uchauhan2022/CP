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

int dp[100][100];

int equalSumPartition(int arr[], int sum, int n){
  for(int i = 0; i<100; i++){
    for(int j = 0; j<100; j++){
      dp[i][j]=0;
    }
  }
  for(int i = 0; i<=sum; i++){
    dp[0][i]=0;
  }
  for(int i = 0; i<=n ;i++){
    dp[i][0]=1;
  }
  for(int i = 1; i<=n;i++){
    for(int j=1; j<=sum; j++){
      if(arr[i-1]<=j)
        dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i-1]]);
      else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][sum];
}

int main()
{
  int arr[]={1,1,2,6,4,9,3};
  int arr1[]={5,5,8,6,5,5};
  int n1 = 7;
  int n2 = 6;
  int sum = 0;
  for(int i = 0; i<7; i++){
    sum+=arr[i];
  }
  if(sum%2==0)
    cout<<"ans :"<<equalSumPartition(arr,sum/2,n1)<<endl;
  else
    cout<<"ans :"<<0<<endl;
  sum = 0;
  for(int i = 0; i<n2; i++){
      sum+=arr1[i];
  }
  if(sum%2==0)
    cout<<"ans :"<<equalSumPartition(arr1,sum/2,n2)<<endl;
  else
    cout<<"ans :"<<0<<endl;
  sum = 0;

}

// Find minimum number of coins required
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
int minCoins(int arr[], int c, int n){
  FOR(i,0,n+1,1)  dp[i][0]=0;
  FOR(i,0,c+1,1)  dp[0][i] = INT_MAX;
  FOR(i,1,n+1,1){
    FOR(j,1,c+1,1){
      if(arr[i-1]<=j){
        dp[i][j]=min(dp[i-1][j], 1+dp[i][j-arr[i-1]]);
      }
      else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][c];
}

int main()
{
  int arr[] = {1,3,4,7};
  int n = 4;
  int c = 7;
  cout<<"ans : "<<minCoins(arr,c,n)<<endl;
  return 0;
}

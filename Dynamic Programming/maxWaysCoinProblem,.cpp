// Given unlimited supply of the following types of coin (arr[]={1,2,3}), find the max number of ways to total upto an integer C
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

int coinsMaxWays(int arr[], int c, int n){
  FOR(i,0,c+1,1)  dp[0][i] = 0;
  FOR(i,0,n+1,1)  dp[i][0] = 1;
  FOR(i,1,n+1,1){
    FOR(j,1,c+1,1){
      if(arr[i-1]<=j){
        dp[i][j]=dp[i][j-arr[i-1]]+dp[i-1][j];
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
  int coins[]={1,3,4,5};
  int c = 10;
  int n = 4;
  cout<<"ans : "<<coinsMaxWays(coins, c, n)<<endl;
  return 0;
}

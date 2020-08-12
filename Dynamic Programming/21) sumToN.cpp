// https://www.geeksforgeeks.org/different-ways-sum-n-using-numbers-greater-equal-m/
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


int f(int n, int m,int i, int j, vector<vector<int> > &dp){
  if(j<m){
    return 0;
  }
  if(i==0){
    return 1;
  }
  if(dp[i][j]!=-1)  return dp[i][j];
  if(i>=j){
    dp[i][j]=f(n,m,i-j,j,dp)+f(n,m,i,j-1,dp);
  }
  else{
    dp[i][j]=f(n,m,i,j-1,dp);
  }
  return dp[i][j];
}

int main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int n, m;
      cin>>n>>m;
      vector<vector<int> > dp(n+2, vector<int> (n+2,-1));
      for(int i = 0; i<n+2; i++){
        for(int j= 0; j<n+2; j++){
          dp[i][j]=-1;
        }
      }
      cout<<f(n,m,n,n,dp)<<endl;
    }
  return 0;
}

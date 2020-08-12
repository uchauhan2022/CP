// https://www.geeksforgeeks.org/number-n-digits-non-decreasing-integers/
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

int f(int n, int k, vector<vector<int> > &dp){
  if(n==0) return 1;
  if(k==9) return 1;
  if(dp[n][k]!=-1)  return dp[n][k];
  int ans = 0;
  for(int i = k; i<10; i++){
    ans+=f(n-1,i,dp);
  }
  return dp[n][k]=ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<vector<int> > dp(n+2, vector<int>(11,-1));
      cout<<f(n,0,dp)<<endl;
    }
  return 0;
}

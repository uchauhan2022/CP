// https://www.geeksforgeeks.org/remove-array-end-element-maximize-sum-product/
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

int f(vector<int> v, int ans , int i , int j , vector<vector<int> > &dp){
  if(i>j) return 0;
  if(i==j) return v[i]*ans;
  if(dp[i][j]!=-1) return dp[i][j];
  return dp[i][j]=max(v[i]*ans+f(v,ans+1,i+1,j,dp),v[j]*ans+f(v,ans+1,i,j-1,dp));
}

int main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      int n ;
      cin>>n;
      vector<int> v(n,0);
      for(int i = 0 ; i<n; i++){
        cin>>v[i];
      }
      vector<vector<int> > dp(n+2, vector<int>(n+2,-1));
      cout<<f(v,1,0,n-1,dp)<<endl;
    }
  return 0;
}

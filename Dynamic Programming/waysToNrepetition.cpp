// https://www.geeksforgeeks.org/ways-sum-n-using-array-elements-repetition-allowed/
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

int f(vector<int> v, int i , int k , int n, vector<vector<int> > &dp){
  if(i==n||k<0)  return 0;
  if(k == 0)  return 1;

  if(dp[i][k]!=-1)  return dp[i][k];
  return dp[i][k] = f(v,i,k-v[i],n,dp) + f(v,i+1,k,n,dp);
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
      int k ;
      cin>>k;
      vector<int> vec(n,0);
      for(int i = 0; i<n; i++){
        cin>>vec[i];
      }
      vector<vector<int> > dp(n+2, vector<int> (k+2,-1));
      cout<<f(vec, 0 , k , n, dp)<<endl;
    }
  return 0;
}

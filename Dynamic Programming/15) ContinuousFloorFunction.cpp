// https://www.geeksforgeeks.org/value-continuous-floor-function-fx-ffloorx2-x/
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

int f(int n, vector<int> &dp){
  if(n==0)  return 0;
  if(dp[n]!= -1)  return dp[n];
  return dp[n]=n+f(n/2,dp);
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
      vector<int> v(n,0);
      int m = INT_MIN;
      for(int i = 0; i<n; i++){
          cin>>v[i];
          m = max(m,v[i]);
      }
      vector<int> dp(m+2,-1);
      for(int i = 0; i<n; i++) {
          cout<<f(v[i],dp)<<" ";
      }
      cout<<endl;
    }
  return 0;
}

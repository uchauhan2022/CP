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

int f(vector<int> v, int maximum, int i, vector<int> &dp){
  if(i==v.size()) return 0;
  if(dp[i]!=-1) return dp[i];
  if(v[i]>maximum){
    return dp[i] = max(1+f(v,v[i],i+1,dp),f(v,maximum,i+1,dp));
  }
  else{
    return dp[i]= f(v,maximum,i+1,dp);
  }
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
      for(int i = 0; i<n; i++){
        cin>>v[i];
      }
      vector<int> dp(n+2,-1);
      cout<<f(v,INT_MIN,0,dp)<<endl;
    }
  return 0;
}

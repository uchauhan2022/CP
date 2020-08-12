//https://www.geeksforgeeks.org/probability-reaching-point-2-3-steps-time/
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

double f(int n,int i, double p,vector<double> &dp){
  if(i>n) return 0;
  if(i==n) return 1;
  if(dp[i]!=-1) return dp[i];
  return dp[i]=p*f(n,i+2,p,dp) + (1-p)*f(n,i+3,p,dp);
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
      double p;
      cin>>p;
      vector<double> dp(n+2,-1);
      cout<<f(n,0,p,dp)<<endl;
    }
  return 0;
}

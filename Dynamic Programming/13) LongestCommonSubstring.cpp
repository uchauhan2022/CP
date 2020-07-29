// Tob Down approach.
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

int lcs(string x, string y, int n , int m){
  FOR(i,0,n+1,1)
    FOR(j,0,m+1,1)
      dp[i][j]=-1;
  FOR(i,0,n+1,1)  dp[i][0]=0;
  FOR(i,0,m+1,1)  dp[0][i]=0;
  FOR(i,1,n+1,1){
    FOR(j,1,m+1,1){
      if(x[i-1]==y[j-1])
        dp[i][j]=1+dp[i-1][j-1];
      else
        dp[i][j]=0;
    }
  }
  int maxi = INT_MIN;
  FOR(i,0,n+1,1)
    FOR(j,0,m+1,1)
      maxi=max(dp[i][j],maxi);
  return maxi;
}

int main()
{
  string x = "abcedhj",y="abdkj";
  int n = x.length();
  int m = y.length();
  cout<<"ans : "<<lcs(x,y,n,m)<<endl;
  return 0;
}

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

int lcs(string x,string y,int n,int m){
  if(n==0 || m==0){
    return 0;
  }
  if(dp[n][m]!=-1)  return dp[n][m];
  if(x[n-1]==y[m-1])  {
    return dp[n][m]=1+lcs(x,y,n-1,m-1);
  }
  else{
    return dp[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
  }

}

int main()
{
  string x = "abcdefgh";
  string y = "abfghsjkdgh";
  int n = x.length();
  int m = y.length();
  FOR(i,0,100,1){
    FOR(j,0,100,1){
      dp[i][j]=-1;
    }
  }
  cout<<"ans : "<<lcs(x,y,n,m)<<endl;
  return 0;
}

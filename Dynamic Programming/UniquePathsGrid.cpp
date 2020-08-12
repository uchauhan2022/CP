// https://www.geeksforgeeks.org/unique-paths-in-a-grid-with-obstacles/
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


int f(vector<vector<int> > &arr, int n,int i, int j, vector<vector<int> > &dp){
  if(i==n || j==n)  return 0;
  if(i==n-1 && j==n-1)  return 1;
  if(arr[i][j]==1) return 0;
  if(dp[i][j]!=-1)  return dp[i][j];
  return dp[i][j] = f(arr, n,i+1 ,j,dp )+f(arr,n,i,j+1,dp);

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
      vector<vector<int> > arr(n+1, vector<int> (n+1,-1));
      for(int i = 0 ; i<n; i++ ){
        for(int j = 0 ; j<n; j++){
          cin>>arr[i][j];
        }
      }
      vector<vector<int> > dp(n+2, vector<int> (n+2,-1));
      cout<<f(arr,n,0,0,dp)<<endl;
    }
  return 0;
}

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
int flag = 0;
void solve(vector<vector<int> > &ans, int x, int y, int count, int val, int n){
  if(count==0)  return;
  if(y-1>=0 && ans[x][y-1]==0){
    ans[x][y-1]=val;
    solve(ans,x,y-1,count-1,val,n);
  }
  else if(x+1<n && ans[x+1][y]==0){
    ans[x+1][y]=val;
    solve(ans,x+1,y,count-1,val,n);
  }
  else {
    flag = 1;
  }
  return;
}
void printAns(vector<vector<int> > &ans, int n){
  for(int i = 0; i<n; i++){
    for( int j = 0; j<=i; j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n,0);
    FOR(i,0,n,1)  cin>>v[i];
    vector<vector<int> > ans(n,vector<int>(n,0));

    for(int i = 0; i<n; i++){
      ans[i][i]=v[i];
      solve(ans,i,i,v[i]-1,v[i],n);
    }
    if(flag){
      cout<<-1<<endl;
      return 0;
    }
    printAns(ans,n);

  return 0;
}

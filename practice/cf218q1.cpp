#include "bits/stdc++.h"
using namespace std;
#define FOR(i, j, k) for (int i=j; i<k; i+=1)
#define RFOR(i, j, k) for (int i=j; i>=k; i-=1)
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
vector<vector<vector<long long int> > > dp(501, vector<vector<long long int> > (501, vector<long long int>(21,-2)));

long long int dfs(vector<vector<long long int> > &ans, vector<vector<long long int> > &sideX,vector<vector<long long int> > &sideY, int k, int n, int m, int startx, int starty, int i, int j){
  // cout<<"checking at path "<<i<<", "<<j<<" for "<<startx<<", "<<starty<<endl;
  // cout<<"K = "<<k<<endl;
  if(k==0){
    if(startx==i && starty==j)  return 0;
    return -1;
  }
  if(dp[i][j][k]!=-2) return dp[i][j][k];
  long long int s1=INT_MAX,s2=INT_MAX,s3=INT_MAX,s4=INT_MAX;
  if(i+1<n){
    s1=dfs(ans,sideX,sideY,k-1,n,m,startx,starty,i+1,j);
    if(s1==-1)  s1=INT_MAX;
    else  s1+=sideY[i][j];
  }
  if(j+1<m){
    s2=dfs(ans,sideX,sideY,k-1,n,m,startx,starty,i,j+1);
    if(s2==-1)  s2=INT_MAX;
    else  s2+=sideX[i][j];
  }
  if(i-1>=0){
    s3=dfs(ans,sideX,sideY,k-1,n,m,startx,starty,i-1,j);
    if(s3==-1)  s3=INT_MAX;
    else  s3+=sideY[i-1][j];
  }
  if(j-1>=0){
    s4=dfs(ans,sideX,sideY,k-1,n,m,startx,starty,i,j-1);
    if(s4==-1)  s4=INT_MAX;
    else  s4+=sideX[i][j-1];
  }
  long long int s = min(s1,min(s2,min(s3,s4)));
  if(s==INT_MAX)  return dp[i][j][k]=-1;
  return dp[i][j][k]=s;
}
void show(vector<vector<long long int> > &ans, long long int n , long long int m){
  FOR(i,0,n){
    FOR(j,0,m){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}
void reset(){
  FOR(i,0,501){
    FOR(j,0,501){
      FOR(k,0,21) dp[i][j][k]=-2;
    }
  }
}
void solve(vector<vector<long long int> > &ans, vector<vector<long long int> > &sideX,vector<vector<long long int> > &sideY, int k, int n, int m){
  FOR(i,0,n){
    FOR(j,0,m){
      reset();
      ans[i][j]=dfs(ans,sideX,sideY,k,n,m,i,j,i,j);
    }
  }
  show(ans,n,m);
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t=1;
        // cin>>t;
        while(t--){
          int n,m,k;
          cin>>n>>m>>k;
          vector<vector<long long int> > sidesX(n,vector<long long int> (m-1,-1));
          vector<vector<long long int> > sidesY(m,vector<long long int> (m,-1));
          FOR(i,0,n){
            FOR(j,0,m-1){
              cin>>sidesX[i][j];
            }
          }
          FOR(i,0,n-1){
            FOR(j,0,m){
              cin>>sidesY[i][j];
            }
          }
          vector<vector<long long int> > ans(n,vector<long long int> (m,INT_MAX));
          solve(ans,sidesX,sidesY,k,n,m);
        }
        return 0;
}

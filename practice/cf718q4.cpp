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
int n,m,k;
vector<vector<vector<lli> > > dp (501,vector<vector<lli> > (501, vector<lli> (21,-1)));
lli dfs(vector<vector<lli> > &ans, vector<vector<int> > &sideX, vector<vector<int> > &sideY, int i, int j , int steps){
  if(steps==0){
    return 0;
  }
  if(dp[i][j][steps]!=-1) return dp[i][j][steps];
  long long int s1=INT_MAX,s2=INT_MAX,s3=INT_MAX,s4=INT_MAX;
  if(i+1<n){
    s1=dfs(ans,sideX,sideY,i+1,j,steps-1)+sideY[i][j];
  }
  if(j+1<m){
    s2=dfs(ans,sideX,sideY,i,j+1,steps-1)+sideX[i][j];
  }
  if(i-1>=0){
    s3=dfs(ans,sideX,sideY,i-1,j,steps-1)+sideY[i-1][j];
  }
  if(j-1>=0){
    s4=dfs(ans,sideX,sideY,i,j-1,steps-1)+sideX[i][j-1];
  }
  long long int s = min(s1,min(s2,min(s3,s4)));
  return dp[i][j][steps]=s;
}
void show(vector<vector<lli> > &ans){
  FOR(i,0,n){
    FOR(j,0,m){
      cout<<ans[i][j]*2<<" ";
    }
    cout<<endl;
  }
}
void showF(vector<vector<lli> > &ans){
  FOR(i,0,n){
    FOR(j,0,m){
      cout<<-1<<" ";
    }
    cout<<endl;
  }
}
void solve(vector<vector<lli> > &ans, vector<vector<int> > &sideX, vector<vector<int> > &sideY){
  FOR(i,0,n){
    FOR(j,0,m){
      ans[i][j]=dfs(ans,sideX,sideY,i,j,k/2);
    }
  }
  show(ans);
}



int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t=1;
        // cin>>t;
        while(t--) {
          cin>>n>>m>>k;
          vector<vector<int> > sideX(n,vector<int> (m-1,0));
          vector<vector<int> > sideY(n-1,vector<int> (m,0));
          FOR(i,0,n){
            FOR(j,0,m-1){
              cin>>sideX[i][j];
            }
          }
          FOR(i,0,n-1){
            FOR(j,0,m){
              cin>>sideY[i][j];
            }
          }
          vector<vector<lli> > ans(n,vector<lli> (m,0));
          if(k%2){
            showF(ans);
            return 0;
          }
          solve(ans,sideX,sideY);
        }
        return 0;
}

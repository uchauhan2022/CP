// https://www.geeksforgeeks.org/height-generic-tree-parent-array/
#include "bits/stdc++.h"
using namespace std;
#define FOR(i, j, k, in) for (int i=j; i<k; i+=in)
#define RFOR(i, j, k, in) for (int i=j; i>=k; i-=in)
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
typedef vector<long long int> VI;
typedef vector<string> VS;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;

lli fillHeight(VI &parent, int node ,VI &visited, VI &height){
  if(parent[node]==-1){
    visited[node]=1;
    return height[node]=0;
  }
  if(visited[node]) return height[node];
  visited[node]=1;
  return height[node]=1+fillHeight(parent,parent[node],visited,height);
}

lli solve(VI parent, int n){
  VI visited(n,0), height(n,0);
  lli maxx = 0;

  for(int i = 0; i<n; i++){
    if(!visited[i]){
      height[i]=fillHeight(parent,i,visited,height);
      maxx=max(maxx,height[i]);
    }
    else{
      maxx=max(maxx,height[i]);
    }
  }
  return maxx;
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--) {
          int n;
          cin>>n;
          VI parent(n,-1);
          FOR(i,0,n,1)  cin>>parent[i];
          cout<<solve(parent,n)<<endl;
        }
        return 0;
}

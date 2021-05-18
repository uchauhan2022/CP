#include "bits/stdc++.h"
using namespace std;
#define FOR(i, j, k) for (int i=j ; i<k ; i+=1)
#define RFOR(i, j, k) for (int i=j ; i>=k ; i--)
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

pair<bool,int> f(vector<vector<int> > &lot, int i, int j, int n, int m, vector<vector<int> > &visited ){
  if(lot[i][j]==9)  return {true,0};
  pair<bool,int> ans1,ans2,ans3,ans4,ans5;
  int curBool = false;
  int curMin = INT_MAX;
  visited[i][j]=1;
  if(i+1<n && lot[i+1][j]!=0 && !visited[i+1][j]){
    ans1=f(lot,i+1,j,n,m,visited);
    if(ans1.first){
      curBool = true;
      curMin = min(1+ans1.second,curMin);
    }
  }
  else if(j+1<m && lot[i][j+1]!=0 &&!visited[i][j+1]){
    ans2=f(lot,i,j+1,n,m,visited);
    if(ans2.first){
      curBool = true;
      curMin = min(1+ans2.second,curMin);
    }
  }
  else if(j-1>=0 && lot[i][j-1]!=0 &&!visited[i][j-1]){
    ans3=f(lot,i,j-1,n,m,visited);
    if(ans3.first){
      curBool = true;
      curMin = min(1+ans3.second,curMin);
    }
  }
  else if(i-1>=0 && lot[i-1][j]!=0  &&!visited[i-1][j]){
    ans4=f(lot,i-1,j,n,m,visited);
    if(ans4.first){
      curBool = true;
      curMin = min(1+ans4.second,curMin);
    }
  }
  return {curBool,curMin};
}
int distanceTraversed(vector<vector<int> > lot){
  int n = lot.size();
  int m = lot[0].size();
  vector<vector<int> > visited(n,vector<int>(m,0));
  pair<bool,int> ans = f(lot,0,0,n,m,visited);
  if(ans.first) return ans.second;
  return -1;
}
int main(){
  vector<vector<int> > x(4,vector<int>(4,0));
  for(int i = 0; i<4 ;i++){
    for(int j = 0; j<4; j++){
      cin>>x[i][j];
    }
  }
  cout<<distanceTraversed(x)<<endl;
}

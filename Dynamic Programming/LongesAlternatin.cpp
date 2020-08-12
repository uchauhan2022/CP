// https://www.geeksforgeeks.org/longest-alternating-positive-negative-subarray-starting-every-index/
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

bool pos(int n){
  if(n>0) return true;
  return false;
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
      vector<int> v(n,-1), sum(n,1);
      for(int i = 0 ; i< n; i++){
        cin>>v[i];
      }
      sum[n-1]=1;
      for(int i = n-2; i>=0; i--){
        if(pos(v[i])^pos(v[i+1])) {
          sum[i]=1+sum[i+1];
        }
        else{
          continue;
        }
      }
      for(int i = 0; i<n; i++){
        cout<<sum[i]<<" ";
      }
      cout<<endl;
    }
  return 0;
}

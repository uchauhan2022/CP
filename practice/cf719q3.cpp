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
typedef vector<unsigned long long int> VI;
typedef vector<string> VS;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;


int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--) {
          int n;
          cin>>n;
          if(n==1)  cout<<1<<endl;
          else if(n==2) cout<<-1<<endl;
          else if(n==3){
            cout<<"2 9 7\n4 6 3\n1 8 5"<<endl;
          }
          else{
            vector<vector<int> > v(n,vector<int> (n,0));
            int cur = 1;
            FOR(i,0,n,1){
              FOR(j,0,n,2){
                v[i][j]=cur++;
              }
            }
            FOR(i,0,n,1){
              FOR(j,1,n,2){
                v[i][j]=cur++;
              }
            }
            FOR(i,0,n,1){
              FOR(j,0,n,1){
                cout<<v[i][j]<<" ";
              }
              cout<<endl;
            }
          }

        }
        return 0;
}

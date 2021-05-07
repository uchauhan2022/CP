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

lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

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
          vector<lli> v(n,0);
          FOR(i,0,n,1) cin>>v[i];
          vector<pair<int,lli> > ans;
          FOR(i,1,n,1){
            if(gcd(v[i-1],v[i])==1) continue;
            lli cur = min(v[i],v[i-1]);
            v[i-1] = cur;
            v[i]=cur+1;
            ans.PB(MP(i,cur));
            // cout<<i<<endl;
          }
          cout<<ans.size()<<endl;
          FOR(i,0,ans.size(),1){
            cout<<ans[i].F<<" "<<ans[i].F+1<<" "<<ans[i].S<<" "<<ans[i].S+1<<endl;
          }
        }
        return 0;
}

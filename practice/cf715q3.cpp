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
                vector<pair<lli,lli> > v;
                for(int i = 0; i<n; i++) {
                        lli x;
                        cin>>x;
                        v.PB(MP(0,x));
                }
                FOR(i,0,n,1){
                        lli x;
                        cin>>x;
                        lli y = v[i].S;
                        v[i]=MP(x,y);
                }
                sort(v.begin(), v.end(),greater<pair<int,int> >());
                unordered_map<int,vector<int> > umap;
                unordered_map<int,int> leng;
                FOR(i,0,n,1){
                        umap[v[i].S].PB(v[i].F);
                        leng[v[i].S]++;
                }
                FOR(i,1,n+1,1){
                        // cout<<"CURRENT K :"<<i<<endl;
                        lli sum = 0;
                        for(auto j:umap) {
                                int cur_len = leng[j.F];
                                int lim = cur_len-(cur_len%i);
                                // cout<<"universities : "<<j.F<<" :";
                                for(auto k:j.S) {
                                        if(lim==0) break;
                                        // cout<<k<<" ";
                                        sum+=k;
                                        lim--;
                                }
                                // cout<<endl;
                        }
                        cout<<sum<<" ";

                }
                cout<<endl;
        }
        return 0;
}

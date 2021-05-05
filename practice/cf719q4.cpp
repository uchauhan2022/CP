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


lli countPairs(vector<int> arr, lli n)
{
        unordered_map<int, lli> map;
        for (int i = 0; i < n; i++)
                map[arr[i] - i]++;
        lli res = 0;
        for (auto x : map) {
                lli cnt = x.second;
                res += ((cnt * (cnt - 1)) / 2);
        }
        return res;
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
          vector<int> v(n,0);
          FOR(i,0,n,1)  cin>>v[i];
          cout<<countPairs(v,n)<<endl;
        }
        return 0;
}

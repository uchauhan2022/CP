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
                lli n,temp;
                cin>>n;
                temp=n;
                lli ans=0;
                int count = 0;
                while(temp>9){
                  ans+=9;
                  temp/=10;
                  count++;
                }
                // cout<<"ans"<<ans<<endl;;
                lli x=temp;
                while(count){
                  count--;
                  x=x*10+temp;
                }
                if(x<=n){
                  ans+=temp;
                }
                else{
                  ans+=(temp-1);
                }
                cout<<ans<<endl;
        }
        return 0;
}

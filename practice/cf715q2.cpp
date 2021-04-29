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
                string s;
                cin>>s;
                int count = 0;
                for(int i = 0; i<n; i++) {
                        if(s[i]=='M') count++;
                }
                if(n/3==count) {
                        int cT=0,cM=0;
                        int flag = 0;
                        for(int i = 0; i<(2*n/3); i++) {
                                if(s[i]=='T') cT++;
                                else cT--;
                                if(cT<0) {
                                        flag = 1;
                                        break;
                                }
                        }
                        if(cT!=0) flag = 1;
                        if(flag) cout<<"NO"<<endl;
                        else cout<<"YES"<<endl;

                }
                else{
                        cout<<"NO"<<endl;
                }
        }
        return 0;
}

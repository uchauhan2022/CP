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
          vector<int> umap(26,0);
          umap[s[0]-'A']=1;
          char cur = s[0];
          int flag = 1;
          for(int i = 1; i<n; i++){
            if(s[i]!=cur){
              cur=s[i];
              if(umap[s[i]-'A']){
                flag = 0;
                break;
              }
              umap[s[i]-'A']=1;
            }
          }
          if(flag)  cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
        }
        return 0;
}

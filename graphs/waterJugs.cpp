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

void solve(int m, int n, int d){
        map<pair<int,int>, int> visited;
        list<pair<int,int> > queue;
        vector<pair<int,int> > path;
        queue.push_back(MP(0,0));

        while(!queue.empty()) {
                pair<int, int> cur = queue.front();
                queue.pop_front();
                int x = cur.F;
                int y = cur.S;
                // cout<<"exe1"<<endl;
                if(visited[cur]==1) continue;
                visited[cur]=1;
                path.push_back(cur);
                if(x==d || y==d) {
                        if(cur.F==d) {
                                path.push_back(MP(d,0));
                        }
                        else{
                                path.push_back(MP(0,d));
                        }
                        int sz = path.size();
                        for (int i = 0; i < sz; i++)
                                cout << "(" << path[i].first<< ", " << path[i].second << ")\n";
                        // cout<<"exe"<<endl;
                        break;
                }
                if(x>m || y>n || x<0 || y<0) {
                        continue;
                }
                queue.push_back(MP(0,cur.S));
                queue.push_back(MP(cur.F,0));
                queue.push_back(MP(m,cur.S));
                queue.push_back(MP(cur.F,n));
                if((m-x)>=y) queue.push_back(MP(x+y,0));
                else queue.push_back(MP(m,y-(m-x)));
                if((n-y)>=x) queue.push_back(MP(0,x+y));
                else queue.push_back(MP(x-(n-y),n));

        }
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--) {
                int m,n,d;
                cout<<"Enter m,n,d:";
                cin>>m>>n>>d;
                solve(m,n,d);
        }
        return 0;
}

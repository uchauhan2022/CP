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

void addEdge(vector<int> adj[], int s, int d){
        adj[s].push_back(d);
        adj[d].push_back(s);
}
vector<int> printLevels(vector<int> graph[], int V, int x)
{
    // array to store level of each node
    vector<int> level(V,0);
    bool marked[V];

    // create a queue
    queue<int> que;

    // enqueue element x
    que.push(x);

    // initialize level of source node to 0
    level[x] = 0;

    // marked it as visited
    marked[x] = true;

    // do until queue is empty
    while (!que.empty()) {

        // get the first element of queue
        x = que.front();

        // dequeue element
        que.pop();

        // traverse neighbors of node x
        for (int i = 0; i < graph[x].size(); i++) {
            // b is neighbor of node x
            int b = graph[x][i];

            // if b is not marked already
            if (!marked[b]) {

                // enqueue b in queue
                que.push(b);

                // level of b is level of x + 1
                level[b] = level[x] + 1;

                // mark b
                marked[b] = true;
            }
        }
    }

    return level;
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
          vector<int> adj[n+1];
          FOR(i,0,n-1,1){
            int a,b;
            cin>>a>>b;
            addEdge(adj,a,b);
          }
          vector<int> levels = printLevels(adj,n,1)
          int maxLevel = 0, nextMax = 0;
          int count = 0;
          FOR(i,0,levels.size(),1)  maxLevel=max(maxLevel,levels[i]);
          FOR(i,0,levels.size(),1)  {
            if(levels[i]==maxLevel) count++;
          }
          if(count>1) nextMax=maxLevel;
          else{
            FOR(i,0,level.size(),1){
              if(levels[i]!=maxLevel){
                nextMax=max(nextMax,levels[i]);
              }
            }
          }



        }
        return 0;
}

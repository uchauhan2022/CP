#include "bits/stdc++.h"
using namespace std;
#define FOR(i, j, k) for (int i=j; i<k; i+=1)
#define RFOR(i, j, k) for (int i=j; i>=k; i-=1)
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

void topsort(int start, vector<pair<int,int> > adj[],stack<int> &st, vector<int> &visited){
        visited[start]=1;
        for(int i = 0; i<adj[start].size(); i++) {
                if(!visited[adj[start][i].F]) {
                        topsort(adj[start][i].F,adj,st,visited);
                }
        }
        st.push(start);
}
vector<int> topologicalSort(vector<pair<int,int> > adj[], int n){
        vector<int> visited(n,0);
        stack<int> st;
        for(int i = 0; i<n; i++) {
                if(!visited[i]) {
                        topsort(i,adj,st,visited);
                }
        }
        vector<int> ans;
        while(!st.empty()) {
                ans.push_back(st.top());
                st.pop();
        }
        return ans;
}
void distance(vector<pair<int,int> > adj[], int n, vector<int> topo){
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        for(int i = 0; i<n; i++) {
                if(dist[topo[i]]!=INT_MAX) {
                        for(int j = 0; j<adj[topo[i]].size(); j++) {
                                dist[adj[topo[i]][j].F]=min(dist[adj[topo[i]][j].F],dist[topo[i]]+adj[topo[i]][j].S);
                        }
                }
        }
        for(int i = 0; i<n; i++) {
                cout<<dist[i]<<" ";
        }
        cout<<endl;
}

void addEdge(vector<pair<int,int> > adj[], int s,int w, int d){
        adj[s].push_back(MP(d,w));
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout<<"Enter number of testcases : ";
        int t;
        cin>>t;
        while(t--) {
                cout<<"Enter number of vertices : ";
                int v, e;
                cin>>v;
                cout<<"Enter number of edges : ";
                cin>>e;
                cout<<"Enter the edges pair and weight one by one:-"<<endl;
                vector<pair<int,int> > adj[v];
                for(int i = 0; i<e; i++) {
                        int source,destination,weight;
                        cin>>source>>destination>>weight;
                        addEdge(adj,source,weight,destination);
                }
                distance(adj,v,topologicalSort(adj, v));

        }
        return 0;
}

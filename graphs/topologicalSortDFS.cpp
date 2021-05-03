#include "bits/stdc++.h"
using namespace std;
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
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

void topsort(int start, vector<int> adj[],stack<int> &st, vector<int> &visited){
  visited[start]=1;
  for(int i = 0; i<adj[start].size(); i++){
    if(!visited[adj[start][i]]){
      topsort(adj[start][i],adj,st,visited);
    }
  }
  st.push(start);
}

void topologicalSort(vector<int> adj[], int n){
  vector<int> visited(n,0);
  stack<int> st;
  cout<<"topologicalSort :";
  for(int i = 0; i<n; i++){
    if(!visited[i]){
      topsort(i,adj,st,visited);
    }
  }
  while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl;
}
void addEdge(vector<int> adj[], int s, int d){
        adj[s].push_back(d);
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
                cout<<"Enter the edges pair one by one:-"<<endl;
                vector<int> adj[v];
                for(int i = 0; i<e; i++) {
                        int source,destination;
                        cin>>source>>destination;
                        addEdge(adj,source,destination);
                }
                topologicalSort(adj,v);
        }
        return 0;
}

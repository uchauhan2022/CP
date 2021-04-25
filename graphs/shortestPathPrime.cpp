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

void SieveOfEratosthenes(vector<int> &v)
{
    int n = 9999;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 1000; p <= n; p++)
        if (prime[p])
            v.push_back(p);
}
int bfs(vector<int> adj[], int source, int destination, int n){
  vector<int> visited(n,0);
  visited[source]=1;
  list<int> queue;
  queue.push_back(source);
  while(!queue.empty()){
    int x = queue.front();
    queue.pop_front();
    for(int i = 0; i<adj[x].size(); i++){
      if(!visited[adj[x][i]]){
        visited[adj[x][i]]=visited[x]+1;
        queue.push_back(adj[x][i]);
      }
      if(adj[x][i]==destination){
        return visited[adj[x][i]]-1;
      }
    }
  }
  return 0;
}
void addEdge(vector<int> adj[],int s, int d){
  adj[s].push_back(d);
  adj[d].push_back(s);
}
bool compare(int num1, int num2)
{
    // To compare the digits
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    int c = 0;
    if (s1[0] != s2[0])
        c++;
    if (s1[1] != s2[1])
        c++;
    if (s1[2] != s2[2])
        c++;
    if (s1[3] != s2[3])
        c++;

    // If the numbers differ only by a single
    // digit return true else false
    return (c == 1);
}
// bool compare(int a, int b){
//   int count = 0;
//   for(int i = 0; i<3; i++){
//     if(b%10!=a%10){
//       count++;
//     }
//     a/=10;
//     b/=10;
//   }
//   if(count==1)  return true;
//   return false;
// }
void solve(int n1, int n2){
  vector<int> prime;
  SieveOfEratosthenes(prime);
  vector<int> adj[prime.size()];
  FOR(i,0,prime.size()){
    FOR(j,0,prime.size()){
      if(compare(prime[i],prime[j])){
        addEdge(adj,i,j);
      }
    }
  }
  int i1,i2;
  for(int i = 0; i<prime.size(); i++){
    if(n1==prime[i]){
      i1=i;
    }
    if(n2==prime[i]){
      i2=i;
    }
  }

  cout<<bfs(adj,i1,i2,prime.size())<<endl;
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--){
          int n1,n2;
          cin>>n1>>n2;
          solve(n1,n2);
        }
        return 0;
}

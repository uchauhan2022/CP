// IP = wt[], val[], W
// OUTPUT = max value
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

int td[16][8];
int dp[17][9];
// RECURSIVE APPROACH
int knapsack(int wt[], int val[], int W, int n){
  if(n==0 || W==0){
    return 0;
  }
  if(wt[n-1]<=W){
    return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1));
  }
  else{
    return knapsack(wt,val,W,n-1);
  }
}

//  MEMORISE RECURSIVE
int memorisedKnapsack(int wt[], int val[], int W, int n){
  if(n==0 || W==0){
    return 0;
  }
  if(dp[W][n]!=-1)  return dp[W][n];
  if(wt[n-1]<=W){
    return dp[W][n]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1));
  }
  else{
    return dp[W][n]=knapsack(wt,val,W,n-1);
  }
}

// TOP DOWN APPROACH
int topdown(int wt[], int val[], int W, int n){
  for(int i = 0; i<=W; i++){
    td[i][0] = 0;
  }
  for(int i = 0; i<=n; i++){
    td[0][i]=0;
  }
  for(int i = 1; i<=W; i++){
    for(int j = 1; j<=n; j++){
      if(wt[j-1]<=i){
        td[i][j]=max(td[i-wt[j-1]][j-1]+val[j-1], td[i][j-1]);
      }
      else{
        td[i][j]=td[i][j-1];
      }
    }
  }
  return td[W][n];

}

int main()
{
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int wt[]={2,4,6,3,25,7,5};
    int val[]={2,3,1,4,6,3,2};
    int W = 15;
    int n = 7;
    cout<<"Basic Recursion ans = "<<knapsack(wt,val,W,7)<<endl;
    //dp table initialise
    for(int i = 0; i<17; i++){
      for(int j = 0; j<9; j++){
        dp[i][j]=-1;
      }
    }
    cout<<"Memorized Recursion ans = "<<memorisedKnapsack(wt,val,W,7)<<endl;
    cout<<"Top Down ans = "<<topdown(wt,val,W,7)<<endl;

  return 0;
}

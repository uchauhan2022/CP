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
        int n,t;
        cin>>n>>t;
        int k;
        cin>>k;
        int start, mid ,end;
        start = 1;
        end = n;

        while(start<=end){
          mid = start+(end-start)/2;
          int temp1,temp2;
          cout<<"? "<<start<<" "<<mid<<endl;
          cin>>temp1;
          if((mid-start+1)-temp1>=k){
            // cout<<"K :"<<k<<endl;
            // cout<<"start :"<<start<<endl;
            // cout<<"mid :"<<mid<<endl;
            if(start==mid && !temp1){
              cout<<"! "<<start<<endl;
              break;
            }
            else if(start==mid){
              cout<<"? "<<start+1<<" "<<mid+1<<endl;
              cin>>temp2;
              if(temp2==0){
                cout<<"! "<<start+1<<endl;
                break;
              }
            }
            end = mid;
          }
          else{
            // cout<<"K :"<<k<<endl;
            // cout<<"end :"<<end<<endl;
            // cout<<"mid :"<<mid<<endl;
            k-=(mid-start+1)-temp1;
            start = mid+1;
          }
        }
        return 0;
}

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

lli minJumps(string seats)
{
    // Store the indexes
    vector<lli> position;

    // Stores the count of occupants
    lli count = 0;

    // Length of the string
    int len = seats.length();

    // Traverse the seats
    for (int i = 0; i < len; i++) {

        // If current place is occupied
        if (seats[i] == '*') {

            // Push the current position
            // in the vector
            position.push_back(i - count);
            count++;
        }
    }

    // Base Case:
    if (count == len || count == 0)
        return 0;

    // The index of the median element
    lli med_index = (count - 1) / 2;

    // The value of the median element
    lli med_val = position[med_index];

    lli ans = 0;

    // Traverse the position[]
    for (lli i = 0;
         i < position.size(); i++) {

        // Update the ans
        ans = (ans+ abs(position[i]- med_val));
    }

    // Return the final count
    return ans ;
}

int solve2(string A){
        vector<int> arr;
        for(int i=0; i<A.length(); i++)
        {
                if(A[i]=='*')
                        arr.push_back(i);
        }
        int mid = floor(arr.size()/2);
        int cp = arr[floor(arr.size()/2)];
        int sum = 0;

        for(int i=0; i<arr.size(); i++)
        {
                int start = arr[i];
                int end = cp - mid +i;

                sum = (sum + abs(end-start))%MOD;
        }

        return sum;
}
int solve(string a, int n){

        vector<int> v;
        for(int i = 0; i<n; i++) {
                if(a[i]=='*') {
                        v.push_back(i);
                }
        }
        int p=v.size();
        int m = p/2;
        int ans=0;
        for(int i = 0; i<p; i++) {
                ans+=(abs(v[i]-v[m])-abs(m-i));
        }
        return ans;
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
                string a;
                cin>>a;
                cout<<minJumps(a)<<endl;
        }
        return 0;
}

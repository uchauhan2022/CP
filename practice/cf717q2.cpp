#include <bits/stdc++.h>
using namespace std;

int main()
{
        int t;
        cin>>t;

        while(t--)
        {
                int n;
                cin>>n;

                vector<int> v(n,0);

                int res=0;

                for(int i=0; i<n; i++)
                {
                        cin>>v[i];
                        res^=v[i];
                }
                if(res==0)
                        cout<<"YES"<<endl;
                else
                {
                        cout<<"Res = "<<res<<endl;
                        int num=0, ind=0;
                        for(int i=0; i<n; i++)
                        {
                                num^=v[i];
                                if(num==0){
                                  cout<<"i = "<<i<<endl;
                                  ind=i;
                                }
                        }
                        cout<<"Out of first"<<endl;
                        num=0;
                        int count=0;
                        cout<<"Ind = "<<ind<<endl;
                        for(int i=0; i<=ind; i++)
                        {
                                num^=v[i];
                                cout<<"Num at i="<<i<<" is "<<num<<endl;
                                if(num==res)
                                {
                                        count++;
                                        cout<<"count incremented to"<<count<<endl;
                                        num=0;
                                        //cout<<count<<endl;
                                }
                        }
                        cout<<"num,count = "<<num<<" "<<count<<endl;
                        if(num==0 && count%2==0 && count>0)
                                cout<<"YES"<<endl;
                        else
                                cout<<"NO"<<endl;
                }
        }

        return 0;
}

#include<bits/stdc++.h>

using namespace std;

int bag[1003][1111];

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {

        int n,m;
        cin>>n>>m;
        int goal=1<<m;
        memset(bag,-1,sizeof(bag));
        bag[0][0]=0;

        for(int i=1 ; i<=n ; i++)
        {
            int q,s;
            cin>>q>>s;
            int w=0;
            for(int j=0; j<s; j++)
            {
                int c;
                cin>>c;
                w=w|(1<<(c-1));
            }
            for(int j=0; j<goal; j++)
            {
                if(bag[i-1][j]==-1)
                    continue;
                bag[i][j^w]=max(bag[i][j^w],bag[i-1][j]+q);
                bag[i][j]=max(bag[i][j],bag[i-1][j]);
            }
        }
        cout<<bag[n][goal-1]<<endl;

    }
    return 0;
}

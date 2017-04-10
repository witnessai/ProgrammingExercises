#include <bits/stdc++.h>

using namespace std;

int val[2][1004];

vector<int> tree[1004];

void dfs(int v,int fa,int tn,int goal,int &cnt)
{
    if(cnt==0)
        return ;
    int len=tree[v].size();
    for(int i=0 ; i<len ; i++)
    {
        int u=tree[v][i];
        if(u!=fa)
        {
            dfs(u,v,tn,goal,cnt);
            val[tn][v]+=val[tn][u];
        }
    }
    if(val[tn][v]==goal&&v!=1)
    {
        val[tn][v]=0;
        cnt--;
    }
}


int main()
{
    //freopen("std.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //freopen("b.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sum=0;
        memset(val,0,sizeof(val));
        for(int i=1 ; i<=n ; i++)
        {
            cin>>val[0][i];
            val[1][i]=val[0][i];
            sum+=val[0][i];
            tree[i].clear();
        }
        for(int i=1 ; i<n ; i++)
        {
            int a,b;
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        if(sum%2!=0 && sum%3!=0)
        {
            cout<<"He can give gift to 0 teammate."<<endl;
            continue;
        }
        int save=2;
        if(sum%3==0)
        {
            dfs(1,0,0,sum/3,save);
            if(save==0)
            {
                cout<<"He can give gift to 2 teammates."<<endl;
                continue;
            }

        }
        if(sum%2==0)
        {
            save=1;
            dfs(1,0,1,sum/2,save);
            if(save==0)
            {
                cout<<"He can give gift to 1 teammate."<<endl;
                continue;
            }
        }
        cout<<"He can give gift to 0 teammate."<<endl;
    }
    return 0;
}

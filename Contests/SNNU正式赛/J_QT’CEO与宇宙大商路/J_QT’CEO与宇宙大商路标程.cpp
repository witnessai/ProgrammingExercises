#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define RDI(x) scanf("%d",&x)
#define RDII(x,y) scanf("%d%d",&x,&y)
#define LL long long
#define REP(i,x,y) for (int i=x;i<=y;i++)
#define REPF(i,x,y) for (int i=x;i>=y;i--)
#define MEM(x,y) memset(x,y,sizeof(x))
#define P 1000000000
using namespace std;
int fa[10010];
int w[10010];
int v[10010];
int dp[10010][10010];
int n,k;
vector<int> E[10010];
void ss(int id,int res)
{
    if (res<0) return ;
    REP(i,0,(int)(E[id].size())-1)
    {
        int temp=E[id][i];
        REP(j,0,k-v[temp]) dp[temp][j]=dp[id][j]+w[temp];
        ss(temp,k-v[temp]);
        REP(j,1,k) dp[id][j]=max(dp[id][j],dp[temp][j-v[temp]]);
    }
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    RDI(t);
    while (t--)
    {
        MEM(fa,0);MEM(w,0);
        MEM(dp,0);MEM(v,0);
        RDII(n,k);
        REP(i,1,n) E[i].clear();
        REP(i,1,n)
        {
            RDI(fa[i]);
            RDII(w[i],v[i]);
            E[fa[i]].push_back(i);
        }
        ss(1,k);
        cout<<dp[1][k]+w[1]<<endl;\
    }

}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
 
using namespace std;
const int MAX = 1000000+10;
int add[MAX];
int dis[MAX];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        int x,y;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            add[i]=x+y;
        }
        sort(add,add+n);
        for(int i=0;i<n-1;i++)
        {
            dis[i]=add[i+1]-add[i];
 
        }
        sort(dis,dis+n-1);
        printf("%d\n",dis[0]);
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define rep(i,x,y) for(int i=x;i<y;i++)
using namespace std;

int main()
{

    int t;cin>>t;
    int n;
    long long f[331];
    f[0]=1;
    f[1]=1;

    rep(i,1,330)
        rep(j,0,i+1)
          f[i+1] = f[j] * f[i-j] + f[i+1] ;

    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",f[n-1]);

    }
    return 0;
}

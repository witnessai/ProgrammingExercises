#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
 
using namespace std;
 
int main()
{
    int t;
    scanf("%d",&t);
    long long n;
    while(t--)
    {
        long long sum=0;
        scanf("%lld",&n);
        while(n!=0)
        {
            sum+=n/3;
            n=n/3;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
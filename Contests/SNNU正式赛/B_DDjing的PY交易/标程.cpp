#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    while(scanf("%d\n",&n)!=EOF)
    {
        int tempnum=0;
        int maxnum=0;
        char nowc;
        char lastc=0;
        for(int i=0;i<n;i++)
        {
            scanf("%c",&nowc);
            if(nowc!=lastc)
            {
                maxnum=max(maxnum,tempnum);
                lastc=nowc;
                tempnum=0;
                tempnum++;
            }
            else
            {
                tempnum++;
            }
 
        }
        maxnum=max(maxnum,tempnum);
        printf("%d\n",maxnum);
    }
    return 0;
}
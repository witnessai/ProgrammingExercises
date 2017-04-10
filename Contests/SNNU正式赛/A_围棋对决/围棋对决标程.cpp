#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
 
bool chuxian[30];  //判断这个人有没有出现过
double score[30];   //得分
 
 
void ini( )         //初始化
{
    for(int i=0; i<30; i++)
    {
        score[i]=0;
        chuxian[i]=0;
    }
}
 
//加得分
void work(int n)
{
    char c1,c2;
    int num=0;
    for(int i=0; i<n; i++)
    {
        scanf("%c %c %d",&c1,&c2,&num);
            getchar();
            chuxian[c1-'A']=1;
            chuxian[c2-'A']=1;
            switch(num)
            {
            case 1:
                score[c1-'A']+=1;
                break;
            case 0:
                score[c1-'A']+=0.5;
                score[c2-'A']+=0.5;
                break;
            case -1:
                score[c2-'A']+=1;
                break;
            }
 
    }
}
 
 
 
int main()
{
    //freopen("testwq.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        getchar();
        ini( );
        work(n);
        int p;
        double ans=0;
        for(int i=0; i<26; i++)
        {
            if(chuxian[i])   //如果出现了
                if(ans<score[i])   //判断最大的，<而不是<=能保证字典序最大
                {
                    ans=score[i];
                    p=i;
                }
        }
         
         
        char aaa='A'+p;
        printf("%c\n",aaa);
    }
}
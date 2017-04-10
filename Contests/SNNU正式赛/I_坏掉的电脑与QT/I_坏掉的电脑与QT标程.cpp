#include<bits/stdc++.h>
using namespace std;
char a[2003];
char b[2003];
char c[2003];
 
void toadd(char sa[],char sb[],int len)
{
    for(int i=0; i<len; i++)
    {
        if((sa[i]&sb[i])=='1')
        {
            for(int j=i; j<=len; j++)
            {
                if(sa[j]=='1')
                {
                    sa[j]='0';
                }
                else
                {
                    sa[j]='1';
                    break;
                }
            }
        }
        else
        {
            sa[i]=max(sa[i],sb[i]);
        }
    }
}
 
 
 
int main()
{
    int T;
    cin>>T;
    getchar();
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int la=0;
        int lb=0;
        char ch;
        int opr;
        while(1)
        {
            ch=getchar();
            if(ch=='*')
            {
                opr=1;
                break;
            }
            else if(ch=='+')
            {
                opr=0;
                break;
            }
            a[la++]=ch;
        }
        while(1)
        {
            ch=getchar();
            if(ch=='\n')
                break;
            b[lb++]=ch;
        }
        for(int i=0 ; i<la/2 ; i++)
        {
            int t=a[i];
            a[i]=a[la-i-1];
            a[la-i-1]=t;
        }
        for(int i=0 ; i<lb/2 ; i++)
        {
            int t=b[i];
            b[i]=b[lb-i-1];
            b[lb-i-1]=t;
        }
        if(opr==0)
        {
            toadd(a,b,max(la,lb));
        }
        else
        {
            for(int i=0 ; i<2002 ; i++)
                c[i]='0';
            for(int i=0,j=lb-1; i<lb; i++,j--)
            {
                if(b[i]=='1')
                {
                    toadd(c+i,a,la+i);
                }
            }
            strcpy(a,c);
        }
        la=0;
        for(int i=2002 ; i>0 ; i--)
        {
            if(a[i]>'0')
            {
                la=i;
                break;
            }
        }
        for(int i=la; i>=0; i--)
        {
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
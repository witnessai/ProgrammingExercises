#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string s;
int tab;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    tab=0;
    bool flag=0;
    while(getline(cin,s))
    {
        if(s.empty())
        {
            for(int i=0;i<tab;i++)
            cout<<" ";
            cout<<endl;
            tab-=4;
            continue;
        }
        if(s[s.length()-1]==':')
            flag=1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==',')
            {
                s.insert(i+1," ");
                i++;
            }
        }
        for(int i=0;i<tab;i++)
            cout<<" ";
        cout<<s<<endl;
        if(flag)
        {
            tab+=4;
            flag=0;
        }
    }
    return 0;
}

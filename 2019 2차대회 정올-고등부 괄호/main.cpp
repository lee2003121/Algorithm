#include<bits/stdc++.h>

using namespace std;

string dp[1005];
map<char,char> m;

string change(string x)
{
    string ret="";
    int a=x.size();
    for(int i=0; i<a; i++)
    {
        ret+=m[x[i]];
    }
    return ret;
}

void turn(int a)
{

    for(int i=1; i<=a-1; i++)
    {
        if(dp[a]=="")
        {
            dp[a]=(dp[i]+dp[a-i]);
        }
        if(dp[a].size()>dp[i].size()+dp[a-i].size())
        {
            dp[a]=(dp[i]+dp[a-i]);
        }
        else if(dp[a].size()==dp[i].size()+dp[a-i].size())
        {
            if(change(dp[a])>change(dp[i]+dp[a-i]))
            {
                dp[a]=(dp[i]+dp[a-i]);
            }
        }
    }
    if(a%2==0)
    {
        if(dp[a].size()>(dp[a/2].size()+2))
        {
            dp[a]=("("+dp[a/2]+")");
        }
        else if((dp[a].size()==(dp[a/2].size()+2)))
        {
            if(change(dp[a])>change("("+dp[a/2]+")"))
            {
                dp[a]=("("+dp[a/2]+")");
            }
        }
    }
    if(a%3==0)
    {
        if(dp[a].size()>(dp[a/3].size()+2))
        {
            dp[a]=("{"+dp[a/3]+"}");
        }
        else if((dp[a].size()==(dp[a/3].size()+2)))
        {
            if(change(dp[a])>change("{"+dp[a/3]+"}"))
            {
                dp[a]=("{"+dp[a/3]+"}");
            }
        }
    }
    if(a%5==0)
    {

        if(dp[a].size()>(dp[a/5].size()+2))
        {
            dp[a]=("["+dp[a/5]+"]");
        }
        else if((dp[a].size()==(dp[a/5].size()+2)))
        {
            if(change(dp[a])>change("["+dp[a/5]+"]"))
            {
                dp[a]=("["+dp[a/5]+"]");
            }
        }
    }
}

int main()
{
    m['('] = '1';
    m[')'] = '2';
    m['{'] = '3';
    m['}'] = '4';
    m['['] = '5';
    m[']'] = '6';

    dp[1]="()";
    dp[2]="{}";
    dp[3]="[]";

    for(int i=4; i<=1000; i++){turn(i);}

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}

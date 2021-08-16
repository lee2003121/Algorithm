#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m,mars[1002][1002],ml[1002][1002],mr[1002][1002],mm[1002][1002],result[1002];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&mars[i][j]);
        }
    }
    mm[0][0] = mars[0][0];
    for(int j=1; j<m; j++)
    {
        mm[0][j]=mm[0][j-1]+mars[0][j];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            mr[i][j] = mm[i-1][j]+mars[i][j];
            ml[i][j] = mm[i-1][j]+mars[i][j];
        }
        for(int j=1; j<m; j++){
            mr[i][j] = max(mr[i][j],mr[i][j-1]+mars[i][j]);
        }
        for(int j=m-2;j>=0;j--){
            ml[i][j] = max(ml[i][j],ml[i][j+1]+mars[i][j]);
        }
        for(int j=0; j<m; j++){
            mm[i][j] = max(mr[i][j],ml[i][j]);
        }
    }

    printf("%d",mm[n-1][m-1]);
}
//------------------------------------------------------------------------------------------------------
/*
#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m,mars[1002][1002],ml[1002][1002],mr[1002][1002],mm[1002][1002],result[1002];

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&mars[i][j]);
        }
    }
    mm[0][0] = mars[0][0];
    for(int j=1; j<m; j++)
    {
        mm[0][j]=mm[0][j-1]+mars[0][j];
    }
    for(int j=0; j<m; j++)
    {
        ml[0][j]=mm[0][j];
        mr[0][j]=mm[0][j];
    }
    for(int i=1; i<n; i++) //y
    {
        for(int j=0; j<m; j++) //x
        {
            if(j==0)
                mr[i][j]=mm[i-1][j]+mars[i][j];
            else
                mr[i][j]=max(mr[i][j-1],mm[i-1][j])+mars[i][j];
        }
        if(i!=n-1)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(j==m-1)
                    ml[i][j]=mm[i-1][j]+mars[i][j];
                else
                    ml[i][j]=max(ml[i][j+1],mm[i-1][j])+mars[i][j];
            }
            for(int j=0; j<m; j++)
            {
                mm[i][j]=max(mr[i][j],ml[i][j]);
            }
        }
    }
    printf("%d",mr[n-1][m-1]);
}
*/

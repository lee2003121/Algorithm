#include <stdio.h>

using namespace std;
int b[3],k1,k2,save[6][2],maxX,maxY;
int main()
{
    int p[501][501]= {-1,};
    for(int i=0; i<501; i++)
    {
        for(int j=0; j<501; j++)
        {
            p[i][j]=-1;
        }
    }
    for(int i=0; i<3; i++) //²¨³»´Â °¹¼ö b[0,1,2]
    {
        scanf("%d",&b[i]);
    }
    for(int i=0; i<5; i++)//ÃÖ´ñ°ª °è»ê maxX,maxY
    {
        scanf("%d %d",&k1,&k2);
        save[i][0]=k1;
        save[i][1]=k2;
        if(k1>maxX)
        {
            maxX=k1;
        }
        if(k2>maxY)
        {
            maxY=k2;
        }
    }
    for(int i=0; i<=maxX; i++)
    {
        for(int j=0; j<=maxY; j++)
        {
            for(int k=0; k<3; k++)
            {
                if(i-b[k]>=0&&p[i-b[k]][j]==-1)
                {
                    p[i][j]=1;
                    break;
                }
                if(j-b[k]>=0&&p[i][j-b[k]]==-1)
                {
                    p[i][j]=1;
                    break;
                }
                if(i-b[k]>=0&&p[i-b[k]][j]==1)
                {
                    p[i][j]=-1;
                }
                if(j-b[k]>=0&&p[i][j-b[k]]==1)
                {
                    p[i][j]=-1;
                }

            }
        }
    }
    for(int i=0; i<5; i++)
    {
        if(p[save[i][0]][save[i][1]]==1)
        {
            printf("A\n");
        }
        else
        {
            printf("B\n");
        }
    }


}

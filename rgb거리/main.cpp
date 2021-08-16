#include <stdio.h>

using namespace std;
int count,house[3],num,cheap[1003][3];
int main()
{
    scanf("%d",&num);
    for(int i=1; i<=num; i++)
    {
        for(int j=0; j<3; j++)
        {
            scanf("%d",&house[j]);
        }
        for(int j=0; j<3; j++)
        {
            if(j==0)
            {
                if(cheap[i-1][1]>cheap[i-1][2])
                {
                    cheap[i][j]=cheap[i-1][2]+house[j];
                }
                else
                {
                    cheap[i][j]=cheap[i-1][1]+house[j];
                }
            }
            if(j==1)
            {
                if(cheap[i-1][0]>cheap[i-1][2])
                {
                    cheap[i][j]=cheap[i-1][2]+house[j];
                }
                else
                {
                    cheap[i][j]=cheap[i-1][0]+house[j];
                }
            }
            if(j==2)
            {
                if(cheap[i-1][0]>cheap[i-1][1])
                {
                    cheap[i][j]=cheap[i-1][1]+house[j];
                }
                else
                {
                    cheap[i][j]=cheap[i-1][0]+house[j];
                }
            }
        }
    }
    if(cheap[num][0]<=cheap[num][1]&&cheap[num][0]<=cheap[num][2])
    {
        printf("%d",cheap[num][0]);
    }
    else if(cheap[num][1]<=cheap[num][2]&&cheap[num][1]<=cheap[num][0])
    {
        printf("%d",cheap[num][1]);
    }
    else
    {
        printf("%d",cheap[num][2]);
    }
}

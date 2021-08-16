#include<stdio.h>

using namespace std;
int num,stair[301][2],score[301];
int main()
{
    scanf("%d",&num);
    scanf("%d",&score[0]);
    stair[0][0]=score[0];
    scanf("%d",&score[1]);
    stair[1][0]=score[0]+score[1];
    stair[1][1]=score[1];

    for(int i=2; i<num; i++)
    {
        scanf("%d",&score[i]);
        stair[i][0]=stair[i-1][1]+score[i];
        if(stair[i-2][1]>stair[i-2][0])
        {
            stair[i][1]=stair[i-2][1]+score[i];
        }
        else
        {
            stair[i][1]=stair[i-2][0]+score[i];
        }
    }

    if(stair[num-1][0]>stair[num-1][1])
    {
        printf("%d",stair[num-1][0]);
    }
    else
    {
        printf("%d",stair[num-1][1]);
    }

}

#include <stdio.h>

using namespace std;
int n,dp[101],way[101],tallest;

struct st
{
    int wide;
    int tall;
    int weight;
    int savepos;
};
struct st arr[101];
int main()
{


    scanf("%d",&n);
    for(int i=0; i<n; i++) //입력
    {
        scanf("%d %d %d",&arr[i].wide,&arr[i].tall,&arr[i].weight);
        arr[i].savepos=i+1;
    }
    for(int i=0; i<n; i++)//정렬
    {
        for(int j=i; j<n; j++)
        {
            if( arr[i].wide <arr[j].wide)
            {
                st temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        way[i]=-1;
    }

    for(int i=0; i<n; i++)
    {
        int a=0;
        for(int j=0; j<=i; j++)
        {
            if(arr[i].weight<arr[j].weight&&tallest<=arr[j].tall)
            {
                tallest=arr[j].tall;
                way[i]=j;
            }
        }
        arr[i].tall+=tallest;
        tallest=0;
    }
    int tallpos=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].tall>tallest)
        {
            tallest=arr[i].tall;
            tallpos=i;
        }
    }
    int count=0;
    int pos=tallpos;
    int pos1=tallpos;
    while(pos!=-1)
    {
        pos=way[pos];
        count++;
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++)
    {
        printf("%d\n",arr[pos1].savepos);
        pos1=way[pos1];
    }

}

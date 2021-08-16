#include<stdio.h>

using namespace std;

int board[100005],save[10005],bundle=-1001;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&board[i]);
    }
    save[0]=board[0];
    for(int i=1; i<n; i++)
    {
        if(save[i-1]<=0)
        {
            save[i]=board[i];
        }
        else
        {
            save[i]=save[i-1]+board[i];
        }
    }
    for(int i=0; i<n; i++)
    {
            if(bundle<save[i])
            {
                bundle=save[i];
            }
    }

    printf("%d",bundle);
}

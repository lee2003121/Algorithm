#include<stdio.h>
#include<algorithm>

using namespace std;

int n,state[100001],m,total,_max,_min,mid,result;

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&state[i]);
        if(state[i]>_max)
        {
            _max=state[i];
        }
    }
    scanf("%d",&m);
    _min=1;
    while(_max>=_min)
    {
        mid=(_max+_min)/2;
        total=0;
        for(int i=0;i<n;i++)
        {
            if(mid>state[i])
            {

                total+=state[i];
            }
            else
            {
                total+=mid;
            }
        }
        if(total>m)
        {
            _max=mid-1;
        }
        else
        {
            result=mid;
            _min=mid+1;
        }
    }
    printf("%d",result);


}

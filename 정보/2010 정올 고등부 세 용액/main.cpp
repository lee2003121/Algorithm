#include<stdio.h>
#include<algorithm>

using namespace std;

typedef long long int INT;

INT n,arr[5003],c,low=100000000000000,x,y,root[3];

INT close(int a,int b,INT d)//-(arr[i]+arr[j])의 가장가까운값을 이진탐색으로
{
    int mid=(a+b+1)/2;

    if(a>b)
    {
        return arr[mid];
    }
    else if(a+1==b||b==a)
    {
        if(abs(arr[a]-d)<abs(arr[b]-d))
        {
            return arr[a];
        }
        else
        {
            return arr[b];
        }
    }


    if(arr[mid]< d)
    {
        if(abs(arr[mid]-d)>abs(arr[mid+1]-d))
        {
            return close(mid+1,b, d);
        }
        else
        {
            return arr[mid];
        }
    }
    else
    {

        if(abs(arr[mid]-d)>abs(arr[mid-1]-d))
        {
            return close(a,mid-1, d);
        }
        else
        {
            return arr[mid];
        }
    }
}

int main()
{
    scanf("%lld",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    sort(arr,arr+n);
    for(x=0; x<n-2; x++)
    {
        for(y=x+1; y<n-1; y++)
        {
            c=arr[x]+arr[y]+close(y+1,n-1, -(arr[x]+arr[y]));
            if(abs(low)>abs(c))
            {
                low=c;
                root[0]= arr[x];
                root[1]= arr[y];
                root[2]= c-arr[x]-arr[y];

            }
        }
    }
    sort(root,root+3);
    for(int i=0; i<3; i++)
    {
        printf("%lld ",root[i]);
    }


}

#include <bits/stdc++.h>
#define INT long long int

using namespace std;

INT mini=30000000005,arr[5005],res[3];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    sort(arr,arr+n);
    for(int i=0; i<n-2; i++){
        int j, k;
        j = i+1; k = n-1;
        while(1){
            if(j>=k)
                break;
            INT x = arr[i]+arr[j]+arr[k];
            INT X=abs(x);
            if(mini > X){
                mini = X;
                res[0]=arr[i];
                res[1]=arr[j];
                res[2]=arr[k];
            }
            if(x>0){
                k--;
            }else{
                j++;
            }
        }
    }
    for(int i=0; i<3; i++){
        printf("%lld ", res[i]);
    }
    return 0;
}

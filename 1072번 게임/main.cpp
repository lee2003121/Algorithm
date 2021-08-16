#include<bits/stdc++.h>
int main()
{
    long long rate,lastrate;//rate는 승률 lastrate는 이긴판수를 포함한 승률

    long long first, last, mid,x,y;

    scanf("%lld %lld", &x, &y);
    rate = y * 100 / x;
    if (rate >= 99)//승률99에서 100퍼는 못만듬
    {
        printf("-1\n");
        return 0;
    }

    first = 0;
    last = x;

    //-------------------------이진탐색
    while (first <= last)
    {
        mid = (first + last) / 2;// 이진탐색의 중간
        lastrate = (y + mid) * 100 / (x + mid); //lastrate는 이긴판수를 포함한 승률
        if (rate< lastrate)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    printf("%lld\n", first);

}

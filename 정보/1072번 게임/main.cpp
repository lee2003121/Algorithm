#include<bits/stdc++.h>
int main()
{
    long long rate,lastrate;//rate�� �·� lastrate�� �̱��Ǽ��� ������ �·�

    long long first, last, mid,x,y;

    scanf("%lld %lld", &x, &y);
    rate = y * 100 / x;
    if (rate >= 99)//�·�99���� 100�۴� ������
    {
        printf("-1\n");
        return 0;
    }

    first = 0;
    last = x;

    //-------------------------����Ž��
    while (first <= last)
    {
        mid = (first + last) / 2;// ����Ž���� �߰�
        lastrate = (y + mid) * 100 / (x + mid); //lastrate�� �̱��Ǽ��� ������ �·�
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

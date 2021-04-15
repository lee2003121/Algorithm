#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int need,company,l,num,count=0,k=0,money=0;
    vector<pair<int,int> > vc;
    scanf("%d %d",&need,&company);
    for(int i=0; i<company; i++)
    {
        scanf("%d %d",&l,&num);
        vc.push_back(make_pair(l,num));
    }

    sort(vc.begin(),vc.end());

    while(count<need)
    {

        if(count+vc[k].second<=need)
        {
            count+=vc[k].second;
            money+=vc[k].first*vc[k].second;

        }
        else
        {
            money+=vc[k].first*(need-count);
            break;
        }
        k++;
    }
    printf("%d",money);


}

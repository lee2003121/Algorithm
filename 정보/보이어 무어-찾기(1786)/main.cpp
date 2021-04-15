#include <bits/stdc++.h>

using namespace std;

char s[1000002],w[1000002];
int s_size,w_size,arr[10000],jump;
vector <int>vc;
int main()
{
    cin.getline(s,1000002);
    cin.getline(w,1000002);
    s_size=strlen(s);
    w_size=strlen(w);
    for(int i=w_size-1; i>=0; i--)
    {
        if(arr[w[i]]==0)
        {
            arr[w[i]]=w_size-i;
        }
    }
    for(int i=w_size-1; i<s_size;)
    {

        for(int j=0; j<w_size; j++) //탐색
        {
            int s_pos = i-j;
            int w_pos = w_size-j-1;

            if(w[w_pos]!=s[s_pos])//불일치
            {
                char bad = s[s_pos];
                jump=0;
                if(arr[bad]>j+1)//필요한 단어가 앞에 있을 때
                {
                    jump = arr[bad]-(j+1);
                }
                else if(arr[w[i-j]]==0)//필요한 단어가 없을때
                {
                    jump = w_size;
                }
                else//필요한 단어가 뒤에 있을 때
                {
                    int count = -1;
                    for(int k=w_pos; k>=0; k--)
                    {
                        count++;
                        if(bad==w[k])
                        {
                            jump = count;
                            printf("i : %d, count : %d\n",i,count);
                            break;
                        }
                    }
                }
                i+=jump;
                printf("i : %d\n",i);
                break;
            }
            if(j==w_size-1)//일치
            {
                vc.push_back(s_pos+1);
                i++;
            }
        }

    }
    int l=vc.size();
    printf("%d\n",l);
    for(int i=0; i<l; i++)
    {
        printf("%d ",vc[i]);
    }
}

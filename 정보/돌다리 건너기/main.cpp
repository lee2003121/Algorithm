#include <stdio.h>
#include <string.h>

using namespace std;

char road[21];
char stone[2][101];
int count[2][101];
int check[2][101][101];
int main()
{
    scanf("%s",road);
    scanf("%s",stone[0]);
    scanf("%s",stone[1]);
    int roadl=strlen(road);
    int stonel=strlen(stone[0]);
    int a=2;
    for(int j=0; j<2; j++)
    {
        for(int i=0; i<stonel; i++)
        {

            check[j][i][1]=(road[0]==stone[j][i])?1:0;
        }
    }

    for(int i=1; i<roadl; i++)
    {
        for(int j=0; j<stonel; j++)
        {
            if(road[i]==stone[0][j])
            {
                int many=0;
                for(int k=0; k<j; k++)
                {
                    many+=check[1][k][i];
                }
                check[0][j][i+1]=many;
            }
            if(road[i]==stone[1][j])
            {
                int many=0;
                for(int k=0; k<j; k++)
                {

                        many+=check[0][k][i];

                }
                check[1][j][i+1]=many;
            }
        }
    }
    int c=0;
    for(int j=0; j<stonel; j++)
    {
            c+=check[0][j][roadl];
            c+=check[1][j][roadl];
    }
    printf("%d",c);
}

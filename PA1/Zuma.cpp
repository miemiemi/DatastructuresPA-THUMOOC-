#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


char s[20050];

int solve(int len, int pos , char color)
{
    for(int i=len;i>pos;i--)
        s[i]=s[i-1];
    s[pos]=color;
    len++;

    for(int i=0;i<len-2;i++)
    {
        if(s[i]==s[i+1]&&s[i+1]==s[i+2])
        {
            int r,sub;
            for(r=i+2;r<len&&s[r]==s[i];r++);
            sub=r-i;
            for(int j=i;j<len;j++)
                s[j]=s[j+sub];
            len-=sub;
            i=-1;
        }
    }
    return len;
}

int main()
{
    cin.getline(s,10005);
    int len = strlen(s);
    int n;
    scanf("%d",&n);
    int pos;
    char color;
    while (n--)
    {
        scanf("%d %c",&pos,&color);
        len = solve(len,pos,color);
        if(len)
            printf("%s\n",s);
        else
            printf("-\n");
    }
    
    return 0;
}
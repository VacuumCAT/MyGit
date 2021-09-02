#include <iostream>

using namespace std;

const int N=20;

//本题按层寻找，然后用三个数组标记此行，正斜线，反斜线
char g[N][N];
int n,col[N],dg[N],udg[N];

void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++) puts(g[i]);
        puts("");
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!col[i] && !dg[i+u] && !udg[i-u+n]){
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[i-u+n]=true;
            dfs(u+1);
            col[i]=dg[u+i]=udg[i-u+n]=false;
            g[u][i]='.';
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            g[i][j]='.';
        }
    }
    dfs(0);
    return 0;
}
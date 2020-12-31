#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int mp[maxn][15];
bool used[maxn];
int cnt[maxn],cap[maxn];//cnt[i]记录现在第i个星球有多少个人，cap[i]记录 i星球的容量 
int mat[maxn][15],n,m;//mat[i][j]表示第i个星球第j个匹配的人是谁 

bool dfs(int x)
{
    for(int i=0;i<m;i++)
    {
        if(mp[x][i]&&!used[i])//表示第x个人可以匹配第i个星球 
        {
            used[i]=1;
            if(cnt[i]<cap[i])//并且该星球人数未上限，直接匹配 
            {
                mat[i][cnt[i]++]=x;
                return true;
            }
            else//人数上限，查找该星球上所以人是否可以让位置 
            {
                for(int j=0;j<cap[i];j++)
                {
                    if(dfs(mat[i][j]))//可以让位置 
                    {
                        mat[i][j]=x;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool solve()
{
    for(int i=0;i<n;i++)//查看是否所以人可以逃离 
    {
        for(int j=0;j<=m;j++)
            used[j]=0;
        if(!dfs(i))//该人不可以逃离就输出NO 
            return false;
    }
    return true;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                scanf("%d",&mp[i][j]);
        }
        for(int i=0;i<m;i++)
            scanf("%d",&cap[i]);
        if(solve())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
} 
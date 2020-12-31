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
int cnt[maxn],cap[maxn];//cnt[i]��¼���ڵ�i�������ж��ٸ��ˣ�cap[i]��¼ i��������� 
int mat[maxn][15],n,m;//mat[i][j]��ʾ��i�������j��ƥ�������˭ 

bool dfs(int x)
{
    for(int i=0;i<m;i++)
    {
        if(mp[x][i]&&!used[i])//��ʾ��x���˿���ƥ���i������ 
        {
            used[i]=1;
            if(cnt[i]<cap[i])//���Ҹ���������δ���ޣ�ֱ��ƥ�� 
            {
                mat[i][cnt[i]++]=x;
                return true;
            }
            else//�������ޣ����Ҹ��������������Ƿ������λ�� 
            {
                for(int j=0;j<cap[i];j++)
                {
                    if(dfs(mat[i][j]))//������λ�� 
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
    for(int i=0;i<n;i++)//�鿴�Ƿ������˿������� 
    {
        for(int j=0;j<=m;j++)
            used[j]=0;
        if(!dfs(i))//���˲�������������NO 
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
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxnum=101;
bool a[maxnum][maxnum];//图的邻接矩阵
bool x[maxnum]; //当前解
int cn;//当前团的顶点数
int bestn;//当前的最优解
int n;//图G的顶点数
int e;//图G的边数
void backtrack(int i)
{
    int j;
    if(i>n)
    {
        bestn=cn;
        printf("%d\n",bestn);
        for(j=1; j<=n; j++)
        {
            if(x[j])
            {
                printf("%d ",j);
            }
        }
        printf("\n");
        return ;
    }

    bool ok=true;
    for(j=1; j<i; j++)
    {
        if(x[j]&&!a[j][i])//i与j不相连
        {
            ok=false;
            break;
        }
    }
    if(ok)//进入左子树
    {
        cn++;
        x[i]=true;
        backtrack(i+1);
        cn--;
    }
    if(cn+n-i>bestn)  //剪枝
    {
        x[i]=false;
        backtrack(i+1);
    }
}

int main()
{
    int i,u,v;
    memset(a,false,sizeof(a));
    memset(x,false,sizeof(x));
    scanf("%d%d",&n,&e);
    for(i=0; i<e; i++)
    {
        scanf("%d%d",&u,&v);
        a[u][v]=true;
        a[v][u]=true;
    }
    cn=bestn=0;
    backtrack(1);
    return 0;
}

/*
5 7
1 2
1 4
1 5
2 5
2 3
3 5
4 5
*/
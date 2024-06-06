#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 65; // 设置矩阵的大小
int graph[N][N];   // 用邻接矩阵存储图
bool x[N];         // 是否将i个顶点加入团中
bool bestx[N];     // 记录最优已经放入团中的顶点
int bestn;         // 记录最优值

int n;             // 顶点个数
int cn;            // 已经放入团中的结点数


bool place(int t) // 判断是否能放进团中
{
    for (int j = 1; j < t; j++) // 判断目前扩展的t顶点和前面t-1个顶点是否相连。
    {
        if (x[j] && graph[t][j] == 0) // 如果不相连
        {
            return false; // 返回false
        }
    }
    return true; // 如果相连。返回true
}

void backtrack(int t) // 回溯，递推
{
    if (t > n) // 当到达叶子结点
    {
        bestn = cn; // 记录最优值
        memcpy(bestx, x, sizeof(x)); // 记录最优已经放入团中的顶点
        return;
    }
    if (place(t)) // 如果能放进团中
    {
        x[t] = true; // 标为true
        cn++;        // 个数+1
        backtrack(t + 1); // 向下递推
        cn--;        // 向上回溯
    }
    if (cn + n - t > bestn) // 限界条件，进入右子树，不能加入团中。
    {
        x[t] = false; // 不能放入团中，标为false
        backtrack(t + 1); // 向下递推。
    }
}

int maxClique(int numNodes, vector<pair<int, int>>& edges) {
    n = numNodes;
    memset(graph, 0, sizeof(graph));
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    bestn = 0;
    cn = 0;
    backtrack(1);
    return bestn;
}

int main()
{
    int numNodes, numEdges;
    // cout << "Enter the number of nodes: ";
    cin >> numNodes >> numEdges;
    // cout << "Enter the number of edges: ";
    // cin >> numEdges;

    vector<pair<int, int>> edges;
    // cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int maxCliqueSize = maxClique(numNodes, edges);
    cout << maxCliqueSize << endl;
    // cout << "Nodes in the maximum clique: ";
    // for (int i = 1; i <= numNodes; ++i) {
    //     if (bestx[i]) {
    //         cout << i << " ";
    //     }
    // }
    // cout << endl;

    return 0;
}

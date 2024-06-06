#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 65; // ���þ���Ĵ�С
int graph[N][N];   // ���ڽӾ���洢ͼ
bool x[N];         // �Ƿ�i�������������
bool bestx[N];     // ��¼�����Ѿ��������еĶ���
int bestn;         // ��¼����ֵ

int n;             // �������
int cn;            // �Ѿ��������еĽ����


bool place(int t) // �ж��Ƿ��ܷŽ�����
{
    for (int j = 1; j < t; j++) // �ж�Ŀǰ��չ��t�����ǰ��t-1�������Ƿ�������
    {
        if (x[j] && graph[t][j] == 0) // ���������
        {
            return false; // ����false
        }
    }
    return true; // �������������true
}

void backtrack(int t) // ���ݣ�����
{
    if (t > n) // ������Ҷ�ӽ��
    {
        bestn = cn; // ��¼����ֵ
        memcpy(bestx, x, sizeof(x)); // ��¼�����Ѿ��������еĶ���
        return;
    }
    if (place(t)) // ����ܷŽ�����
    {
        x[t] = true; // ��Ϊtrue
        cn++;        // ����+1
        backtrack(t + 1); // ���µ���
        cn--;        // ���ϻ���
    }
    if (cn + n - t > bestn) // �޽����������������������ܼ������С�
    {
        x[t] = false; // ���ܷ������У���Ϊfalse
        backtrack(t + 1); // ���µ��ơ�
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

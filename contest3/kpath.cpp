#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr;           //# tổng chi phí tới thời điểm hiện tại
int mark[MAX];      //# đánh dấu những thành phố đã đi
int x[MAX];         //# lưu giữ các thành phố đã đi
//# Đọc dữ liệu vào
void input_matrix(int n)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            c[i][j] = 0;
        }
}
void input_graph(int m)
{
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        c[u][v] = 1;
        c[v][u] = 1;
    }
}

void output_graph(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
//# Thuật toán quay lui
int countwalks(int graph[MAX][MAX], int u, int v, int k, int n)
{
    // Base cases
    if (k == 0 && u == v)
        return 1;
    if (k == 1 && graph[u][v])
        return 1;
    if (k <= 0)
        return 0;
    if (u == v)
    {
        return 0;
    }
    if (k == 1 && graph[u][v] == 0)
    {
        return 0;
    }

    // Initialize result
    int count = 0;
    mark[u] = 1;
    // Go to all adjacents of u and recur
    for (int i = 1; i <= n; ++i)
    {
        if (graph[u][i] == 1)
        { // Check if is adjacent of u
            if (k > 1 && i == v)
            {
                continue;
            }

            if (!mark[i])
            {
                mark[i] = 1;
                count += countwalks(graph, i, v, k - 1, n);
                mark[i] = 0;
            }
        }
        // mark[i] = 0;
    }
    mark[u] = 0;
    return count;
}
void insert(list<int> graph_list[], int u, int v)
{
    graph_list[u].push_back(v);
    graph_list[v].push_back(u);
}
int main()
{
    int n, k;
    int m;
    cin >> n >> k;
    cin >> m;
    input_matrix(n);
    input_graph(m);
    // output_graph(n);
    int t2 = 2;
    int t1 = 1;
    int sum = 0;
    int total_sum = 0;
    while (t2 != n + 1)
    {

        for (int i = t2; i <= n; i++)
        {
            sum += countwalks(c, t1, i, k, n);
            // cout << t1 << "-" << i << " ";
        }
        // total_sum += sum;
        t1++;
        t2++;
    }

    // cout << countwalks(c, 2, 4, k, n) << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << mark[i] << " ";
    // }
    cout << sum;
    return 0;
}
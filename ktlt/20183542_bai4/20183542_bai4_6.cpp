#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <deque>

using namespace std;
void bfs(vector<list<int>> adj)
{
    queue<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1

    /*****************
    # YOUR CODE HERE #
    *****************/
    while (!S.empty())
    {
        int s;
        s = S.front();
        S.pop();

        if (!visited[s])
        {
            cout << s << endl;
            visited[s] = true;
        }

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // cout << *i << " ";
            if (!visited[*i])
                S.push(*i);
        }
    }
}
int main()
{
    int n = 7;
    vector<list<int>> adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    // output_adj(adj);

    bfs(adj);
}
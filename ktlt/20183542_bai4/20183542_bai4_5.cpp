#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
void dfs(vector<list<int>> adj)
{
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1

    /*****************
    # YOUR CODE HERE #
    *****************/
    while (!S.empty())
    {
        int s;
        s = S.top();
        S.pop();

        if (!visited[s])
        {
            cout << s << endl;
            visited[s] = true;
        }

        for (auto i = adj[s].rbegin(); i != adj[s].rend(); ++i)
        {
            // cout << *i << " ";
            if (!visited[*i])
                S.push(*i);
        }
    }
}
void output_adj(vector<list<int>> adj)
{
    // for (auto i = adj[1].r(); i != adj[1].rbegin(); i--)
    //     cout << *i;
    // cout << endl;
    for (auto i = adj[1].rbegin(); i != adj[1].rend(); i++)
        cout << *i;
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

    dfs(adj);
}
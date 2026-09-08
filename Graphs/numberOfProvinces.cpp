#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    void dfs(int curr, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[curr] = true;
        // check all cities that are connected to the curr city
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[curr][j] && !visited[j])
                dfs(j, isConnected, visited);
        }
    }

    void bfs(int node, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            // check all cities that are connected to the curr city
            for (int j = 0; j < isConnected.size(); j++)
            {
                if (isConnected[curr][j] && !visited[j])
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // need to traverse, and number of traversals will be my answer
        vector<bool> visited(isConnected.size(), false);
        int provinces = 0;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution obj;
    int result = obj.findCircleNum(isConnected);

    cout << "Number of Provinces: " << result << endl;

    return 0;
}

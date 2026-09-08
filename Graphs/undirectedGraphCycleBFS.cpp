#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution
{
    public: 

        bool cycleDetectionUndirectedBFS(int src, unordered_map<int, bool> &visited, vector<int> adj[])
        {
            queue<int> q;
            unordered_map<int, int> parent;

            //initial state
            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            //main logic
            while(!q.empty())
            {
                int frontNode = q.front();
                q.pop();

                for(auto nbr: adj[frontNode])
                {
                    if(!visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr] = true;
                        parent[nbr] = frontNode;
                    }
                    //cycle detection case
                    else if(visited[nbr] == true && nbr != parent[frontNode])
                    {
                        //cycle present
                        return true;
                    }
                }
            }
            return false;
        }

        bool isCycle(int v, vector<int> adj[])
        {
            bool ans = false;
            unordered_map<int, bool> visited;
            int n = v;

            for(int i = 0; i < n; i++)
            {
                if(!visited[i])
                {
                    ans = cycleDetectionUndirectedBFS(i, visited, adj);

                    if(ans == true)
                        break;
                }
            }
            return ans;
        }
};

int main()
{
    int v = 4; // Number of vertices
    int e = 4; // Number of edges

    vector<int> adj[v];

    // Adding edges based on the image
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    Solution s;
    if (s.isCycle(v, adj))
        cout << "Cycle is present in the graph.\n";
    else
        cout << "No cycle found in the graph.\n";

    return 0;
}


// int main()
// {
//     int v, e;
//     cout << "Enter number of vertices: ";
//     cin >> v;
//     cout << "Enter number of edges: ";
//     cin >> e;

//     vector<int> adj[v];

//     cout << "Enter edges (u v) for an undirected graph:\n";
//     for (int i = 0; i < e; i++)
//     {
//         int u, v_;
//         cin >> u >> v_;
//         adj[u].push_back(v_);
//         adj[v_].push_back(u); // since it's an undirected graph
//     }

//     Solution s;
//     if (s.isCycle(v, adj))
//         cout << "Cycle is present in the graph.\n";
//     else
//         cout << "No cycle found in the graph.\n";

//     return 0;
// }
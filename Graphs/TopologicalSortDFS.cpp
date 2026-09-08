#include <iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
    public:
        void topoDFS (int src, unordered_map<int, bool>&vis, vector<int> adj[], vector<int> &ans)
        {
            vis[src] = true;

            for(auto nbr: adj[src])
            {
                if(!vis[nbr])
                {
                    topoDFS(nbr, vis, adj, ans);
                }
            }
            //backtrack
            ans.push_back(src);
        }
        vector<int> topoSort(int V, vector<int> adj[])
        {
            unordered_map<int, bool> visited;
            int n = V;
            vector<int> ans;

            for(int i = 0; i < n; i++)
            {
                if(!visited[i])
                {
                    topoDFS(i, visited, adj, ans);
                }
            }
            //reverse the ordering
            reverse(ans.begin(), ans.end());
            return ans;
        }
};

int main()
{
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Directed edges (u -> v means u comes before v)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> result = obj.topoSort(V, adj);

    cout << "Topological Sort of the graph is:\n";
    for(int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


#include <iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution
{
    public: 
        bool checkCycleDfsHelper(int src, unordered_map<int, bool> &visited, vector<int> adj[], int parent)
        {
            visited[src] = true;
            for(auto nbr: adj[src])
            {
                if(!visited[nbr])
                {
                    bool ans = checkCycleDfsHelper(nbr, visited, adj, src);

                    if(ans == true)
                        return true;
                }
                else if(visited[nbr] == true && nbr != parent)
                {
                    return true;
                }
            }
            return false;
        }

        bool isCycle(int V, vector<int> adj[]) 
        {
            //handle disconnected components 
            int n = V;
            bool ans = false;
            unordered_map<int,bool> visited;
            int parent = -1;
            for(int i=0; i<V; i++) {
                if(!visited[i]) {
                    ans = checkCycleDfsHelper(i,visited,adj, parent);
                    if(ans) {
                        break;
                    }
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
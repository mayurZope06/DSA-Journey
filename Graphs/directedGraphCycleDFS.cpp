#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution 
{
  public:
    bool dfsHelper(int node, unordered_map<int,bool>& vis, vector<int> adj[],
    unordered_map<int,bool>& dfsTracker) 
    {
        
        vis[node] = true;
        dfsTracker[node] = true;
        
        for(auto nbr: adj[node]) 
        {
            if(!vis[nbr]) {
                bool ans = dfsHelper(nbr, vis, adj, dfsTracker);
                if(ans == true) 
                {
                    return true;
                }
            }
            else if(vis[nbr] == true && dfsTracker[nbr] == true)
            {
                //cycle present
                return true;
            }
        }
        
        //backtrack
        dfsTracker[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) 
    {
        bool ans = false;
        int n = V;
        unordered_map<int,bool> vis;
        unordered_map<int,bool> dfsTracker;
        
        for(int i=0; i<n; i++) 
        {
            if(!vis[i]) {
                ans = dfsHelper(i,vis,adj, dfsTracker);
                if(ans == true)
                {
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int V = 4; // Number of vertices
    vector<int> adj[V];

    // Add directed edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // Creates a cycle: 1 -> 2 -> 3 -> 1

    Solution obj;
    if (obj.isCyclic(V, adj)) {
        cout << "Cycle is present in the directed graph." << endl;
    } else {
        cout << "No cycle in the directed graph." << endl;
    }

    return 0;
}

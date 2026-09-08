#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class Solution
{
    public:

        void topoBfs(int n, vector<int> adj[], vector<int> &ans)
        {
            unordered_map<int, int> indegree;
            queue<int> q;

            //prepare indegree map
            for(int src = 0; src < n; src++)
            {
                for(auto nbr: adj[src])
                {
                    //src -> nbr
                    indegree[nbr]++;
                }
            }
            //check for indegree 0 and push in q
	        //maintain insitial state in q
            for(int i = 0; i < n; i++)
            {
                if(indegree[i] == 0)
                {
                    q.push(i);
                }
            }

            //main logic
            while(!q.empty())
            {
                int frontNode = q.front();
                ans.push_back(frontNode);
                q.pop();

                //kyoki frontNode graph se hatt chuki h
                //update the indegree of its children accordingly    
                
                for(auto nbr: adj[frontNode])
                {
                    //remove frontNode -> nbr
                    indegree[nbr]--;
                    if(indegree[nbr] == 0)
                    {
                        q.push(nbr);
                    }
                }
            }
        }

        vector<int> topoSort(int V, vector<int> adj[])
        {
            vector<int> ans;

            topoBfs(V, adj, ans);
            return ans;
        }
};

int main()
{
    int V = 6;
    vector<int> adj[V];

    // Directed edges
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> result = obj.topoSort(V, adj);

    cout << "Topological Sort using BFS (Kahn's Algorithm):\n";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

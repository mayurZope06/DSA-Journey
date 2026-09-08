#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class Solution 
{
  public:
    
    void topoBfs(int n, vector<int> adj[],vector<int>& ans) 
    {
	    unordered_map<int,int> indegree;
	    queue<int> q;
	    
	    //prepare indegree map 
	    for(int src=0; src<n; src++) 
        {
	        for(auto nbr: adj[src]) 
            {
	            //src-> nbr
	            indegree[nbr]++;
	        }
	    }
	    
	    //check for indegree 0 and push in q
	    //maintain insitial state in q
	    for(int i=0; i<n; i++) 
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
	            //remove frontNode->nbr
	            indegree[nbr]--;
	            if(indegree[nbr] == 0) 
                {
	                q.push(nbr);
	            }
	        }
	        
	    }
	}

    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<int> ans;
        topoBfs(V, adj, ans);

        if(ans.size() == V)
        {
            //all nodes reached, no cycle 
            return false;
        }
        else
        {
            //cycle present
            return true;
        }
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

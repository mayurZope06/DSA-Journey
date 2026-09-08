#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Solution {
public:
    bool topoSortBfs(unordered_map<int,list<int> >& adj, int n) {

        unordered_map<int,int> indegree;
        vector<int> topoOrder;

        for(int i=0; i<n; i++) {
            indegree[i] = 0;
        }

        //now calculate indegree of each ndoe 

        for(auto i : adj) {
            int u = i.first;
            for(auto j: i.second) {
                int v = j;
                indegree[v]++;
            }
        }

        //BFS Logic 
        queue<int> q;
        //intial state 
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        //main bfs logic 
        while(!q.empty()) {
            int front = q.front();
            topoOrder.push_back(front);
            q.pop();
            //nbr check 
            for(auto nbr: adj[front]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        //valid or not  
        if(topoOrder.size() == n) {
            return true;
        }
        else {
            return false;
        }
    }   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int> > adj;

        for(auto i: prerequisites) {
            int u = i[1];
            int v = i[0];
            adj[u].push_back(v);
        }
        //graph is ready 

        bool ans = topoSortBfs(adj,numCourses);
        return ans;
    }
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    Solution obj;
    bool result = obj.canFinish(numCourses, prerequisites);

    if (result)
        cout << "Yes, you can finish all courses." << endl;
    else
        cout << "No, it's not possible to finish all courses." << endl;

    return 0;
}
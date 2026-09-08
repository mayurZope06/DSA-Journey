#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 1 means directed edge
        if (direction == 1) {
            adj[u].push_back(v);
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void printAdjList(int n) {
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (auto nbr : adj[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

    void topoSortDFS(stack<int> &s, int node, unordered_map<int, bool> &vis) {
        vis[node] = true;

        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                topoSortDFS(s, nbr, vis);
            }
        }

        s.push(node);
    }

    void dfs(int src, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adjNew) {
        vis[src] = true;
        cout << src << " ";

        for (auto nbr : adjNew[src]) {
            if (!vis[nbr]) {
                dfs(nbr, vis, adjNew);
            }
        }
    }

    int countSCC(int n) {
        // Step 1: Topological sort
        stack<int> s;
        unordered_map<int, bool> vis;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                topoSortDFS(s, i, vis);
            }
        }

        // Step 2: Reverse all edges
        unordered_map<int, list<int>> adjNew;

        for (auto i : adj) {
            for (auto j : i.second) {
                int u = i.first;
                int v = j;
                // u -> v edge exists, we want v -> u in reversed graph
                adjNew[v].push_back(u);
            }
        }

        // Step 3: DFS on reversed graph using order in stack
        int count = 0;
        unordered_map<int, bool> visited;

        while (!s.empty()) {
            int src = s.top();
            s.pop();

            if (!visited[src]) {
                cout << "SCC: ";
                dfs(src, visited, adjNew);
                cout << endl;
                count++;
            }
        }

        return count;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 3, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(1, 0, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);

    int n = 8;
    g.printAdjList(n);

    int sccCount = g.countSCC(n);
    cout << "SCC Count: " << sccCount << endl;

    return 0;
}

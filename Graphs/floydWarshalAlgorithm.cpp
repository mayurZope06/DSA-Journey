#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class graph 
{
	public:
	unordered_map<int, list<pair<int,int>>> adjList;

	void addEdge(int u, int v, int wt, bool direction) 
    {
		//direction = 1 -> undirected graph
		//direction => 0 -> directed graph;
		adjList[u].push_back({v,wt});
		if(direction == 1) {
			adjList[v].push_back({u,wt});
		}
	}

	void printAdjList() 
    {
		for(auto i: adjList)
        {
			cout << i.first <<"-> ";
			for(auto j: i.second) 
            {
				cout << "(" << j.first<<", "<<j.second<<"), ";
			}
			cout << endl;
		}
	}

    void floydWarshalAlgo(int n) {
        vector<vector<int> > dist(n, vector<int>(n, 1e9));

        //step1: diagnol pr 0 rakkhdiye 
        for(int i=0; i<n; i++) 
        {
            dist[i][i]= 0;
        }
        //step2: copy all distance from graph to matrix 
        for(auto a: adjList) 
        {
            for(auto b: a.second) 
            {
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
        }
        //main logic of helper node 
        for(int helper=0; helper<n; helper++) 
        {
            for(int u=0; u < n; u++) 
            {
                for(int v=0; v<n; v++) 
                {
                    dist[u][v] = min(dist[u][v], dist[u][helper]+dist[helper][v]);
                }
            }
        }

        cout << "Printing Result of FW algo: " << endl;
        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                cout << dist[i][j] <<", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g;
	g.addEdge(0,2,-2,0);
    g.addEdge(1,0,4,0);
    g.addEdge(1,2,3,0);
    g.addEdge(3,1,-1,0);
    g.addEdge(2,3,2,0);

    g.floydWarshalAlgo(4);

    return 0;
}
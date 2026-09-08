#include <iostream>
#include <unordered_map>
#include <list>
#include <limits.h>
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

    //a -> pair<int,list<pair<int,int> >
    //a.first = u
    //a.second -> nbr of u node -> list <pair<int,int>
    //b -> pair<int,int>
    //b.first -> v;
    //b.second -> weight
    void  bellmanForAlgo(int src, int n) 
    {
        vector<int> dist(n, INT_MAX);
        //intial state 
        dist[src] = 0;

        //n-1 times loop chalao 
        for(int i=0; i<n-1; i++) 
        {
            //hr edge pr jao and relaxaction stp karo
            for(auto a: adjList) 
            {
                for(auto b: a.second) 
                {
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) 
                    {
                        dist[v] = dist[u] + wt;
                    }  
                } 
            }
        }

        bool negativeCyclePresent = false;

        for(auto a: adjList) 
        {
            for(auto b: a.second)
            {
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) 
                {
                    dist[v] = dist[u] + wt;
                    negativeCyclePresent = true;
                    break;
                }
            }
        }
        
        if(negativeCyclePresent == true)
        {
            cout << "-ve cycle present" << endl;
        }
        else 
        {
            cout << "-ve cycle not present" << endl;

            cout << "printing bellman for result: " << endl;
            for(int i=0; i<n; i++) 
            {
                cout << dist[i] << " ";
            }
        }
    }
};

int main()
{
    graph g;
	// g.addEdge(0,1,-1,0);
	// g.addEdge(1,4,2,0);
	// g.addEdge(0,2,4,0);
	// g.addEdge(3,2,5,0);
	// g.addEdge(4,3,-3,0);
	// g.addEdge(1,2,3,0);
	// g.addEdge(1,3,2,0);
	// g.addEdge(3,1,1,0);

    g.addEdge(0,1,-1,0);
    g.addEdge(1,0,-2,0);


    //g.bellmanForAlgo(0, 5);
    g.bellmanForAlgo(0, 2);

    return 0;
}
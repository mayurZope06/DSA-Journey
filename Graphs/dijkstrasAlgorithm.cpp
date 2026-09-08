#include <iostream>
#include <unordered_map>
#include <set>
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

  void shortestDistanceDijkstra(int src, int n) 
  {
      vector<int> dist(n+1, INT_MAX);
      set<pair<int,int> > st;

      //intial state
      dist[src] = 0;
      st.insert({0,src});

      //main logic 
      while(!st.empty()) 
      {
        auto topElement = *(st.begin());
        int topNodeDistance = topElement.first;
        int topNode = topElement.second;

        //pop this node
        st.erase(st.begin());

        //neighbour pr jao 
        for(auto nbr: adjList[topNode]) 
        {
          //nbr is a pair
          //nbr = {a,b}
          //a -> node
          //b -> wt
          int nbrNode = nbr.first;
          int nbrDistance = nbr.second;
          if(dist[topNode] + nbrDistance < dist[nbrNode]) 
          {
            //2 kaam krne h 
            //distnce array ko update krna h 
            //set ko update krna h 
            auto result = st.find({dist[nbrNode], nbrNode});
            if(result != st.end()) {
              //entry found;
              //remove this entry 
              st.erase(result);
            }
            dist[nbrNode] = dist[topNode] + nbrDistance;
            st.insert({dist[nbrNode], nbrNode});
          }
        }

      }

      cout << "Printing the result" << endl;

      for(int i=0; i<n; i++)
      {
        cout << dist[i] << " ";
     }
  }
};

int main()
{
    graph g;
	g.addEdge(0,5,9,1);
	g.addEdge(0,3,6,1);
	g.addEdge(5,4,2,1);
	g.addEdge(4,3,11,1);
	g.addEdge(5,1,14,1);
	g.addEdge(4,1,9,1);
	g.addEdge(4,2,10,1);
	g.addEdge(3,2,15,1);
	g.addEdge(2,1,7,1);

    g.shortestDistanceDijkstra(0, 6);

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <climits>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // let's build Adj list
        unordered_map<int, list<pair<int, int>>> graph;
        for (auto &flight : flights)
            graph[flight[0]].push_back({flight[1], flight[2]});

        // Priority Queue to select the next city with minimal cost
        // each element would be: {cost so far, current city, stops so far}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        // visited array storing minimum number of stops to reach a city
        vector<int> visited(n, INT_MAX);
        visited[src] = 0;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0];  // total cost so far
            int city = curr[1];  // current city
            int stops = curr[2]; // number of stops made so far

            if (city == dst)
                return cost;

            // if stops exceeds k, then skip this path
            if (stops > k)
                continue;

            // if we have already visited the city with fewer stops, skip this path
            if (visited[city] != INT_MAX && visited[city] < stops)
                continue;

            // update the mini stops for the current city
            visited[city] = min(visited[city], stops);

            // Explore all neighbours cities
            for (auto &nbr : graph[city])
            {
                int nextCity = nbr.first;
                int price = nbr.second;
                pq.push({cost + price, nextCity, stops + 1});
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600}
    };
    int src = 0, dst = 3, k = 1;

    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << result << endl;

    return 0;
}

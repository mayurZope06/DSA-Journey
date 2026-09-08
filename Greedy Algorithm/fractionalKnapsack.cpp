#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Item {
    int value;
    int weight;
};


class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w) {
        vector<double> valWtRatio;
        
        for(int i=0; i<values.size(); i++ ) {
            double ratio = (values[i] * 1.0 / weights[i]);
            valWtRatio.push_back(ratio);
        }
        
        //to find the max ratio wala item, let's create a max heap 
        priority_queue< pair<double, pair<int,int>  > > pq;
        
        for(int i=0; i<values.size(); i++) {
            pq.push({valWtRatio[i], {values[i], weights[i]}});
        }
        
        //let's find the total value 
        double totalVal = 0;
        
        int capacity = w;
        
        while(capacity != 0 && !pq.empty()) {
            auto front = pq.top();
            pq.pop();
            
            double ratio = front.first;
            int value = front.second.first;
            int weight = front.second.second;
            
            //choose whole item include karu ya fer fraction me include karu
            if(capacity >= weight) {
                //whole item include karlo
                totalVal += value;
                capacity -= weight;
            }
            else {
                //fraction include karlo
                double valToInclude = ratio * capacity;
                totalVal += valToInclude;
                capacity = 0;
                break;
            }
        }
        return totalVal;
        
    }
};

int main() {

    Solution s1;
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;  

    cout << s1.fractionalKnapsack(values, weights, capacity);
    return 0;
}

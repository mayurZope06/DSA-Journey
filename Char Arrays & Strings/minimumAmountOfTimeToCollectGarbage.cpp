#include <iostream>
#include <vector>
using namespace std;
class  Solution
{
    public:
        int garbageCollection (vector <string> &garbage, vector<int> &travel)
        {
            // P Truck
            int pickP = 0;
            int travelP = 0;
            int lastHouseP = 0;
            // M Truck
            int pickM = 0;
            int travelM = 0;
            int lastHouseM = 0;
            // G Truck
            int pickG = 0;
            int travelG = 0;
            int lastHouseG = 0;

            // Let's travel to the street of houses 
            for(int i = 0; i < garbage.size(); i++)
            {
                // ith house
                string currHouse = garbage[i];
                // Let's dive in to current house and see the type of garbage present.
                for (int j = 0; j < currHouse.length(); j++)
                {
                    char garbageType = currHouse[j];
                    if (garbageType == 'P')
                    {
                        pickP++;
                        // yaha tak toh mera P truck pkka aaya hai toh let's store it
                        lastHouseP = i;
                    }
                    if (garbageType == 'M')
                    {
                        pickM++;
                        // yaha tak toh mera M truck pkka aaya hai toh let's store it
                        lastHouseM = i;
                    }
                    if (garbageType == 'G')
                    {
                        pickG++;
                        // yaha tak toh mera G truck pkka aaya hai toh let's store it
                        lastHouseG = i;
                    }

                }
            }
            // Let's calculate travel time for P
            for (int i = 0; i < lastHouseP; i++)
                travelP = travelP + travel[i];
            
            // Let's calculate travel time for M
            for (int i = 0; i < lastHouseM; i++)
                travelM = travelM + travel[i];
            
            // Let's calculate travel time for P
            for (int i = 0; i < lastHouseG; i++)
                travelG = travelG + travel[i];

            int totalPickingTime = pickP + pickM + pickG;
            int totalTravelTime = travelP + travelM + travelG;

            int totalTime = totalPickingTime + totalTravelTime;

            return totalTime;
        }
};
int main()
{
    vector <string> garbage {"G","P","GP","GG"};
    vector <int> travel {2,4,3};
    Solution s;
    int result = s.garbageCollection(garbage, travel);
    cout<<result;

    return 0;
}
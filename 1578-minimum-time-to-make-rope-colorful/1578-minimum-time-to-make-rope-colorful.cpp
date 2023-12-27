class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // Initialize two pointers i, j
        int i = 0, j = 0, totalTime = 0;
        
        while (i < neededTime.size() && j < neededTime.size()){
            int currMax = 0, currTime = 0;
            
            // Find all the balloons having the same color as the balloon indexed at i,
            // record the total removal time and the maximum removal time
            while (j < neededTime.size() && colors[i] == colors[j]){
                currTime += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                ++j;
            }
            
            // Once we reached the end of the current group, add the cost of this group
            // to total_time, and reset 2 pointers
            totalTime += currTime - currMax;
            i = j;
        }
        
        return totalTime;
    }
};
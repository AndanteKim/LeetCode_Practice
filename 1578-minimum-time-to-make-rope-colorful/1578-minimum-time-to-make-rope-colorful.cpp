class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // totalTime: total time needed to make rope colorful
        // currMaxTime: maximum time of a balloon needed in this group
        int totalTime = 0, currMaxTime = 0;
        
        // For each balloon in thios array
        for(int i = 0; i < neededTime.size(); ++i){
            // If this balloon is the first of a new group, set the currMaxTime as 0 
            if (i > 0 && colors[i - 1] != colors[i])
                currMaxTime = 0;
            
            // Increment totalTime by the smaller one
            totalTime += min(currMaxTime, neededTime[i]);
            currMaxTime = max(currMaxTime, neededTime[i]);
        }
        
        // Return totalTime as the minimum removal time
        return totalTime;
    }
};
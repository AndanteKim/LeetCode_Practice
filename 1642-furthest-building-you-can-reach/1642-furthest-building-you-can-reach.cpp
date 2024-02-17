class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // We'll use heapq to treat this aas a minHeap
        priority_queue<int, vector<int>, greater<int>> ladderAllocation;
        
        for (int i = 0; i < heights.size() - 1; ++i){
            // If this is actually a "jump down", skip it.
            int climb = heights[i + 1] - heights[i];
            
            if (climb <= 0)
                continue;
            
            // Otherwise, allocate ladder for this climb.
            ladderAllocation.push(climb);
            
            // If we haven't gone over the number of ladders, nothing else to do
            if (ladderAllocation.size() <= ladders)
                continue;
            
            // Otherwise, we'll need to take a climb out of ladderAllocations
            bricks -= ladderAllocation.top();
            ladderAllocation.pop();
            
            // If this causes bricks to go negative, we can't get to i + 1
            if (bricks < 0)
                return i;
        }
        
        // If we get to there, this means we had enough to cover every climb.
        return heights.size() - 1;
    }
};
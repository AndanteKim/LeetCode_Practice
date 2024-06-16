class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        // sort the boxes by height
        sort(boxes.begin(), boxes.end());
        int leftIndex = 0, rightIndex = warehouse.size() - 1;
        int boxesCount = 0, boxIndex = boxes.size() - 1;
        
        // Iterate through the boxes from the largest to the smallest
        while (leftIndex <= rightIndex && boxIndex >= 0){
            // Check if the current box can fit in the
            // leftmost available room
            if (boxes[boxIndex] <= warehouse[leftIndex]){
                ++boxesCount;
                ++leftIndex;
            }
            // Check if the current box can fit in the
            // rightmost available room
            else if (boxes[boxIndex] <= warehouse[rightIndex]){
                ++boxesCount;
                --rightIndex;
            }
            
            --boxIndex;
        }
        
        return boxesCount;
    }
};
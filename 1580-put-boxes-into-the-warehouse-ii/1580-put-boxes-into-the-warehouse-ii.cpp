class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        int minHeight = 1'000'000'001;
        vector<int> effectiveHeights(n, minHeight);
        
        // Preprocess the height of the warehouse rooms to
        // get usable heights from the left end.
        for (int i = 0; i < n; ++i){
            minHeight = min(minHeight, warehouse[i]);
            effectiveHeights[i] = minHeight;
        }
        
        minHeight = 1'000'000'001;
        // Update the effective heights considering the right end
        for (int i = n - 1; i >= 0; --i){
            minHeight = min(minHeight, warehouse[i]);
            effectiveHeights[i] = max(minHeight, effectiveHeights[i]);
        }
        
        // sort the boxes by height
        sort(boxes.begin(), boxes.end());
        // sort the effective heights of the warehouse rooms
        sort(effectiveHeights.begin(), effectiveHeights.end());
        int ans = 0, boxIdx = 0;
        
        // Try to place each box in the warehouse
        // from the smallest room to the largest
        for (int i = 0; i < n; ++i){
            if (boxIdx < boxes.size() && boxes[boxIdx] <= effectiveHeights[i]){
                // Place the box and move to the next one
                ++ans;
                ++boxIdx;
            }
        }
        
        return ans;
    }
};
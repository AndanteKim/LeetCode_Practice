class Solution {
private:
    int n;
    int binarySearch(vector<vector<int>>& items, int targetPrice){
        int left = 0, right = n - 1, maxBeauty = 0, mid;
        
        while (left <= right){
            mid = (left + right) >> 1;
            
            if (targetPrice < items[mid][0])
                right = mid - 1;
            else{
                // Found viable price. Keep moving to right
                maxBeauty = max(maxBeauty, items[mid][1]);
                left = mid + 1;
            }
        }
        
        return maxBeauty;
    }
    
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort and store max beauty
        sort(items.begin(), items.end());
        int mx = items[0][1];
        this -> n = items.size();
        for (int i = 0; i < n; ++i){
            mx = max(mx, items[i][1]);
            items[i][1] = mx;
        }
        
        int qSize = queries.size();
        vector<int> ans(qSize);
        for (int i = 0; i < qSize; ++i)
            ans[i] = binarySearch(items, queries[i]);
        
        return ans;
    }
};
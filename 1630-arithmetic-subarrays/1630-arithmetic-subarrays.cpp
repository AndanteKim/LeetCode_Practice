class Solution {
private:
    bool check(vector<int>& arr){
        int maxElem = INT_MIN, minElem = INT_MAX;
        unordered_set<int> arrSet;
        
        for (int num : arr){
            maxElem = max(num, maxElem);
            minElem = min(num, minElem);
            arrSet.insert(num);
        }
        
        if ((maxElem - minElem) % (arr.size() - 1) != 0)
            return false;
        int diff = (maxElem - minElem) / (arr.size() - 1), curr = minElem + diff;
        
        while (curr < maxElem){
            if (!arrSet.count(curr))
                return false;
            curr += diff;
        }
        
        return true;
    }
    
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); ++i){
            vector<int> arr(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans.push_back(check(arr));
        }
        
        return ans;
    }
};
class Solution {
private:
    int n;
    bool checkUnique(int start, vector<int>& nums){
        unordered_set<int> seen;

        for (int i = start; i < n; ++i){
            if (seen.count(nums[i])) return false;
            seen.insert(nums[i]);
        }
        return true;
    }

public:
    int minimumOperations(vector<int>& nums) {
        this -> n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i += 3){
            if (checkUnique(i, nums)) return ans;
            ++ans;
        }

        return ans;
    }
};
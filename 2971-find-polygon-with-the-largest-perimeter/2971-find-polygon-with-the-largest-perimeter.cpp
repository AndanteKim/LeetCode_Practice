class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long prevSum = 0, ans = -1;
        
        for (int num:nums){
            if (prevSum > num)
                ans = prevSum + num;
            prevSum += num;
        }
        
        return ans;
    }
};
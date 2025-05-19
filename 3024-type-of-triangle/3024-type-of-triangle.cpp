class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Base case
        if (nums[0] == nums[1] && nums[1] == nums[2] && nums[0] == nums[1]) return "equilateral";

        if (nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[0] + nums[2] > nums[1]){
            return (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2])? "isosceles" : "scalene";
        }

        return "none";
    }
};
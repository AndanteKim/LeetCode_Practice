class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> sumVec = nums;
        if (sumVec.size() == 1) return sumVec[0];

        while (sumVec.size() > 1){
            vector<int> curr;

            for (int i = 0; i < sumVec.size() - 1; ++i)
                curr.push_back((sumVec[i] + sumVec[i + 1]) % 10);

            sumVec = curr;
        }

        return sumVec[0];
    }
};
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int, vector<int>> reflected;
        
        for (int num: nums){
            if (num == 0){
                reflected[mapping[num]].push_back(num);
                continue;
            }
            
            int digits = 1, origin = num, newN = 0;
            while (origin > 0){
                newN += mapping[origin % 10] * digits;
                digits *= 10;
                origin /= 10;
            }
            
            reflected[newN].push_back(num);
        }
        
        vector<int> ans;
        for (auto& [_, l]: reflected){
            for (int n:l)
                ans.push_back(n);
        }
        return ans;
    }
};
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        map<int, int> counter;
        for (int num:nums)
            ++counter[num];
        
        while (!counter.empty()){
            int curr = counter.begin() -> first;
            
            for (int next = curr; next < curr + k; ++next){
                if (!counter.contains(next) || counter[next] == 0)
                    return false;
                --counter[next];
                
                if (counter[next] == 0)
                    counter.erase(next);
            }
        }
        
        return true;
    }
};
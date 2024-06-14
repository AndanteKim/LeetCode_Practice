class Solution {
private:
    int find(int x, unordered_map<int, int>& root){
        root[x] = (root.find(x) != root.end())? find(root[x] + 1, root) : x;
        
        return root[x];
    }
    
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> root;
        
        for (int num : nums){
            ans += find(num, root) - num;
        }

        return ans;
    }
};
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> count(limit + 1, 0);
        for (int p : people) ++count[p];
        
        int idx = 0;
        for (int val = 1; val <= limit; ++val){
            while(count[val]-- > 0){
                people[idx++] = val;
            }
        }
        
        int ans = 0, left = 0, right = people.size() - 1;
        
        while (left <= right){
            if (people[left] + people[right] <= limit){
                ++left;
                --right;
            }
            else --right;
            ++ans;
        }
        return ans;
    }
};
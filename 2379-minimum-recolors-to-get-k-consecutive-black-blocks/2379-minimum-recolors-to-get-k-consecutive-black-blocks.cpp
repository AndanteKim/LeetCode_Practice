class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        if (blocks.size() < k) return -1;
        
        int ans = 0;
        for (int i = 0; i < k; ++i) if (blocks[i] == 'W') ++ans;

        int left = 0, curr = ans, n = blocks.size();
        for (int right = k; right < n; ++right){
            if (blocks[right] == 'W') ++curr;
            if (blocks[left++] == 'W') --curr;

            ans = min(ans, curr);
        }

        return ans;
    }
};
class Solution {
private:
    int rev(int x){
        stack<int> st;
        while (x > 0){
            st.push(x % 10);
            x /= 10;
        }
        int num = 0;
        long digit = 1;
        while (!st.empty()){
            num = (num + st.top() * digit) % 1'000'000'007;
            digit *= 10;
            st.pop();
        }
        
        return num;
    }
    
public:
    int countNicePairs(vector<int>& nums) {
        long ans = 0;
        unordered_map<int, int> diffPairs;
        
        for (int num : nums){
            int diff = num - rev(num);
            ++diffPairs[diff];
        }
        
        for (auto& [_, freq] : diffPairs)
            ans = (ans + (((long)freq * (freq - 1)) >> 1)) % 1'000'000'007;
        
        return static_cast<int>(ans);
    }
};
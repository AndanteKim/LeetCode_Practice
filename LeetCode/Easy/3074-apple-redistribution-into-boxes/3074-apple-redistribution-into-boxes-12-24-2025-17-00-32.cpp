class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), [](int a, int b) {return a > b;});

        int ans = 0;
        while (totalApples > 0) {
            totalApples -= capacity[ans++];
        }
        
        return ans;
    }
};
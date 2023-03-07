class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int left = 0;
        long long curr = 0;
        int n = chargeTimes.size();
        deque<int> *dq = new deque<int>;
        
        for (int right = 0; right < n; ++right){
            curr += runningCosts[right];
            while (!dq -> empty() && chargeTimes[dq -> back()] <= chargeTimes[right]) dq -> pop_back();
            dq -> push_back(right);
            if ((long long)(chargeTimes[dq -> front()] + (right - left + 1) * curr) > budget){
                if (dq -> front() == left) dq -> pop_front();
                curr -= runningCosts[left];
                ++left;
            }
        }
        
        return n - left;
    }
};
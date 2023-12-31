class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if (n < d)
            return -1;
        
        // minDiffCurrDay and minDiffPrevDay record the minimum total job difficulty
        // for the current day and previous day, respectively
        vector<int> minDiffPrevDay(n, 1001), minDiffCurrDay(n, 0);
        
        for (int day = 0; day < d; ++day){
            // Use a monotonically decreasing stack to record difficulties
            stack<int> st;
            
            // The number of jobs needs to be no less than number of days passed
            for (int i = day; i < n; ++i){
                // We initialize minDiffCurrDay[i] as only performing 1 job at the i-th index.
                // At day 0, the minimum total job difficulty is to complete the 0th job only.
                if (i == 0)
                    minDiffCurrDay[i] = jobDifficulty[0];
                
                // Otherwise, we increment minDiffPrevDay[i - 1] by the i-th job difficulty
                else
                    minDiffCurrDay[i] = minDiffPrevDay[i - 1] + jobDifficulty[i];
                
                // When we find the last element in the stack is smaller than or equal to current job
                // we need to pop out the element to maintain a monotonic decreasing stack.
                while (!st.empty() && jobDifficulty[st.top()] <= jobDifficulty[i]){
                    // If we include all jobs with indce j + 1 to i to the current day,
                    // total job difficulty of the current day will be increased
                    // by the amount of jobDifficulty[i] - jobDifficulty[j]
                    int j = st.top();
                    st.pop();
                    int diffIncr = jobDifficulty[i] - jobDifficulty[j];
                    minDiffCurrDay[i] = min(minDiffCurrDay[i], minDiffCurrDay[j] + diffIncr);
                }
                
                // When the last element in the stack is larger than current element,
                // If we include all jobs with index j + 1 to i to the current day,
                // the overall job difficulty will not change.
                if (!st.empty())
                    minDiffCurrDay[i] = min(minDiffCurrDay[i], minDiffCurrDay[st.top()]);
                
                // Update the monotonic stack by adding in the current index
                st.push(i);
            }
            swap(minDiffPrevDay, minDiffCurrDay);
        }
        
        return minDiffPrevDay.back();
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // freq array to store the frequency of each task
        vector<int> freq(26);
        int maxCount = 0;
        
        // Count the frequency of each task and find the maximum frequency
        for (char& task:tasks){
            ++freq[task - 65];
            maxCount = max(maxCount, freq[task - 65]);
        }
        
        // Calculate the total time needed for execution
        int time = (maxCount - 1) * (n + 1);
        
        for (int f : freq){
            if (f == maxCount)
                ++time;
        }
        
        // Return the maximum of total time needed and the length of the task list
        return max((int)tasks.size(), time);
    }
};
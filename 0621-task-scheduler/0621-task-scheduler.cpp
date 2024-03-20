class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count the array to store the frequency of each task
        vector<int> counter(26);
        int maxVal = 0, maxCount = 0;
        
        // Traverse through tasks to calculate task frequencies
        for (char& task:tasks){
            ++counter[task - 65];
            
            if (maxVal == counter[task - 65])
                ++maxCount;
            else if (maxVal < counter[task - 65]){
                maxCount = 1;
                maxVal = counter[task - 65];
            }
        }
        
        // Calculate idle slots, available_tasks, and idles needed
        int partCount = maxVal - 1, partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maxVal * maxCount, idles = max(0, emptySlots - availableTasks);
        
        // Return the total time required
        return tasks.size() + idles;
    }
};
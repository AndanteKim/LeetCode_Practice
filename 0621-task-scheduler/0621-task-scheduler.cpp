class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Create a frequency array to keep track of the count of each task.
        vector<int> freq(26);
        
        for(char& task:tasks) ++freq[task - 65];
        
        // sort the frequency array in non-decreasing order
        sort(freq.begin(), freq.end());
        // Calculate the number of idle slots that will be required
        int maxFrequency = freq[25] - 1;
        int idleSlots = maxFrequency * n;
        
        // Iterate over the frequency aray from the second highset frequency to the lowest frequency
        for (int i = 24; i >= 0; --i){
            // subtract the minimum of the maximum frequency and the current frequency
            // to the lowest frequency
            idleSlots -= min(maxFrequency, freq[i]);
        }
        
        // If there are any idle slots left, add them to the total number of tasks.
        return (idleSlots > 0)? idleSlots + tasks.size() : tasks.size();
    }
};
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Stores the last index of each character in 's'
        int partitionStart = 0, partitionEnd = 0;
        vector<int> lastOccurrence(26);

        for (int i = 0; i < s.size(); ++i){
            lastOccurrence[s[i] - 97] = i;
        }

        vector<int> ans;
        for (int i = 0; i < s.size(); ++i){
            partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 97]);

            // End of the current partition
            if (i == partitionEnd){
                ans.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }

        return ans;
    }
};
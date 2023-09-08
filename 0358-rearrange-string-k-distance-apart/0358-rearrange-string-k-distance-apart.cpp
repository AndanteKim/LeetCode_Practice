class Solution {
public:
    string rearrangeString(string s, int k) {
        int freq[26] = {0};
        // store the frequency for each character
        for (char& c : s) ++freq[c - 'a'];
        
        priority_queue<pair<int, int>> maxHeap;
        // insert the charaters with their frequencies in the max heap
        for (int i = 0; i < 26; ++i) if (freq[i] > 0) maxHeap.push(make_pair(freq[i], i));
        
        queue<pair<int, int>> busy;
        string ans = "";
        // This queue stores the characters that cannot be used now
        while (ans.size() != s.size()){
            int idx = ans.size();
            
            // insert the character that could be used now into the max heap
            if (!busy.empty() && idx - busy.front().first >= k){
                auto[prevIdx, chIdx] = busy.front();
                busy.pop();
                maxHeap.push(make_pair(freq[chIdx], chIdx));
            }
            
            // If the max heap is empty, it implies no character can be used at this index
            if (maxHeap.empty()) return "";
            
            int currChIdx = maxHeap.top().second;
            maxHeap.pop();
            ans.push_back(currChIdx + 'a');
            
            // insert the used character into busy queue with the current index
            --freq[currChIdx];
            if (freq[currChIdx] > 0){
                busy.push(make_pair(idx, currChIdx));
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream iss(sentence1);
        deque<string> dq1, dq2;
        string word;
        
        while (iss >> word){
            dq1.push_back(word);
        }
        
        iss.clear();
        iss.str(sentence2);
        while (iss >> word){
            dq2.push_back(word);
        }
        
        // Compare the longest common prefix
        while (!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()){
            dq1.pop_front();
            dq2.pop_front();
        }
        
        // Compare the longest common suffix
        while (!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back()){
            dq1.pop_back();
            dq2.pop_back();
        }
        
        return dq1.empty() || dq2.empty();
    }
};
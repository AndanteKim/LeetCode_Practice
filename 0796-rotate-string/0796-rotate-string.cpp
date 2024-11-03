class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        deque<char> rotate(s.begin(), s.end());
        deque<char> g(goal.begin(), goal.end());
        
        for (int i = 0 ; i < n; ++i){
            rotate.push_front(rotate.back());
            rotate.pop_back();
            
            if (rotate == g)
                return true;
        }
        
        return false;
    }
};
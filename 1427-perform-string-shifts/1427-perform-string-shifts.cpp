class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        deque<char> dq;
        for (const char& c : s)
            dq.push_back(c);

        for (const auto& command : shift){
            // If left
            if (command[0] == 0){
                for (int i = 0; i < command[1]; ++i){
                    char c = dq.front(); dq.pop_front();
                    dq.push_back(c);
                }
            }
            else{
                for (int i = 0; i < command[1]; ++i){
                    char c = dq.back(); dq.pop_back();
                    dq.push_front(c);
                }
            }
        }

        string ans = "";

        while (!dq.empty()){
            ans.push_back(dq.front());
            dq.pop_front();
        }

        return ans;
    }
};
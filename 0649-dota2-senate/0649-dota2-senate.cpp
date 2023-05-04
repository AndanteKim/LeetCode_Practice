class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        
        queue<int> r_queue, d_queue;
        for (int i = 0; i < senate.size(); ++i){
            if (senate[i] == 'R') r_queue.push(i);
            else d_queue.push(i);
        }
        
        while (!r_queue.empty() && !d_queue.empty()){
            int r_turn = r_queue.front(), d_turn = d_queue.front();
            r_queue.pop();
            d_queue.pop();
            if (r_turn < d_turn) r_queue.push(r_turn + n);
            else d_queue.push(d_turn + n);
        }
        
        return d_queue.size() == 0? "Radiant" : "Dire";
    }
};
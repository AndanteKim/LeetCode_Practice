class Solution {
public:
    string predictPartyVictory(string senate) {
        int rCount = count(senate.begin(), senate.end(), 'R');
        int dCount = senate.size() - rCount;
        
        int dFloatingBan = 0, rFloatingBan = 0;
        queue<char> queue;
        for (int i = 0; i < senate.size(); ++i) queue.push(senate[i]);
        
        while (rCount > 0 && dCount > 0){
            char curr = queue.front();
            queue.pop();
            
            if (curr == 'D'){
                if (dFloatingBan > 0){
                    --dFloatingBan;
                    --dCount;
                }
                else{
                    ++rFloatingBan;
                    queue.push(curr);
                }
            }
            else{
                if (rFloatingBan > 0){
                    --rFloatingBan;
                    --rCount;
                }
                else {
                    ++dFloatingBan;
                    queue.push(curr);
                }
            }
        }
        
        return dCount == 0? "Radiant" : "Dire";
    }
};
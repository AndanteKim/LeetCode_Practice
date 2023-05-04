class Solution {
public:
    string predictPartyVictory(string senate) {
        int rCount = count(senate.begin(), senate.end(), 'R');
        int dCount = senate.size() - rCount;
        
        auto ban = [&](char toBan, int startAt){
            bool loopAround = false;
            int pointer = startAt;
            
            while (true){
                if (pointer == 0) loopAround = true;
                if (senate[pointer] == toBan){
                    senate.erase(senate.begin() + pointer);
                    break;
                }
                pointer = (pointer + 1) % senate.size();
            }
            return loopAround;
        };
        
        int turn = 0;
        
        while (rCount > 0 && dCount > 0){
            if (senate[turn] == 'R'){
                bool bannedSenatorBefore = ban('D', (turn + 1) % senate.size());
                --dCount;
                if (bannedSenatorBefore) --turn;
            }
            else{
                bool bannedSenatorBefore = ban('R', (turn + 1) % senate.size());
                --rCount;
                if (bannedSenatorBefore) --turn;
            }
            
            turn = (turn + 1) % senate.size();
        }
        
        return dCount == 0? "Radiant" : "Dire";
    }
};
class Solution {
public:
    bool winnerOfGame(string colors) {
        if (colors.size() <= 2)
            return false;
        
        int aOptions = 0, bOptions = 0;
        
        for (int i = 1; i < colors.size() - 1; ++i){
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]){
                if (colors[i] == 'A')
                    ++aOptions;
                else
                    ++bOptions;
            }
        }
        
        return aOptions > bOptions? true : false;
    }
};
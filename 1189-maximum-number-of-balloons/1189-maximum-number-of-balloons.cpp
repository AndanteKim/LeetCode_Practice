class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int bCnt = 0, aCnt = 0, lCnt = 0, oCnt = 0, nCnt = 0;
        for (int i = 0; i < text.size(); ++i){
            if (text[i] == 'b') ++bCnt;
            else if (text[i] == 'a') ++aCnt;
            else if (text[i] == 'l') ++lCnt;
            else if (text[i] == 'o') ++oCnt;
            else if (text[i] == 'n') ++nCnt;
        }
        lCnt /= 2;
        oCnt /= 2;
        
        return min({bCnt, aCnt, lCnt, oCnt, nCnt});
        
    }
};
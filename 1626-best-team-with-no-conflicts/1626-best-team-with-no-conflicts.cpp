class Solution {
    int queryBit(vector<int> &BIT, int age){
        int maxScore = INT_MIN;
        for (int i = age; i > 0; i -= i & (-i)){
            maxScore = max(maxScore, BIT[i]);
        }
        return maxScore;
    }
    
    void updateBIT(vector<int> &BIT, int age, int currentBest){
        for (int i = age; i < BIT.size(); i += i & (-i)) BIT[i] = max(BIT[i], currentBest);
    }
    
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> ageScorePair;
        for (int i = 0; i < scores.size(); ++i){
            ageScorePair.push_back({scores[i], ages[i]});
        }
        sort(ageScorePair.begin(), ageScorePair.end());
        
        int highestAge = 0;
        for (const int& age : ages) highestAge = max(highestAge, age);
        
        vector<int> BIT(highestAge + 1, 0);
        
        int answer= INT_MIN;
        for (const pair<int, int> ageScore: ageScorePair){
            int currentBest = ageScore.first + queryBit(BIT, ageScore.second);
            updateBIT(BIT, ageScore.second, currentBest);
            answer = max(answer, currentBest);
        }
        
        return answer;
    }
};
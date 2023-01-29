class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        losses_cnt = [-1] * 100001
        
        for winner, loser in matches:
            if losses_cnt[winner] == -1:
                losses_cnt[winner] = 0
            if losses_cnt[loser] == -1:
                losses_cnt[loser] = 1
            else:
                losses_cnt[loser] += 1
        
        answer = [[], []]
        for i in range(100001):
            if losses_cnt[i] == 0:
                answer[0].append(i)
            elif losses_cnt[i] == 1:
                answer[1].append(i)
        
        return answer
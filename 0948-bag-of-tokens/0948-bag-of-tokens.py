class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        score = 0
        tokens.sort()
        dq = deque(tokens)
        
        while dq:
            # When we've enough power, play token face-up
            if power >= dq[0]:
                power -= dq.popleft()
                score += 1
                
            # We don't have enough power to play a token face-up
            # When there is at least one token remaining,
            # and we've enough score, play token face-down
            elif len(dq) > 2 and score > 0:
                power += dq.pop()
                score -= 1
                
            # We don't have enough score, power, or tokens
            # to play face-up or down and increase our score
            else:
                return score
        
        return score
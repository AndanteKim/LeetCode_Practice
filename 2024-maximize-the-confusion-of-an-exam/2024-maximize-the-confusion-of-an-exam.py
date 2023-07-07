class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        ans, n = 0, len(answerKey)
        
        # count T
        left, offset_f = 0, k
        for right in range(n):
            if answerKey[right] == 'F':
                if offset_f > 0:
                    offset_f -= 1
                else:
                    while answerKey[left] == 'T':
                        left += 1
                    left += 1
            
            ans = max(ans, right - left + 1)
        
            
        # count F
        left, offset_t = 0, k
        for right in range(n):
            if answerKey[right] == 'T':
                if offset_t > 0:
                    offset_t -= 1
                else:
                    while answerKey[left] == 'F':
                        left += 1
                    left += 1
                
            ans = max(ans, right - left + 1)
        return ans
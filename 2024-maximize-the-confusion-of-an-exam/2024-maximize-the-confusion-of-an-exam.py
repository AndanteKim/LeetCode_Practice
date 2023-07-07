class Solution:
    def isValid(self, size: int, answerKey: str, k: int) -> bool:
        counter = Counter(answerKey[:size])
        if min(counter['T'], counter['F']) <= k:
            return True
        for i in range(size, self.n):
            counter[answerKey[i]] += 1
            counter[answerKey[i - size]] -= 1
            if min(counter['T'], counter['F']) <= k:
                return True
        return False
    
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        self.n = len(answerKey)
        left, right = k, self.n
        
        while left < right:
            mid = (left + right + 1) >> 1
            
            if self.isValid(mid, answerKey, k):
                left = mid
            else:
                right = mid - 1
        
        return left
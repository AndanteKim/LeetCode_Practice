class Solution:
    LEFT_BOUND, RIGHT_BOUND = 0, 0
    s, t = "", ""
    def rec_isSubsequence(self, left_index: str, right_index: str) -> bool:
        #base cases
        if left_index == self.LEFT_BOUND:
            return True
        if right_index == self.RIGHT_BOUND:
            return False
        
        if self.s[left_index] == self.t[right_index]:
            left_index += 1
        right_index += 1
        
        return self.rec_isSubsequence(left_index, right_index)
    
    def isSubsequence(self, s: str, t: str) -> bool:
        self.LEFT_BOUND, self.RIGHT_BOUND = len(s), len(t)
        self.s, self.t = s, t
        return self.rec_isSubsequence(0, 0)
        
        
        
class Solution:
    def is_common_prefix(self, strs: List[str], l: int) -> bool:
        str1 = strs[0][:l]
        for i in range(1, len(strs)):
            if not strs[i].startswith(str1):
                return False
        return True
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        
        min_len = float('inf')
        for s in strs:
            min_len = min(min_len, len(s))
            
        low, high = 1, min_len
        
        while low <= high:
            mid = (low + high) >> 1
            if self.is_common_prefix(strs, mid):
                low = mid + 1
            else:
                high = mid - 1
        
        return strs[0][0: (low + high) >> 1]
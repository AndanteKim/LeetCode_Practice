class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        arr_cnt, target_cnt = Counter(arr), Counter(target)
        
        return arr_cnt == target_cnt
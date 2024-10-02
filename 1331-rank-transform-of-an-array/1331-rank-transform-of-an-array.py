class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        # Store the rank for each number in arr
        num_to_idx = {k: [] for k in sorted(set(arr))}
        
        for i, num in enumerate(arr):
            num_to_idx[num].append(i)
            
        rank = 1
        for num in num_to_idx:
            for idx in num_to_idx[num]:
                arr[idx] = rank
            rank += 1
            
        return arr
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        hashmap, ans = defaultdict(int), []
        
        for num in nums:
            hashmap[num] += 1
        
        for num, height in hashmap.items():
            for i in range(height):
                if len(ans) < i + 1:
                    ans.append([num])
                else:
                    ans[i].append(num)
        
        return ans
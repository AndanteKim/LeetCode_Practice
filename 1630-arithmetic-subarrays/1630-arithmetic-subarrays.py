class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        ans, queries = [], []
        for i in range(len(l)):
            query = nums[l[i] : r[i] + 1]
            query.sort()
            queries.append(query)
            
        for query in queries:
            arithmetic, flag = query[1] - query[0], True
            for i in range(1, len(query)):
                if query[i - 1] + arithmetic != query[i]:
                    flag = False
                    break
            ans.append(flag)
        return ans
        
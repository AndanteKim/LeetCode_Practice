class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        ans, count = [], Counter(nums)

        for num, freq in count.items():
            if freq == 2:
                ans.append(num)

        return sorted(ans)
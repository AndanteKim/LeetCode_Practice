class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n, product, flag = len(nums), 1, False
        for i in range(n):
            if not nums[i]:
                if not flag:
                    flag = True
                    continue
                else:
                    return [0] * n
            product *= nums[i]
            
        return [product if num == 0 else 0 for num in nums] if flag else [product // num for num in nums]
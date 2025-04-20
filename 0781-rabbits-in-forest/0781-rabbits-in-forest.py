class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        count = Counter(answers)
        return sum(-v % (k + 1) + v for k, v in count.items())
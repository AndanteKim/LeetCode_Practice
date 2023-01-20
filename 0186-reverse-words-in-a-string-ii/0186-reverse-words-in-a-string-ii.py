class Solution:
    def reverse(self, l: List[str], left: int, right: int) -> None:
        while left < right:
            l[left], l[right] = l[right], l[left]
            left, right = left + 1, right - 1
    
    def reverse_each_word(self, l: List[str]) -> None:
        n = len(l)
        start = end = 0
        while start < n:
            while end < n and l[end] != ' ':
                end += 1
            self.reverse(l, start, end - 1)
            start = end + 1
            end += 1
    
    
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        self.reverse(s, 0, len(s) - 1)
        self.reverse_each_word(s)
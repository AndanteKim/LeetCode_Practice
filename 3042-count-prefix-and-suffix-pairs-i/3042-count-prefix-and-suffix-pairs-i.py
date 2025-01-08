class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        def is_prefix_and_suffix(str1: str, str2: str) -> bool:
            # Base case
            if len(str1) > len(str2):
                return False
            
            is_prefix, is_suffix = True, True
            # Check prefix
            for i in range(len(str1)):
                if str1[i] != str2[i]:
                    is_prefix = False
                    break
            
            diff = len(str2) - len(str1)
            # Check suffix
            for i in range(len(str1) - 1, -1, -1):
                if str1[i] != str2[i + diff]:
                    is_suffix = False
                    break

            return is_prefix and is_suffix

        n, ans = len(words), 0
        for i in range(n - 1):
            for j in range(i + 1, n):
                ans += is_prefix_and_suffix(words[i], words[j])
        return ans
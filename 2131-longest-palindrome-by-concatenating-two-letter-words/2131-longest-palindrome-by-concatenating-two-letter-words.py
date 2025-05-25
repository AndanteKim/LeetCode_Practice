class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        # A count variable contains the number of occurrences of each word
        count = Counter(words)
        ans, central = 0, False

        for word, cnt in count.items():
            # If the word is a palindrome
            if word[0] == word[1]:
                if cnt % 2 == 0:
                    ans += cnt
                else:
                    ans += cnt - 1
                    central = True
            # consider a pair of non-palindrome words,
            # such that one is the reverse of another
            # word[1] + word[0] is the reversed word
            elif word[0] < word[1]:
                ans += 2 * min(cnt, count[word[1] + word[0]])
        
        if central:
            ans += 1
        return 2 * ans
class Solution:
    # Dictionary to store words for numbers
    n_to_words = {
        1_000_000_000: "Billion", 1_000_000: "Million", 1000: "Thousand", 100: "Hundred",\
        90: "Ninety", 80: "Eighty", 70: "Seventy", 60: "Sixty", 50: "Fifty", 40: "Forty",\
        30: "Thirty", 20: "Twenty", 19: "Nineteen", 18: "Eighteen", 17: "Seventeen",\
        16: "Sixteen", 15: "Fifteen", 14: "Fourteen", 13: "Thirteen", 12: "Twelve", \
        11: "Eleven", 10: "Ten", 9: "Nine", 8: "Eight", 7: "Seven", 6: "Six", 5: "Five",\
        4: "Four", 3: "Three", 2: "Two", 1: "One"
    }
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        
        for val, word in self.n_to_words.items():
            # Check if the number is greater than or equal to the current unit
            if num >= val:
                # Convert the quotient to words if the current unit is 100 or greater
                prefix = (self.numberToWords(num // val) + " ") if num >= 100 else ""
                
                # Get the word for the current unit
                unit = word
                
                # Convert the remainder to words if it's not zero
                suffix = "" if num % val == 0 else " " + self.numberToWords(num % val)
                
                return prefix + unit + suffix
                
        return ""        
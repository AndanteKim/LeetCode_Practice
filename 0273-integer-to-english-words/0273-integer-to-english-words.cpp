class Solution {
private:
    // Vectors to store words for numbers less than 10, 20, and 100
    const vector<string> ones {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const vector<string> twenties {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen","Fifteen", "Sixteen", "Seventeen",\
                          "Eighteen", "Nineteen"};
    const vector<string> hundreds {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    // Recursive function to convert numbers to words
    // Handles numbers based on their ranges: <10, <20, <100, <1000, <1'000'000, <1'000'000'000, <1'000'000'000'000, and >=
    // 1'000'000'000'000
    string convertToWords(int num){
        if (num < 10)
            return ones[num];
        
        if (num < 20)
            return twenties[num - 10];
        
        if (num < 100)
            return hundreds[num / 10] + (num % 10 != 0? " " + convertToWords(num % 10) : "");
        
        if (num < 1000)
            return convertToWords(num / 100) + " Hundred" + (num % 100 != 0? " " + convertToWords(num % 100) : "");
        
        if (num < 1'000'000)
            return convertToWords(num / 1000) + " Thousand" + (num % 1000 != 0? " " + convertToWords(num % 1000) : "");
        
        if (num < 1'000'000'000)
            return convertToWords(num / 1'000'000) + " Million" + (num % 1'000'000 != 0? " " + convertToWords(num % 1'000'000) : "");
        
        return convertToWords(num / 1'000'000'000) + " Billion" + (num % 1'000'000'000 != 0? " " + convertToWords(num % 1'000'000'000) : "");
    }
    
public:
    // Main function to convert a number to English words
    string numberToWords(int num) {
        // Handle the special case where the number is zero
        if (num == 0)
            return "Zero";
        
        // Call the helper function to start the conversion
        return convertToWords(num);
    }
};
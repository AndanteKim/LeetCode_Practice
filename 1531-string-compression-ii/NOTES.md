For everyone to understand how the key is calculated :
k's range is from 0 to length of the string , indicating 101 possible values.
To avoid overlap of the next set of values we add to the value of k , lastCharCount 101 (which is the max value possible for k)
Next we want to store last character which has to exceed range of k which is 101 + range of lastCharCount which is 101 , so the character value relative to 'a' and multiplied by 101 * 101 , will give us the unique value corresponding to lastChar.
Next we want to store index which should exceed the range of k (101) + range of lastCharCount (101) + range of characters (27) , so the index is multiplied by 101 * 101 * 27.
​
Reason of character range to be of 27 is to include an invalid of lastChar for the first position , that is for index 0 in string, we start with lastChar which is out of range of 26 characters 'a' to 'z' . So that is an additional value to be considered that makes char range of 27.
​
​
​
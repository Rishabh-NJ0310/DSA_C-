/*

Amazon is developing a string matching library. You are to develop a service that finds the longest substring that matches a given regex.
More formally, you are given two strings, a text string text, and a regex expression regex. The string regex contains exactly one wildcard character(*). 
A wildcard character (*) matcherfhny sequence of zero or more lowercase Englis characters. 
A regex matches some string if it is possible to replace the wildcard character with some sequence of characters such that the regex expression becomes equal to the string. 
No other character can be changed. For example, regex "abc*bcd" matches "abcbcd", "abcefgbcd" and "abccbcd" whereas it does not match the strings "abcbd", "abzbcd", "abcd".
Return the length of the longest substring of texthat matches the expression regex. Return -1 if there is no such substring.

Note: A substring is a contiguous sequence of characters within a string

Example
Given text = "hackerrank", regex = "ack*r" The following substrings match regex
"acker", we can replace with "e" and regex becomes equal to "acker", length = 5
"ackerr", we can replace with "er" and regex becomes equal to "ackerr". length = 6

Function Description
Complete the function getLongestMatch in the editor below.
getLongest Match has the following parameters:
text: a string
regex: a string
Returns
int: the length of the longest substring of text that matches regex or -1 if there is none

Constraints
    1≤ | text |, | regex ≤10^5
    text contains lowercase English Letters only.
    regex contains lowercase English letters and exactly one wildcard(*) character.
*/

#include<bits/stdc++.h> 
using namespace std;

int getLongestMatch(string text, string regex) {

    int starPos = regex.find('*');
    
    
    string prefix = regex.substr(0, starPos);    
    string suffix = regex.substr(starPos + 1);  

    int n = text.size();
    int pLen = prefix.size();
    int sLen = suffix.size();

    int longestMatch = -1;
    
    
    for (int i = 0; i <= n - pLen; ++i) {
        if (text.compare(i, pLen, prefix) == 0) {
            for (int j = i + pLen; j + sLen <= n; ++j) {
                if (text.compare(j, sLen, suffix) == 0) {
                
                    int currentLength = j + sLen - i;
                    longestMatch = max(longestMatch, currentLength);
                }
            }
        }
    }
    
    return longestMatch;
}


int main(){
    string text = "hackerrank";
    string regex = "ack*r";
    cout<<getLongestMatch(text, regex)<<endl;
return 0;
}
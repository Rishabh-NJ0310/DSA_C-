/* 
A company wants all of its employees to focus on cyber security and hence regularly change their passwords. 
Given two binary string passwords s and t of equal length. 
Each string represents a binary integer where the first character represents the most significant bit of the number. 
You can rearrange the characters of t in any order you want.

The task is to maximize the value of bitwise XOR of sand t. 
Return this maximum possible XOR as a binary string of length the same as the input strings.

For example, s = "0011110", t = "1111000", 

It is optimal to rearrange the characters of t to "1100011".
The bitwise XOR of s and t would be "1111101". Hence the answer is "1111101". It can be shown that this is the maximum possible answer.

Function Description
Complete the function getMaximumXor in the editor below. 
The function must return a binary string denoting the maximum possible value of bitwise XOR.
getMaximumXor has the following parameters:

s: a binary string

t: a binary string

Sample Input For Custom Testing

11001100
01011111

Sample Output
11110011

Explanation
Given s = "11001100", t= "01011111", It is optimal to rearrange t to "00111111", the bitwise XOR becomes "11110011".

Sample Input For Custom Testing
1100
1010

Sample Output
1111
Explanation
Given s = "1100", t = "1010", It is optimal to rearrange tto "0011", the bitwise XOR become "1111".

*/

#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

string getMaximumXor(string s, string t) {
    int n = s.length();
    string result(n, '0');
    int ones_count = count(t.begin(), t.end(), '1');

    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && ones_count > 0) {
            result[i] = '1';
            ones_count--;
        } else if (s[i] == '1' && ones_count < n - i) {
            result[i] = '1';
        }
    }

    return result;
}

int main() {
    string s = "1100";
    string t = "1010";
    cout << getMaximumXor(s, t) << endl;
    return 0;
}
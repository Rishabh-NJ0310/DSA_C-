/*
    we have given Ankit an input string s, and target string t. The strins will have lengths
    -lenS and lenT respectively. He has to find smallest subset in the input string that contains element
    in the target. If fails to do so, he must return null

    input Format: 
    The first line contains a input string s, while the second line contains a target string t.

    Output Format:
    Print the smalles subset 

    Constraints

The strings may have both uppercase and lowercase characters

The solution must have a time complexity of O(n).

<1 <= lens <<<= 20000

<1 <= lent <= 100
Examples

• Input

sajkfhk
hjk

Output:
jkfh

Explanation:

Since the target value ishik, the smallest subset containing these characters is jkfh.

• Input

sajkab
hijk

Output:
null
*/

#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

string smallestSubset(string s, string t){
    int n = s.length();
    int m = t.length();
    if(n < m){
        return "null";
    }
    int freq[256] = {0};
    for(int i = 0; i < m; i++){
        freq[t[i]]++;
    }
    int count = 0;
    int start = 0;
    int min_len = INT_MAX;
    int start_index = -1;
    for(int i = 0; i < n; i++){
        freq[s[i]]--;
        if(freq[s[i]] >= 0){
            count++;
        }
        while(count == m){
            if(min_len > i - start + 1){
                min_len = i - start + 1;
                start_index = start;
            }
            freq[s[start]]++;
            if(freq[s[start]] > 0){
                count--;
            }
            start++;
        }
    }
    if(start_index == -1){
        return "null";
    }
    return s.substr(start_index, min_len);
}

int main(){

    string s, t;
    cin >> s >> t;
    cout << smallestSubset(s, t) << endl;
    
return 0;
}
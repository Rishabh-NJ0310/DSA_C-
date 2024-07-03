// Excel Column Number
// Report
// In Excel, columns are labeled as A,B,C....Z, then AA,AB,AC....AZ, BA,BB... BZ and so forth.
// The corresponding numerical values for these labels are as follows:
// B> 2
// Z-> 26
// AA -> 27
// AB -> 28
// bcda49

// Your task is to write a program that takes a string input representing the column label in uppercase letters and prints the corresponding column number.
// Input:
// • The first line of input is a string that represents the column label in uppercase letters.
// Output:
// • The output is a single line that returns the corresponding column number.
// Constraints:
// 1<=Length of Input String <= 10
// Input contains only uppercase English Alphabet letters
// Sample Input 1
// AA
// Sample Output 1
// 27
// Sample Input 2
// BA
// Sample Output 2
// 53
// Given a column label, return the corresponding column number.

#include<bits/stdc++.h>  
using namespace std;


char lowerToUpper(char c){
    if(c>='a' && c<='z'){
        return c-32;
    }
    return c;
}

int titleToNumber(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = s.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        s[i] = lowerToUpper(s[i]);
        ans = ans*26 + (s[i]-'A'+1);
    }
    return ans;
}

int main(){

    string s;
    cin>>s;
    cout<<titleToNumber(s)<<endl;

return 0;
}
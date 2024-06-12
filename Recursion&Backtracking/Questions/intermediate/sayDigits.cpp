// // failing on test cases like 12390

// #include<bits/stdc++.h>  // only for competitive programming not for developing
// using namespace std;

// string sayDigits(int n, string ans, unordered_map<int,string> mp){
//     if(n == 0){
//         return ans;
//     }
//     int rem = n%10;
//     ans += mp[rem];
//     ans+= ' ';
//     n=n/10;
//     return sayDigits(n,ans,mp);
// }


// int main(){
// unordered_map<int,string> mp;
// mp[0] = "zero";
// mp[1] = "one";
// mp[2] = "two";
// mp[3] = "three";
// mp[4] = "four";
// mp[5] = "five";
// mp[6] = "six";
// mp[7] = "seven";
// mp[8] = "eight";
// mp[9] = "nine";
// cout<<"Enter the number "<<endl;
// int number;
// cin>>number;
// int reversed = 0;
// while(number!=0){
//     int rem = number%10;
//     reversed = reversed*10 + rem;
//     number = number/10;
// }
// string ans = "";
// cout<<sayDigits(reversed, ans, mp)<<endl;
// return 0;
// }

#include<bits/stdc++.h>
using namespace std;

string sayDigits(int n, unordered_map<int,string> &mp){
    if(n == 0){
        return "";
    }
    int rem = n % 10;
    return sayDigits(n / 10, mp) + mp[rem] + " ";
}

int main(){
    unordered_map<int,string> mp;
    mp[0] = "zero";
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";
    
    cout << "Enter the number " << endl;
    int number;
    cin >> number;

    // Handle the special case when number is 0
    if (number == 0) {
        cout << mp[0] << endl;
    } else {
        string ans = sayDigits(number, mp);
        // Remove trailing space
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        cout << ans << endl;
    }

    return 0;
}

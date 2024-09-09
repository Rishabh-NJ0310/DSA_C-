#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;
//template<typename T>
#define f(n) for(int i=0;i<n;i++)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define ff(i,a,b) for(int i=a;i<b;i++)
#define frf(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define ll long long
#define vT vector<T>
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/__gcd(a,b)
#define mod 1000000007

void i_o_f(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int revNumber(int n){
    string s = to_string(n);
    reverse(s.begin(),s.end());
    return stoi(s);
}

bool isPalin(string s){
    int l=0,h=s.length()-1;
    while(l<=h){
        if(s[l] != s[h]){
            return false;
        }
        l++,h--;
    }
    return true;
}

int printNumber(int n){
    int count =0;
    int curr = n;
    while(!isPalin(to_string(curr))){
        int rev = revNumber(curr);
        curr+=rev;
        count++;
    }
    cout<<curr<<endl;
    return count;
}

int main(){
i_o_f();

    cout<<printNumber(74);

return 0;
}
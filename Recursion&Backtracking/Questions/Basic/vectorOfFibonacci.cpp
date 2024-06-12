#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

vector<int> vectorOfFibonacci(int end, vector<int> &ans, int curr){
    int temp = ans[ans.size()-1] + ans[ans.size()-2]; 
    if(curr >= end){
        ans.push_back(temp);
        return ans;
    }
    ans.push_back(temp);
    curr++;
    return vectorOfFibonacci(end, ans, curr);
}



int main(){
    vector<int> pinglaSutra{0,1};
    cout<<"Enter the range of numbers upto which you wanted to have fibonacci series "<<endl;
    int range;
    cin>>range;
    vectorOfFibonacci(range, pinglaSutra, 2);
    for(auto i: pinglaSutra){
        cout<<i<<" ";
    }

return 0;
}
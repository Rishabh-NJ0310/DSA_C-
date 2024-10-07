#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

// find two subarrays with equal average of sum
bool isAverageSumSubArray(vector<int> &v){
    int leftsum = 0, rightsum = accumulate(v.begin(),v.end(),0);
    /*
    for(int i=0;i<v.size();i++){
        leftsum += v[i];
        rightsum -= v[i];
        if(leftsum == rightsum){
            return true;
        }
    }
    return false;
    */
    for(int i=0;i<v.size();i++){
        leftsum += v[i];
        rightsum -= v[i];
        if(leftsum/(i+1) == rightsum/(v.size() - i +1)){
            return true;
        }
    }
    return false;
}

int main(){
    string s;
    getline(cin,s);
    vector<int> v;
    for(int i=0;i<s.length();i++){
        if(s[i]== ' ' || s[i] == ',' || s[i] == '[' || s[i] == ']'){
            continue;
        }
        else{
            v.push_back(s[i]-'0');
        }
    }
    if(isAverageSumSubArray(v)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
return 0;
}
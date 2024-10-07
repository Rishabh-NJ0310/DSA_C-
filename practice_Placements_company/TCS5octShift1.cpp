#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

vector<int> stringToVec(string s){
    stringstream ss;
    ss<<s;
    int num;
    char ch;
    vector<int> vec;
    while(ss>>num){
        vec.push_back(num);
        ss>>ch; // for white spaces or any other characters
    }
    return vec;
}

// method 1 using nested for loop O(N^2)
int countTheDiff(vector<int> arr, int k){
    int count = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(abs(arr[i] - arr[j]) == k){
                ++count;
            }
        }
    }
    return count;
}

// method 2 using set O(N^2)
int countTheDiff(vector<int> arr, int k){
    set<pair<int,int>> s;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(abs(arr[i] - arr[j]) == k){
                s.insert({arr[i],arr[j]});
            }
        }
    }
    return s.size();
}

// method 3 using sorting O(NlogN)
int countTheDiff(vector<int> arr, int k){
    sort(arr.begin(),arr.end());
    int count = 0;
    int i=0,j=1;
    for(int i=1;i<arr.size();i++){
        if(abs(arr[i-1] - arr[i]) == k){
            ++count;
        }
    }
    return count;
}


// method 4 using unordered_map O(N)
int countTheDiff(vector<int> arr, int k){
    unordered_map<int,int> m;
    int count = 0;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    for(int i=0;i<arr.size();i++){
        if(m.find(arr[i] + k) != m.end()){
            ++count;
        }
    }
    return count;
}


int main(){
    string s;
    getline(cin,s);
    int k;
    cin>>k;
    vector<int> arr = stringToVec(s);

    int count = countTheDiff(arr,k);

    cout<<count<<endl;
return 0;
}
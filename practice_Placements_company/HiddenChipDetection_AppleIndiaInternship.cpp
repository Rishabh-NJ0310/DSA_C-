/*
A dataset comprising n images, each with varying dimensions and sizes, is provided for an image recognition system. 
The images are structured as squares and represent chips of diverse shapes, with each chip weighing 1 gram.

The objective is to develop a chip detection algorithm to identify situations where one chip is concealed within another. 
In this context, a chip is considered hidden if the dimensions of the larger chip are at least k times greater 
than those of the smaller chip. Furthermore, the total weight of the chips in the system must not exceed 2 grams, 
meaning that, at most, one chip can be hidden inside another.
To optimize the chip detection efficiency, and given an array imageDim of length n, specifying the side
length of each chip, detemine the maximum number of chips that can be accurately identified as hidden within other chips

Example:
imageDim = [4,2,6,14] and k = 3
The 2nd chip with a side of length 2 can be hidden inside the 3rd chip with a side of length 6,
additionally the 1st chip with a side length of 4 can be hidden inside the 4th chip with a side length of 14.
*/
/*
solution:
Step 1: Define the Problem Parameters
    n: Number of images (chips).
    k: Dimension ratio threshold for hidden chip detection.
    Weight Constraint: Total weight must not exceed 2 grams.
Step 2: Sort Chips by Size
    Sort the chips based on their dimensions in descending order.
Step 3: Check for Hidden Chips
    Iterate through the sorted list of chips.
    For each chip, check if there exists another chip whose dimensions are at least k times smaller.
    Ensure that if a chip is found to be hidden, the total weight constraint (2 grams) is not violated.
Step 4: Implement Detection Logic
    Use a nested loop to compare each chip with others that come after it in the sorted list.
    If a chip’s dimensions are at least k times greater than another chip’s dimensions, mark the smaller chip as hidden.
    Break the loop if a hidden chip is found to avoid multiple detections under the weight constraint.
Step 5: Validate Weight Constraint
    After identifying a potential hidden chip, verify that the total weight does not exceed 2 grams.
    If the weight constraint is violated, adjust the detection logic or report an error.
*/

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
int getMaxHiddenChips(vector<int> imageDim, int k){
    int n = imageDim.size();
    sort(imageDim.begin(),imageDim.end());
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(imageDim[j]>=k*imageDim[i]){
                ans++;
                break;
            }
        }
    }
    return ans;
}
int main(){
i_o_f();
int n;
cin>>n;
vector<int> imageDim(n);
f(n){
    cin>>imageDim[i];
}
int k;
cin>>k;
cout<<getMaxHiddenChips(imageDim,k)<<endl;
return 0;
}
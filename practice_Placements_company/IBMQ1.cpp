/* 
you are given 'n' triangles and their sides a,b,c print them in the same style 
but sorted by their area in from smallest to largest it is guaranteed that all the 
areas are different. 
The best way to calculare a area of a triangle is by using Heron's formula
Area = sqrt(s(s-a)(s-b)(s-c)) where s = (a+b+c)/2

input format:
The first line of each test file contains a single integer 'n'
Then, 'n' lines follow with three space-separated integers a,b,c

3
7 24 25
5 12 13
3 4 5

output format:
print exactly 'n' lines each containing three space-separated integers a,b,c
for the input above, the output should be 
as below 
3 4 5
5 12 13
7 24 25

Explanation:
Area of 1st triangle a = 7 b = 24 c = 25 is S =  84
Area of 2nd triangle a = 3 b = 4 c = 5 is S = 6
Area of 3rd triangle a = 5 b = 12 c = 13 is S = 30
*/
#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

struct triangle{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle; 
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap2(triangle *a, triangle *b){
    triangle temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *area, triangle *tr, int low, int high){
    int pivot = area[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(area[j]<pivot){
            i++;
            swap(&area[i], &area[j]);
            swap2(&tr[i], &tr[j]);
        }
    }
    swap(&area[i+1], &area[high]);
    swap2(&tr[i+1], &tr[high]);
    return i+1;
}
void quickSort(int *area, triangle *tr, int low, int high){
    if(low<high){
        int pi = partition(area, tr, low, high);
        quickSort(area, tr, low, pi-1);
        quickSort(area, tr, pi+1, high);
    }
    return;
}

int sort_by_area(triangle* tr, int n) {
    int s[n];
    for(int i=0;i<n;i++){
        s[i] = (tr[i].a + tr[i].b + tr[i].c)/2.0;
    }
    int area[n];
    for(int i=0;i<n;i++){
        area[i] = sqrt(s[i]*(s[i]-tr[i].a)*(s[i]-tr[i].b)*(s[i]-tr[i].c));
    }
    quickSort(area, tr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<tr[i].a<<" "<<tr[i].b<<" "<<tr[i].c<<endl;
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    triangle tr[n];
    for(int i=0;i<n;i++){
        cin>>tr[i].a>>tr[i].b>>tr[i].c;
    }
    sort_by_area(tr, n);

return 0;
}
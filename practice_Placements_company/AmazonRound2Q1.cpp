/*
An AWS client has brought servers and databases from data centers in different parts of the world for their application.
For simplicity, let's assume all the servers and data centers are located on a 1-dimensional line.
You have been given the task of optimizing the network connection. Each data center must be connected to a server.
The positions of n data centers and n servers are given in the form of arrays.
Any particular data center, center[i], can deliver to any particular server destination, destination[j]. 
The lag is defined distance between a data center at location x and a server destination at location y is x-y, i.e., 
the absolute difference between x and y. 
Determine the minimum lag to establish the entire network.

Example
There are n = 3 connections, 
the positions of data centers, center = [1, 2, 2], and 
the positions of the server destinations, destination = [5, 2,4]

The most efficient deliveries are:

• The center at location 1 makes the first connection to the server at location 2.

• The center at location 2 makes the second connection to the server at location 4.

• The center at location 2 makes the third connection to the server at location 5.

The minimum total lag is = abs(1-2) + abs(2-4) + abs(2-5)=1+2+3=6.

Function Description

Complete the function getMinDistance in the editor below.

getMin Distance has the following parameter(s):

int center[n]: the positions of data centers int destination[n]: the positions of server destinations

Returns:
long int the minimum lag
*/


#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

long long getMinDistance(vector<int> center, vector<int> destination){
    int n = center.size();
    long long minLag = 0;
    int m = destination.size();
    for(int i=0;i<n;i++){
        minLag += static_cast<long long>(abs(static_cast<long long>(center[i])-destination[i]));
    }
    return minLag;
}


int main(){
    vector<int> center = {1, 2, 2};
    vector<int> destination = {5, 2, 4};
    cout<<getMinDistance(center, destination)<<endl;
return 0;
}
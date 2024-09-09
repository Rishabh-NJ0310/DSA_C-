/*
In order to uniquely identify the devices on the computer network, 
each device is allotted an Internet Protocol address (IP address). 
There are 2 versions of address formats in use i.e. IPv4 which 32 bits in 
length and IPv6 having 128 bits. Modern devices use IPv6 but in order to 
communicate with devices supporting only IPv4, the conversion from IPv4 to IPv6 and 
vice versa. Also, the IPv4 addresses of the format 127.x.x.x 
(where x means any octet value) are the loopback addresses and the equivalent
of it in IPV6 is ::1.

Consider the IP address 192.168.10.92. 
The 4 octets of the IP address would be 192, 168, 10 and 92 and the hexadecimal equivalent of these octets are CO, AS, OA and 5C. 
Then, the the first and second are concatenated and third and fourth are concatenated to get COAS and BA5C. Finally, the IPv6 is formed as:: FFFF:C0A8:0ASC. (The FFFF in the IPv6 address is a constant and should appear in all IPv4 to IPv6 converted address except the loopback address.)
Similarly, any input IPv4 address which is a loopback address, the output should be ::1.
You are expected to finish the function with takes a the IPv4 address as a parameter and print the IPv6 equivalent of it.
Function Description

Complete the function convertTolpv6 in the editor below.
convert Tolpv6 has the following parameter:
str ipv4address: A string representing the IPv4 address.
Output

The IPv6 address should be printed on the console.

Constraints

The IPv4 address should have only 4 octets.

Each octet can have decimal value between 0 and 255 only.

• Any IPv4 address having the first octet as 127 shall be considered a loopback address.

The IPv6 address should be printed in all uppercase, using lowercase would cause tests to fail.

sample input:
192.168.10.92
sample output:
::FFFF:C0A8:0A5C
*/


#include <bits/stdc++.h> // Only for competitive programming, not for production/development.
using namespace std;

// Function to convert a decimal octet to its 2-digit uppercase hexadecimal equivalent.
string octetToHex(int octet) {
    stringstream ss;
    ss << uppercase << hex << setw(2) << setfill('0') << octet;  // Format as 2-digit uppercase hex
    return ss.str();
}

// Function to convert an IPv4 address to its IPv6 equivalent.
void convertToIpv6(string ipv4address) {
    // Check if the IPv4 address is a loopback address
    if (ipv4address.substr(0, 4) == "127.") {
        cout << "::1" << endl;
        return;
    }

    // Split the IPv4 address into its octets
    vector<string> octets;
    stringstream ss(ipv4address);
    string octet;
    while (getline(ss, octet, '.')) {
        octets.push_back(octet);
    }

    // Convert the octets to hexadecimal
    string hexPart1 = octetToHex(stoi(octets[0])) + octetToHex(stoi(octets[1]));
    string hexPart2 = octetToHex(stoi(octets[2])) + octetToHex(stoi(octets[3]));

    // Format the IPv6 address with the constant "FFFF"
    cout << "::FFFF:" << hexPart1 << ":" << hexPart2 << endl;
}

int main() {
    string ipv4address = "192.168.10.92";
    convertToIpv6(ipv4address);

    return 0;
}

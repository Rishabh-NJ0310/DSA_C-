#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;
// what this sorting used for
// External sorting is a class of algorithms used for dealing with massive quantities of data that do not fit into a computer's main memory. 
//External sorting is required when the data being sorted do not fit into the main memory of a computing device (usually RAM) and instead they must reside in the slower external memory (usually a hard drive).
void externalSort(string input_file, string output_file, int block_size, int memory_size, int num_blocks){
    ifstream in(input_file);
    ofstream out(output_file);
    vector<int> input;
    int x;
    while(in>>x){
        input.push_back(x);
    }
    int num_files = ceil((double)input.size()/block_size);
    for(int i=0;i<num_files;i++){
        string file_name = "file" + to_string(i) + ".txt";
        ofstream temp(file_name);
        for(int j=0;j<block_size;j++){
            if(i*block_size+j<input.size()){
                temp<<input[i*block_size+j]<<" ";
            }
        }
        temp.close();
    }
    vector<ifstream> files;
    for(int i=0;i<num_files;i++){
        string file_name = "file" + to_string(i) + ".txt";
        ifstream temp(file_name);
        files.push_back(temp);
    }
    vector<int> output;
    for(int i=0;i<num_files;i++){
        vector<int> block;
        for(int j=0;j<block_size;j++){
            if(files[i]>>x){
                block.push_back(x);
            }
        }
        sort(block.begin(), block.end());
        for(int j=0;j<block.size();j++){
            output.push_back(block[j]);
        }
    }
    sort(output.begin(), output.end());
    for(int i=0;i<output.size();i++){
        out<<output[i]<<" ";
    }
    in.close();
    out.close();
    for(int i=0;i<num_files;i++){
        string file_name = "file" + to_string(i) + ".txt";
        remove(file_name.c_str());
    }
}


int main(){
    string input_file = "input.txt";
    string output_file = "output.txt";
    int block_size = 5;
    int memory_size = 20;
    int num_blocks = 4;
    externalSort(input_file, output_file, block_size, memory_size, num_blocks);

return 0;
}
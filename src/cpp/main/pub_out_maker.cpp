#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

const char path_in[] =   "./data/_in/";
const char path_out[]=   "./data/_out/";
const char exe_name[]=  "std.exe";
const int  num_file = 12;

int main(){
    for(int i = 1; i <= num_file; ++i){
        string in_name = path_in;
        in_name += to_string(i)+".in";

        string out_name = path_out;
        out_name += to_string(i)+".out";

        string cmd = string(exe_name)+"<"+in_name+">"+out_name;
        printf("exe:%s", cmd.c_str());
        int rc = system(cmd.c_str());
        printf("[%d]\n", rc);
    }
    return 0;
}

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;
const string working_path =     "../";
const string path_in =          working_path+"./in";
const string data_maker_name=   "data_maker.exe";
int main(){
    srand(time(0)^rand());
    for(int i = 1; i <= 20; ++i){
        string in_name = path_in + "/" + to_string(i)+".in";
        string seed = to_string(rand());
        if(0 and 1 <= i and i<= 5){//LIST
            string tp = "0";
            string cmd = data_maker_name +" "+tp+" "+seed+" > "+in_name;
            printf("cmd:[%s]",cmd.c_str());
            int rc = system(cmd.c_str());
            printf("(%d)\n", rc);
        }else if(0 and 6 <= i and i<= 10){//FLOWER
            string tp = "1";
            string cmd = data_maker_name +" "+tp+" "+seed+">"+in_name;
            printf("cmd:[%s]",cmd.c_str());
            int rc = system(cmd.c_str());
            printf("(%d)\n", rc);
        }else if(1 and 11 <= i and i<= 15){//VERTICAL
            if(i == 11 ) continue;
            if(i == 13 ) continue;
            if(i == 14 ) continue;
            if(i == 15 ) continue;
            string tp = "2";
            string cmd = data_maker_name +" "+tp+" "+seed+">"+in_name;
            printf("cmd:[%s]",cmd.c_str());
            int rc = system(cmd.c_str());
            printf("(%d)\n", rc);
        }else if(0 and 16 <= i and i<= 20){//NAN
            string tp = "3";
            string cmd = data_maker_name +" "+tp+" "+seed+">"+in_name;
            printf("cmd:[%s]",cmd.c_str());
            int rc = system(cmd.c_str());
            printf("(%d)\n", rc);
        }
    }
    return 0;
}

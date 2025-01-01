#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;
const string working_path =     "./";
const string path_in =          working_path+"./data/_in";
const string data_maker_name=   "pub_data_maker.exe";
int main(){
    srand(time(0)^rand());
    for(int i = 11; i <= 12; ++i){
        string in_name = path_in + "/" + to_string(i)+".in";
        string seed = to_string(rand());
        if(11<= i and i<= 12){//NAN
            string tp = "3";
            string cmd = data_maker_name +" "+tp+" "+seed+">"+in_name;
            printf("cmd:[%s]",cmd.c_str());
            int rc = system(cmd.c_str());
            printf("(%d)\n", rc);
        }
    }
    return 0;
    for(int i = 1; i <= 8; ++i){
        string in_name = path_in + "/" + to_string(i)+".in";
        string seed = to_string(rand());
        if(1 <= i and i<= 2){
            string tp = "0";
            string cmd = data_maker_name +" "+tp+" "+seed+" > "+in_name;
            printf("cmd:[%s]",cmd.c_str());
            int rc = system(cmd.c_str());
            printf("(%d)\n", rc);
        }else if(3 <= i and i<= 4){//FLOWER
            string tp = "1";
            string cmd = data_maker_name +" "+tp+" "+seed+">"+in_name;
            printf("cmd:[%s]",cmd.c_str());
            int rc = system(cmd.c_str());
            printf("(%d)\n", rc);
        }else if(5 <= i and i<= 6){//VERTICAL
            string tp = "2";
            string cmd = data_maker_name +" "+tp+" "+seed+">"+in_name;
            printf("cmd:[%s]",cmd.c_str());
            int rc = system(cmd.c_str());
            printf("(%d)\n", rc);
        }else if(7<= i and i<= 8){//NAN
            string tp = "3";
            string cmd = data_maker_name +" "+tp+" "+seed+">"+in_name;
            printf("cmd:[%s]",cmd.c_str());
            int rc = system(cmd.c_str());
            printf("(%d)\n", rc);
        }
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

#include <assert.h>
#include <time.h>
#include <string.h>

using namespace std;
const int MAX_SIZE = 100+30;
const int POS_RANGE = 100; 
const int F_RANGE = 5000; 




int main(int argc, char** argv){
    int tp = argv[1][0]-'0';

    int seed = 0;
    for(int i = 0; i < strlen(argv[2]); ++i){
        seed *= 10;
        seed += argv[2][i]-'0';
    }
    srand(rand()^seed);

    int ring_num;
    int is_tree = tp&1;

    if(tp <= 1){
        ring_num = 1;
    }else{
        ring_num = rand()%400+100;
    }

    vector<pair<int, int>> edge;
    int node_idx = 1;
    for(int i = 1; i <= ring_num; ++i){
        int node_num = (1e5/3)/ring_num + rand()%10;
        int head = node_idx;
        for(int j = 0; j < node_num-1; ++j){
            edge.push_back({node_idx, node_idx+1});
            node_idx ++;
        }
        edge.push_back({node_idx, head});
        node_idx ++;
    }

    if(is_tree){
        while(node_idx < 1e5){
            edge.push_back({node_idx, (rand()^(rand()<<5))%(node_idx-2)+1});
            node_idx ++;
        }
    }

    vector<int> hash;
    for(int i = 0; i <= edge.size(); ++i){
        hash.push_back(i);
    }
    random_shuffle(hash.begin()+1, hash.end());
    random_shuffle(edge.begin(), edge.end());

    cout << edge.size() << '\n';
    for(auto e : edge){
        cout << hash[e.first] << ' ' << hash[e.second] << '\n';
    }
    return 0;
}
#include <iostream>
#include <set>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
const int MAX_SIZE = 100+30;
const int POS_RANGE = 100; 
const int F_RANGE = 5000; 

enum Type{
    LIST, FLOWER, VERTICAL, NAN
}type = VERTICAL;

struct Vec3{
    int x, y, z;
    Vec3(int x = 0, int y = 0, int z = 0):x(x), y(y), z(z){}
    Vec3(const string& cmd){
        if(cmd == "rand pos"){
            x = rand()%(2*POS_RANGE)-POS_RANGE;
            y = rand()%(2*POS_RANGE)-POS_RANGE;
            z = rand()%(2*POS_RANGE)-POS_RANGE;
        }else if(cmd == "rand f"){
            x = rand()%F_RANGE;
            y = rand()%F_RANGE;
            z = rand()%F_RANGE;
        }else{
            assert(0);
        }
    }
    string str(){
        return to_string(x)+to_string(y)+to_string(z); 
    }
}pos[MAX_SIZE];

vector<pair<int, int>> eage;
vector<int> G[MAX_SIZE];


int main(int argc, char** argv){
    int tp = argv[1][0]-'0';
    assert(0<= tp and tp <= NAN);
    type = (Type)tp;

    int seed = 0;
    for(int i = 0; i < strlen(argv[2]); ++i){
        seed *= 10;
        seed += argv[2][i]-'0';
    }
    srand(rand()^time(0)^seed);

    int n = 100;//[1, 100]
    int root;
    if(type == LIST){
        root = 1;
        vector<int> arr;
        for(int i = 1; i <= n; ++i){
            arr.push_back(i);
        }
        random_shuffle(arr.begin()+1, arr.end());
        for(int i = 0; i < n-1; ++i){
            eage.push_back({arr[i], arr[i+1]});
        }
    }else if(type == FLOWER){
        root = 1;
        for(int i = 2; i <= n; ++i){
            eage.push_back({root, i});
        }
    }else{
        root = rand()%n+1;
        vector<int> used = {root};
        vector<int> not_used;
        for(int i = 1; i <= n; ++i){
            if(i != root){
                not_used.push_back(i);
            }
        }
        random_shuffle(not_used.begin(), not_used.end());
        for(int i = 0; i < not_used.size(); ++i){
            int a = not_used[i];
            int b = used[rand()%(used.size())];

            used.push_back(a);
            eage.push_back({b, a});
        }
    }

    // printf("luozi");
    set<string> pos_str;
    if(type == VERTICAL){
        //建图
        for(int i = 0; i < eage.size(); ++i){
            G[eage[i].first].push_back(eage[i].second);
            G[eage[i].second].push_back(eage[i].first);
        }
        pos[root] = Vec3("rand pos");
        pos_str.insert(pos[root].str());
        set<int> vit;
        queue<int> que;

        que.push(root);
        vit.insert(root);

        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(int i = 0; i < G[now].size(); ++i){
                if(vit.count(G[now][i]) == 0){
                    vit.insert(G[now][i]);
                    que.push(G[now][i]);

                    while(1){
                        int ray = rand()%3;
                        Vec3 v = pos[now];
                        if(ray == 0){
                            v.x += rand()%100 - 50;
                            if(abs(v.x) >= 100) continue;
                        }else if(ray == 1){
                            v.y += rand()%100 - 50;
                            if(abs(v.y) >= 100) continue;
                        }else{
                            v.z += rand()%100 - 50;
                            if(abs(v.z) >= 100) continue;
                        }

                        if(pos_str.count(v.str()) == 1){
                            continue;
                        }else{
                            pos[G[now][i]] = v;
                            pos_str.insert(v.str());
                            break;
                        }
                    }
                }
            }
        }

    }else{
        for(int i = 1; i <= n; ++i){
            while(1){
                Vec3 v("rand pos");
                if(pos_str.count(v.str()) == 0){
                    pos[i] = v;
                    pos_str.insert(v.str());
                    break;
                }else{
                    void();
                }
            }            
        }
    }

    //输出 n
    cout << n << '\n';
    //输出pos[1~n]
    for(int i = 1; i <= n; ++i){
        cout << pos[i].x << ' ' << pos[i].y << ' ' << pos[i].z << '\n';
    }
    //输出边集
    assert(eage.size() == n-1);
    random_shuffle(eage.begin(), eage.end());
    for(int i = 0; i < eage.size(); ++i){
        if(rand()&1){
            cout << eage[i].first << ' ' << eage[i].second << '\n';
        }else{
            cout << eage[i].second << ' ' << eage[i].first << '\n';
        }
    }
    
    //输出 p
    cout << root << ' ';
    //输出 F
    if(type == VERTICAL){
        int ray = rand()%3+1;
        for(int i = 1; i <= 3; ++i){
            int sgn = rand()&1?-1:1;
            if(i == ray){
                cout << sgn*(rand()%500 + 4000);
            }else{
                cout << '0';
            }

            if(i != 3){
                cout << ' ';
            }else{
                cout << '\n';
            }
        }

    }else{
        cout << (rand()&1?-1:1)*(rand()%500 + 4000) << ' ';  
        cout << (rand()&1?-1:1)*(rand()%500 + 4000) << ' ';  
        cout << (rand()&1?-1:1)*(rand()%500 + 4000);  
    }
    return 0;
}





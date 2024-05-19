#include <list>
#include <iostream>
#include <algorithm>

#include <assert.h>
using namespace std;
const int MAX_SIZE = 1e5 +30;

struct Ring{
    list<int> nodes;
    int val = 0;
    int max = 0;
    int min = 0;

    void formate();
};

int n;
list<int> edge[MAX_SIZE];
int nxt[MAX_SIZE];

list<Ring> rings;

int color[MAX_SIZE];

int dfs(int src);

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        assert(1<=a  and a<= n);
        assert(1<=b  and b<= n);
        nxt[a] = b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    // int ring_n = 0;
    for(int i = 1; i <= n; ++i){
        int tag = i;
        int now = i;
        while(color[now] == 0){
            color[now] = tag;
            now = nxt[now];
        }
        if(color[now] == tag){//ring
            list<int> new_ring;
            new_ring.push_back(now);
            int itr = nxt[now];
            while(itr != now){
                new_ring.push_back(itr);
                itr = nxt[itr];
            }
            rings.push_back({new_ring,0,0,0});
            rings.back().formate();
            // ring_n += rings.back().nodes.size();
        }
    }
    // assert(ring_n == n);
    // assert(rings.size() == 1);

    Ring* ans = &(rings.front());
    for(auto itr = rings.begin(); itr != rings.end(); ++itr){
        if(itr->val > ans->val){
            ans = &(*itr);
        }else if(itr->val == ans->val && itr->max > ans->max){
            ans = &(*itr);
        }
    }

    for(int num : ans->nodes){
        cout << num << ' ';
    }
    return 0;
}

void Ring::formate(){
    min = max = nodes.front();

    for(int num : nodes){
        max = ::max(max, num);
        min = ::min(min, num);
    }

    while(nodes.front() != min){
        nodes.push_back(nodes.front());
        nodes.pop_front();
    }

    val = 2*nodes.size() - dfs(nodes.front());
}   


bool vit[MAX_SIZE];
int dfs(int src){
    vit[src] = true;
    int ret = 1;
    for(auto b : edge[src]){
        if(vit[b] == false){
            vit[b] = true;
            ret += dfs(b);
        }
    }
    return ret;
}

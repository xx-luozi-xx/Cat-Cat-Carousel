#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
using namespace std;
const int MAX_SIZE = 100+30;
int n, P;
vector<int> eage[MAX_SIZE];
int fa[MAX_SIZE];

struct Vec3{
    double x, y, z;
    Vec3()=default;
    Vec3(double x, double y, double z):x(x),y(y),z(z){}
    Vec3(const Vec3& p1, const Vec3& p2):
        x(p2.x-p1.x),y(p2.y-p1.y),z(p2.z-p1.z){}
    double len(){return sqrt(x*x+y*y+z*z);}
    double len2(){return x*x+y*y+z*z;}
    Vec3 X(const Vec3& rhs){
        return {
            y*rhs.z-z*rhs.y,
            z*rhs.x-x*rhs.z,
            x*rhs.y-y*rhs.x
        };
    }
    double cdot(const Vec3& rhs){
        return x*rhs.x+y*rhs.y+z*rhs.z;
    }
    Vec3 times(double num){
        return {num*x, num*y, num*z};
    }
}F;

Vec3 pos[MAX_SIZE];
double S[MAX_SIZE];
void make_fa(int root);
void make_S(int point, Vec3 f);
void init();
int main(){
    int T; cin >> T;
    again_:init();

    T--;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> pos[i].x >> pos[i].y >> pos[i].z;
    }
    //建图 
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        eage[a].push_back(b);
        eage[b].push_back(a);
    }
    
    cin >> P;
    cin >> F.x >> F.y >> F.z;
    //以P为根建树
    make_fa(P);
    //计算所有
    make_S(P, F);
    //输出
    for(int i = 1; i <= n; ++i){
        printf("%lf\n", S[i]);
        // cout << S[i] << '\n';
    }
    if(T) goto again_;
    return 0;
}

void make_fa(int root){
    for(int i = 0; i < (int)(eage[root].size()); ++i){
        if(eage[root][i] != fa[root]){
            fa[eage[root][i]] = root;
            make_fa(eage[root][i]);
        }
    }
}

void make_S(int point, Vec3 f){
    bool tran = 0;
    for(int i = 0; i < (int)(eage[point].size()); ++i){
        if(eage[point][i] != fa[point]){
            tran = 1;
            Vec3 Pq(pos[point], pos[eage[point][i]]);
            assert(Pq.len2()!=0);
            Vec3 next_f = Pq.times(f.cdot(Pq)/Pq.len2());
            S[point] += f.X(next_f).len();
            make_S(eage[point][i], next_f);
        }
    }
    if(tran == 0){
        S[point] = f.len();
    }
}

void init(){
    for(int i = 0; i < MAX_SIZE; ++i){
        eage[i] = vector<int>();
        fa[i] = int();
        pos[i] = Vec3();
        S[i] = double();
    }
    F = Vec3();
    n = P = 0;
}
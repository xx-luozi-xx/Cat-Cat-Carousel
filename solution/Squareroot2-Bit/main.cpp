#include <iostream>

#define N 100005

using namespace std;
struct Node {
    int to = 0;
    int type = 0;   // 0 未标记,1 暂时标记,2 环外,3 环上
    int ring_index = 0;
};
struct Ring {
    int min, max;
    int love;
};
Node nodes[N];
Ring rings[N];
int ring_index = 0;

// 返回入环节点序号
int dfs(int i) {
    if (nodes[i].type == 0) {   // 该节点尚未标记（0）
        nodes[i].type = 1;             //先为其做暂时标记（1）
        int d = dfs(nodes[i].to);   //然后对下一个节点调用dfs函数。
        if (d == 0) {   //该节点在环外，使得该环的love--
            nodes[i].type = 2;  //将该节点标记为在环外（2）
            nodes[i].ring_index = nodes[nodes[i].to].ring_index;
            rings[nodes[i].ring_index].love--;
            return 0;
        } else {        //该节点在环上，使得该环的love++
            nodes[i].type = 3;  //将该节点标记为在环上（3）
            nodes[i].ring_index = nodes[nodes[i].to].ring_index;
            if (i < rings[nodes[i].ring_index].min) //更新该环上的编号最小节点
                rings[nodes[i].ring_index].min = i;
            if (i > rings[nodes[i].ring_index].max) //更新该环上的编号最大节点
                rings[nodes[i].ring_index].max = i;
            rings[nodes[i].ring_index].love++;
            if (i == d)     //该节点为入环节点
                return 0;
            else            //该节点不是入环节点
                return d;
        }
    } else if (nodes[i].type == 1) {    // 该节点已做暂时标记（1），证明新找到了一个环，返回该节点的编号。
        rings[ring_index].min = rings[ring_index].max = i;  // 初始化该环的编号最小节点、编号最大节点
        rings[ring_index].love = 0;     // 初始化该环的猫猫喜爱程度
        nodes[i].ring_index = ring_index;
        ring_index++;
        return i;
    } else  // 该节点已被标记为在环外（2）或环上（3），证明找到了一个旧的环，返回0。
        return 0;
}

int main() {
    int n;
    cin >> n;
    int index, to;
    for (int i = 0; i < n; ++i) {   //建表
        cin >> index >> to;
        nodes[index].to = to;
        nodes[index].type = 0;
    }
    for (int i = 1; i <= n; ++i) {  //找环，并计算猫猫的喜爱程度
        dfs(i);
    }
    int r = 0;
    for (int i = 1; i < ring_index; ++i) {  // 寻找猫猫最喜欢的“旋转木马”
        if (rings[i].love > rings[r].love ||
            (rings[i].love == rings[r].love && rings[i].max > rings[r].max))
            r = i;
    }
    int p = rings[r].min;
    do {            // 输出猫猫最喜欢的“旋转木马”
        cout << p;
        p = nodes[p].to;
        if (p != rings[r].min)
            cout << " ";
    } while (p != rings[r].min);
    return 0;       // return 0
}


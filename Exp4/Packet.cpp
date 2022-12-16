#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <windows.h>
#include <fstream>
#include <stack>

using namespace std;

struct thing
{
    int sign;
    int weight;
    int value;
    double value_per_weight;

    bool operator<(const thing &t) const
    {
        return value_per_weight > t.value_per_weight;
    }
};

struct Node
{
    int bound;  // 最大可能价值
    int weight; // 背包剩余的重量
    int value;  // 当前价值
    int level;  // 当前物品的编号
    int sign;   // 在ans数组中的下标
    int parent; // 父节点在ans数组中的下标
    int choose; // 是否选择
    Node() {}
    Node(int w, int v, int l, int b, int s, int p, int c) : weight(w), value(v), level(l), bound(b), sign(s), parent(p), choose(c) {}
    Node &operator=(const Node &n)
    {
        bound = n.bound;
        weight = n.weight;
        value = n.value;
        level = n.level;
        sign = n.sign;
        parent = n.parent;
        choose = n.choose;
        return *this;
    }
};

struct cmp
{
    bool operator()(const Node &a, const Node &b)
    {
        return a.bound < b.bound;
    }
};

priority_queue<Node, vector<Node>, cmp> q;

thing *things;

int best_value = 0;

Node best_thing(0, 0, 0, 0, 0, 0, 0);

Node *ans;

int node_sign = 0;

int calculate_bound(int level, int value, int weight, int n, int c)
{
    int w = weight;
    int v = value;
    for (int i = level; i < n; i++)
    {
        if (w + things[i].weight <= c)
        {
            w += things[i].weight;
            v += things[i].value;
        }
        else
        {
            v += (c - w) * things[i].value_per_weight;
            break;
        }
    }
    return v;
}

void packet(int c, int n)
{
    sort(things, things + n);
    int w = 0;
    int v = 0;
    int level = 0;
    int bound = 0;
    bound = calculate_bound(0, 0, 0, n, c);
    Node init_node(0, 0, 0, bound, 0, -1, 0);
    q.push(init_node);
    ans[node_sign++] = init_node;
    while (!q.empty() && level != n)
    {
        Node temp = q.top();
        q.pop();
        level = temp.level + 1;
        if (temp.bound > best_value && (temp.level != n))
        {
            if (temp.weight + things[temp.level].weight <= c)
            {
                Node temp1(temp.weight + things[temp.level].weight, temp.value + things[temp.level].value, level, temp.bound, node_sign, temp.sign, 1);
                q.push(temp1);
                if (temp1.value > best_value)
                {
                    best_value = temp1.value;
                    best_thing = temp1;
                }
                ans[node_sign] = temp1;
                node_sign++;
            }
            Node temp2(temp.weight, temp.value, level, calculate_bound(level, temp.value, temp.weight, n, c), node_sign, temp.sign, 0);
            q.push(temp2);
            ans[node_sign] = temp2;
            node_sign++;
        }
    }
}

int main()
{
    ifstream examples("D:/VS Code C++ works/AlgorithmHomeworks/Exp4/examples.txt");
    ofstream in("D:/VS Code C++ works/AlgorithmHomeworks/Exp4/Q1ans.txt", ios::trunc);
    if (!examples.is_open())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    int groups;
    int thing_num;
    examples >> groups;
    int groupslen = groups;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    double time;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); // 采用QueryPerformanceFrequency进行精确计时

    while (groups--)
    {
        while (!q.empty())
        {
            q.pop();
        }
        examples >> thing_num;
        things = new thing[thing_num];
        ans = new Node[thing_num * thing_num];
        int c;
        examples >> c;
        int init_weight;
        int init_value;
        for (int i = 0; i < thing_num; i++)
        {
            examples >> init_weight >> init_value;
            thing temp;
            temp.sign = i;
            temp.weight = init_weight;
            temp.value = init_value;
            temp.value_per_weight = (double)init_value / (double)init_weight;
            things[i] = temp;
        } // 读取测试用例文件

        packet(c, thing_num);

        in << "Group " << groupslen - groups << " max_value = " << best_value << endl;

        in << "answer :";

        Node now_thing = best_thing;
        while (true)
        {
            if (now_thing.choose == 1)
                in << things[now_thing.level].sign << " ";
            if (now_thing.parent == -1)
                break;
            now_thing = ans[now_thing.parent];
        }
        in << endl;
        delete[] ans;
        delete[] things;
    }

    QueryPerformanceCounter(&nEndTime);
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
    printf("%d groups, time cost: %f\n", groupslen, time);

    examples.close();
    system("pause");
    return 0;
}

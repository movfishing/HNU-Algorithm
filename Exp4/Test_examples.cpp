#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void menu()
{
    printf("[1]0-1背包问题\n");
    printf("[2]TSP问题\n");
    printf("[3]无和集问题\n");
    printf("[4]工作分配问题\n");
}

int main()
{
    ofstream out("D:/VS Code C++ works/AlgorithmHomeworks/Exp4/examples.txt", ios::trunc);
    if (!out.is_open())
    {
        printf("文件打开失败,请检查后重试\n");
        exit(1);
    }
    menu();
    int n;
    int x;
    int y;
    int temp;
    cin >> n;
    int arrlen = 500; // 题1的节点个数
    int num = 10;     // 测试用例组数
    clock_t start_time = clock();
    switch (n)
    {
    case 1:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            int things = 10;
            out << things << endl;
            int c = rand();
            out << c << endl;
            int w, v;
            for (int i = 0; i < things; i++)
            {
                w = rand() % 10000;
                v = rand() % 10000;
                out << w << " " << v << endl;
            }
        }
        printf("操作成功！\n");
        break;
    case 2:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            out << arrlen << endl;
            out << (rand() % arrlen) << endl;
            int **arr = new int *[arrlen];
            for (int i = 0; i < arrlen; i++)
            {
                arr[i] = new int[arrlen];
            }
            for (int i = 0; i < arrlen; i++)
            {
                arr[i][i] = 0;
                for (int j = 0; j < i; j++)
                {
                    arr[i][j] = (rand() % 20) + 1;
                }
            }
            for (int j = 0; j < arrlen; j++)
            {
                for (int i = 0; i < j; i++)
                {
                    arr[i][j] = arr[j][i];
                }
            }
            for (int i = 0; i < arrlen; i++)
            {
                for (int j = 0; j < arrlen; j++)
                {
                    out << arr[i][j] << " ";
                }
                out << endl;
            }
            for (int i = 0; i < arrlen; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
        }
        printf("操作成功！\n");
        break;
    case 3:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            int k = rand() % 1000 + 1;
            out << k << endl;
        }
        printf("操作成功！\n");
        break;
    case 4:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            int len = rand() % 1000 + 1;
            out << len << endl;
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < len; j++)
                {
                    out << rand() % 15 + 1 << " ";
                }
                out << endl;
            }
            out << endl;
        }
        printf("操作成功！\n");
        break;
    default:
        printf("闰土都没你会找茬\n");
        break;
    }
    out.close();
    system("pause");
    return 0;
}
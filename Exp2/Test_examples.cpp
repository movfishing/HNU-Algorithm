#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void menu()
{
    printf("[1]��Ԫ���·������\n");
    printf("[2]0-1��������\n");
    printf("[3]�ַ���������\n");
    printf("[4]�������������������\n");
}

string Q3()
{
    string s;
    int len = 100;
    char ch = 'a';
    while (len--)
    {
        int offset = rand() % 26;
        s += (ch + offset);
    }
    return s;
}

int main()
{
    ofstream out("D:/VS Code C++ works/AlgorithmHomeworks/Exp2/examples.txt", ios::trunc);
    if (!out.is_open())
    {
        printf("�ļ���ʧ��,���������\n");
        exit(1);
    }
    menu();
    int n;
    int x;
    int y;
    int temp;
    int arrlen = 500; // ��1�Ľڵ����
    cin >> n;
    int num = 1000; //������������
    clock_t start_time = clock();
    switch (n)
    {
    case 1:
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
                    int seed = rand() % 10;
                    if (seed > 6)
                        arr[i][j] = -1;
                    else
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
                out << i;
                for (int j = 0; j < arrlen; j++)
                {
                    out << " " << arr[i][j];
                }
                out << endl;
            }
            for (int i = 0; i < arrlen; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
        }
        printf("�����ɹ���\n");
        break;
    case 2:
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
        printf("�����ɹ���\n");
        break;
    case 3:
        out << num << endl;
        srand(unsigned(time(0)));
        while (num--)
        {
            out << Q3() << endl;
            out << Q3() << endl;
            int k = rand() % 100;
            out << k << endl;
        }
        printf("�����ɹ���\n");
        break;
    case 4:
        srand(time(nullptr));
        out << num << endl;
        while (num--)
        {
            int length = 1000;
            out << length << endl;
            for (int i = 0; i < length; i++)
            {
                int a = (rand() << 15) + rand();
                out << a << endl;
            }
        }
        printf("�����ɹ���\n");
        break;
    default:
        printf("������û����Ҳ�\n");
        break;
    }
    out.close();
    system("pause");
    return 0;
}
#include <iostream>
using namespace std;
#define N 1005
int Asd[N][N];
int Value[N];
int Vol[N];
int W[N];

int main()
{
    int n, Volume, Weight;
    cin >> n >> Volume >> Weight;
    for (int i = 1; i <= n; i++)
        cin >> Vol[i] >> W[i] >> Value[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = Volume; j >= Vol[i]; j--)
        {
            for (int k = Weight; k >= W[i]; k--)
                Asd[j][k] = max(Asd[j][k], Asd[j - Vol[i]][k - W[i]] + Value[i]);
        }
    }
    cout << Asd[Volume][Weight] << endl;
    return 0;
}
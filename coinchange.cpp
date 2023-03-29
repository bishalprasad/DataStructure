#include <iostream>

using namespace std;

int coinchange(int coin[],int sum,int n)
{
    int t[n+1][sum+1];
    int i,j;
    for(int i=0;i<=n;i++)
        t[i][0] =1;
    for(int i =1;i<=sum;i++)
        t[0][i] = 0;
    for(i = 1; i<=n;i++)
    {
        for(j = 1;j<=sum;j++)
        {
            if(coin[i-1]<= j)
                t[i][j] = t[i-1][j] + t[i][j-coin[i-1]];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];

}

int main()
{
    cout << "Hello world!" << endl;

    int coins[] = { 1, 2, 3 };
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 4;
    cout << coinchange(coins, sum, n);
    return 0;
}

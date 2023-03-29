#include <iostream>

using namespace std;

int maxprofit(int price[],int len[],int sum,int n)
{
    int i,j;
    int t[n+1][sum+1];
    for(int i = 0; i<=n;i++)
    {
        for(int j = 0; j<=sum;j++)
        {
            if(i == 0 || j == 0)
                t[i][j] = 0;
            else if(len[i-1]<=j)
            {
                t[i][j] = max(price[i-1]+
                              t[i][j-len[i-1]],
                              t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    cout << "Hello world!" << endl;

    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int Max_len = n;

    // Function Call
    cout << "Maximum obtained value  is "
         << maxprofit(price, length, Max_len,n) << endl;
    return 0;
}

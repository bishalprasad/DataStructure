#include <iostream>

using namespace std;

int unboundedKnapsack(int val[], int wt[],int W, int n)
{

    int t[n+1][W+1];
    int i,j;
    for(int i =0;i<=n;i++)
    {
        for(j = 0;j <=W;j++ )
        {
            if(i == 0|| j == 0)
                t[i][j] = 0;
            else if(wt[i-1]<=j)
            {
                t[i][j] = max(val[i-1]+
                              t[i][j-wt[i-1]],
                              t[i-1][j]);

            }
            else
                t[i][j] = t[i-1][j];

        }
    }
    return t[n][W];

}

int main()
{
    cout << "Hello world!" << endl;
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);

    cout << unboundedKnapsack(val, wt,W, n);
    return 0;
}

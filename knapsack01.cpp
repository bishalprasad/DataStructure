#include <iostream>
#include <vector>

using namespace std;

int knapsack(int val[],int wt[],int W,int n)
{
    if(W ==0 || n == 0)
        return 0;
    if(wt[n-1]<= W)
        return max(val[n-1] + knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1));
    else
        return knapsack(val,wt,W,n-1);
}

int knapsack1(int val[], int wt[],int W, int n )
{
    int i,j;
    int t[n+1][W+1];
    for( i = 0 ; i<=n ; i++){
        for( j = 0 ; j <= W ; j++)
        {
            if(i == 0 || j==0)
              t[i][j] = 0;
            else if(wt[i-1]<= j)
              t[i][j] = max(val[i-1] +
                            t[i-1][j-wt[i-1]],
                            t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }

    return t[n][W];




}

int main()
{


    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapsack( profit,weight, W, n);
    //return 0;
    cout << "Hello world!" << endl;
    cout << knapsack1( profit,weight, W, n)<<endl;
    return 0;
}

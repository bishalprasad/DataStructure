#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lcsub(char a[],char b[],int m, int n)
{
    int arr[m+1][n+1];
    int result =0;
    for(int i =0;i<=m;i++)
        for(int j=0;j<=n;j++)
    {
        if(i==0||j==0)
            arr[i][j] =0;
        else if(a[i-1] == b[j-1]){
            arr[i][j] = 1+arr[i-1][j-1];
            result = max(result,arr[i][j]);
        }

        else
            arr[i][j]= 0;
    }
    return result;
}

int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of Longest Common Substring is "
         << lcsub(X, Y, m, n);
    return 0;
}

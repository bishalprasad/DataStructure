#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lcs(char s1[],char s2[],int m, int n)
{
    if(m==0 || n == 0)
        return 0;
    else if(s1[m-1]== s2[n-1])
        return 1+lcs(s1,s2,m-1,n-1);
    else
        return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));


}

int lcs1(char s1[],char s2[],int m,int n)
{
    int i,j;
    int t[m+1][n+1];
    for(i = 0;i<=m;i++)
        for(j =0;j<=n;j++)
    {
        if(i==0 || j == 0)
            t[i][j] = 0;
        else if(s1[i-1] == s2[j-1])
            t[i][j] = 1+ t[i-1][j-1];
        else
            t[i][j] = max(t[i-1][j],t[i][j-1]);
    }
    return t[m][n];

}

int longestcommonsubstring(char s1[],char s2[],int m,int n)
{
    int i,j;
    int result=0;
    int t[m+1][n+1];
    for(i = 0;i<=m;i++)
        for(j=0;j<=n;j++)
    {
        if(i ==0 || j == 0)
            t[i][j] = 0;
        else if(s1[i-1] == s2[j-1]){
            t[i][j] = 1+t[i-1][j-1];
            result = max(result, t[i][j]);

        }

        else
            t[i][j] = 0;
    }
    return result;
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);
    cout << "Length of LCS is " << lcs(X, Y, m, n);
    cout << "Hello world!" << endl;
    cout << "Length of LCS is " << lcs1(X, Y, m, n);

    char A[] = "OldSite:GeeksforGeeks.org";
    char B[] = "NewSite:GeeksQuiz.com";

    int c = strlen(A);
    int d = strlen(B);

    cout << "Length of Longest Common Substring is "
         << longestcommonsubstring(A, B, c, d);
    return 0;
}

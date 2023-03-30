#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void minimumindel(char s1[],char s2[],int m,int n)
{
    int i,j;
    int t[m+1][n+1];
    for(int i =0;i<=m;i++)
        for(int j =0;j<=n;j++)
    {
        if(i == 0 || j == 0)
            t[i][j] = 0;
        else if(s1[i-1] == s2[j-1])
        t[i][j] = 1+ t[i-1][j-1];
        else
            t[i][j] = max(t[i-1][j],t[i][j-1]);


    }

    cout<<"deletion is "<< m- t[m][n]<<endl;
    cout <<"insertion is " << n - t[m][n] <<endl;

}

int lps(string s1,int m)
{
    string s2 = string(s1.rbegin(),s1.rend());
    int t[m+1][m+1];
    int i,j;
    for(i =0;i<=m;i++)
        for(j=0;j<=m;j++)
    {
        if(i == 0||j == 0)
            t[i][j] = 0;
        else if(s1[i-1] == s2[j-1])
            t[i][j] = 1+t[i-1][j-1];
        else t[i][j] = max(t[i-1][j],t[i][j-1]);
    }
    return t[m][m];

}

int main()
{
    cout << "Hello world!" << endl;
    char s1[] = "heap";
    char s2[] = "pea";

    int m = strlen(s1);
    int n = strlen(s2);
    minimumindel(s1,s2,m,n);
    string s = "GEEKSFORGEEKS";
    n = s.size();
    cout<<"Lps of s= "<<s<<"is=  "<< lps(s,n);
    return 0;
}

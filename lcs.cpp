#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lcs(char a[],char b[],int i,int j)
{
    if(i == 0 || j == 0)
        return 0;
    if(a[i] == b[j])
        return 1+lcs(a,b,i-1,j-1);
    else
    return max(lcs(a,b,i-1,j),lcs(a,b,i,j-1));
}
int lcs1(char a[],char b[],int i,int j)
{
    int arr[i+1][j+1];
    for(int p=0;p<=i;p++)
        for( int q= 0;q<=j;q++)
    {
        if(p == 0 || q == 0 )
            arr[p][q] = 0;
        else if(a[p-1] == b[q-1])
            arr[p][q] = 1+ arr[p-1][q-1];
        else
            arr[p][q] = max(arr[p-1][q],arr[p][q-1]);
    }

    return arr[i][j];
}
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    cout<<"Length of LCS is "<< lcs( X, Y, m, n )<<endl ;

    cout<<"Length of LCS is "<< lcs1( X, Y, m, n ) ;

    return 0;
}

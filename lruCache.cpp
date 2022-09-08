#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int lcs(string s1,string s2,int m,int n)
{
    if(s1.length()==0 || s2.length()== 0)
        return 0;

    if(s1[i] == s2[j])
        return (1+lcs(s1,s2,m-1,n-1));
    return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));

}

int knapsack(int wt[],int W,int val[],int n)
{
    if(W== 0 || n == 0)
        return 0;
    if(wt[n-1]< W)
        return max(val[n-1]+ knapsack(wt,W-wt[n-1],val,n-1)),
        kanpsack(wt,W,val,n-1));
    else
        return knapsack(wt,W,val,n-1),
}
int unboundedKnapsack(int wt[],int val[],int W,int n)
{
    if(W==0 || n == 0)
        return 0;
    if(wt[n-1]< W)
        return max(val[n-1]+ unboundedKnapsack(wt,val,W-val[n-1],n),unboundedKnapsack(wt,val,W,n-1));
    return unboundedKnapsack(wt,val,W,n-1);


}

class LRUCache{
private:
    list<int> l;
    unordered_map<int ,list<int>::iterator>m;
    int cSize;
public:
    LRUCache(int);
    void refer(int val);
    void display();

};

LRUCache::LRUCache(int n)
{
    cSize = n;
}

void LRUCache::refer(int val)
{
    if(m.find(x) == m.end())
    {
        if(l.size() == cSize)
        {
            int item = l.back();
            l.pop_back();
            m.erase(item);
        }
        else{
            l.erase(m[val]);

        }
        l.push_front(val);
        m.[val]=l.begin();
    }
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

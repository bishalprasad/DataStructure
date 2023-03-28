 #include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class lruCache{
private:
    int maxsize;
    list<int> dq;;
    unordered_map<int,list<int>::iterator> ma;
public:
    lruCache(int);
    void refer(int);
    void display();


};

lruCache::lruCache(int data){
maxsize = data;
}

void lruCache::refer(int x)
{
    if(ma.find(x) == ma.end())  //not prsent in the cache
    {
        if(dq.size() == maxsize)
        {
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }

    }
    else  //present in the cache
        dq.erase(ma[x]);

        dq.push_front(x);
        ma[x]=dq.begin();

}

void lruCache::display()
{

    for(auto it = dq.begin();it != dq.end();it++)
    {
        cout<< *it<<"  ";

    }
    cout<<endl;
}

int main()
{
    lruCache la(4);
    la.refer(1);
    la.refer(2);
    la.refer(3);
    la.refer(4);
    la.refer(5);
    la.display();

    cout << "Hello world!" << endl;
    return 0;
}

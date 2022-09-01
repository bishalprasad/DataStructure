#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    node(){left = nullptr;right = nullptr;data =0;}
    }NODE;
NODE * createNode(int data)
{
    NODE * n = new NODE;
    n->data = data;
    return n;


}
void printvector(vector<int >s)
{
    for(auto i:s)
        cout<<i<<" -> ";
    cout<<"NULL"<<endl;
}

void preorder(NODE * root)
{
    if(root == nullptr)
        return;
    cout<<root->data << "   ";
    preorder(root->left);
    preorder(root->right);

}
void inorder(NODE * root)
{
    if(root == nullptr)
        return;

    inorder(root->left);
    cout<<root->data << "   ";
    inorder(root->right);

}

void postorder(NODE * root)
{
    if(root == nullptr)
        return;

    postorder(root->left);

    postorder(root->right);
    cout<<root->data << "   ";

}

int height(NODE *root)
{
    if(root == nullptr)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight,rheight)+1;

}

void printPath(NODE *root,vector<int> v)
{
    if(root== nullptr)
        return;
    v.push_back(root->data);
    if(!root->left && !root->right)
    {
        printvector(v);
        v.erase(v.end()-1);
    }

    printPath(root->left,v);
    printPath(root->right,v);


}
int ans;
int diameter(NODE *root)
{
    if(root == nullptr)
        return 0;
    int ldiameter = diameter(root->left);
    int rdiamater = diameter(root->right);
    int lheight = height(root->left);
    int rheight = height(root->right);
    int ans = lheight+rheight+1;
    return max(ans,max(ldiameter,rdiamater));

}

void levelorder(NODE *root )
{
    queue<NODE *> q;
    q.push(root);
    while(!q.empty())
    {
        NODE *tmp = q.front();
        q.pop();
        cout<<tmp->data << "   ";
        if(tmp->left != nullptr)
            q.push(tmp->left);
        if(tmp->right !=nullptr)
            q.push(tmp->right);

    }

}

void spiraltraversal(NODE *root)
{
    stack<NODE *>q1;
    stack<NODE *>q2;
    q1.push(root);
    while(!q1.empty()|| !q2.empty())
    {
        while(!q1.empty())
        {
            NODE * tmp = q1.top();
            q1.pop();
            if(tmp->left)q2.push(tmp->left);
            if(tmp->right)q2.push(tmp->right);
            cout<< tmp->data<<" ";


        }
        cout<<endl;
        while(!q2.empty())
        {
            NODE * tmp = q2.top();
            q2.pop();
            if(tmp->right)q1.push(tmp->right);
            if(tmp->left)q1.push(tmp->left);
            cout<< tmp->data<<" ";
        }
        cout<<endl;

    }

}


NODE * lca(NODE *root,int n1,int n2)
{
    if(root == nullptr)
        return nullptr;
    if(root->data == n1|| root->data == n2)
        return root;
  NODE *tmpleft=  lca(root->left,n1,n2);
  NODE *tmpright=lca(root->right,n1,n2);

    if(tmpleft&& tmpright)
        return root;

        return tmpleft !=nullptr ?tmpleft:tmpright;


}
void bottomView(NODE * root)
{
        if(root == nullptr)
        return;
    map<int, int >m;
    queue<pair<NODE *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<NODE*,int> tmp = q.front();
        q.pop();
        //m[tmp.second] = tmp.first->data;
        m.insert({tmp.second,tmp.first->data});
        if(tmp.first->left)
        {
            q.push({tmp.first->left,tmp.second-1});

        }

        if(tmp.first->right)
        {
            q.push({tmp.first->right,tmp.second +1});

        }



    }
    for (auto i = m.begin(); i != m.end(); i++)
        cout<< i->first<< "  ->    "<< "      " << i->second<<endl;
         cout<< endl;

}

void topView(NODE *root)
{
    if(root == nullptr)
        return;
    map<int, int >m;
    queue<pair<NODE *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<NODE*,int> tmp = q.front();
        q.pop();
        if(m.find(tmp.second) == m.end())
                m.insert({tmp.second,tmp.first->data});
        if(tmp.first->left)
        {
            q.push({tmp.first->left,tmp.second-1});

        }

        if(tmp.first->right)
        {
            q.push({tmp.first->right,tmp.second +1});

        }



    }
    for (auto i = m.begin(); i != m.end(); i++)
        cout << i->second <<"  ";
         cout<< endl;


}

void leftView(NODE *root)
{
    if (root == nullptr)
        return;

    queue<NODE *>q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 1;i<=n;i++)
        {
            NODE * tmp = q.front();
            q.pop();
            if(i ==1)
                cout<<tmp->data<<"  "<<endl;
            if(tmp->left != nullptr) q.push(tmp->left);
            if(tmp->right != nullptr) q.push(tmp->right);
        }


    }
}




void  rightView(NODE *root)
{
    if (root == nullptr)
        return;

    queue<NODE *>q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 1;i<=n;i++)
        {
            NODE * tmp = q.front();
            q.pop();
            if(i ==n)
                cout<<tmp->data<<"  "<<endl;
            if(tmp->left != nullptr) q.push(tmp->left);
            if(tmp->right != nullptr) q.push(tmp->right);
        }


    }

}

void verticalOrderTraversal(NODE *root)
{
            if(root == nullptr)
        return;
    map<int, vector<int> >m;
    queue<pair<NODE *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<NODE*,int> tmp = q.front();
        q.pop();
        m[tmp.second].push_back(tmp.first->data);
        //m.insert({tmp.second,tmp.first->data});
        if(tmp.first->left)
        {
            q.push({tmp.first->left,tmp.second-1});

        }

        if(tmp.first->right)
        {
            q.push({tmp.first->right,tmp.second +1});

        }



    }
    for (auto i = m.begin(); i != m.end(); i++)
        for(auto v = i->second.begin();v != i->second.end();v++)
        cout<< i->first<< "  ->    "<< "      " << *v<<endl;
         cout<< endl;

}

void mirrorTree(NODE * root)
{
    if(root== nullptr)
        return;

    if(root->left|| root->right)
    {
        NODE *tmp = root->left;
        root->left=root->right;
        root->right=tmp;
    }
    mirrorTree(root->left);
    mirrorTree(root->right);

}

bool isSumTree(NODE * root)
{
    if(root == nullptr)
        return true;
   if(!isSumTree(root->left))
    return false;
   if(!isSumTree(root->right))
    return false;

   if(root->left == nullptr && root->right == nullptr)
    return true;
   cout<<"root->data" <<root->data<< "  ";
   if(root->left)
    cout<<"root->left->data" <<root->left->data <<"  ";
   if(root->right)
    cout<<"root->right->data"<< root->right->data<<"  "<<endl;
   cout<<endl;
   return (root->data == (((root->left? root->left->data:0) +( root->right?root->right->data:0)))?true:false);

}

int largestUniquePath(NODE* root)
{

}






int main()
{

    NODE *root =createNode(100);
    root->left =createNode(200);
    root->left->left =createNode(700);
    root->right =createNode(300);
    root->right->right =createNode(400);
    root->right->left =createNode(450);
    root->right->right->left =createNode(500);
    root->left->right =createNode(600);
    root->right->right->right =createNode(800);
    root->right->right->right->left =createNode(900);

   /* preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"height="<<height(root)<<endl;
    cout<<"diameter of tree is "<<diameter(root)<<endl;
    cout<<"Root to leaf path:"<<endl;
    vector<int> v;
    printPath(root,v);
    cout<<"Level order traversal"<<endl;
    levelorder(root);*/

  //  cout<<"\nspiraltraversal"<<endl;
 //   spiraltraversal1(root);
   // NODE * ans = lca(root,900,900);
   // cout<<"LCA of(900 and 700)  "<<ans->data;
    cout<<"Left view of tree is :\n";
    leftView(root);

    cout<<"Right view of tree is :\n";
    rightView(root);

    cout<<"topView() of binary tree is :"<<endl;
    topView(root);

    cout<<"bottomView() of binary tree is :"<<endl;
    bottomView(root);

    cout<<"Vertical ordertraversal:"<<endl;
    verticalOrderTraversal(root);
    cout<<"preorder before mirror"<<endl;
    preorder(root);
   /* cout<<endl;
    mirrorTree(root);
    cout<<"preorder after mirror"<<endl;
    preorder(root);*/

    NODE *root1 =createNode(1000);
    root1->left=createNode(300);
    root1->right=createNode(700);
    root1->left->left=createNode(100);
    root1->left->right=createNode(200);
    root1->right->left=createNode(300);
    root1->right->right=createNode(400);

    if(isSumTree(root1))
       {
           cout<<"The tree is a sum tree"<<endl;
       }
       else
        cout<<"tree is not a sum tree"<<endl;



    return 0;
}

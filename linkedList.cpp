#include <iostream>

using namespace std;


class Node{
    public:
int data;
class Node* next;

    node()
    {
        data = 0;
        next= nullptr;
    }
    Node(int i)
    {
        this->data = i;
        this->next = nullptr;
    }
};



class List{
 Node *head;

 public:
     List()
     {
         head =nullptr;
     }
     void insertNode(int val);
     void deleteNode();
     void *find_loop() ;
     void printList();
     Node* reverseNplace(int n,Node *head);
     void reversen(int n);
     void reverseList();
     void middleElement();
     void nthNodeFromEnd(int n);
     void rotateLinkedList(int n);
     void deleteLastoccouranceItem(int n);
     void deleteMiddleElement();
     void createLoop(int n);
     void detectLoop();
     void deleteloop();

};

void List::insertNode(int val)
{
    Node* newNode =new Node(val);
    if(head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = newNode;;

}

void List::printList()
{
    if(head == nullptr)
        cout<< "List is empty"<<endl;
    Node *tmp = head;
    while(tmp)
    {
        cout<<tmp->data<<" ->";
        tmp =tmp->next;
    }
    cout<<"NULL"<<endl;
}

Node * List::reverseNplace(int n,Node *head)
{
    if(head == nullptr)
        return head;

    Node *curr = head;
    Node *previous=nullptr;
    Node *next=nullptr;
    int i=0;

    while(curr != nullptr && i<n)
    {
        i++;
        next= curr->next;
        curr->next= previous;
        previous =curr;
        curr= next;


    }
    if(next != nullptr)
        head->next = reverseNplace(n,next);
    return  previous;


}
void List::reversen(int n)
{
    head = reverseNplace(n,head);
}
void List::reverseList()
{
    if(head == nullptr)
        return;
    Node *curr = head;
    Node *prev= nullptr;
    Node *next = nullptr;
    while(curr)
    {
        next = curr->next;
        curr->next =prev;
        prev = curr;
        curr = next;


    }
    head = prev;
}

void List::middleElement()
{

    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node *fast = head;
    Node *slow = head;
    while(fast!= nullptr && fast->next != nullptr)
    {
            fast = fast->next->next;
            slow = slow->next;
    }
    cout<<"Middle Element of the list is: "<<slow->data<<endl;

}
void List::nthNodeFromEnd(int n)
{
    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;

    }
    Node *temp =head;
    Node *nthnode = head;
    int c =0;

    while(c<n && temp->next != nullptr)
    {
        temp = temp->next;
        c++;
        if(temp == nullptr)
        {
            cout<<"Atleast %d node are not present in the list"<<n<<endl;
            return;
        }
    }

        while(temp)
        {
            temp = temp ->next;
            nthnode = nthnode->next;
        }

        cout<<"nth node of list is:"<<nthnode->data<<endl;

}

void List::rotateLinkedList(int n)
{
    if(head == nullptr)
        return;

    Node* temp = head;
    Node *nthnode = head;
    int i =1;
    while(i<n )
    {
        if(temp->next == nullptr)
        {
            return;
        }
        temp = temp->next;
        i++;
    }

    Node * prev;
    while(temp->next)
    {
        prev=nthnode;
        temp = temp->next;
        nthnode = nthnode->next;
    }
    prev->next =nullptr;
    temp->next = head;
    head = nthnode;



}

void List::deleteMiddleElement()
{
    if(head == nullptr)
        return;
    Node *fast =head;
    Node *slow = head;
    Node *prev = head;
    while( fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next= slow->next;
    delete slow;
}

void List::createLoop(int n)
{
    if(head == nullptr)
        return;

    Node* temp = head;
    Node *nthnode = head;
    int i =1;
    while(i<n )
    {
        if(temp->next == nullptr)
        {
            return;
        }
        temp = temp->next;
        i++;
    }

    Node * prev;
    while(temp->next)
    {
        prev=nthnode;
        temp = temp->next;
        nthnode = nthnode->next;
    }

    temp->next = nthnode;



}

void List::detectLoop()
{
    if(head == nullptr)
        return;
    Node *fast;
    Node *slow;
    while(fast != nullptr && fast->next != nullptr)
    {

        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            cout<< "Loop is there node"<< endl;
            break;
        }
            
    }
    cout<< "Loop is not present"<< endl;

}

int main()
{
    List l ;
    l.insertNode(10);
    l.insertNode(20);
    l.insertNode(30);
    l.insertNode(40);
    l.insertNode(50);
    l.insertNode(60);
    l.insertNode(70);
    l.insertNode(80);
    l.insertNode(90);
    l.insertNode(100);
    l.insertNode(110);
    l.printList();
    l.reversen(3);
    l.printList();
    l.reverseList();
    l.printList();
    l.middleElement();
    l.nthNodeFromEnd( 2);
    l.rotateLinkedList(3);
    l.printList();
    l.deleteMiddleElement();
    l.printList();
    l.createLoop(3);
    //l.printList();
    l.detectLoop();

    cout << "Hello world!" << endl;
    return 0;
}

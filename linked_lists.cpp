#include <iostream>
#include <cstdlib>
 using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next= NULL;
    }
    void printInfo()
    {
        cout<<"value in the node is "<<data<<endl;
    }
};
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}
int length(node* &head)
{
    int i=1;
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    return i;
}
void InsertAtTail(node* &head, int val)
{
    //cout<<"head is"<<head<<endl;
    node* n=new node(val);
    //cout<<"head is "<<head<<endl;
    if(head==NULL)
    {
        //cout<<"sania1"<<endl;
        head=n;
    }
    // cout<<"head is"<<head<<endl;
    else
    {
        node* temp =head;
        //cout<<"temp is"<<temp->next<<endl;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
void inserAtHead(node* &head,int val)
{
    node* n =new node(val);
    n->next=head;
    head=n;
}
bool search(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    delete todelete;
}
void deletion(int key, node* &head)
{
    node* temp=head;
    if(temp==NULL)
    {
        return;
    }

    if(temp->data==key)
    {
        deleteAtHead(head);
        return;
    }
    while(temp!=NULL)
    {
        if((temp->next)->data==key)
        {
            node* todelete=temp->next;
            temp->next=temp->next->next;
            delete todelete;
            break;
        }
        temp=temp->next;
    }

}
node* reverse_linked_list(node* &head)
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;        
    }
    return prevptr;
}
node* reverse__knodes(int k, node* &head)

{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int i =0;
    while(i<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        i++;          
    }
    if(nextptr!=NULL && currptr!=NULL )
    {
        head->next=reverse__knodes(k,nextptr);
    }
    return prevptr;
}
node* reverse_linked_list_recurrsive(node* &head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node* newhead=reverse_linked_list_recurrsive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
//Floyd's Algorithm
//Hare and Tortoise Algorithm
//Detect Cycle in a linked list
bool detectCycle(node* &head)
{
    node* turtle=head;
    node* hare=head;
    while(hare!=NULL && hare->next!=NULL)
    {
        turtle=turtle->next;
        hare=hare->next->next;
        if(turtle==hare)
        {
            cout<<"Loop Detected"<<endl;
            return true;
        }
    }
    cout<<"loop not detected"<<endl;
    return false;
}
void makeCycle(node* head, int pos)
{
    int i=0;
    node* temp=head;
    node* cycleStartNode;
    while(temp->next!=NULL)
    {
        if(i==pos)
        {
            cycleStartNode=temp;
        }
        temp=temp->next;
        i++;

    }
    temp->next=cycleStartNode;
}
void removeCycle(node* &head)
{
    node* turtle=head;
    node* hare=head;
    do
    {
        turtle=turtle->next;
        hare=hare->next->next;
    } while(turtle!=hare);
    hare=head;
    while(turtle->next!=hare->next)
    {
        turtle=turtle->next;
        hare=hare->next;
    }
    turtle->next=NULL;
    
}
//append last k nodes to the beginning
node* appendK(node* &head, int k)
{
    int l=length(head);
    node* temp=head;
    node* newhead;
    node* newtail;
    if(k==1)
    {
        cout<<"sania"<<endl;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        newhead=temp->next;
        newhead->next=head;
        temp->next=NULL;
    }
    else
    {
        int i=0;
        cout<<(temp->next!=NULL)<<endl;
        while(temp->next!=NULL)
        {
            if(i==(l-k))
            {
                newtail=temp;
            }
            if(i==(l-k+1))
            {
                newhead=temp;
                
            }
            temp=temp->next;
            i++;
        }
        newtail->next=NULL;   
        temp->next=head;       
    }
    cout<<"newheadtemp is"<<newhead->data<<endl;
    return newhead;
}
//find intersection point of two linked list
int findIntersection(node* &head1,node* &head2)
{
    int l1=length(head1);
    int l2=length(head2);
    if(l1<l2)
    {
        node* exchange_temp;
        exchange_temp=head1;
        head1=head2;
        head2=exchange_temp;
    }
    cout<<"heads are"<<head1->data<<", "<<head2->data<<endl;
    cout<<"lengths are"<<l1<<", "<<l2<<endl;
    node* ptr1;
    node*ptr2;
    int i =1;
    node* temp=head1;
    while(temp->next!=NULL && i<abs(l1-l2))
    {
        temp=temp->next;
        i++;
    }
    ptr2=head2;
    ptr1=temp->next;
    cout<<"starting heads are"<<ptr1->data<<", "<<ptr2->data<<endl;

    while(ptr1->next!=NULL && ptr2->next!=NULL)
    {
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
//make two linked lists intersect
void intersect(node*h1,node* h2,int pos)    
{
    node* temp1=h1;
    pos--;
    while(pos--)
    {
        temp1=temp1->next;
    }
    node* temp2=h2;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
node* MergeSortedLinkedLists(node* &h1,node* &h2)
{
    node* dummy_node=new node(-1);
    node* ptr1=h1;
    node* ptr2=h2;
    node* ptr3=dummy_node;
    while(ptr1->next!=NULL && ptr2->next!=NULL)
    {
        if(ptr1->data<ptr2->data)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else
        {
           ptr3->next=ptr2;
           ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    while(ptr1->next!=NULL)
    {
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2->next!=NULL)
    {
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return dummy_node->next;
}

int main()
{
    //node* n;
    // n.printInfo();
    node* head=NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    inserAtHead(head,4);
    display(head);
    cout<<search(head,5)<<endl;
    node* newhead=reverse_linked_list(head);
    display(newhead);
    node* newhead_recurr=reverse_linked_list(newhead);
    display(newhead_recurr);
    int array[]={5,6,7,8,9,10,11,12};
    for(int i=0;i<8;i++)
    {
        InsertAtTail(head,array[i]);
    }
    //deletion(4,head);
    display(head);
    // node* newknodes_reverse=reverse__knodes(3,head);
    // display(newknodes_reverse);
    // makeCycle(head,4);
    // detectCycle(head);
    // removeCycle(head);
    // detectCycle(head);
    cout<<length(head)<<endl;
    node* head1=NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++)
    {
        InsertAtTail(head1,arr[i]);
    }
    int arr1[]={7,8,9};
    node* head2=NULL;
    for(int i=0;i<3;i++)
    {
        InsertAtTail(head2,arr1[i]);
    }    
    display(head1);
    display(head2);
    // node* newhead1=appendK(head1,5);
    // display(newhead1);
    // intersect(head,head1,4);
    // display(head1);
    // display(head);
    // cout<<findIntersection(head,head1);
    display(MergeSortedLinkedLists(head2,head1));


}
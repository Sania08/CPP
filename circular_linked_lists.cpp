#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    //constructor
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void InsertAtHead(node* &head,int val)
{
   node* n = new node(val);
   if (head==NULL)
   {
    n->next=n;
    head=n;
    return;
   }
   node* temp  = head;
   while(temp->next!=head)
   {
    temp=temp->next;
   }
   temp->next=n;
   n->next=head;
   head=n;

}
// Insert at tail in a circular linked list
void InsertAtTail(node* &head,int val)
{
    node*n= new node(val);
   if (head==NULL)
   {
        n->next=n;
        head=n;
        return;
   }
    node* temp=head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void display(node* &head)
{
    node* temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<"->"<<temp->next->data<<endl;;
}
node* deleteAtHead(node* &head)
{
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    node* todelete=head;
    temp->next=head->next;
    // cout<<"values of head and next of head "<<temp->data<<", "<<head->data<<", "<<temp->next->data;
    delete todelete;
    // display(temp->next);
    return temp->next;
}
node* deletion(node* &head, int pos)
{
    node* todelete;
    node* newhead;
    if(pos==1)
    {
        cout<<"sania"<<endl;
        newhead=deleteAtHead(head);
        return newhead;
    }
    else
    {
        node* temp=head;
        int count=1;
        while(temp->next!=NULL && count<pos-1)
        {
            temp=temp->next;
            count++;
        }
        todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
        return head;
    }
}
int main()
{
    node* head1=NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++)
    {
        InsertAtTail(head1,arr[i]);
    }
    display(head1);
    node* newhead=deletion(head1,6);
    display(newhead);
}
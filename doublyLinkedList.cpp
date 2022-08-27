#include <iostream>

using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;

    //constructor
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void display(node* head)
{
        node* temp=head;
        cout<<"NULL->";
        while(temp!=NULL)
        {
            cout<<temp->data<<"<->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;

}
void InsertAtHead(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
    }
    else
    {
        n->next=head;
        head->prev=n;
        head=n;
    }

}
void InsertAtTail(node* &head, int val)
{
    if(head==NULL)
    {
        InsertAtHead(head,val);
        display(head);
        return;
    }
    else
    {
        node* temp=head;
        node* n=new node(val);

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }
}
void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}
void deletion(node* &head, int pos)
{
    if(pos==1)
    {
        deleteAtHead(head);
    }
    else
    {
        node* temp=head;
        int i=1;
        while(temp!=NULL && i!=pos)
        {
            temp=temp->next;
            i++;
        }
        node* todelete=temp;
        temp->prev->next=temp->next;
        if(temp->next!=NULL)
        {
            temp->next->prev=temp->prev;
        }
        
        delete todelete;      
    }

}

int main()
{
    node* head=NULL;
    InsertAtHead(head,1);
    InsertAtHead(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    display(head);
    deletion(head,1);
    display(head);
}

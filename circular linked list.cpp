#include<iostream>
using namespace std;

 class linkedlist
    {
       struct node
         {
           float data;
           node *ptr;
         }*head,*temp,*temp1,*last;
	public:
           linkedlist()
               {
                   last=NULL;
               }

void insert_in_end()
{
        struct node* head=new node;
        cout<<"\nEnter data to be entered in the list ";
        cin>>head->data;
        head->ptr=NULL;
        if(last==NULL)
        {
            head->ptr=head;
            last=head;
        }
        else
        {
            head->ptr=last->ptr;
            last->ptr=head;
            last=head;
        }
}

void insert_in_beg()
{
    struct node* head=new node;
    cout<<"\nEnter data to be inserted ";
    cin>>head->data;
    head->ptr=NULL;
    head->ptr=last->ptr;
    last->ptr=head;
}

void insert_at_pos()
{
    int pos;
	struct node* head=new node;
	cout<<"\nEnter data to be inserted ";
    cin>>head->data;
	head->ptr=NULL;
	cout<<"\nInsert position (1st position is the start)";
	cin>>pos;
	temp=last->ptr;
	for(int i=1;i<pos-1;++i)
    {
        temp=temp->ptr;
    }
	head->ptr=temp->ptr;
	temp->ptr=head;
}

void delete_at_end()
{
    if(last=NULL)
        cout<<"\nlink list is empty ";
    else
    {
        temp=last->ptr;
        temp1=last;
        while(temp->ptr!=last)
        {
            temp=temp->ptr;
        }
        temp->ptr=last->ptr;
        last=temp;
        delete temp1;
    }
}

void delete_at_beg()
{
    if(last=NULL)
        cout<<"\nlink list is empty ";
    else
    {
    temp=last->ptr;
    last->ptr=temp->ptr;
    delete temp;
    }

}
void delete_at_pos()
{
    if(last=NULL)
    {
        cout<<"\nlinked list is empty";
    }
    int pos;
    cout<<"\nEnter the position";
    cin>>pos;
    if(pos==1)
    {
        delete_at_beg();
    }
    else
    {
        temp=last->ptr;
        temp1=last->ptr;
        for(int i=1;i<(pos-1);++i)
        {
            temp=temp->ptr;
        }
        temp1=temp->ptr;
        temp->ptr=temp1->ptr;
        delete temp1;
    }
}
void display()
    {
        cout<<"The list is as follows : ";
        temp=last->ptr;
        while(temp->ptr!=last->ptr)
        {
         cout<<temp->data<<" ";
         temp=temp->ptr;
        }
        cout<<last->data;
    }
};



    int main()
    {
        linkedlist obj;
        char chh;
        int n;
do
        {
            cout<<"\n1.Insert Element at end";
            cout<<"\n2.Insert Element at begining";
            cout<<"\n3.Insert at position";
            cout<<"\n4.Delete from End";
            cout<<"\n5.Delete from begining";
            cout<<"\n6.Delete from position";
            cout<<"\n7..Display linked list";
            cout<<"\nEnter Choice ";
            cin>>n;
            switch(n)
	{
		case 1 :
			ob.insert_in_end();
			break;
		case 2 :
			obj.insert_in_beg();
			break;
		case 3 :
			obj.insert_at_pos();
			break;
		case 4 :
			obj.delete_at_end();
                        break;
		case 5 :
			obj.delete_at_beg();
			break;
		case 6 :
			obj.delete_at_pos();
			break;
                case 7 :
                         obj.display();
                         break;
	}
        cout<<"\n Do you want to continue ?? ";
        cin>>chh;
        }while(chh=='y'||chh=='Y');
    return 0;
    }


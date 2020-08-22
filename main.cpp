/* Link list implementation through classes*/

#include<iostream>

using namespace std;

    class linklist
{
    struct node
    {
        float data;
        node *next;
    }*head,*temp,*temp1,*first,*last;

public:
    linklist()
    {
        first=NULL;
        last=NULL;
    }

    ~linklist()
    {
        temp=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            delete first;
            first=temp;
        }
    }
    void INSERT_END()
{
    char ch;
    do
    {
        node* head=new node;
        cout<<"\nEnter your data in the list :";
        cin>>head->data;
        head->next=NULL;
        if(first==NULL)
        {
            first=head;
            last=head;
        }
    else
        {
            last->next=head;
            last=head;
        }
        cout<<"\n Do want to enter more (y/n)??";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}

void INSERT_BEGIN()
{
    struct node* head=new node;
    cout<<"\nEnter data to be inserted: ";
    cin>>head->data;
    head->next=NULL;
    head->next=first;
    first=head;
}

void Insert_at_Pos()
{
    int pos;
    struct node* head=new node;
    cout<<"\nEnter data to be inserted :";
    cin>>head->data;
    head->next=NULL;
    cout<<"\nWhich Position (1 is first position) ? ";
    cin>>pos;
    if(pos<1)
    {
        cout<<"\nInvalid Input Try Again";
    }
    else if(pos==1)
    {
       INSERT_BEGIN();
    }
    else
    {
        temp=first;
    for(int i=1;i<(pos-1);++i)
    {
        temp=temp->next;
    }
    head->next=temp->next;
    temp->next=head;
    }
}
void DEL_BEGIN()
{
    if(first=NULL)
        cout<<"\nlink list is empty :";
    else
    {
        temp=first;
        first=temp->next;
        delete temp;
    }
}
void DEL_END()
{
    if(first=NULL)
        cout<<"\nlink list is empty :";
    else
    {
        temp=first;
        temp1=last;
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        last=temp;
        delete temp1;
    }
}
void DEL_AT_POS()
{
    if(first=NULL)
    {
        cout<<"\nlinked list is empty ";
    }
    int pos;
    cout<<"\nEnter the position :";
    cin>>pos;
    if(pos==1)
    {
        DEL_BEGIN();
    }
    else
    {
        temp=first;
        temp1=first;
        for(int i=1;i<(pos-1);++i)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
    }
}
void REVERSE_LIST()
{
	temp=first;
	head=temp1=NULL;
	while(temp!=NULL)
	{
		temp1=temp->next;
		temp->next=head;
		head=temp;
		temp=temp1;
	}
	last=first;
	first=head;
}
    void Display()
    {
        cout<<"The list is as follows : ";
        temp=first;
        while(temp!=NULL)
        {
         cout<<temp->data<<" ";
         temp=temp->next;
        }
    }
    void SEARCH_LIST()
    {
        int ctr,i=1,flag=0;
        cout<<"\nEnter element to be found ";
        cin>>ctr;
        temp=first;
        while(temp->next!=NULL)
        {
            if(temp->data==ctr)
            {
                cout<<"\nElement found at "<<i<<"position ";
                flag=1;
                break;
            }
            temp=temp->next;
            i++;
        }
         if(flag==0)
            {
                cout<<"\nItem not found ";
            }
    }
};
    int main()
    {

        linklist obj;
        char ch1;
        int n;

        do
        {   cout<<"**MAIN MENU**\n";
            cout<<"\n1.Insert Element at begining";
            cout<<"\n2.Insert Element at end";
            cout<<"\n3.Insert at position";
            cout<<"\n4.Delete from End";
            cout<<"\n5.Delete from begining";
            cout<<"\n6.Delete from position";
            cout<<"\n7.Reverse list";
            cout<<"\n8.Search Element";
            cout<<"\n9.Display linked list";
            cout<<"\nEnter Choice: ";
            cin>>n;
            switch(n)
	{
		case 1 :
			obj.INSERT_BEGIN();
			break;
		case 2 :
			obj.INSERT_END();
			break;
		case 3 :
			obj.Insert_at_Pos();
			break;
		case 4 :
			obj.DEL_END();
		case 5 :
			obj.DEL_BEGIN();
			break;
		case 6 :
			obj.DEL_AT_POS();
			break;
		case 7 :
			obj.REVERSE_LIST();
			obj.Display();
			break;
        case 8 :
            obj.SEARCH_LIST();
            break;
        case 9 :
            obj.Display();
            break;

	}
            cout<<"\nDo want to continue(Y/N)?? ";
            cin>>ch1;
        }while(ch1=='y'||ch1=='Y');
       return 0;
        }


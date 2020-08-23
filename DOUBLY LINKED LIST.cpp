/* doubly linked list using classes*/


#include<iostream.h>
#include<conio.h>
class linklist
{
     struct node
    {
        float info;
        node *next;
        node *prev;
    }*first,*tail,*head, *temp,*temp1;

public:
    linklist ()
    {
        first=NULL;
        tail=NULL;
    }
    ~linklist()
    {
        temp=first;
	while(temp!=NULL)
        {
            temp=temp->next;
            delete first;
            first=temp;
        }
    }
    void INSERT_AT_BEG()
{
    struct node* head=new node;
    cout<<"\nEnter data to be inserted ";
    cin>>head->info;
    head->next=NULL;
    head->prev=NULL;
    head->next=first;
    first->prev=head;
    first=head;
}

     void INSERT_AT_POS()
{
    int pos;
    struct node* head=new node;
    cout<<"\nEnter data to be inserted ";
    cin>>head->info;
    head->next=NULL;
    head->prev=NULL;
    cout<<"\nEnter the position (1 is the first position) ";
    cin>>pos;
    if(pos<1)
    {
        cout<<"\nInvalid Input";
    }
    else if(pos==1)
    {
       INSERT_AT_BEG();
    }
    else
    {
        temp=first;
    for(int i=1;i<(pos-1);++i)
    {
        temp=temp->next;
    }
    head->next=temp->next;
    head->prev=temp;
    temp->next=head;
    }

    void INSERT_AT_END()
   {
        struct node* head=new node;
        cout<<"\nEnter data to be entered in the list ";
        cin>>head->info;
        head->next=NULL;
        head->prev=NULL;
        if(first==NULL)
        {
            first=head;
            tail=head;
        }
    else
        {
            tail->next=head;
            head->prev=last;
            tail=head;
        }
}

void DELETE_BEGIN()
{
    if(first=NULL)
        cout<<" link list is empty ";
    else
    {
        temp=first;
        first=temp->next;
        first->prev=NULL;
        delete temp;
    }
}

void DELETE_POS()
{
    if(first=NULL)
    {
        cout<<"linked list is empty";
    }
    int pos;
    cout<<"Enter the position";
    cin>>pos;
    if(pos==1)
    {
        DELETE_BEGIN();
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
        temp1->next->prev=temp;
        delete temp1;
    }
}

void DELETE_END()
{
    if(first=NULL)
        cout<<"\nlink list is empty ";
    else
    {
        temp=tail->prev;
        tail=temp;
        temp=temp->next;
        tail->next=NULL;
        delete temp;
    }
}

void REVERSE_LIST()
{
    temp=tail;
    while(temp!=NULL)
    {
        cout<<temp->info;
        temp=temp->prev;
    }
}
void display()
    {
        cout<<"Here is your list: "<<endl;
        temp=first;
        while(temp!=NULL)
        {
         cout<<temp->info<<" ";
         temp=temp->next;
        }
    }
 void FIND_IN_LIST()
    {
        int ctr,i=1,flag=0;
        cout<<"Enter element to be found "<<endl;
        cin>>ctr;
        temp=first;
        while(temp!=NULL)
        {
            if(temp->info==ctr)
            {
                cout<<"Element found at "<<i<<" position "<<endl;
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



void  main()
    {
	    clrscr();
	linklist obj;
	char ch;
	int n;
	
	do
	{   cout<<"\n*** MAIN MENU ***";
	    cout<<"1.Insert Element at beginning"<<endl;
	    cout<<"2.Insert Element at a position"<<endl;
	    cout<<"3.Insert at end"<<endl;
	    cout<<"4.Delete from beginning"<<endl;
	    cout<<"5.Delete from a position"<<endl;
	    cout<<"6.Delete from end"<<endl;
	    cout<<"7.Reverse list"<<endl;
	    cout<<"8.Search Element"<<endl;
	    cout<<"9.Display linked list"<<endl;
	    cout<<"Enter Choice"<<endl;
	    cin>>n;
	    switch(n)
	{
		case 1 :
			obj.INSERT_AT_BEG();
			break;
		case 2 :
			obj.INSERT_AT_POS();
			break;
		case 3 :
			obj.INSERT_AT_END();
			break;
		case 4 :
			obj.DELETE_BEGIN();
		case 5 :
			obj.DELETE_POS();
			break;
		case 6 :
			obj.DELETE_END();
			break;
		case 7 :
			obj.REVERSE_LIST();
			obj.display();
			break;
	case 8 :
	    obj.FIND_IN_LIST();
	    break;
	case 9 :
	    obj.display();
	    break;
	}
	    cout<<" Do want to continue?"<<endl;
	    cin>>ch;
	     }
	     while(ch=='y'||ch=='Y');
       getch();
       }



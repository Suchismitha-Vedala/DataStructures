#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class sl
{
	private:
		struct node
		{
			node *next;
			int data;
		}*header;
	public:
	    sl();
		void create(int);
		void addbeg(int);
		void addend(int);
		void addafter(int,int);
		void count();
		void display();
		void deletebeg();
		void deleteend();
		void deleteafter(int);
			
};
sl::sl()
{
	header=NULL;
}
void sl::create(int num)
{
	node *temp,*r;
	if(header==NULL)
	{
		temp=new node;
		temp->data=num;
		temp->next=NULL;
		header=temp;
	}
	else
	{
		temp=header;
		while(temp->next!=NULL)
		temp=temp->next;
		r=new node;
		r->data=num;
		r->next=NULL;
		temp->next=r;
	}
}
void sl::addbeg(int num)
{
	node *temp;
	temp=new node;
	temp->data=num;
	temp->next=header;
	header=temp;
}
void sl::addend(int num)
{
    node *p,*temp;
	p=header;
	while(p->next!=NULL)
	p=p->next;
	temp=new node;
	temp->data=num;
	temp->next=NULL;
    p->next=temp;
}
void sl::addafter(int pos,int num)
{
	node *temp,*r;
	temp=header;
	for(int i=0;i<pos-1;i++)
	{ 
	  temp=temp->next;
	  if(temp==NULL)
	  { 
	    cout<<endl<<"there are less than "<<pos<<"nodes";
	  }
	}
	r=new node;
	r->data=num;
	r->next=temp->next;
	temp->next=r;
	
}
void sl::display()
{
	node *temp;
	temp=header;
	while (temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
}
void sl::count()
{
	node *q;
	q=header;int c=1;
    while(q->next!=NULL)	
	{
		c=c++;
		q=q->next;
	}
	cout<<endl<<"Number of nodes in the list are"<<c;
	
}
void sl::deletebeg()
{
	node *temp;
	if(header==NULL)
	{
		cout<<endl<<"list is empty"<<endl;
	}
	else
	{
		temp=header;
		header=temp->next;
		free(temp);
		
	}
}
void sl::deleteend()
{
	node *temp,*p;
	temp=header;
	p=temp->next;
	while(p->next!=NULL)
	{
		temp=temp->next;
		p=p->next;
	}
	free(p);
	temp->next=NULL;
}
void sl::deleteafter(int pos)
{
	node *p,*temp;
	temp=header;
	for(int i=1;i<pos;i++)
	{
		p=temp;
		temp=temp->next;
		if(temp==NULL)
		{
			cout<<endl<<"there are less than"<<pos<<"elements";
			return;
		}
    }
		
		p->next=temp->next;
		free(temp);
}
int main()
{
	sl x;
	int op;
	do
	{
		cout<<endl<<"enter an option";
		cout<<endl<<"1.create a node";
		cout<<endl<<"2. add a node at the beginning";
		cout<<endl<<"3.add a node at end";
		cout<<endl<<"4.add a node at given posiion";
		cout<<endl<<"5.cout the number of nodes in the list";
		cout<<endl<<"6.display the list";
		cout<<endl<<"7.delete a node at beginning";
		cout<<endl<<"8.delete a node at end";
		cout<<endl<<"9.delete a node after a position";
		cout<<endl<<"10.exit the program"<<endl; 
		cin>>op;
		switch(op)
		{
			case 1: cout<<endl<<"enter a number:"<<endl;
			        int a;
			        cin>>a;
			        x.create(a);
			        break;
			case 2: cout<<endl<<"enter a number to add at beginning"<<endl;        
		            int b;
		            cin>>b;
		            x.addbeg(b);
		            break;
            case 3: cout<<endl<<"enter a number to add at end"<<endl;        
		            int c;
		            cin>>c;
		            x.addend(c);
		            break;
		    case 4: cout<<endl<<"enter the position at which u want the number to add"<<endl;        
		            int d,e;
		            cin>>d>>e;
		            x.addafter(d,e);
		            break;
		    case 5: cout<<endl<<"the number of nodes in the list are:"<<endl;
			        x.count();
					break;
			case 6: cout<<endl<<"display the list:"<<endl;
			        x.display();
					break;		                   
     
	        case 7: cout<<endl<<"deleting a node at beginning"<<endl;
	                x.deletebeg();
	                break;
	        case 8: cout<<endl<<"deleting a node at end"<<endl;
			        x.deleteend();
					break;
			case 9: cout<<endl<<"enter the position at which u want to delete the number:"<<endl;
			        int p;
					cin>>p;
					x.deleteafter(p);	break;	  
			case 10: exit(1);
			           		break;
	 }
 }while(op>0&&op<11);
 return 0;
}

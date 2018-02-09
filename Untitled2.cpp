#include<iostream>
#include<iomanip>
using namespace std;
class linklist
{
	private:
		struct node
		{
			int rank;char name;
			node *next,*prev;
			
		}*header;
		
	public:
		linklist();
		void addatbeg(char, int);
		void addend(char,int);
		void addafter(char,int,int);
		void display();
};
linklist::linklist()
{
	header=NULL;
}
void linklist::addatbeg(char s,int n)				
{
	node *temp;
	if(header==NULL)
	{
		header=new node;
		header->name=s;
		header->rank=n;
		header->next=NULL;
		header->prev=NULL;
		
	}
	else
	{
		if(header->prev==NULL)
		{
			temp=new node;
			temp->name=s;
			temp->rank=n;
			temp->next=NULL;
			temp->prev=header;
			header=temp;
			
		}
	}
}
void linklist::addend(char p,int m)
{
	node *temp1,*temp;
	temp=header;
	if(temp1==NULL)
	{
		temp=new node;
		temp->name=p;
		temp->rank=m;
		temp->prev=temp1;
		temp1->next=temp;
		temp->next=NULL;
		
	}
}				
void linklist::addafter(char q,int p, int w)
{
	node *temp,*temp1;
	int i,pos;
	pos=w;
	for(i=0;temp!=header,i<pos-1;i++)
	{
		temp1=temp->next;
		if(temp1==NULL)
		{
			cout<<"there are less than "<<pos<<"elements";
			return;
		
		}
	}
	temp=new node;
	temp->name=q;
	temp->rank=p;
	temp->next=temp1->next;
	temp1->next=temp;
}
void linklist::display()
{
	int q;
	node *temp;
	temp=header;
	do
	{
		if(temp==NULL)
		cout<<endl<<"end of list";	
		else
		{
			cout<<endl<<"name is"<<temp->name<<endl;
			cout<<"rank is"<<temp->rank<<endl;
			cout<<endl<<endl;
			temp=temp->next;
		}
	}while(temp!=NULL);
	cin>>q;
	
}
int main()
{
	linklist x;
	int op;
	do{
		cout<<endl<<"please enter an optio:";
		cout<<endl<<"1.add a nodeat beginning";
		cout<<endl<<"2.add a nodeat end";
		cout<<endl<<"3.add a nodeat any position";
		cout<<endl<<"4.display the link list";
		cin>>op;
		switch(op)
		{
			case 1:
					cout<<endl<<"enter the name and rank to add";
					int a;char b;
					cin>>b>>a;
					x.addatbeg(b,a);
					break;
			case 2:
					cout<<endl<<"enter the name and rank to addat end";
					int d;char c;
					cin>>c>>d;
					x.addend(c,d);
					break;	
			case 3:
					cout<<endl<<"enter the name and rank to add after the position";
					int p;char q;int r;
					cin>>q>>p>>r;
					x.addafter(q,p,r);
					break;
			case 4:
					cout<<endl<<"the nodes in linked list are:";
					x.display();
					break;				
	        default:
	        	    cout<<endl<<"enter an appropriate option:";
	    	}
}while(op!=0);
}

#include<iostream>
#include<iomanip>
using namespace std;
class sl
{
	private:
		struct node
		{
			int data;
			node *next;
		
		}*header;
	public:
		sl();
		void create(int);
		void addbeg(int);
		void addafter(int,int);
		void addend(int);
		void delet(int);
		void display();
		
};
sl::sl()
{ header=NULL;
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
		temp->next =r;
		
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
	node *q, *temp;
	temp=new node;
	temp->data=num;
	temp->next=NULL;
	q=header;
	q->next=temp;
	q=q->next;
}
void sl::addafter(int num,int pos)
{
	node *temp, *r;
	temp=header;
	for(int i=1;i<pos;i++)
	{
		temp=temp->next;
		if(temp==NULL)
		cout<<endl<<"there are less than"<<pos<<"nodes";
		
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
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
		
	}
}
int main()
{
	sl x;
	int op;
	do
	{
		
	cout<<endl<<"select an option:";
	cout<<endl<<"1.create node";
	cout<<endl<<"2.add a not at begginning";
	cout<<endl<<"3. add a node at end:";
	cout<<endl<<"4.add a node at any position";
	cout<<endl<<"5.display the list";
	cin>>op;
	switch(op)
	{
		case 1:cout<<endl<<"enter num to create a list:"<<endl;
				int n;
				cin>>n;
				x.create(n);
				break;
		case 2: cout<<endl<<"enter num to add at beginning:"<<endl;
					int a;
					cin>>a;
					x.addbeg(a);
					break;
		case 3: cout<<endl<<"enter num to add at end"<<endl;
		         int b;
				 cin>>b;
				 x.addend(b);
				 break;							
	   case 4: cout<<endl<<"enter the num to add and position"<<endl;
	             int c,p;
	             cin>>c>>p;
	             x.addafter(c,p);
	             break;
		case 5: cout<<endl<<"the nodes in list are:"<<endl;
	            x.display();
	        }

	
}while(op>0&&op<5);
}

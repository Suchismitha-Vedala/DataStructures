#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class cl
{
	private:
		struct node
		{
			node *next;
			int data;
		}*front,*rear;
	public:
	    cl();
		void create(int);
		void addbeg(int);
		void addend(int);
		void addafter(int,int);
		void deletebeg();
		void display();
		void deleteend();
		void count();
		void deleteafter(int);
			
};
cl::cl()
{
	front=rear=NULL;
}
void cl::create(int num)
{
	node *temp;
	temp=new node;
	temp->data=num;
	if(front==NULL)
	front=temp;
	else
	rear->next=temp;
	rear=temp;
	rear->next=front;

}
void cl::addbeg(int num)
{
	node *temp;
	temp=new node;
	temp->data=num;
    temp->next=front;
    rear->next=temp;
    front=temp;
}
void cl::addend(int num)
{
    
    node *p,*temp;
	p=front;
	while(p->next!=front)
	p=p->next;
	temp=new node;
	temp->data=num;
	p->next=temp;
	temp->next=front;
	rear=temp;
}
void cl::addafter(int pos,int num)
{
	node *temp,*r;
	temp=front;
	for(int i=0;i<pos-1;i++)
	{ 
	  temp=temp->next;
    }
	r=new node;
	r->data=num;
	r->next=temp->next;
	temp->next=r;
	
}
void cl::display()
{
	node *temp,*p;
	temp=front;
	p=NULL;
	while (temp!=p)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
		p=front;
	}
}
void cl:: deletebeg()
{
	node *temp;
    temp=front;
    front=temp->next;
    rear->next=temp->next;
    free(temp);
}
void cl::deleteend()
{
	node *temp,*p;
	temp=front;
	p=temp->next;
	while(p->next!=front)
	{
		p=p->next;
		temp=temp->next;
	}
	free(p);
	temp->next=front;
	rear=temp;
	
}
void cl::count()
{
	node *q;
	q=front;
	int c=1;
	while(q->next!=front)
	{
		q=q->next;
		c++;
	}
	cout<<endl<<"the number of nodes in the list are"<<c;
}
void cl::deleteafter(int pos)
{
	node *temp,*p;
	temp=front;
	for(int i=1;i<pos;i++)
	{
		p=temp;
		temp=temp->next;
		if(temp->next==front)
		{
			cout<<endl<<"there are less than"<<pos<<"elements";
		}
	}
	p->next=temp->next;
	free(temp);
}


int main()
{
	cl x;
	int op;
	do
	{
		cout<<endl<<"enter an option";
		cout<<endl<<"1.create a node";
		cout<<endl<<"2. add a node at the beginning";
		cout<<endl<<"3.add a node at end";
		cout<<endl<<"4.add a node at given posiion";
		cout<<endl<<"5.display the list";
	    cout<<endl<<"6.delete a node at beginning";
		cout<<endl<<"7.delete a node at end";
		cout<<endl<<"8.count the number of nodes";
		cout<<endl<<"9.delete a node at given position";
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
		    
			case 5: cout<<endl<<"display the list:"<<endl;
			        x.display();
					break;		                   
     
	         case 6: cout<<endl<<"deleting a node at beginning"<<endl;
	                 x.deletebeg();
	                 break;
			case 7: cout<<endl<<"deleting a node at end"<<endl;
			        x.deleteend();
			        break;
			
			case 8: cout<<endl<<"counting the number of nodes in the list";
			         x.count();
			         break;
			
			case 9: cout<<endl<<"enter the position at which u want to delete the node";
			        int z;
			        cin>>z;
			        x.deleteafter(z);
			        break;
			
			
			case 10: exit(1);
			           		break;
	 }
 }while(op>0&&op<11);
 return 0;
}

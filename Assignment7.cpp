/*Assignment-07.Sakshi Pramod Malpure,39A;
Appointment Management: Write a menu driven C++ program for storing
appointment schedules for the day.
Appointments are booked randomly using linked lists. Set start and end
time for visit slots. Write functions for
1. Display free slots
2. Book appointment
3. Cancel appointment ( check validity, time bounds, availability etc)
4. Sort list based on time
5. Sort list based on time using pointer manipulation*/
#include<iostream>
using namespace std;
int size;
struct node
{
	int start;
	int end;
	int min;
	int max;
	int flag;
	struct node*next;
}*head;
class schedule
{
	public:
		void create()
		{	
			int i;
			struct node*temp,*last;
			head=NULL;
			cout<<"\n\n How many appointment slots: ";
			cin>>size;
			for(i=0;i<size;i++)
			{
				temp=new(struct node);
				cout<<"\n\nEnter Start Time: ";
				cin>>temp->start;
				cout<<"\n\nEnter end Time: ";
				cin>>temp->end;
				cout<<"\n\nEnter Maximum Duration: ";
				cin>>temp->max;
				cout<<"\n\nEnter Minimum Duration: ";
				cin>>temp->min;
				temp->flag=0;
				temp->next=NULL;
				if(head==NULL)
				{
					head=temp;
					last=head;
				}
				else
				{
					last->next=temp;
					last=last->next;
				}
			}
				
		}
		void display()
		{
			int count=1;
			struct node*temp;
			cout<<"\n\n\t***Appointment Schedule***";
			cout<<"\n\n\tSr.\tstart\tend\tmin\tmax\tstatus"<<endl;
			temp=head;
			while(temp!=NULL)
			{
				cout<<"\n\n\t "<<count;
				cout<<"\t "<<temp->start;
				cout<<"\t "<<temp->end;
				cout<<"\t "<<temp->min;
				cout<<"\t "<<temp->max;
			if(temp->flag)
			{
				cout<<"\t Booked ";
			}
			else
			{
				cout<<"\t free ";
			}
			temp=temp->next;
			count++;
			}
		}
				
		void book()
		{
			int start;
			struct node*temp;
			cout<<"Please Enter appointment time: ";
			cin>>start;
			temp=head;
			while(temp!=NULL)
			{
				if(start==temp->start)
				{
					if(temp->flag==0)
					{
						cout<<"\n\nAppointment is booked!"<<endl;
						temp->flag=1;
					}
					else
					{
						cout<<"\n\nAppointment slot is not available"<<endl;
					}
				}
					temp=temp->next;
					
			}
			
		}
		void cancel()
		{
			int start;
			struct node*temp;
			cout<<"Enter time slot you want to cancle: ";
			cin>>start;
			temp=head;
			while(temp!=NULL)
			{
				if(start==temp->start)
				{
					if(temp->flag==1)
					{
						cout<<"\n\n Your appointment is canceled!";
						temp->flag=0;
					}
					else
					{
						cout<<"\n\n No such Appontement found!";
					}
					temp=temp->next;
				}
			}
		}
		void sort()
		{
			int i,j,val;
			struct node*temp;
			 for(i=0; i < size-1; i++) 	
   			{
      			 temp = head;
       			while(temp->next != NULL)
      		 	{ 
          			if(temp->start > temp->next->start)
          			{
              			val = temp->start;
	      				temp->start = temp->next->start;
	      				temp->next->start = val;

              			val = temp->end;
	      				temp->end = temp->next->end;
	      				temp->next->end = val;

              			val = temp->min;
	      				temp->min = temp->next->min;
	      				temp->next->min = val;

              			val = temp->max;
	      				temp->max = temp->next->max;
	      				temp->next->max = val;
	
          			}
          		temp = temp->next;
      		 }   
  		 }

  			 cout<<"\n\n\t The Appointments got Sorted!!!";

	}


			
	};
int main()
{
	schedule s;
	int ch;
	char ans;
	do{
	cout<<"\n\n***Menu***";
	cout<<"\n1.Create Appointment schedule,\n2.Display Appointment schedule,\n3.Book the Appointment,\n4.Cancel the appointment,\n5.Sort appointments"<<endl;
	cout<<"\nEnter Your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			s.create();
		break;
		case 2:
			s.display();
		break;
		case 3:
			s.book();
		break;
		case 4:
			s.cancel();
		break;
		case 5:
			s.sort();
		break;
		default:
			cout<<"Invalid choice";
		break;
	}
	cout<<"\nDo you want to continue?: ";
	cin>>ans;
	}while(ans=='Y');	
return 0;
}

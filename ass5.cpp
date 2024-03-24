#include<iostream>
using namespace std;
struct poly
{ 
	int coeff; 
	int expo;
};
 struct poly p1[20];
 struct poly p2[30];
 struct poly p3[50];

int readPoly(struct poly []);
void displayPoly( struct poly [],int t1);
int addpoly(struct poly p1[10],struct poly p2[10],struct poly p3[10],int t1,int t2);
int readPoly(struct poly p[])
{
int t1,i;
cout<<"\n Enter the total number of terms in the polynomial: ";
cin>>t1;
cout<<"\n Enter the COEFFICIENT and EXPONENT "<<endl;
for(i=0;i<t1;i++)
{
	cout<<"  Enter the Coefficient("<<i+1<<"):";
	cin>>p[i].coeff;
	cout<<" \nEnter the Exponent("<<i+1<<"):";
	cin>>p[i].expo;
}
return(t1);
} 
void displayPoly(struct poly p[10],int t1)
{
 int k;

 for(k=0;k<t1-1;k++)
	cout<<p[k].coeff<<"(x^"<<p[k].expo<<")+";
 cout<<p[k].coeff<<"(x^"<<p[k].expo<<")";
}
int addpoly(struct poly p1[10],struct poly p2[10],struct poly p3[10],int t1,int t2)
{
int i=0,j=0,k=0;
while(i<t1 && j<t2)
{
	if(p1[i].expo == p2[j].expo)
	{
		p3[k].expo = p1[i].expo;
		p3[k].coeff = p1[i].coeff + p2[j].coeff;
		i++;
		j++;
		k++;
		
	}
        else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        }
        else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
        }
        //for other remaining term
         while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }
    //for rest over terms of polynomial 2 
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }
	return (k+1);
	}

int main()
{
 int t1,t2,t3,ch;
 int value;
 cout<<"Enter your choice"<<endl;
 cout<<"1 Read polynomial"<<endl;
 cout<<"2 Display polynomial"<<endl;
 cout<<"3 Add two  polynomial"<<endl;
 cin>>ch;
 switch(ch){
     case 1:
     cout<<"\n Enter the polynomial:";
     t1=readPoly(p1);
     break;
     
     case 2:
     cout<<"\n Enter the polynomial:";
     t1=readPoly(p1);
     cout<<"\n  The polynomial is: ";
     displayPoly(p1,t1);
     break;
     
     case 3:
      cout<<"\n Enter the polynomial 1:";
      t1=readPoly(p1);
      cout<<"\n Enter the polynomial 2:";
      t2=readPoly(p2);
      cout<<"\n  The polynomial is: ";
      displayPoly(p1,t1);
      cout<<"\n  The polynomial is: ";
      displayPoly(p2,t2);
      t3 =addpoly(p1, p2, p3,t1, t2);
      cout<<"\n The Addition of polynomial is: ";
      displayPoly(p3,t3);
 }

 return 0;
}



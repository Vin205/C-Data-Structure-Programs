#include <iostream>
#include <string>

using namespace std;

class Iss
{
	public:
	string name;
	int count;
	int n;int s,l;
	void freq()
	{
		char c;
		count=0;
		cout<<"Enter the character"<<endl;
		cin>>c;
		for(int i=0;i<n;i++)
		{
			if(name[i]==c)
			{ 
		  count ++;
			}
		
		
		}
		
				cout<<"Frequency of character"<<c<<"is"<<count<<endl;
	}
	
	void extract()
	{
	
		cout<<"Enter the position from where to extract a string"<<endl;
		cin>>s;
		cout<<"Enter the length of a string"<<endl;
		cin>>l;
		for(int i=s;i<l;i++)
		{
			cout<<name[i];
		}
		
	}
	
	void eliminate()
	{
		char ch;
	 cout<<"Enter the character to remove"<<endl;
	 cin>>ch;	
		string qtr;
		for(int i=0;i<n;i++)
		{
				if(name[i]!=ch){
					qtr += name[i];
				}
		
		} cout<<"String after removing"<<ch<<"is"<<qtr<<endl;
	
	}
   void place()
   {
   	    string q;
		cout<<"Enter the position from where to extract a string"<<endl;
		cin>>s;
		cout<<"Enter the length of a string"<<endl;
		cin>>l;
		cout<<"Enter new string"<<endl;
        cin>>q;  
		
		name.erase(s,l);
		cout<<"New string"<<name.insert(s,q)<<endl;;	
   }
   
   void palindrome()
   {  
     int j;
   	for(int i=0;i<n;i++) 
	   {
	   	 if(name[i]==name[n-i])
	   	  {
	   	 	 j=1;
	   	  }
			else
	   	    j=0;
	   }
	   	   if(j=1){
	   	   	cout<<"Not a palindrome"<<endl;
		}
		else 
		cout<<"Palindrome"<<endl;
	}
			
	};
	int main()
	{
		Iss t;
		string w;
		int n,c;
		cout<<"Enter length"<<endl;
		cin>>n;
		t.n=n;
		cout<<"Enter a string"<<endl;
		cin>>w;
		t.name=w;
		do
		{
		cout<<"	1. To determine the frequency of occurrence of a particular character in the string"<<endl;
    cout<<"2. Extract a new string from original string by accepting startingposition and length"<<endl;
   cout<< "3. To accept any character and return the string with by removing all occurrences of a character accepted"<<endl;
   cout<< "4. To make an in-place replacement of a substring w of a string by the string x. Note that w may not be of same size that ofxwhether given string is palindrome or not"<<endl;        
   cout<<"To check whether given string is palindrome or not"<<endl;	
	cin>>c;
        switch(c)
        {
        	case 1:
        	t.freq();
        	break;
        	
        	case 2:
        	t.extract();
        	break;
        	
        	case 3:
        	t.eliminate();
        	break;
        	
        	case 4:
        	t.place();
        	break;
        	
        	case 5:
        	t.palindrome();
        	break;
		}
        
		}while(c!=6);
		
		return 0;
		
	}

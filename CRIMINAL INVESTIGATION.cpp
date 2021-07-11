#include<bits/stdc++.h>
#include<fstream>
using namespace std;
void search();
void deleted();
void modify();
void create();
void show();
int main()
{
	string username,password;
	string un="ISHIKA",psw="JAIN";
	cout<<"       ----------"<<endl;
	cout<<"       LOGIN PAGE "<<endl;
	cout<<"       ----------"<<endl;
	cout<<"ENTER USERNAME =";
	cin>>username;
	cout<<endl<<"ENTER PASSWORD =";
	cin>>password;
	while(username!=un || password!=psw)
	{
		cout<<"INVALID LOGIN"<<endl;
	
	cout<<endl<<" LOGIN "<<endl;
	cout<<"ENTER USERNAME =";
	cin>>username;
	cout<<endl<<"ENTER PASSWORD =";
	cin>>password;
}
	cout<<"----------------"<<endl;
	cout<<"SUCCESSFUL LOGIN"<<endl;
	cout<<"----------------"<<endl;
	menustart:
	system("color e");
	system("color C");
	int choice;
	char o;
	do
	{
	cout<<"WELCOME TO CRIMINAL INVESTIGATION TRACKER WITH SUSPECT PREDICTION"<<endl;
	cout<<endl;
	cout<<"--------------------MAIN FUNCTIONALITY-------------------"<<endl;
	cout<<endl;
	cout<<"              PRESS 1 TO CREATE NEW RECORD OF CRIMINAL              "<<endl;
	cout<<"              PRESS 2 TO DELETE RECORD OF A CRIMINAL                "<<endl;
	cout<<"              PRESS 3 TO MODIFY RECORD OF A CRIMINAL                "<<endl;
	cout<<"              PRESS 4 TO SEARCH RECORD OF A CRIMINAL                "<<endl;
	cout<<"              PRESS 5 TO SHOW RECORD OF ALL CRIMINALS               "<<endl;
	cout<<"              PRESS 6 TO EXIT                                        "<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
	cout<<"ENTER YOUR CHOICE ON THE BASIS OF ABOVE : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			char ch;
			do{
				create();
				cout<<"DO YOU WANT TO CREATE ANOTHER ACCOUNT ? PRESS (Y/N)=";
				cin>>ch;
			}while(ch=='y' || ch=='Y');
			break;
		case 2:
			deleted();
			break;
		case 3:
			modify();
			break;
		case 4:
			search();
            break;
		case 5:
			show();
			break;
		case 6:	
			cout<<"EXITING";
			exit(0);
	    default:
		cout<<"INVALID CHOICE"<<endl;
	}
	cout<<"DO YOU WANT TO PERFORM MORE OPERATION ? PRESS (Y/N)";
	cin>>o;
}while(o=='y' || o=='Y');
goto menustart;
}
struct criminal
{
	char date[50],name[50],crime[50];
	long case_id;
}obj;
void create()
{
	fstream file;
	int i;
		cout<<"ENTER CASE ID = ";
		cin>>obj.case_id;
		cout<<endl;
		cout<<"ENTER CRIMINAL NAME =";
		cin>>obj.name;
		cout<<endl;
		cout<<"ENTER DATE  =";
		cin>>obj.date;
		cout<<endl;
		cout<<"ENTER CRIME DONE BY THE CRIMINAL =";
		cin>>obj.crime;
		cout<<endl;
		file.open("criminal.txt",ios::app | ios::out);
		file<<obj.case_id<<" "<<obj.name<<" "<<obj.date<<" "<<obj.crime<<endl;
		file.close();
}
	void search_case_id();
	void search_date();
	void search_crime();
	void search()
	{
		int choice;
	char opt;
	do
	{
	cout<<"PRESS 1 TO SEARCH BY THE CASE ID "<<endl;
	cout<<"PRESS 2 TO SEARCH BY THE DATE  "<<endl;
	cout<<"PRESS 3 TO SEARCH BY THE CRIME COMMINTTED "<<endl;
	cout<<"PRESS 4 TO EXIT "<<endl;
	cout<<"ENTER YOUR CHOICE";
	cin>>choice;
	switch(choice)
	{
		case 1:
			search_case_id();
			break;
	    case 2:
	    	search_date();
	    	break;
	    case 3:
	    	search_crime();
	    	break;
	    case 4:
	    	cout<<"EXITING";
	    	exit(0);
		default:
			cout<<"INVALID CHOICE";
			break;
	}
	cout<<"DO YOU WANT TO SEARCH MORE ? (Y/N) = ";
	cin>>opt;
    }while(opt=='y' || opt=='Y');
    
}
void search_case_id()
{
	        fstream file;
		 	long case_id1;
			int flag=0;
		 	file.open("criminal.txt",ios::in);
		 	if(!file.is_open())
		 	cout<<"file is not present"<<endl;
		 	else
		 	{
		 		cout<<"ENTER CASE ID YOU WANT TO SEARCH"<<endl;
		 		cin>>case_id1;
		 		file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
			 while(!file.eof())
	 	    {
            if(obj.case_id==case_id1)
            {
	 	    cout<<"CASE ID ="<<obj.case_id<<endl<<"NAME ="<<obj.name<<endl<<"DATE ="<<obj.date<<endl<<"CRIME ="<<obj.crime<<endl;
			 flag=1;	
			}
			file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
		    }
		    if(flag==0)
		    cout<<"NOT FOUND CRIMINAL OF THIS CASE ID"<<endl;
			file.close();
		   }
}
void search_date()
{
	        fstream file;
		 	string date1;
			int flag=0;
		 	file.open("criminal.txt",ios::in);
		 	if(!file.is_open())
		 	cout<<"file is not present"<<endl;
		 	else
		 	{
		 		cout<<"ENTER DATE YOU WANT TO SEARCH"<<endl;
		 		cin>>date1;
		 		file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
			 while(!file.eof())
	 	    {
            if(date1==obj.date)
            {
	 	    cout<<"CASE ID ="<<obj.case_id<<endl<<"NAME ="<<obj.name<<endl<<"DATE ="<<obj.date<<endl<<"CRIME ="<<obj.crime<<endl;
			flag=1;	
			}
			file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
		    }
		    if(flag==0)
		    cout<<"NOT FOUND CRIMINAL OF THIS DATE"<<endl;
			file.close();
		   }
}
void search_crime()
{
	        fstream file;
		 	string criminal1;
			 int flag=0;
		 	file.open("criminal.txt",ios::in);
		 	if(!file.is_open())
		 	cout<<"file is not present"<<endl;
		 	else
		 	{
		 		cout<<"ENTER CRIME YOW WANT TO SEARCH"<<endl;
		 		cin>>criminal1;
		 		file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
			 while(!file.eof())
	 	    {
            if(criminal1==obj.crime)
            {
	 	    cout<<"CASE ID ="<<obj.case_id<<endl<<"NAME ="<<obj.name<<endl<<"DATE ="<<obj.date<<endl<<"CRIME ="<<obj.crime<<endl;
			 flag=1;	
			}
			file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
		    }
		    if(flag==0)
		    cout<<"NOT FOUND THIS CRIME"<<endl;
			file.close();
		   }
	}
void deleted()
{
	        ifstream file;
		    ofstream t;
		    t.open("temp.txt",ios::out);
		 	long case_id1;
		 	file.open("criminal.txt",ios::in);
		 	if(!file.is_open())
		 	cout<<"file is not present"<<endl;
		 	else
		 	{
		 		cout<<"ENTER CASE ID YOU WANT TO DELETE"<<endl;
		 		cin>>case_id1;
		 		file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
			 while(!file.eof())
	 	    {
            if(case_id1!=obj.case_id)
            {
	 	    t<<obj.case_id<<" "<<obj.name<<" "<<obj.date<<" "<<obj.crime<<endl;	
			}
			file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
		    }
		    t.close();
		file.close();
		remove("criminal.txt");
		rename("temp.txt","criminal.txt");
			}
}
void modify()
{
	        fstream file;
			ofstream t;
		 	long case_id1;
			 int flag;
		 	file.open("criminal.txt",ios::in);
		 	t.open("temp.txt",ios::out);
		 	if(!file.is_open())
		 	{
		 		cout<<"FILE NOT FOUND"<<endl;
			}
			else
			{
				cout<<"ENTER CASE ID YOU WANT TO MODIFY"<<endl;
				cin>>case_id1;
				file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
				while(!file.eof())
	 	        {
				if(case_id1==obj.case_id)
				{
					cout<<"OLD RECORDS ARE"<<endl;
					cout<<"CASE ID ="<<obj.case_id<<endl<<"NAME ="<<obj.name<<endl<<"DATE ="<<obj.date<<endl<<"CRIME ="<<obj.crime<<endl;
					cout<<"ENTER MODIFY NAME =";
					cin>>obj.name;
					cout<<"ENTER MODIFIED DATE =";
					cin>>obj.date;
					cout<<"ENTER MODIFIED CRIME=";
					cin>>obj.crime;
					t<<obj.case_id<<" "<<obj.name<<" "<<obj.date<<" "<<obj.crime<<endl;
                 	}
                 	else
                 {
                 	t<<obj.case_id<<" "<<obj.name<<" "<<obj.date<<" "<<obj.crime<<endl;
                 }
                 file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
			   }
            t.close();
			file.close();
			remove("criminal.txt");
			rename("temp.txt","criminal.txt");	
				}
}
void show()
{
	int i=1;
		 	fstream file;
		 	file.open("criminal.txt",ios::in);
		 	if(!file.is_open())
		 	cout<<"file is not present"<<endl;
		 	else
		 	{
		 		cout<<"ALL CRIMINAL RECORDS ARE AS FOLLOWS :"<<endl;
		 		file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
			 while(file.good())
	 	    {
            cout<<"RECORD OF "<<i<<" CRIMINAL :"<<endl;
	 	    cout<<"CASE ID ="<<obj.case_id<<endl<<"NAME ="<<obj.name<<endl<<"DATE ="<<obj.date<<endl<<"CRIME ="<<obj.crime<<endl;	
			cout<<"--------------------------------------"<<endl;
			file>>obj.case_id>>obj.name>>obj.date>>obj.crime;
			i++;
			}
			file.close();
		   }
}

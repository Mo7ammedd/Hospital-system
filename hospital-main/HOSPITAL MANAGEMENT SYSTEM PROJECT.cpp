#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class base {
  public:
  	int age;
  	int choice;
  	char gender;
  	long long id;
  	char date[20]; 
  	char fname[10];
  	char lname[10]; 
	long long Mobilenumber;			
};
class Patient : public base {
  public:
  	long long treatmentBill;
  	char disease[30];
  	char Pboodgroup[5];
  	char treatment[30];
};
class Doctor  : public base {
  public:
    int salary;
    char department[30];
};
void writeP(){
	system("color 0C");	// font color
	 cout<<endl<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t|        write      |"<<endl;
        cout<<"\t\t+-------------------+"<<endl;
        
        //write to file//
    base b1;
    Patient p;
    int flag=0;
    //fstream outFile;
    //outFile.open("temp.txt",ios::out);
    fstream outFile("Patient.txt", ios::out | ios::app);
    char c;
    do
	{
		cout << "\n\n\t>>Please enter data for patient\n";
		cout<<"\t\tFirst Name: ";
		cin>>p.fname;
		cout<<"\t\tLast Name: ";
		cin>>p.lname;
		cout<<"\t\tGender(m/f): ";
		cin>>p.gender;
		cout<<"\t\tID: ";
		cin>>p.id;
		cout<<"\t\tAge: ";
		cin>>p.age;
		again :
		cout<<"\t\tBlood Group: ";
		cin>>p.Pboodgroup;
   if((strcmp(p.Pboodgroup,"A+")==0)||(strcmp(p.Pboodgroup,"a+")==0)||(strcmp(p.Pboodgroup,"A-")==0)||(strcmp(p.Pboodgroup,"a-")==0)||
      (strcmp(p.Pboodgroup,"B+")==0)||(strcmp(p.Pboodgroup,"b+")==0)||(strcmp(p.Pboodgroup,"B-")==0)||(strcmp(p.Pboodgroup,"b-")==0)||
      (strcmp(p.Pboodgroup,"O+")==0)||(strcmp(p.Pboodgroup,"o+")==0)||(strcmp(p.Pboodgroup,"O-")==0)||(strcmp(p.Pboodgroup,"o-")==0)||
      (strcmp(p.Pboodgroup,"AB+")==0)||(strcmp(p.Pboodgroup,"ab+")==0)||(strcmp(p.Pboodgroup,"AB-")==0)||(strcmp(p.Pboodgroup,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        cout<<"\t\t\nWrong Entry..Enter a valid Blood Group..Try Again.."<<endl;
        goto again;
    }
		cout<<"\t\tMobile number: ";
		cin>>p.Mobilenumber;
		cout<<"\t\tThe disease that the patient has: ";
		cin>>p.disease;
		cout<<"\t\tThe treatment is going on: ";
		cin>>p.treatment;
		cout<<"\t\tNumber of treatment days: ";
		cin>>p.treatmentBill;
		
		outFile.write((char*) &p,sizeof(p));
		cout<<"\t\tdo you want to add agin(y/n)";
		cin>>c;
    }
    while(c=='y'|| c=='Y');
	outFile.close();
}
void writeD(){
	system("color 0C");	//color font
	 cout<<endl<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t|        write      |"<<endl;
        cout<<"\t\t+-------------------+"<<endl;
        
        //write to file//   
    base b1;
    Doctor d;
    int flag=0;
    //fstream outFile;
    //outFile.open("temp.txt",ios::out);
    fstream outFile("Doctor.txt", ios::out | ios::app);
    char c;
    do
	{
		cout << "\n\n\t>>Please enter data for doctor\n";
		cout<<"\t\tFirst Name: ";
		cin>>d.fname;
		cout<<"\t\tLast Name: ";
		cin>>d.lname;
		cout<<"\t\tGender(m/f): ";
		cin>>d.gender;
		cout<<"\t\tID: ";
		cin>>d.id;
		cout<<"\t\tAge: ";
		cin>>d.age;
		cout<<"\t\tMobile number: ";
		cin>>d.Mobilenumber;
		cout<<"\t\tDoctor work department:  ";
		cin>>d.department;
		cout<<"\t\tsalary: ";
		cin>>d.salary;
		
		outFile.write((char*) &d,sizeof(d));
		cout<<"\t\tdo you want to add agin(y/n)";
		cin>>c;
    }
    while(c=='y'|| c=='Y');
	outFile.close();
}
void readP(){
	system("color 0A");	// font color
	 cout<<endl<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t|       read        |"<<endl;
        cout<<"\t\t+-------------------+"<<endl;
              //read from file//
    
   base b1;
   Patient p;
   fstream f;
   int ch;
   ifstream infile("Patient.txt",ios::in);
   if(infile.is_open())
  {
      
      while(!infile.eof())
      {
          infile.read((char*) &p,sizeof(p));

          if(ch!=p.id)
          {
    cout<<"\t\t------------------------------------"<<endl;
	cout<<"\t\tPatient data:"<<endl;
	cout<<"\t\tFirst Name         : "<<p.fname<<endl;
	cout<<"\t\tLast Name          : "<<p.lname<<endl;
	cout<<"\t\tId                 : "<<p.id<<endl;
	cout<<"\t\tGender             : "<<p.gender<<endl;
	cout<<"\t\tAge                : "<<p.age<<endl;
	cout<<"\t\tBlood Group        : "<<p.Pboodgroup<<endl;
	cout<<"\t\tMobile Number      : "<<p.Mobilenumber<<endl;
	cout<<"\t\tDisease            : "<<p.disease<<endl;
	cout<<"\t\tTreatment          : "<<p.treatment<<endl;
	cout<<"\t\tTreatmentBill in dollars      : "<<p.treatmentBill*100<<endl;
	cout<<"\t\t------------------------------------"<<endl;
              ch=p.id;
          }
      }
  }
  else
  {
      cout<<"\t\tNo records founded ";
  }
    infile.close();
   } 

void readD(){
	system("color 0A");	
	 cout<<endl<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t|       read        |"<<endl;
        cout<<"\t\t+-------------------+"<<endl;
              //read from file//
       base b1;
    Doctor d1;
    fstream f;  
    int ch;
   ifstream infile("Doctor.txt",ios::in);
   if(infile.is_open())
  {
      
      while(!infile.eof())
      {
          infile.read((char*) &d1,sizeof(d1));

          if(ch!=d1.id)
          {
    cout<<"\t\t------------------------------------"<<endl;
	cout<<"\t\tdoctor data:"<<endl;
	cout<<"\t\tFirst Name       : "<<d1.fname<<endl;
	cout<<"\t\tLast Name          : "<<d1.lname<<endl;
	cout<<"\t\tId                 : "<<d1.id<<endl;
	cout<<"\t\tGender             : "<<d1.gender<<endl;
	cout<<"\t\tAge                : "<<d1.age<<endl;
	cout<<"\t\tsallary            : "<<d1.salary<<endl;
	cout<<"\t\tDepartment         : "<<d1.department<<endl;
	cout<<"\t\tMobile Number      : "<<d1.Mobilenumber<<endl;
	cout<<"\t\t------------------------------------"<<endl;
              ch=d1.id;
          }
      }
  }
  else
  {
      cout<<"\t\t No records founded";
  }
    infile.close();
    
}
void searchP(){
	system("color 0D");//color font
	int choice;
	    do
	{
	cout<<endl<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t|        search     |"<<endl;
        cout<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t-------------------"<<endl;
        cout<<"\t\t1-search by Patient Last Name:"<<endl;
        cout<<"\t\t2-search by Patient Id"<<endl;
        cout<<"\t\t3-Exit"<<endl;
        cout<<"\t\t>>Enter choice: ";
        
    base b1;
    Patient p;
    
    fstream file;
       
	  cin>>choice;
      switch(choice)
	{
		case(1)://search by name
		{
	char Name[10];
	char str[10];
	cout<<"\t\t>>Enter Patient last name to search for: ";
	cin>>str;
    bool found=false;
    ifstream file;
	file.open("Patient.txt",ios::in);
	int id=0;
	if(file.is_open())
	{

	file.read((char*) &p,sizeof(p));
		while(!file.eof())
		{
			if(strcmp(str,p.lname)==0)
				{
	cout<<"\t\t------------------------------------"<<endl;
	cout<<"\t\tPatient data:"<<endl;
	cout<<"\t\tFirst Name       : "<<p.fname<<endl;
	cout<<"\t\tLast Name          : "<<p.lname<<endl;
	cout<<"\t\tId                 : "<<p.id<<endl;
	cout<<"\t\tGender             : "<<p.gender<<endl;
	cout<<"\t\tAge                : "<<p.age<<endl;
	cout<<"\t\tBlood Group        : "<<p.Pboodgroup<<endl;
	cout<<"\t\tMobile Number      : "<<p.Mobilenumber<<endl;
	cout<<"\t\tDisease            : "<<p.disease<<endl;
	cout<<"\t\tTreatment          : "<<p.treatment<<endl;
	cout<<"\t\tTreatmentBill in dollars      : "<<p.treatmentBill*100<<endl;
	cout<<"\t\t------------------------------------"<<endl;
					found=true;
				}
				file.read((char*) &p,sizeof(p));
			}
			if(!found)
			{
				cout<<"\t\tnot founded Xd:"<<endl;
			}
			file.close();
		}
		else
		{
			cout<<"\t\tcan't open this file"<<endl;
		}
            
			break;
			
			
			
		}case(2): //search by id
		{
			
     base s;
     Patient p;

     fstream in;

     in.open("Patient.txt", ios::in);
     int id = 0;
     cout<<"\t\t>>Enter the id of Patient to search:";
     cin >> id;
      if (in.is_open())
       {
        base s1;
        in.read((char*)&p, sizeof p);
        while (!in.eof())
        {
            if (id == p.id)
            {
    cout<<"\t\t------------------------------------"<<endl;
	cout<<"\t\tPatient data:"<<endl;
	cout<<"\t\tFirst Name       : "<<p.fname<<endl;
	cout<<"\t\tLast Name          : "<<p.lname<<endl;
	cout<<"\t\tId                 : "<<p.id<<endl;
	cout<<"\t\tGender             : "<<p.gender<<endl;
	cout<<"\t\tAge                : "<<p.age<<endl;
	cout<<"\t\tBlood Group        : "<<p.Pboodgroup<<endl;
	cout<<"\t\tMobile Number      : "<<p.Mobilenumber<<endl;
	cout<<"\t\tDisease            : "<<p.disease<<endl;
	cout<<"\t\tTreatment          : "<<p.treatment<<endl;
	cout<<"\t\tTreatmentBill in dollars      : "<<p.treatmentBill*100<<endl;
	cout<<"\t\t------------------------------------"<<endl;
            }
            in.read((char*)&p, sizeof p);
        }
        in.close();
    }
    else
    {
        cout << "\t\tnot found" << endl;
    }
			continue;
		}		
		
        default:{
		if(choice>3 || choice<1){
		cout<<"\t\tWrong choice"<<endl;
		}
        else{
			continue;
			} 
			continue;
			}
			}
              }
			  while(choice!=3);


}
void searchD(){
	system("color 0D");
	int choice;
	    do

	{
	cout<<endl<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t|        search     |"<<endl;
        cout<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t-------------------"<<endl;
        cout<<"\t\t1-search by  Doctor Last Name:"<<endl;
        cout<<"\t\t2-search by Doctor Id"<<endl;
        cout<<"\t\t3-Exit"<<endl;
        cout<<"\t\t>>Enter choice: ";
    Doctor d;
    
    fstream file;
       
	   cin>>choice;
      switch(choice)
	{
		case(1)://search by name
		{
	char Name[10];
	char str[10];
	cout<<"\t\t>>Enter Doctor last name to search for: ";
	cin>>str;
    bool found=false;
    ifstream file;
	file.open("Doctor.txt",ios::in);
	int id=0;
	if(file.is_open())
	{

	file.read((char*) &d,sizeof(d));
		while(!file.eof())
		{
			if(strcmp(str,d.lname)==0)
				{
	cout<<"\t\t------------------------------------"<<endl;
	cout<<"\t\tdoctor data        : "<<endl;
	cout<<"\t\tFirst Name         : "<<d.fname<<endl;
	cout<<"\t\tLast Name          : "<<d.lname<<endl;
	cout<<"\t\tId                 : "<<d.id<<endl;
	cout<<"\t\tGender             : "<<d.gender<<endl;
	cout<<"\t\tAge                : "<<d.age<<endl;
	cout<<"\t\tsallary            : "<<d.salary<<endl;
	cout<<"\t\tDepartment         : "<<d.department<<endl;
	cout<<"\t\tMobile Number      : "<<d.Mobilenumber<<endl;
	cout<<"\t\t------------------------------------"<<endl;
					found=true;
				}
				file.read((char*) &d,sizeof(d));
			}
			if(!found)
			{
				cout<<"\t\t\nnot founded Xd:"<<endl;
			}
			file.close();
		}
		else
		{
			cout<<"\t\t\ncan't open this file"<<endl;
		}
            
			break;
		}case(2)://search by id
		{
			
     base s;
     fstream in;
     bool found=false;
     in.open("Doctor.txt", ios::in);
     int id = 0;
     cout<<"\t\t>>Enter the id of Doctor to search:";
     cin >> id;
      if (in.is_open())
       {
        Doctor d;
        in.read((char*)&d, sizeof d);
        while (!in.eof())
        {
            if (id == d.id)
            {
   	cout<<"\t\t------------------------------------"<<endl;
	cout<<"\t\tdoctor data        : "<<endl;
	cout<<"\t\tFirst Name         : "<<d.fname<<endl;
	cout<<"\t\tLast Name          : "<<d.lname<<endl;
	cout<<"\t\tId                 : "<<d.id<<endl;
	cout<<"\t\tGender             : "<<d.gender<<endl;
	cout<<"\t\tAge                : "<<d.age<<endl;
	cout<<"\t\tsallary            : "<<d.salary<<endl;
	cout<<"\t\tDepartment         : "<<d.department<<endl;
	cout<<"\t\tMobile Number      : "<<d.Mobilenumber<<endl;
	cout<<"\t\t------------------------------------"<<endl;
            }
            in.read((char*)&d, sizeof d);
        }
        in.close();
    }
    else
    {
        cout << "\t\t\nnot found" << endl;
    }
			continue;
		}		
		
        default:{
		if(choice>3 || choice<1){
		cout<<"\t\tWrong choice"<<endl;
		}
        else{
			break;
			} 
			continue;
			}
			}
              }
			  while(choice!=3);
			

}
void UpdatePRecord(){
system("color 0E");
int choice;
	    do

	{
        cout<<endl<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t|        Update     |"<<endl;
        cout<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t-------------------"<<endl;
        cout<<"\t\t1-Update Patient  by Last Name:"<<endl;
        cout<<"\t\t2-Update Patient by Id"<<endl;
        cout<<"\t\t3-Exit"<<endl;
        cout<<"\t\t>>Enter choice: ";


	   cin>>choice;
      switch(choice)
	{
		case(1)://update by name
		{
                        
    fstream in;
    in.open("Patient.txt", ios::in | ios::out);
    int id = 0;
    string person;
    cout<<"\t\t>>Enter Patient Last Name to update: ";
    cin >> person;
    if (in.is_open())
    {
        Patient p;
        in.read((char*)&p, sizeof p);
        while (!in.eof())
        {
            if (person == p.lname)
            {
                cout <<"\t\t>>Enter Patient new Data" << " : \n";
                cout<<"\t\t------------------------------------\n";
                cout<<"\t\tFirst Name         : ";cin>>p.fname;
	            cout<<"\t\tLast Name          : ";cin>>p.lname;
	            cout<<"\t\tId                 : ";cin>>p.id;
	            cout<<"\t\tGender(m/f)        : ";cin>>p.gender;
	            cout<<"\t\tAge                : ";cin>>p.age;
	            cout<<"\t\tBlood Group        : ";cin>>p.Pboodgroup;
	            cout<<"\t\tMobile Number      : ";cin>>p.Mobilenumber;
	            cout<<"\t\tDisease            : ";cin>>p.disease;
	            cout<<"\t\tTreatment          : ";cin>>p.treatment;
	            cout<<"\t\tNumber of treatment days      : ";cin>>p.treatmentBill;
	            cout<<"\t\t------------------------------------\n";
                int curr = in.tellg();
                int size = sizeof(p);
                in.seekp(curr - size, ios::beg);
                in.write((char*)&p, sizeof p);

                in.seekg(curr - size, ios::beg);
                in.read((char*)&p, sizeof p);
                cout<<"\t\t------------------------------------";cout<<endl;
              	cout<<"\t\t->New Patient data saved<-";cout<<endl;
	            cout<<"\t\tFirst Name       : "<<p.fname;cout<<endl;
	            cout<<"\t\tLast Name          : "<<p.lname;cout<<endl;
	            cout<<"\t\tId                 : "<<p.id;cout<<endl;
	            cout<<"\t\tGender             : "<<p.gender;cout<<endl;
	            cout<<"\t\tAge                : "<<p.age;cout<<endl;
	            cout<<"\t\tBlood Group        : "<<p.Pboodgroup;cout<<endl;
	            cout<<"\t\tMobile Number      : "<<p.Mobilenumber;cout<<endl;
	            cout<<"\t\tDisease            : "<<p.disease;cout<<endl;
	            cout<<"\t\tTreatment          : "<<p.treatment;cout<<endl;
	            cout<<"\t\tTreatmentBill in dollars      : "<<p.treatmentBill;cout<<endl;
	            cout<<"\t\t------------------------------------";cout<<endl;
            }
            in.read((char*)&p, sizeof p);
        }
        in.close();
    }else
    {
        cout << "\t\tnot found" << endl;
    }
    break;}
    
    
	case(2)://update by id
	{	
	fstream in;
    in.open("Patient.txt", ios::in | ios::out);
    int id = 0;
    int person;
    cout<<"\t\t>>Enter Doctor ID to update: ";
    cin >> person;
    if (in.is_open())
    {
        Patient p;
        in.read((char*)&p, sizeof p);
        while (!in.eof())
        {
            if (person == p.id)
            {
                cout <<"\t\t>>Enter Patient new Data" << " : \n";
                cout<<"\t\t------------------------------------\n";
                cout<<"\t\tFirst Name         : ";cin>>p.fname;
	            cout<<"\t\tLast Name          : ";cin>>p.lname;
	            cout<<"\t\tId                 : ";cin>>p.id;
	            cout<<"\t\tGender(m/f)        : ";cin>>p.gender;
	            cout<<"\t\tAge                : ";cin>>p.age;
	            cout<<"\t\tBlood Group        : ";cin>>p.Pboodgroup;
	            cout<<"\t\tMobile Number      : ";cin>>p.Mobilenumber;
	            cout<<"\t\tDisease            : ";cin>>p.disease;
	            cout<<"\t\tTreatment          : ";cin>>p.treatment;
	            cout<<"\t\tNumber of treatment days      : ";cin>>p.treatmentBill;
	            cout<<"\t\t------------------------------------\n";
                int curr = in.tellg();
                int size = sizeof(p);
                in.seekp(curr - size, ios::beg);
                in.write((char*)&p, sizeof p);

                in.seekg(curr - size, ios::beg);
                in.read((char*)&p, sizeof p);
                cout<<"\t\t------------------------------------";cout<<endl;
              	cout<<"\t\t->New Patient data saved<-";cout<<endl;
	            cout<<"\t\tFirst Name       : "<<p.fname;cout<<endl;
	            cout<<"\t\tLast Name          : "<<p.lname;cout<<endl;
	            cout<<"\t\tId                 : "<<p.id;cout<<endl;
	            cout<<"\t\tGender             : "<<p.gender;cout<<endl;
	            cout<<"\t\tAge                : "<<p.age;cout<<endl;
	            cout<<"\t\tBlood Group        : "<<p.Pboodgroup;cout<<endl;
	            cout<<"\t\tMobile Number      : "<<p.Mobilenumber;cout<<endl;
	            cout<<"\t\tDisease            : "<<p.disease;cout<<endl;
	            cout<<"\t\tTreatment          : "<<p.treatment;cout<<endl;
	            cout<<"\t\tTreatmentBill in dollars      : "<<p.treatmentBill;cout<<endl;
	            cout<<"\t\t------------------------------------";cout<<endl;
            }
            in.read((char*)&p, sizeof p);
        }
        in.close();
    }
    else
    {
        cout << "\t\tnot found" << endl;
    }
		  continue;
		}		
		
        default:{
		if(choice>3 || choice<1)
		{cout<<"\t\tWrong choice"<<endl;}
        else{break;} 
			continue;
			}
			}
			}
			while(choice!=3);
}
void UpdateDRecord(){ 
system("color 0E"); 
int choice;
	    do

	{
        cout<<endl<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t|        Update     |"<<endl;
        cout<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t-------------------"<<endl;
        cout<<"\t\t1-Update Doctor  by Last Name:"<<endl;
        cout<<"\t\t2-Update Doctor by Id"<<endl;
        cout<<"\t\t3-Exit"<<endl;
        cout<<"\t\t>>Enter choice: ";


	   cin>>choice;
      switch(choice)
	{
		case(1):
		{
      fstream in;
    in.open("Doctor.txt", ios::in | ios::out);
    int id = 0;
    string person;
    cout<<"\t\t>>Enter Doctor Last Name to update: ";
    cin >> person;
    if (in.is_open())
    {
        Doctor d;
        in.read((char*)&d, sizeof d);
        while (!in.eof())
        {
            if (person == d.lname)
            {
                cout<<"\t\t------------------------------------\n";
	            cout<<"\t\t->Enter Doctor new Data :\n";
                cout<<"\t\tFirst Name       : ";cin>>d.fname;
	            cout<<"\t\tLast Name          : ";cin>>d.lname;
	            cout<<"\t\tId                 : ";cin>>d.id;
	            cout<<"\t\tGender(m/f)        : ";cin>>d.gender;
	            cout<<"\t\tAge                : ";cin>>d.age;
	            cout<<"\t\tsallary            : ";cin>>d.salary;
	            cout<<"\t\tDepartment         : ";cin>>d.department;
	            cout<<"\t\tMobile Number      : ";cin>>d.Mobilenumber;
	            cout<<"\t\t------------------------------------";
                int curr = in.tellg();
                int size = sizeof(d);
                in.seekp(curr - size, ios::beg);
                in.write((char*)&d, sizeof d);
                
                in.seekg(curr - size, ios::beg);
                in.read((char*)&d, sizeof d);
               cout<<"\t\t------------------------------------";cout<<"\n";
	           cout<<"\t\t->New Doctor data saved <-";cout<<"\n";
	           cout<<"\t\tFirst Name       : "<<d.fname;cout<<"\n";
	           cout<<"\t\tLast Name          : "<<d.lname;cout<<"\n";
	           cout<<"\t\tId                 : "<<d.id;cout<<"\n";
	           cout<<"\t\tGender             : "<<d.gender;cout<<"\n";
	           cout<<"\t\tAge                : "<<d.age;cout<<"\n";
	           cout<<"\t\tsallary            : "<<d.salary;cout<<"\n";
	           cout<<"\t\tDepartment         : "<<d.department;cout<<"\n";
	           cout<<"\t\tMobile Number      : "<<d.Mobilenumber;cout<<"\n";
	           cout<<"\t\t------------------------------------";cout<<"\n";
            }else
            {
               cout << "\t\t **record not found**" << endl;
            }
            in.read((char*)&d, sizeof d);
        }
        in.close();
    }
    else
    {
        cout << "\t\tnot found" << endl;
    }
    break;
    
    }
	
	case(2):
		{
			
	fstream in;
    in.open("Doctor.txt", ios::in | ios::out);
    int id = 0;
    int person;
    cout<<"\t\t>>Enter Doctor ID to update: ";
    cin >> person;
    if (in.is_open())
    {
        Doctor d;
        in.read((char*)&d, sizeof d);
        while (!in.eof())
        {
            if (person == d.id)
            {
                cout<<"\t\t------------------------------------\n";
	            cout<<"\t\t->Enter Doctor new Data :\n";
                cout<<"\t\tFirst Name       : ";cin>>d.fname;
	            cout<<"\t\tLast Name          : ";cin>>d.lname;
	            cout<<"\t\tId                 : ";cin>>d.id;
	            cout<<"\t\tGender(m/f)        : ";cin>>d.gender;
	            cout<<"\t\tAge                : ";cin>>d.age;
	            cout<<"\t\tsallary            : ";cin>>d.salary;
	            cout<<"\t\tDepartment         : ";cin>>d.department;
	            cout<<"\t\tMobile Number      : ";cin>>d.Mobilenumber;
	            cout<<"\t\t------------------------------------";
                int curr = in.tellg();
                int size = sizeof(d);
                in.seekp(curr - size, ios::beg);
                in.write((char*)&d, sizeof d);

                in.seekg(curr - size, ios::beg);
                in.read((char*)&d, sizeof d);
               cout<<"\t\t------------------------------------";cout<<"\n";
	           cout<<"\t\t->New Doctor data saved <-";cout<<"\n";
	           cout<<"\t\tFirst Name       : "<<d.fname;cout<<"\n";
	           cout<<"\t\tLast Name          : "<<d.lname;cout<<"\n";
	           cout<<"\t\tId                 : "<<d.id;cout<<"\n";
	           cout<<"\t\tGender             : "<<d.gender;cout<<"\n";
	           cout<<"\t\tAge                : "<<d.age;cout<<"\n";
	           cout<<"\t\tsallary            : "<<d.salary;cout<<"\n";
	           cout<<"\t\tDepartment         : "<<d.department;cout<<"\n";
	           cout<<"\t\tMobile Number      : "<<d.Mobilenumber;cout<<"\n";
	           cout<<"\t\t------------------------------------";cout<<"\n";
            }
            in.read((char*)&d, sizeof d);
        }
        in.close();
    }
    else
    {
        cout << "\t\tnot found" << endl;
    }
			continue;
		}		
		
        default:{
		if(choice>3 || choice<1)
		{cout<<"\t\tWrong choice"<<endl;}
        else{break;} 
			continue;
			}
			}
			}
		     while(choice!=3);
}
void DeletePRecord(){
  system("color 0F");
        cout<<endl<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t|        Delete     |"<<endl;
        cout<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t-------------------"<<endl;
    fstream in;
    in.open("Patient.txt", ios::in);
    fstream out;
    out.open("del.txt", ios::out);
    int id = 0;
    string person;
    cout<<"\t\tEnter Patient Last Name to Delete: ";
    cin >> person;
   
    if (in.is_open())
    {
        Patient p;

        in.read((char*)&p, sizeof p);
        while (!in.eof())
        {
            if (person != p.lname)
            {
                out.write((char*)&p, sizeof p);
            }
            in.read((char*)&p, sizeof p);

        }

        in.close();
        out.close();
        remove("Patient.txt");
        rename("del.txt", "Patient.txt");
        cout<<"\t\t->Record Deleted Xd<-";
    }
    else
    {
        cout << "\t\tnot found" << endl;
    }
}
void DeleteDRecord(){
   system("color 0F");
        cout<<endl<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t|        Delete     |"<<endl;
        cout<<"\t\t+-------------------+"<<endl;
        cout<<"\t\t-------------------"<<endl;
    fstream in;
    in.open("Doctor.txt", ios::in);
    fstream out;
    out.open("del.txt", ios::out);
    int id = 0;
    string person;
    cout<<"\t\tEnter Doctor Last Name to Delete: ";
    cin >> person;
   
    if (in.is_open())
    {
        Doctor d;

        in.read((char*)&d, sizeof d);
        while (!in.eof())
        {
            if (person != d.lname)
            {
                out.write((char*)&d, sizeof d);
            }
            in.read((char*)&d, sizeof d);

        }

        in.close();
        out.close();
        remove("Doctor.txt");
        rename("del.txt", "Doctor.txt");
        cout<<"\t\t->Record Deleted Xd<-";
    }
    else
    {
        cout << "\t\tnot found" << endl;
    }
}
int main(){
    system("color 0B");	
    base b1;
    int choice;

    main :
	cout<<"\t\t+----------------------------+"<<endl;
    cout<<"\t\t+ HOSPITAL MANAGEMENT SYSTEM +"<<endl;
    cout<<"\t\t+----------------------------+"<<endl;
    
    	cout<<"\n\t\tWelcome............"<<endl; 
		cout<<"\t\t-------------------"<<endl;
        cout<<"\t\t[1]-Enter Patients Department "<<endl;
        cout<<"\t\t[2]-Enter Doctors Department "<<endl;
        cout<<"\t\t[3]-Exit"<<endl;
        int c;
        cout<<"\t\t>>Enter choice: ";
        cin>>c;
        if(c==1){

    do	
		{
	    cout<<endl<<"\t\t-------------------"<<endl;
        cout<<"\t\t[1]-write to file"<<endl;
        cout<<"\t\t[2]-read from file"<<endl;
        cout<<"\t\t[3]-search for record "<<endl;
        cout<<"\t\t[4]-update some record"<<endl;
        cout<<"\t\t[5]-delete some record"<<endl;
        cout<<"\t\t[6]-go to the Main menu"<<endl;
        cout<<"\t\t[7]-Exit"<<endl;
        cout<<"\t\t>>Enter choice: ";
        

		cin>>choice;
      switch(choice)
	{
		case(1):
		{ writeP();
			break;
		}
		case(2):
		{ readP();
			break;
		}
		case(3):
		{ searchP();
			break;
		}
		case(4):
		{ UpdatePRecord();
			break;
		}
		case(5):
		{ DeletePRecord();
			break;
		}
		case(6):
		{ goto main ; 
			break;
		}

		case(7):
		{ 
		cout<<"\t\tThank you!";
		return 0;;
			break;
		}

			
	 default:{if(choice>7 || choice<1)
        {cout<<"\t\tWrong choice"<<endl;}
            else{continue;} break;}}
              	 }while(choice!=7);
			  
			  
		}else if(c==2){
		
			
	do	
	   {
	    cout<<endl<<"\t\t-------------------"<<endl;
        cout<<"\t\t[1]-write to file"<<endl;
        cout<<"\t\t[2]-read from file"<<endl;
        cout<<"\t\t[3]-search for record "<<endl;
        cout<<"\t\t[4]-update some record"<<endl;
        cout<<"\t\t[5]-delete some record"<<endl;
        cout<<"\t\t[6]-go to the Main menu"<<endl;
        cout<<"\t\t[7]-Exit"<<endl;
        cout<<"\t\t>>Enter choice: ";
        

		cin>>choice;
      switch(choice)
	{
		case(1):
		{ writeD();
			break;
		}
		case(2):
		{ readD();
			break;
		}
		case(3):
		{ searchD();
			break;
		}
		case(4):
		{ UpdateDRecord();
			break;
		}
		case(5):
		{ DeleteDRecord();
			break;
		}
		case(6):
		{ goto main; 
			break;
		}

		case(7):
			cout<<"\t\tThank you!";
		{ return 0;;
			break;
		}

			
	 default:{if(choice>7 || choice<1)
        {cout<<"\t\tWrong choice"<<endl;}
            else{continue;} break;}}
              	 }while(choice!=7);
			  
		}else if(c==3){
			cout<<"\t\tThank you!";
			return 0;
		}
		else
		cout<<"\t\twrong choise";
		
		
		
	return 0;
}

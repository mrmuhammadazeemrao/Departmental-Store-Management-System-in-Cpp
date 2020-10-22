#include <iostream>
#include <fstream>
#include  <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

//sare function jo hum ne use kia hen
void adminMenu();
void delete_item();
void update_item();
void display_all();
void search_item();
void  insert_item();
void AdminOPtion();
void sale_item();
void login(string& admin, string& password);
void Print_sale_record();
void sale_item();

int main()
{
	int error;
	string user,pass;
int a;//a login ke lia rakha he.

cout<<"\n\t\t  Welcome to General Store"<<endl <<"\t\t                   "<<endl<<"\t\t Note::Only Admin can delete things.\n";

cout<<"\n\t------------------------------------------------------------------\n\t----------------------------Please Select-------------------------\n\t------------------------------------------------------------------";
   do{

   	cout<<"\n\t 1:Admin log in.\n\t 2:Buy an item\n\t 3.Sell an item\n\t 0.Exit"<<endl;
   	cin>>a;
   	if(a>=0&&a<=4)
	   {
	   a=a;
	   }
   	   else{
   	   	cout<<"################################## wrong input please enter a valid input #############################";
		  }

		  switch(a){
		  	 case 1:
			   	{
					cout<<"\n\t Please enter Admin user name.";
					 cin>>user;
					cout<<"\n\t please Enter the password";
					cin>>pass;
					login(user,pass);
			   		} break;



			 case 2:
			 {
			 			for(int i=0 ; i<2 ; i++)
	{
		cout<<"Please wait, While File is loading.";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading..";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading...";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading....";
		Sleep(250);
		system("cls");
	}
		cout<<"\n\n\n************************You Are Going to buy items for the store***********************\n\n";
		insert_item();


	}break;

		  case 3:
		  	{


		  				 		 	for(int i=0 ; i<2 ; i++)
	{
		cout<<"Please wait, While File is loading.";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading..";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading...";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading....";
		Sleep(250);
		system("cls");
	}
			cout<<"\n\n\n\t\t\t---------You are in sell Menu-----------\n\n";
					sale_item();
			  }


   }
   }while(a!=0);
	system("CLS");











cout<<"\n************************************************************************************************\n************************************************************************************************\n*******************************Thanks for Choosing Store********************************\n************************************************************************************************\n************************************************************************************************\n";
}


void delete_item()
{

    fstream stud;
    fstream temp;

    stud.open("inventory.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char name [50];
    char qu[50];
    char id [50];
    char pr[50];
    char com[50];
    char date[50];
    char a[50];
    cin.ignore();
    cout<<" \n\t enter the id number to delete record : ";
    cin.getline(a,50);
    while(!stud.eof())
    {
        stud.getline(id,50,'|');
        stud.getline(name,50,'|');
        stud.getline(pr,50,'|');
        stud.getline(com,50,'|');
        stud.getline(qu,50,'|');
        stud.getline(date,50);
        if(strcmp(id,a)==0)
        {
        	
            continue;
        }
        else
        {
            temp<<id<<'|'<<name<<'|'<<pr<<'|'<<com<<'|'<<qu<<'|'<<date<<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("inventory.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(id,50,'|');
        temp.getline(name,50,'|');
        temp.getline(pr,50,'|');
        temp.getline(com,50,'|');
        temp.getline(qu,50,'|');
        temp.getline(date,50);
        stud<<id<<'|'<<name<<'|'<<pr<<'|'<<com<<'|'<<qu<<'|'<<date<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n\a";
}
void update_item()
{
    fstream stud;
    fstream temp;

    stud.open("inventory.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char name [50];
    char qu[50];
    char id [50];
    char pr[50];
    char com[50];
    char date[50];
    char a[50];
    cin.ignore();
    cout<<" \n\t enter the id number to update record : ";
    cin.getline(a,50);
    while(!stud.eof())
    {
        stud.getline(id,50,'|');
        stud.getline(name,50,'|');
        stud.getline(pr,50,'|');
        stud.getline(com,50,'|');
        stud.getline(qu,50,'|');
        stud.getline(date,50);
        if(strcmp(id,a)==0)
        {

            cout<<" \n\tenter new value of record  \n ";
            cout<<" \n id : ";
            cin.getline(id,50);
            cout<<" \n Name : ";
            cin.getline(name,50);
            cout<<" \n Price : ";
            cin.getline(pr,50);
            cout<<" \n Company: ";
            cin.getline(com,50);
            cout<<" \n Quantity : ";
            cin.getline(qu,50);
            cout<<" \n Date : ";
            cin.getline(date,50);
            temp<<id<<'|'<<name<<'|'<<pr<<'|'<<com<<'|'<<qu<<'|'<<date<<'\n';
        }
        else
        {
            temp<<id<<'|'<<name<<'|'<<pr<<'|'<<com<<'|'<<qu<<'|'<<date<<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("inventory.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(id,50,'|');
        temp.getline(name,50,'|');
        temp.getline(pr,50,'|');
        temp.getline(com,50,'|');
        temp.getline(qu,50,'|');
        temp.getline(date,50);
        stud<<id<<'|'<<name<<'|'<<pr<<'|'<<com<<'|'<<qu<<'|'<<date<<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
}
void display_all()
{
    char name [50];
    char qu[50];
    char id [50];
    char pr[50];
    char com[50];
    char date[50];

    fstream stud;
    stud.open("inventory.txt",ios::in);

    cout<< " \n\t id \t name \t pr \t com \t qu \t date \n";
    while(!stud.eof())
    {
        stud.getline(id,50,'|');
        stud.getline(name,50,'|');
        stud.getline(pr,50,'|');
        stud.getline(com,50,'|');
        stud.getline(qu,50,'|');
        stud.getline(date,50);
        cout<< "\n \t "<<id<<"\t\t"<<name<<"\t\t"<<pr<<"\t\t"<<com<<"\t\t"<<qu<<"\t\t"<<date<<endl;
	}
	stud.close();
	system("pause");
}
void search_item()
{

    fstream stud;
    stud.open("inventory.txt",ios::in);
    char name [50];
    char qu[50];
    char id [50];
    char pr[50];
    char com[50];
    char date[50];
    char a[50];
    cout<<" \n enter the id no to search about it : ";
    cin.ignore();
    cin.getline(a,50);
    int x=0;
    cout<< " \n\t id \t\t name\t\tproduct\t\tcompany\t\tamount\t\tdate \n";
    while(!stud.eof())
    {
    	stud.getline(id,50,'|');
        stud.getline(name,50,'|');
        stud.getline(pr,50,'|');
        stud.getline(com,50,'|');
        stud.getline(qu,50,'|');
        stud.getline(date,50);
    	if(strcmp(id, a)==0)
        {
            cout<< "\n \t "<<id<<"\t\t"<<name<<"\t\t"<<pr<<"\t\t"<<com<<"\t\t"<<qu<<"\t\t"<<date<<endl;
            x=1;
            break;
        }

    }
    if(x==0)
    {
        cout<<" \n not found !!!!\n";
    }
    system ("pause");
    stud.close();
}
//Inserting new items in inventory
void  insert_item()
{

    char name [50];
    char qu[50];
    char id [50];
    char pr[50];
    char com[50];
    char date[50];
    fstream stud;
    stud.open("inventory.txt", ios::app);
    cin.ignore();
    cout<<" \n Id no : ";
    cin.getline(id,50);
    cout<<" \n Name : ";
    cin.getline(name,50);
    cout<<" \n Price : ";
    cin.getline(pr,50);
     cout<<" \n Company : ";
    cin.getline(com,50);
     cout<<" \n Quantity : ";
    cin.getline(qu,50);
     cout<<" \n Date : ";
    cin.getline(date,50);
    stud<<id<<'|'<<name<<'|'<<pr<<'|'<<com<<'|'<<qu<<'|'<<date<<'\n';
    cout<< "done !";
    stud.close();
    system ("pause");
}


void adminMenu()		//admin ka main kam
{
	int sel,deletops,updateops,searchops;
	do{
		AdminOPtion();
		int error;
		do{
			 error = 0;
			cout<<"\n\n\t\tPlease Enter your selection: ";
			cin>>sel;
			if(cin.fail())
			{
				cout<<"Please enter a valid input: ";
				error=1;
				cin.clear();
				cin.ignore(80,'\n');

			};

		}while(error==1);


		switch(sel)
		{
			case 1:{sel=1;

			}break;
			case 2:{
				sel=2;
			}break;

			case 3:{
				sel=3;
			} break;
			case 4:{
				sel=4;
			} break;
			case 5: {
				sel=5;
			}break;
			case 6:{
				sel=6;
			} break;
			case 7:{
				sel=7;
			} break;
			
			case 0: {
				return; break;
			} break;
			default:cout<<"\n\t Invalid selection try again  ";
			Sleep(800);

		}
	if(sel==1)
	{
		insert_item();
	};






		if(sel==2)
		{
			do{
				delete_item();

				do{
					error=0;
					cout<<"\n\n\t Enter your selection";
					cin>>deletops;
					if(cin.fail())
					{
						cout<<"\n\t Please enter a valid number!!!!!!";
						error=1;
						cin.clear();
						cin.ignore(80,'\n');

					}

				}while(error==1);

				switch(deletops)
				{
					case 1:break;
					case 2:break;
					case 3 :break;
					case 4: break;
					case 0: break;
					default: cout<<"\n\t Please enter a correct number!!!!!! Try again....";



				}

			}while(deletops!=0);
		}


	if(sel==3)
	{
		display_all();
	}


		if(sel==4)
		{
					 			for(int i=0 ; i<2 ; i++)
	{
		cout<<"Please wait, While File is loading.";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading..";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading...";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading....";
		Sleep(250);
		system("cls");
	}
			search_item();
		}
			if(sel==5)
		{
					 			for(int i=0 ; i<2 ; i++)
	{
		cout<<"Please wait, While File is loading.";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading..";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading...";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading....";
		Sleep(250);
		system("cls");
	}
			update_item();

		};

		if(sel==6)
		{
									for(int i=0 ; i<2 ; i++)
	{
		cout<<"Please wait, While File is loading.";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading..";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading...";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading....";
		Sleep(250);
		system("cls");
	}
		cout<<"\n\n\n\t\t\t---------Total bought items are----------";

		Print_sale_record();

		}

			if(sel==7)
			{
							 			for(int i=0 ; i<2 ; i++)
	{
		cout<<"Please wait, While File is loading.";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading..";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading...";
		Sleep(250);
		system("cls");
		cout<<"Please wait, While File is loading....";
		Sleep(250);
		system("cls");
	}

				cout<<"\n\n\n\t\t\t---------Total bought items are----------";
				display_all();

			}

		

	}while(sel!=0);
}


void AdminOPtion()							//ADMIN ke haq
{
	cout<<"Loading Admin Menu.";
	Sleep(200);
	system("cls");
	cout<<"\t\tWelcome to the Control Menu of the store\a";
	cout<<"\n\n============= ============ =============== ============ ===============";
	cout<<"\n\t1 : Add New Item.  ";
	cout<<"\n\t2 : Delete an Item. ";
	cout<<"\n\t3 : Display All Items.";
	cout<<"\n\t4 : Search An Item in the Store.";
	cout<<"\n\t5 : Update an item.";
	cout<<"\n\t6 : Check total items sold.";
	cout<<"\n\t7 : Check total item bought.";
	cout<<"\n\t0 : Return To the main menu";
	}

	void Print_sale_record()
{
    char name [50];
    char qu[50];
    char id [50];
    char pr[50];
    char com[50];
    char date[50];

    fstream stud;
    stud.open("sale_record.txt",ios::in);

    cout<< " \n\t id \t\t name \t\t pr \t\t com \t\t qu \t\t date\n";
    while(!stud.eof())
    {
        stud.getline(id,50,'|');
        stud.getline(name,50,'|');
        stud.getline(pr,50,'|');
        stud.getline(com,50,'|');
        stud.getline(qu,50,'|');
        stud.getline(date,50);
        cout<< "\n \t "<<id<<"\t\t"<<name<<"\t\t"<<pr<<"\t\t"<<com<<"\t\t"<<qu<<"\t\t"<<date<<endl;

    }
    system("pause");
}

	void sale_item()
{
	fstream stud;
	fstream temp;
	fstream record;
	stud.open("inventory.txt",ios::in);
	record.open("sale_record.txt",ios::app|ios::out);
	char id[50],a[50],name[50],pr[50],com[50],date[50],qua[50];
	char qu[50];
	int bill;
	int bill1;
	int bill2;
	cin.ignore();
	cout<<"Enter the id of the item: ";
	cin.getline(a,50);
	while (!stud.eof())
	{
		stud.getline(id,50,'|');
		stud.getline(name,50,'|');
		stud.getline(pr,50,'|');
		stud.getline(com,50,'|');
		stud.getline(qu,50,'|');
		stud.getline(date,50);
		if(strcmp(id,a)==0)
		{
			cout<<"Record found\nEnter quantity: ";
			cin.getline(qua,50);
			cout<<"Enter Date: ";
			cin.getline(date,50);
			cout<<"\t\tId: "<<id<<endl;
			cout<<"\t\tName: "<<name<<endl;
			cout<<"\t\tPrice: "<<pr<<endl;
			cout<<"\t\tCompany: "<<com<<endl;
			cout<<"\t\tQuantity: "<<qua<<endl;
			cout<<"\t\tDated: "<<date<<endl;
			record<<id<<'|'<<name<<'|'<<pr<<'|'<<com<<'|'<<qua<<'|'<<date<<'\n';
				
			
		
		}
		
		
		
	}
	stud.close();
	record.close();
}

	void login(string& admin, string& password)
{ string user[200];

  	string pass[200];
  	bool valid=true;
  	int test=0;
  	int x=0;
  	ifstream read;
  	read.open("admin.txt");
  	while(!read.eof())
  	{    if(x>=200)
  	{
  			break;
	  }
  		read>>user[x]>>pass[x];
  		x++;

	  }
	  for(int i=0;i<x;i++)
	  {
	  	if(admin ==user[i] && password==pass[i])
	  	{ 	for(int i=0 ; i<2 ; i++)
	{
		cout<<"Please wait, While File is loading.";
		Sleep(200);
		system("cls");
		cout<<"Please wait, While File is loading..";
		Sleep(200);
		system("cls");
		cout<<"Please wait, While File is loading...";
		Sleep(200);
		system("cls");
		cout<<"Please wait, While File is loading....";
		Sleep(200);
		system("cls");
	}
	  		cout<<"Logged in successfully";
	  		test=1;
	  		valid=true;
	  		while(valid==true)
	  		{
	  			 adminMenu();
			  }
	  		break;
		  }
	  }

  	if(!valid || test==0)
  	{
  		cout<<"\n\t\a please enter correct user name and password\n";
  		system("pause");
	  }

	}






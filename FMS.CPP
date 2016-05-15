#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<windows.h>
using namespace std;

class data
{
	char company[10],features[255],modelno[10];
	int stock;
	long int price;
	public:
		void input();
		void input_fp();
		void show();
		void in_stock(int ta);
		void show_stock();
		int ret_stock();
		long int ret_price();
		char* ret_company();
		char* ret_modelno();
};
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void create();
void update();
void add();
void del();
void search_modelno();
void search_budget();
void search_company();
void sell_handset();
void add_handset();
void showall();
void border();
void border_logo();
void border2();

void data::input()
{
	cout<<"Enter The Cell Phone's Manufacturer: ";gets(company);
	cout<<"Enter Model No.: ";gets(modelno);
	cout<<"Enter The Price: ";cin>>price;
	cout<<"Enter a Description about the Phone's Features: ";gets(features);
	cout<<"Enter the total stock: ";cin>>stock;
}
void data::input_fp()
{
	cout<<"Re-enter the Features: ";gets(features);
	cout<<"Re-enter Price: ";cin>>price;
}
void data::show()
{
	cout<<"Manufacturer: "<<company<<endl;
	cout<<"Model No.: "<<modelno<<endl;
	cout<<"Price: Rs."<<price<<endl;
	cout<<"Features: "<<features<<endl;
	cout<<"In Stock: "<<stock<<endl;
}
void data::show_stock()
{
	cout<<"No. of handsets in store: "<<stock;
}
int data::ret_stock()
{
	return stock;
}
void data::in_stock(int ta)
{
	stock=stock+ta;
}
char* data::ret_company()
{
	return company;
}
char* data::ret_modelno()
{
	return modelno;
}
long int data::ret_price()
{
	return price;
}
void create()
{
	system("cls");
	data d;
	fstream file;
	int n;
	border2();
	cout<<"Enter the no. of records you want to create: ";cin>>n;
	file.open("data.dat",ios::out|ios::binary);
	for (int i=1;i<=n;i++)
	{
		cout<<"\n"<<i<<":"<<endl;
		d.input();
		cout<<endl;
		file.write((char*)&d,sizeof(d));
	}
	file.close();
}
void add()
{
	system("cls");
	data d;
	fstream file;
	int n;
	border2();
	cout<<"Enter the no. of records you want to add on to the database: ";cin>>n;
	file.open("data.dat",ios::app|ios::binary);
	for (int i=1;i<=n;i++)
	{
		cout<<"\n"<<i<<":"<<endl;
		d.input();
		cout<<endl;
		file.write((char*)&d,sizeof(d));
	}
	file.close();
}
void update()
{
	system("cls");
	data d;
	char tmno[10];
	int f=0,n,k;
	fstream file,tfile;
	border2();
	cout<<"Enter Existing Model No. To Make Changes To Its Details: ";
	cout<<"\n(Entering Non Existing Model No. will Redirect you to 'Add Record' Option)"<<endl;
	gets(tmno);
	file.open("data.dat",ios::in|ios::binary);
	while(file)
	{
		file.read((char*)&d,sizeof(d));
		if(file.eof())
			break;
		if (strcmp(d.ret_modelno(),tmno)==0)
		{
			f=1;
		}
	}
	file.close();
	if (f==1)
	{
	      file.open("data.dat",ios::in|ios::binary);
	      tfile.open("tdata.dat",ios::out|ios::binary);
	      while(file)
	      {
			file.read((char*)&d,sizeof(d));
			if(file.eof())
				break;
			if (strcmp(d.ret_modelno(),tmno)==0)
			{
				cout<<"\nFound.\n"<<endl;
				d.show();
				cout<<endl;
				d.input_fp();
			}
			tfile.write((char*)&d,sizeof(d));
	      }
	      file.close();
	      tfile.close();
	      remove("data.dat");
	      rename("tdata.dat","data.dat");
       }
       else
       {
		cout<<"\nModel Not Found, Creating new record\n"<<endl;
		add();
       }
}
void search()
{
	system("cls");
	char ch='1';
	while((int)ch<52&&(int)ch>48)
	{
		system("cls");
		border();
		gotoxy(32,1);cout<<"----------------"<<endl;
		gotoxy(32,2);cout<<"THE MOBILE STORE"<<endl;
		gotoxy(32,3);cout<<"----------------"<<endl;
		gotoxy(26,7);cout<<"1. Search on basis of budget"<<endl;
		gotoxy(26,8);cout<<"2. Search Model No."<<endl;
		gotoxy(26,9);cout<<"3. Search Manufacturer "<<endl;

		gotoxy(26,12);cout<<"Any other key: Go Back"<<endl;

		gotoxy(26,14);cout<<" Your Choice: ";
		ch=getchar();
		switch((int)ch)
		{
			case 49: search_budget();break; //here 49 stands for '1' in the ascii table
			case 50: search_modelno();break;
			case 51: search_company();break;
		}
	}
}
void search_modelno()
{
	system("cls");
	data d;
	fstream file;
	char n[10];
	int f;
	border2();
	cout<<"Enter Model No. of the Phone: ";gets(n);
	file.open("data.dat",ios::in|ios::binary);
	while(file)
	{
		file.read((char*)&d,sizeof(d));
		if (file.eof())
		{
			if (f==1)
				cout<<"\nEnd of database\nPress any key to go back";
			else
				cout<<"\nModel Not Found\nPress any key to go back";
			border_logo();
			getchar();
			break;
		}
		if (strcmp(n,d.ret_modelno())==0)
		{
			system("cls");
			border2();
			f=1;
			cout<<"\n";
			d.show();
			getchar();
		}
	}
	file.close();
}
void search_budget()
{
	system("cls");
	data d;
	fstream file;
	long int b;
	border2();
	cout<<"Enter a Budget: ";cin>>b;
	file.open("data.dat",ios::in|ios::binary);
	while(file)
	{
		file.read((char*)&d,sizeof(d));
		if (file.eof())
		{
			cout<<"\n\nEnd of database";
			border_logo();
			getchar();
			break;
		}
		if (d.ret_price()<=b)
		{
			system("cls");
			border2();
			cout<<"\nBudget: "<<b<<"\n\n";
			d.show();
			cout<<"\nPress any key to continue";
			getchar();
		}
	}
	file.close();
}
void search_company()
{
	system("cls");
	data d;
	fstream file;
	char c[10];
	border2();
	cout<<"Enter a Manufacturer/Company: ";gets(c);
	file.open("data.dat",ios::in|ios::binary);
	while(file)
	{
		file.read((char*)&d,sizeof(d));
		if (file.eof())
		{
			cout<<"\nEnd of Database\nPress any key to return to main menu";
			border_logo();
			getchar();
			break;
		}
		if (strcmp(c,d.ret_company())==0)
		{
			system("cls");
			border2();
			cout<<"\n";
			d.show();
			cout<<"\nPress any key to continue\n";
			getchar();
		}
	}
	file.close();
}
void del()
{
	system("cls");
	data d;
	fstream file,tfile;
	char l[10];
	int f=1;
	file.open("data.dat",ios::in|ios::binary);
	tfile.open("tdata.dat",ios::out|ios::binary);
	border2();
	cout<<"Enter a Model No.to Discontinue sales of(Delete its Record): "; gets(l);
	while(file)
	{
		file.read((char*)&d,sizeof(d));
		if(file.eof())
		{
			break;
		}
		if(strcmp(l,d.ret_modelno())==0)
		{
			f=-1;
		}
		else
		{
			tfile.write((char*)&d,sizeof(d));
		}

	}
	if(f==-1)
	{
		cout<<"\n\nFileDeleted\nPress any key to go back";
	}
	else
	{
		cout<<"\n\nModel not found\nPress any key to go back";
	}
	file.close();
	tfile.close();
	remove ("data.dat");
	rename ("tdata.dat","data.dat");
	border_logo();
	getchar();
}
void sell_handset()
{
	system("cls");
	data d;
	fstream file,tfile;
	int h,l,f=0;
	char n[10];
	border2();
	cout<<"Enter model no.: ";gets(n);
	file.open("data.dat",ios::in|ios::binary);
	tfile.open("tdata.dat",ios::out|ios::binary);
	while(file)
	{
		file.read((char*)&d,sizeof(d));
		if (file.eof())
		{
			break;
		}
		if (strcmp(n,d.ret_modelno())==0)
		{
			f=1;
			do
			{
				border2();
				d.show_stock();
				cout<<"\n\nEnter the no. of handsets sold: ";cin>>h;
				l=1;
				if (h>d.ret_stock())
				{
					cout<<"\nYou are selling more than the available no. of handsets"<<endl;
					cout<<"\nPress any key to Re-Enter\n";
					getchar();
					system("cls");
					l=0;
				}
				else
				{
					h=-1*h;
					d.in_stock(h);
					cout<<"\nHandset Sold \nNew Stock:";
					cout<<d.ret_stock()<<"\n Press any key to return to main menu";
					border_logo();
					getchar();
					break;
				}
			}while(l==0);
		}
		tfile.write((char*)&d,sizeof(d));
	}
	if (f==0)
	{
		cout<<"\n\nModel not found\nPress any key to go back";
		border_logo();
		getchar();
	}
	file.close();
	tfile.close();
	remove("data.dat");
	rename("tdata.dat","data.dat");
}
void add_handset()
{
	system("cls");
	data d;
	fstream file,tfile;
	int h,l,f=0;
	char n[10];
	border2();
	cout<<"Enter model no.: ";gets(n);
	file.open("data.dat",ios::in|ios::binary);
	tfile.open("tdata.dat",ios::out|ios::binary);
	while(file)
	{
		file.read((char*)&d,sizeof(d));
		if (file.eof())
		{
			break;
		}
		if (strcmp(n,d.ret_modelno())==0)
		{
			f=1;
			system("cls");
			border2();
			do
			{
				d.show_stock();
				cout<<"\n\nEnter the no. of handsets bought: ";cin>>h;
				l=1;
				if(h<0) //if by mistake negative value is entered...
				{
					cout<<"\nPlease enter again, press any key"<<endl;
					getchar();
					system("cls"); border2();
					l=0;
				}
				else
				{
					d.in_stock(h);
					cout<<"\nHandsets Bought\nNew Stock:"<<d.ret_stock();
					cout<<"\n\nPress any key to return to main menu";
					border_logo();
					getchar();
					break;
				}
			}while(l==0);
		}
		tfile.write((char*)&d,sizeof(d));
	}
	if (f==0)
	{
		cout<<"\n\nModel not found\nPress any key to go back";
		border_logo();
		getchar();
	}
	file.close();
	tfile.close();
	remove("data.dat");
	rename("tdata.dat","data.dat");
}
void showall()
{
	system("cls");
	data d;
	fstream file;
	file.open("data.dat",ios::in|ios::binary);
	while(file)
	{
		file.read((char*)&d,sizeof(d));
		if(file.eof())
		{
			cout<<endl;
			cout<<"End of Database\nPress any key to get back to main menu"<<endl;
			border_logo();
			break;
		}
		system("cls");
		border2();
		cout<<"\n\n";
		d.show();
		cout<<"\nPress any key to continue"<<endl;
		getchar();

	}
	file.close();
	getchar();
}
void border()
{
	int i,j;
	for(i=24;i<56;i++)
	{
		gotoxy(i,4);
		cout<<(char)196;
		gotoxy(i,25);
		cout<<(char)196;
	}
	for(j=5;j<25;j++)
	{
		gotoxy(24,j);
		cout<<(char)179;
		gotoxy(56,j);
		cout<<(char)179;
	}
	gotoxy(24,4);cout<<(char)218;
	gotoxy(56,25);cout<<(char)217;
	gotoxy(24,25);cout<<(char)192;
	gotoxy(56,4);cout<<(char)191;

	for(i=26;i<55;i++)
	{
		gotoxy(i,6);
		cout<<(char)196;
		gotoxy(i,22);
		cout<<(char)196;
	}
	for(j=7;j<22;j++)
	{
		gotoxy(25,j);
		cout<<(char)179;
		gotoxy(55,j);
		cout<<(char)179;
	}
	gotoxy(25,6);cout<<(char)218;
	gotoxy(25,22);cout<<(char)192;
	gotoxy(55,6);cout<<(char)191;
	gotoxy(55,22);cout<<(char)217;
	gotoxy(38,5);cout<<(char)205<<(char)205<<(char)205<<(char)205<<endl;

	gotoxy(39,23);cout<<(char)218;
	gotoxy(40,23);cout<<(char)196;
	gotoxy(39,24);cout<<(char)192;
	gotoxy(40,24);cout<<(char)196;
	gotoxy(41,23);cout<<(char)191;
	gotoxy(41,24);cout<<(char)217;

	for(i=2;i<30;i++)
	{
		gotoxy(i,1);cout<<(char)196;
	}
	for(i=4;i<30;i++)
	{
		gotoxy(i,2);cout<<(char)196;
	}
	for(i=1;i<22;i++)
	{
		gotoxy(i,24);cout<<(char)196;
	}
	for(i=4;i<22;i++)
	{
		gotoxy(i,23);cout<<(char)196;
	}
	for(i=50;i<80;i++)
	{
		gotoxy(i,1);cout<<(char)196;
	}
	for(i=50;i<78;i++)
	{
		gotoxy(i,2);cout<<(char)196;
	}
	for(i=59;i<80;i++)
	{
		gotoxy(i,24);cout<<(char)196;
	}
	for(i=59;i<78;i++)
	{
		gotoxy(i,23);cout<<(char)196;
	}
	for(j=2;j<24;j++)
	{
		gotoxy(1,j);cout<<(char)179;
		gotoxy(80,j);cout<<(char)179;
	}
	for(j=3;j<23;j++)
	{
		gotoxy(3,j);cout<<(char)179;
		gotoxy(78,j);cout<<(char)179;
	}

	gotoxy(1,1);cout<<(char)218;
	gotoxy(80,1);cout<<(char)191;
	gotoxy(1,24);cout<<(char)192;
	gotoxy(80,24);cout<<(char)217;
	gotoxy(30,1);cout<<(char)191;
	gotoxy(30,2);cout<<(char)217;
	gotoxy(3,2);cout<<(char)218;
	gotoxy(78,2);cout<<(char)191;
	gotoxy(49,1);cout<<(char)218;
	gotoxy(49,2);cout<<(char)192;
	gotoxy(58,24);cout<<(char)192;
	gotoxy(58,23);cout<<(char)218;
	gotoxy(22,24);cout<<(char)217;
	gotoxy(22,23);cout<<(char)191;
	gotoxy(3,23);cout<<(char)192;
	gotoxy(78,23);cout<<(char)217;
}

void border_logo()
{
	int i,j;
	cout<<endl;
	cout<<endl;
	for(i=64;i<80;i++)
	{
		gotoxy(i,22); cout<<(char)196;
		gotoxy(i,24); cout<<(char)196;
	}
	gotoxy(63,23); cout<<(char)179;
	gotoxy(80,23); cout<<(char)179;
	gotoxy(63,22); cout<<(char)218;
	gotoxy(63,24); cout<<(char)192;
	gotoxy(80,22); cout<<(char)191;
	gotoxy(80,24); cout<<(char)217;

	gotoxy(64,23); cout<<"THE MOBILE STORE";
}
void border2()
{
	for(int i=1;i<=80;i++)
	{
		gotoxy(i,1);
		cout<<(char)205;
		gotoxy(i,2);
		cout<<(char)247;
		gotoxy(i,3);
		cout<<(char)205;
	}

}

int main()
{
	system("cls");


	int i,j,l=0;
	char ch='1';
	while((int)ch<57&&(int)ch>47)
	{
	do
	{
		system("cls");
		border();
		gotoxy(32,1);cout<<"----------------"<<endl;
		gotoxy(32,2);cout<<"THE MOBILE STORE"<<endl;
		gotoxy(32,3);cout<<"----------------"<<endl;
		gotoxy(26,7);cout<<"1. Enter Record"<<endl;
		gotoxy(29,8);cout<<"(^formats existing data)"<<endl;
		gotoxy(26,9);cout<<"2. Update Record"<<endl;
		gotoxy(26,10);cout<<"3. Add Record"<<endl;
		gotoxy(26,11);cout<<"4. Delete Record"<<endl;
		gotoxy(26,13);cout<<"5. Search "<<endl;
		gotoxy(26,15);cout<<"6. Add Handset/Model"<<endl;
		gotoxy(26,16);cout<<"7. Sell Handset/Model"<<endl;
		gotoxy(26,18);cout<<"8. Show All Models"<<endl;
		gotoxy(26,19);cout<<"0. Exit Program"<<endl;
		gotoxy(26,21);cout<<" Your Choice: ";
		ch=getchar();
		switch((int)ch)
		{
			case 49: create();break;
			case 50: update();break;
			case 51: add();break;
			case 52: del();break;
			case 53: search();break;
			case 54: add_handset();break;
			case 55: sell_handset();break;
			case 56: showall();break;
			case 48: exit(0);break;
			default: l=1;break;
		}
	}while(l==1);
	}
	return 0;
}

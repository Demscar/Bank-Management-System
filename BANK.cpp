#include<iostream.h>
#include<stdio.h> 			//For return and remove functions
#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<iomanip.h>			//For data manipulation
#include<string.h>
class account
{
	int acno;
	char name[50];
	long int deposit;
	char type;
public:
	void create_account();
	void show_account() const;
	void modify();
	void dep(int);
	void draw(int);
   void credits();
   void help();
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
};

void help()
{

         cout<<"\n\n\t\t\tWelcome to Bank of Hindostan\n\nGood Day Sir/Mam,\n\tMy name is Cortana and I am the AI designed by JUGGADU Pvt. Inc..Below,I will explain each of the options on the main screen:-\n\n\n1.This option is for those users who need to open new account in our bank.\n\n2.Deposit option provides a safer and easier way to deposit money to your account with latest 256bit payment Gateway.\n\n3.Withdraw option provides a safer and easier way to withdraw money from your account with latest 256bit payment Gateaway.\n\n4.Balance Enquiry is accessible to all those who have your account no. so keep it a secret.\n\n5.This option enables you to get access to all the database and get information of each account holder.\n\n6.Enter the account no, and WOOSH!!!!!, its deleted.\n\n\t\tFor online support press enter";
         getch();
         clrscr();
         cout<<"Connecting to Online Support\n\nPress Enter For force connection or in case not connected to online support";
         getch();
         clrscr();
         cout<<"It seems we are facing some technical issues with the server bridge....\n\t\tPress Enter To Continue";
         getch();
         clrscr();
         cout<<"\t\t\nREDIRECTING TO MAIN MENU.............";
}
void account::create_account()
{
	clrscr();
	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>acno;
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<"\n\n\t\t\tAccount Created..";
}

void account::show_account() const
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}

void credits()
{
	clrscr();
   cout<<"\n\nThe Project is a result of dedication of someone and someone 2.0";
   getch();
}

void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}

int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}



void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);

int main()
{
	int num,ch;
	do
	{
	clrscr();
	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\t   BANK OF HINDOSTAN\n\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";

		cout<<"\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t 1. NEW ACCOUNT";
		cout<<"\n\t\t\t\t 2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t 3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t 4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t 5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t\t 6. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t\t 7. MODIFY AN ACCOUNT";
      		cout<<"\n\t\t\t\t 8. HELP";
		cout<<"\n\t\t\t\t 9. CREDITS";
      		cout<<"\n\t\t\t\t10. Exit";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-10): ";
		cin>>ch;

		switch(ch)
		{
		case 1:
			write_account();
			break;
		case 2:
			clrscr();
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case 3:
			clrscr();
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case 4:
			clrscr();
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case 5:
			display_all();
			break;
		case 6:
			clrscr();
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case 7:
		 	clrscr();
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
       case 8:
       	clrscr();
         help();
         break;
       case 9:
       	clrscr();
         credits();
         break;
		 case 10:
{		 	clrscr();
			cout<<"\n\n\t\t\tThanks for using Bank Of Hindostan";
			break;
}
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!=10);
	return 0;
}


void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
}



void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}



void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\nRecord Deleted ..";
}


void display_all()
{
	clrscr();
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME         Type    Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}


void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}

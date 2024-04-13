#include<iostream>
using namespace std;
class Account
{
	private:
	char Cust_Name[20];
	long int Acc_No;
	public:
	long int Balance;
	int Time;
	int Acc_Details()    // Method inherited
	{
		cout<<"\n Enter Customer Name: ";
		cin>>Cust_Name;
		cout<<"\n Enter Account Number: ";
		cin>>Acc_No;
	}
	int Display()       // Method overriding
	{
		cout<<"\n\t Account Holder Name:- "<<Cust_Name;
		cout<<"\n\t Account Number:- "<<Acc_No;
	}
};
class Current_Account:public Account
{
	public:
	int Acc_Bal()      // Method overriding
	{
		cout<<"\n Enter Account Balance: Rs";
		cin>>Balance;
	}
	int Display()      //Method overriding
	{
		Account::Display();      // Method overriding calling through class name
		cout<<"\n\t Current Balance:- Rs"<<Balance;
	}
	int Deposit()      //Method hiding
	{
		float deposit;
		cout<<"\n Current Balance: Rs"<<Balance;
		cout<<"\n Enter Amount to Deposit: Rs";
		cin>>deposit;
		Balance=Balance+deposit;
		cout<<"\n     DEPOSIT SUCCESSFUL";
		cout<<"\n Balancce Amount After Deposit: Rs"<<Balance;
	}
	int Withdraw()      //Method overriding
	{
		float withdraw;
		cout<<"\n Current Balance: Rs"<<Balance;
		cout<<"\n Enter Amount to be withdraw: Rs";
		cin>>withdraw;
		if(Balance>1000)
		{
			Balance=Balance-withdraw;
			cout<<"\n     WITHDRAWL SUCCESSFUL";
			cout<<"\n Balance Amount after withdraw: Rs"<<Balance;
		}
		else
		cout<<"\n INSUFFICIENT BALANCE CANNOT WITHDRAW";
	}
};
class Saving_Account:public Account
{
	public:
	int Acc_Bal()       // Method overriding
	{
		cout<<"\n Enter Account Balance: Rs";
		cin>>Balance;
	}
	int Display()       // Method overriding
	{
		Account::Display();   // Method overriding calling through class name
		cout<<"\n\t Current Balance:- Rs"<<Balance;
	}
	int Deposit(int interest)      // Method hiding
	{
		float deposit,int_amt;
		cout<<"\n Current Balance: Rs"<<Balance;
		cout<<"\n Enter Amount to Deposit: Rs";
		cin>>deposit;
		if(Balance>=100000)
		{
			if(deposit>=50000)
			{
				interest=6;
				Time=3;
			}
			else if(deposit>=30000 && deposit<50000)
			{
				interest=3;
				Time=2;
			}
			else
			{
				interest=2;
				Time=1;
			}
			Balance+=(Balance*interest*Time)/12+deposit;
			cout<<"\n Balancce Amount After Deposit with interest: Rs"<<Balance;
		}
		else
		{
			Balance=Balance+deposit;
			cout<<"\n Balance Amount After Deposit: Rs"<<Balance;
		}
		cout<<"\n     DEPOSIT SUCCESSFUL";
	}
	int Withdraw()       // Method overriding
	{
		float withdraw;
		cout<<"\n Current Balance: Rs"<<Balance;
		cout<<"\n Enter Amount to be withdraw: Rs";
		cin>>withdraw;
		if(Balance>500)
		{
			Balance=Balance-withdraw;
			cout<<"\n     WITHDRAWL SUCCESSFUL";
			cout<<"\n Balancce Amount After Withdraw: Rs"<<Balance;
		}
		else
		cout<<"\n INSUFFICIENT BALANCE CANNOT WITHDRAW";
	}
};
int main()
{
	system("cls");
	Current_Account obj1;
	Saving_Account obj2;
	int interest;
	int choice;
	char Acc_type;
	cout<<"\n Enter 'S' for Saving customer and 'C' for Current Account customer: ";
	cin>>Acc_type;
	Acc_type=toupper(Acc_type);
	if(Acc_type=='C')
	{
		obj1.Acc_Details();    // Method inherited
		obj1.Acc_Bal();        // Method overriding
	}
	else
	if(Acc_type=='S')
	{
		obj2.Acc_Details();    // Method inherited
		obj2.Acc_Bal();        // Method overriding
	}
	while(1)
	{
		cout<<"\n Choose your choice";
		cout<<"\n 1. Deposit";
		cout<<"\n 2. Withdraw";
		cout<<"\n 3. Display Customer Details";
		cout<<"\n 4. EXIT";
		cout<<"\n Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			if(Acc_type=='C')
			{
				system("cls");
				obj1.Deposit();       // Method hiding
			}
			else
			if(Acc_type=='S')
			{
				system("cls");
				obj2.Deposit(interest);       // Method hiding
			}
			break;
			case 2:
			if(Acc_type=='C')
			{
				system("cls");
				obj1.Withdraw();     // Method overriding
			}
			else
			if(Acc_type=='S')
			{
				system("cls");
				obj2.Withdraw();     // Method overriding
			}
			break;
			case 3:
			system("cls");
			cout<<"\n \t\t\t--------------------------------";
			cout<<"\n \t\t\t>    BANK CUSTOMER'S DETAILS   <";
			cout<<"\n \t\t\t--------------------------------\n";
			cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n\n";
			if(Acc_type=='C')
			{
				obj1.Display();   //  Method overriding
			}
			else
			if(Acc_type=='S')
			{
				obj2.Display();   // Method overriding
			}
			cout<<"\n\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
			cout<<"\n\n\t\t      >------------Thanku :)------------<\n\n";
			break;
			case 4:
			exit(0);  break;
			default:
			system("cls");
			cout<<"\n Entered choice is invalid";
		}
	}
	return 0;
}


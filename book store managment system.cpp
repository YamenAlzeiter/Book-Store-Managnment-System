#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<stdlib.h>
#include <sstream>
#include<cstdio>
using namespace std;

//function prototype
void main_menu();//function to display the main menu
void manager_menu();//function that display the manager menu
void show_library();//function that display the book that inside database.txt
void add_book();//function for adding books to database.txt
void delete_book();//function that delet book from database.txt
void show_total();//function that store and display the total money made from selling books in total.txt
void search_book();//function that make a search inside database.txt
void sell_book();//function that search and sell a book exist in database.txt
void quantity_counter(string*,int*);//function that update the quantity for a book recently sold in database.txt
void rent_book();//funtion that search in database.txt allow user to rent a book
void quantity_rent_counter(string*);//function that update the quantity for a book recntly rented in database.txt
void total_1(double);//funtion that read the data inside total.txt and combime them,dispay the total
void edit_book();//function that allow manager to edit a book in database.txt
string check_ID(string);//function that check if the entered book ID already exist
int counter_row(int);//function that count the rows of database.txt
int input_check(int);//function that check if int input is a number


//structure intilazation
struct data
{
	string ID;
	string title;
	string author;
	string category;
	int quantity;
	int quantitly_rent;
	int price;
};


const int row=0;

int main()
{	
 	int choice, manager_choice;
	main_menu();//calling the funtion to dispay
	choice=input_check(choice);//calling the function
	
	while(choice!=0)
	{
		switch (choice)
		{
			case 1://manager mode
			{
				 manager_menu();//calling the function to display the menu
				 manager_choice=input_check(manager_choice);//calling the function to check if input integer
				 while(manager_choice != 0)
				 {
				 	switch (manager_choice)
				 	{
				 		case 1://add book
							add_book();	//calling the function to start adding books			 					
						 	break;
				 		case 2://delete book
				 			delete_book();//calling the function to delete a book
						 	break;
				 		case 3://edit book
				 			edit_book();//calling the function to start editing book
						 	break;
						case 4://show total money made
							show_total();//calling the function to display the total money made
							break;
				 	}
				 	
				 manager_menu();//calling the function to display the manager  menu
				 manager_choice=input_check(manager_choice);//check if manager choice is integer
				 }
			system("CLS");	 
			break;
			}
			case 2://display library
				show_library();//calling the function to display the library
				system("pause");
				break;
			case 3://search
				search_book();	//calling a function that do search
				break;
			case 4://sell
				sell_book();//calling a function to selling books
				break;	
			case 5://rent 
				rent_book();//calling a function to start renting books 
				break;			
		}
		main_menu();//calling the function to display the main menu
		choice=input_check(choice);//check if choice is integer
	}
}

void main_menu()//function to print the menu
{
system("CLS");//clean screan
		cout<<"\n\n\t\t\t\t * * * * * * * * Welecome to Bookstore * * * * * * * *";
			cout<<"\n\n\t main menu";
				cout<<"\n\t"<<setfill('-')<<setw(20)<<" ";
			cout<<"\n\t1. Manager mode\n\t2.show all books\n\t3. search for a book\n\t4. buy a book\n\t5. barrow a book\n\t0. Exit";
		cout<<"\n\nplease enter your choice: ";
}

int input_check(int input)
{
	
		int error=0;
		cin>>input;
		do
		{
			if(cin.fail())//the input not integer
			{
				cout<<"\ninvalid input,please enter a valid one.\n\tenter integer number: ";
				error=1;
				cin.clear();
				cin.ignore(80,'\n');
				cin>>input;
			}
			else
			 
			return input;
			
		}while (error == 1);
}

void manager_menu()//print the manager menu
{
	system("CLS");
		cout<<"\n\n\tmanager mode\n";
			cout<<"\t"<<setfill('*')<<setw(12)<<" ";
				cout<<"\n\n\t1. Add a book\n\t2. Delete a book\n\t3. Edit a book\n\t4. show total sell\n\t0. Back";
					cout<<"\n\nplease rnter your choice: ";
}

int counter_row(int ROW)//count the number of rows
{
	ROW = row;
	string item;
ifstream indata;
indata.open("database.txt");//open database.txt
	while(!indata.eof())
	{ 
		indata>>item;
		ROW++;
	}
indata.close();
	ROW/=7;//7 is the number of colums
return ROW;
}

void add_book()
{
	system("CLS");
	int counter;
		counter=counter_row(row);//calling the function to counter row
		counter+=1;//add one to the number of row 
		data library[counter];	
ifstream indata;//to read from a file
indata.open("database.txt");
ofstream outdata;//to write on a file
outdata.open("database.txt",ios::app);	
	if(!indata.fail())//check if the text file open or not
	{
	for(int i=counter-1;i<counter;i++)//start adding the book
	{	
	cin.ignore();
	cout<<"\n\tenter the book ID: ";
		library[i].ID=check_ID(library[i].ID);
		outdata<<"\n"<<library[i].ID<<"\t";
			cout<<"\n\tenter the title of the book: ";
				getline(cin,library[i].title);
					outdata<<library[i].title<<"\t";
						cout<<"\n\tenter the author name: ";
							getline(cin,library[i].author);
								outdata<<library[i].author<<"\t";
									cout<<"\n\tenter the category of the book: ";
										getline(cin,library[i].category);
										outdata<<library[i].category<<"\t";
									cout<<"\n\tenter the quentity:";
								library[i].quantity=input_check(library[i].quantity);
							outdata<<library[i].quantity<<"\t";
						cout<<"\n\tenter the quentitiy fo rent: ";
					library[i].quantitly_rent=input_check(library[i].quantitly_rent);
				outdata<<library[i].quantitly_rent<<"\t";
			cout<<"\n\tenter the price of the book: ";
		library[i].price=input_check(library[i].price);
	outdata<<library[i].price<<"\t";	
	}				
 	}
	cout<<"\n book added sucssefully\n\n";
outdata.close();
indata.close();
	system("pause");
}

void show_library()//funtion to print the content of text file 
{
	system("CLS");
	int counter;
		counter=counter_row(row);
			ifstream indata;
		indata.open("database.txt");
	data library[counter];
	if(!indata.fail())//check if the text file open 
	{
	cout<<"\n\n\n\t\t\t"<<setw(15)<<setfill(' ')<<left<<"ID"<<right
		<<setw(15)<<setfill(' ')<<left<<"TITLE"<<right
			<<setw(15)<<setfill(' ')<<left<<"AUTHOR"<<right
				<<setw(15)<<setfill(' ')<<left<<"CATEGORY"<<right
					<<setw(15)<<setfill(' ')<<left<<"RENT"<<right
						<<setw(15)<<setfill(' ')<<left<<"price"<<right<<endl;
		for(int i=0;i<counter;i++)//start reading from the file
		{
		indata>>library[i].ID>>
			library[i].title>>
				library[i].author>>
					library[i].category>>
		  				library[i].quantity>>
		 					library[i].quantitly_rent>>
								library[i].price;
		//start printing the content of the file
		cout<<"\n\t\t\t"<<setw(15)<<setfill(' ')<<left<<library[i].ID <<right
			<<setw(15)<<setfill(' ')<<left<<library[i].title<<right
				<<setw(15)<<setfill(' ')<<left<<library[i].author<<right
				   <<setw(15)<<setfill(' ')<<left<<library[i].category<<right
					 <<setw(15)<<setfill(' ')<<left<<library[i].quantitly_rent<<right<<"$"
					 	<<setw(15)<<setfill(' ')<<left<<library[i].price<<right;
		}
		cout<<"\n\n\n\n";
	}
	
}

void search_book()//function the read the content of the text file and try to find the book that entered
{
	system("CLS");
	string ID,name;
	int choice;
	int counter;
	counter=counter_row(row);//calling the function to count the number of rows
	ifstream indata;
	indata.open("database.txt");
	data library[counter];
		cout<<"\n\t1. search by ID\n\t2. search by title\n\nenter option: ";
			choice=input_check(choice);//calling the function to check if the input integer
	switch (choice)
	{
		case 1:		
		{
			cout<<"enter the book ID: ";
			cin>>ID;//enter the ID of the book that the user looking for	
			if(!indata.fail())
			{
				for(int i=0;i<counter;i++)//start reading from the file
				{
			indata>>library[i].ID>>
					library[i].title>>
			  		library[i].author>>
		   			library[i].category>>
		  			library[i].quantity>>
		 			library[i].quantitly_rent>>
				 	library[i].price;
		 								
		 			if(ID==library[i].ID)//compare the entered ID with those already in the file
					{
					cout<<"\n\n\n\t\t\t"<<setw(15)<<setfill(' ')<<left<<"ID"<<right
					 <<setw(15)<<setfill(' ')<<left<<"TITLE"<<right
					  <<setw(15)<<setfill(' ')<<left<<"AUTHOR"<<right
					   <<setw(15)<<setfill(' ')<<left<<"CATEGORY"<<right
					    <<setw(15)<<setfill(' ')<<left<<"RENT"<<right
					     <<setw(15)<<setfill(' ')<<left<<"price"<<right<<endl;
					cout<<"\n\t\t\t"<<setw(15)<<setfill(' ')<<left<<library[i].ID<<right
					 <<setw(15)<<setfill(' ')<<left<<library[i].title<<right
					  <<setw(15)<<setfill(' ')<<left<<library[i].author<<right
					   <<setw(15)<<setfill(' ')<<left<<library[i].category<<right
					    <<setw(15)<<setfill(' ')<<left<<library[i].quantitly_rent<<right<<"$"
						 <<setw(15)<<setfill(' ')<<left<<library[i].price<<right<<endl<<endl<<endl<<endl;
					}				
				}
			}
		break;
		}
		case 2:
		{
		cout<<"enter the book title: ";
		cin>>name;//entring the title of the book that the user looking for
		if(!indata.fail())
		{
			for(int i=0;i<counter;i++)//start reading from the text file
			{
		indata>>library[i].ID>>
				library[i].title>>
				library[i].author>>
		   		library[i].category>>
		  		library[i].quantity>>
		  	 	library[i].quantitly_rent>>
				library[i].price;
		 		if(name==library[i].title)//if the title matched with a title in text file 
				{
				//print the book details	
				cout<<"\n\n\n\t\t\t"<<setw(15)<<setfill(' ')<<left<<"ID"<<right
				 <<setw(15)<<setfill(' ')<<left<<"TITLE"<<right
				  <<setw(15)<<setfill(' ')<<left<<"AUTHOR"<<right
				   <<setw(15)<<setfill(' ')<<left<<"CATEGORY"<<right
					<<setw(15)<<setfill(' ')<<left<<"RENT"<<right
					 <<setw(15)<<setfill(' ')<<left<<"price"<<right<<endl<<endl<<endl;
				cout<<"\n\t\t\t"<<setw(15)<<setfill(' ')<<left<<library[i].ID<<right
				 <<setw(15)<<setfill(' ')<<left<<library[i].title<<right
				  <<setw(15)<<setfill(' ')<<left<<library[i].author<<right
			   	   <<setw(15)<<setfill(' ')<<left<<library[i].category<<right
				    <<setw(15)<<setfill(' ')<<left<<library[i].quantitly_rent<<right<<"$"
					 <<setw(15)<<setfill(' ')<<left<<library[i].price<<right<<endl<<endl;				
				}			
			}	
		}
		break;	
		}	
	}	
	system("pause");
}

void sell_book()//function that read text file and seash for a book the user want to buy then do selling process
{
	show_library();//calling the function to display library
	string name;
	int counter,buy;
	char choice;
	double total;
	
	
	
		cout<<"\n\tenter the name of the book you want to buy: ";
		cin.ignore();
			getline(cin,name);//entering the title for a book the user want to buy
		cout<<"\n\tenter the quantity of the book you want to buy: ";
			cin>>buy;
	counter=counter_row(row);//calling the function that count the rows in text file
	data library[counter];
ifstream indata;
indata.open("database.txt");
	if(!indata.fail())//check if the file open successfully
	{
		for(int i=0;i<counter;i++)//read the data in the text file
		{
		indata>>library[i].ID>>
				library[i].title>>
	  			library[i].author>>
   				library[i].category>>
				library[i].quantity>>
	 			library[i].quantitly_rent>>
			 	library[i].price;
			
		
			
	   		if(name==library[i].title)//check if the user entered a book title that the bookstore have
	 		{
				if(buy<=library[i].quantity)//check if the book out of stock
				{
					
					cout<<"\n\tare you sure you want to buy: \n";
						cout<<"\n\t\t\t"<<setw(15)<<setfill(' ')<<left<<"ID"<<right
							<<setw(15)<<setfill(' ')<<left<<"TITLE"<<right
								<<setw(15)<<setfill(' ')<<left<<"AUTHOR"<<right
									<<setw(15)<<setfill(' ')<<left<<"CATEGORY"<<right
										<<setw(15)<<setfill(' ')<<left<<"RENT"<<right
											<<setw(15)<<setfill(' ')<<left<<"price"<<right<<endl;
												cout<<"\n\t\t\t"<<setw(15)<<setfill(' ')<<left<<library[i].ID<<right
										<<setw(15)<<setfill(' ')<<left<<library[i].title<<right
									<<setw(15)<<setfill(' ')<<left<<library[i].author<<right
								<<setw(15)<<setfill(' ')<<left<<library[i].category<<right
							<<setw(15)<<setfill(' ')<<left<<library[i].quantitly_rent<<right<<"$"	
						<<setw(15)<<setfill(' ')<<left<<library[i].price<<right;	
					cout<<"\n\n\tenter(Y/N): ";
					 cin>>choice;
					 switch (choice)
					 {
					 	case 'Y':case 'y':
					 		{
					 		 quantity_counter(&name,&buy);//calling a function to update the quantity of the book theat recently bought
						 	 total=buy*library[i].price;
						 	 total_1(total);//calling a function that store total intext file
					 	 	 cout<<"\n\t the book added successfully. \n\t the price of the book '"<<library[i].title<<"' is "<<buy<<" X "<<library[i].price<<" = "<<total<<"$\n\n";		
					 	 	 break;
					 		}
					 	default:
					 		cout<<"\n\tthe purchase has been canceled.\n";
						
					 }
					 
				}
				else
				cout<<"\n\tthe number of books you want to buy is greater than our quantity\n\n";
	 		 }
	 		
	 		
		}	
	}

indata.close();
system("pause");
}

void edit_book()//function that allow admin to edit an existing book
{
	system("CLS");
	int counter;
	string name;
	cout<<"\n\t::edit page::"<<"\n\n\n";
	show_library();	//calling function that display the library	
	counter=counter_row(row);//calling function to count the number of rows
	data library[counter]; 		
ifstream indata;
	indata.open("database.txt");
ofstream outdata;
	outdata.open("temp.txt");		
	if(!indata.fail())
	{
		cout<<"\nenter the ID of the book you will to edit: ";
		cin>>name;
		for(int i=0;i<counter;i++)//start reading from text file
		{
		indata>>library[i].ID>>
				library[i].title>>
				library[i].author>>
				library[i].category>>
		  		library[i].quantity>>
		 		library[i].quantitly_rent>>
				library[i].price;
			if(name==library[i].ID)//start editing 
			{
				cin.ignore();
			cout<<"\n\tenter the book ID: ";
				getline(cin,library[i].ID)	;	
					outdata<<"\n"<<library[i].ID<<"\t";
						cout<<"\n\tenter the title of the book: ";
							getline(cin,library[i].title);
							outdata<<library[i].title<<"\t";
						cout<<"\n\tenter the author name: ";
					getline(cin,library[i].author);
				outdata<<library[i].author<<"\t";
			cout<<"\n\tenter the category of the book: ";
				getline(cin,library[i].category);
					outdata<<library[i].category<<"\t";
						cout<<"\n\tenter the quentity:";
							library[i].quantity=input_check(library[i].quantity);
							outdata<<library[i].quantity<<"\t";
						cout<<"\n\tenter the quentitiy fo rent: ";
					library[i].quantitly_rent=input_check(library[i].quantitly_rent);
				outdata<<library[i].quantitly_rent<<"\t";
			cout<<"\n\tenter the price of the book: ";
				library[i].price=input_check();
					outdata<<library[i].price<<"\t";	
			}		
		} 
	}
	fstream infile;
	infile.open("temp.txt");
	ofstream outfile;
	outfile.open("database.txt");
	if(!infile.fail())
	{
	for(int i=0;i<counter;i++)//start coping from temp file to original file
		{
		infile>>library[i].ID;
		outfile<<"\n"<<library[i].ID<<"\t";
			infile>>library[i].title;
			outfile<<library[i].title<<"\t";
	  			infile>>library[i].author;
	  			outfile<<library[i].author<<"\t";
   					infile>>library[i].category;
   					outfile<<library[i].category<<"\t";
		 				infile>>library[i].quantity;
		 				outfile<<library[i].quantity<<"\t";
		 					infile>>library[i].quantitly_rent;
		 					outfile<<library[i].quantitly_rent<<"\t";
							 	infile>>library[i].price;
						 		outfile<<library[i].price;
		}
	}
infile.close();
outfile.close();
	remove("temp.txt");
	system("pause");
}
void delete_book()//function that allow the manager to delete a book from library
{
	string ID;
	system ("CLS");
	cout<<"\n\t::delete page::\n\n\n";
	show_library();	
	cout<<"\tenter the name of the ID of the book you want to delete: ";
	cin.ignore();
	getline(cin,ID);

	int counter;
		counter=counter_row(row);
	data library[counter]; 		
ifstream indata;
	indata.open("database.txt");
ofstream outdata;
	outdata.open("temp.txt");
	if(!indata.fail())
	{
		for(int i=0;i<counter;i++)//start reading from text file
		{
		indata>>library[i].ID>>
			library[i].title>>
				library[i].author>>
					library[i].category>>
		  				library[i].quantity>>
		 					library[i].quantitly_rent>>
								library[i].price;
			if(ID==library[i].ID)//start deleting
			{
			continue;	
			}
			else
			{
			outdata<<"\n"<<library[i].ID<<"\t";
				outdata<<library[i].title<<"\t";
	  				outdata<<library[i].author<<"\t";
   						outdata<<library[i].category<<"\t";
			 				outdata<<library[i].quantity<<"\t";
		 						outdata<<library[i].quantitly_rent<<"\t";
							 		outdata<<library[i].price;						 	
			}			
		} 
	}
indata.close();
outdata.close();
	fstream infile;
		infile.open("temp.txt");
	ofstream outfile;
		outfile.open("database.txt");
	string item;
	if(!infile.fail())
	{
	while(!infile.eof())//start coping from temp file to orignal file
		{
		infile>>item;
		outfile<<item<<"\t";
		}
	}
infile.close();
outfile.close();
		remove("temp.txt");
}

string check_ID(string ID)//function that check if ID exist in library
{

	getline(cin,ID);
	int counter;
	counter=counter_row(row);
		ifstream indata;
	indata.open("database.txt");
	data library[counter];
	if(!indata.fail())
	{
		
		
		for(int i=0;i<counter;i++)//start reading from text file
		{
		indata>>library[i].ID>>
			library[i].title>>
				library[i].author>>
					library[i].category>>
		  				library[i].quantity>>
		 					library[i].quantitly_rent>>
								library[i].price;	
	 	if(ID==library[i].ID)
		{
			cout<<"\n\tthe ID you entered already exist.....\n\tplease enter another ID to continue: ";
			ID=check_ID(ID);
		}
		}
		return ID;
	}	
}

void total_1(double Total)//writing the total of money from selling a book in total file
{
	ofstream outtotal;
	outtotal.open("total.txt",ios::app);
	outtotal<<endl<<Total;
}

void show_total()//reading the total from total file then display the total
{
	system("CLS");
	double item=0;int i=0,num=0,total1=0;

	ifstream intotal;
	intotal.open("total.txt");
	if(!intotal.fail())
	{
		while(!intotal.eof())
		{
			intotal>>num;
			item=item+num;
		}
		
		cout<<"\n\n\n\n\tthe total money you made is: " <<item<<" $\n\n\n\n";
	}
	system("pause");
}

void rent_book()//allow user to rent a book
{
	show_library();
	string name;
	int counter,buy;
	char choice;
	double total;
	double total_sell=0;
	
	
		cout<<"\n\tenter the name of the book you want to barrow: ";
		cin.ignore();
			getline(cin,name);
	counter=counter_row(row);
	data library[counter];
ifstream indata;
indata.open("database.txt");
	if(!indata.fail())
	{
		for(int i=0;i<counter;i++)
		{
		indata>>library[i].ID>>
				library[i].title>>
	  			library[i].author>>
   				library[i].category>>
				library[i].quantity>>
	 			library[i].quantitly_rent>>
			 	library[i].price;
			
			
	   		if(name==library[i].title)
	 		{	
			 if(library[i].quantitly_rent!=0)//check if the quantity of the book not equal to ZERO
			 {
			 		
					cout<<"\n\tare you sure you want to barrow this book: \n";
						cout<<"\n\t\t\t"<<setw(15)<<setfill(' ')<<left<<"ID"<<right
							<<setw(15)<<setfill(' ')<<left<<"TITLE"<<right
								<<setw(15)<<setfill(' ')<<left<<"AUTHOR"<<right
									<<setw(15)<<setfill(' ')<<left<<"CATEGORY"<<right
										<<setw(15)<<setfill(' ')<<left<<"RENT"<<right
											<<setw(15)<<setfill(' ')<<left<<"price"<<right<<endl;
												cout<<"\n\t\t\t"<<setw(15)<<setfill(' ')<<left<<library[i].ID<<right
										<<setw(15)<<setfill(' ')<<left<<library[i].title<<right
									<<setw(15)<<setfill(' ')<<left<<library[i].author<<right
								<<setw(15)<<setfill(' ')<<left<<library[i].category<<right
							<<setw(15)<<setfill(' ')<<left<<library[i].quantitly_rent<<right<<"$"	
						<<setw(15)<<setfill(' ')<<left<<library[i].price<<right;	
					cout<<"\n\n\tenter(Y/N): ";
					 cin>>choice;
					 switch (choice)
					 {
					 	case 'Y':case 'y':
					 		{
					 		 quantity_rent_counter(&name);
					 	 	 cout<<"\n\t the book added successfully.\n\n";		
					 	 	 break;
					 		}
					 	default:
					 		cout<<"\n\tthe renting has been canceled.\n";	
					 }	 
			}
			else
			cout<<"\n\tsorry the book you entered not avaliable for rent...\n\n";
	 		}
	 			
	
		}
		
	}
indata.close();
system("pause");

}

void quantity_counter(string*NAME,int*BUY)//decrease the quantity of the book that bought from a user
{
		
	int counter;
	counter=counter_row(row);
	data library[counter]; 		
ifstream indata;
	indata.open("database.txt");
ofstream outdata;
	outdata.open("temp.txt");		
	if(!indata.fail())
	{
		for(int i=0;i<counter;i++)//start reading from the text file
		{
		indata>>library[i].ID>>
				library[i].title>>
				library[i].author>>
				library[i].category>>
		  		library[i].quantity>>
		 		library[i].quantitly_rent>>
				library[i].price;
			if(*NAME==library[i].title)//check if the name exist in the text file
			{
					outdata<<"\n"<<library[i].ID<<"\t";
							outdata<<library[i].title<<"\t";
				outdata<<library[i].author<<"\t";
					outdata<<library[i].category<<"\t";
					library[i].quantity-=*BUY;
							outdata<<library[i].quantity<<"\t";
				outdata<<library[i].quantitly_rent<<"\t";
					outdata<<library[i].price<<"\t";	
			}		
		} 
	}
	fstream infile;
	infile.open("temp.txt");
	ofstream outfile;
	outfile.open("database.txt");
	if(!infile.fail())
	{
	for(int i=0;i<counter;i++)//start coping from temp file to orignal file
		{
		infile>>library[i].ID;
		outfile<<"\n"<<library[i].ID<<"\t";
			infile>>library[i].title;
			outfile<<library[i].title<<"\t";
	  			infile>>library[i].author;
	  			outfile<<library[i].author<<"\t";
   					infile>>library[i].category;
   					outfile<<library[i].category<<"\t";
		 				infile>>library[i].quantity;
		 				outfile<<library[i].quantity<<"\t";
		 					infile>>library[i].quantitly_rent;
		 					outfile<<library[i].quantitly_rent<<"\t";
							 	infile>>library[i].price;
						 		outfile<<library[i].price;
		}
	}
infile.close();
outfile.close();
	remove("temp.txt");
}

void quantity_rent_counter(string*NAME)//decrease the number for rented book
{
	int counter;
	counter=counter_row(row);
	data library[counter]; 		
ifstream indata;
	indata.open("database.txt");
ofstream outdata;
	outdata.open("temp.txt");		
	if(!indata.fail())
	{
		for(int i=0;i<counter;i++)
		{
		indata>>library[i].ID>>
				library[i].title>>
				library[i].author>>
				library[i].category>>
		  		library[i].quantity>>
		 		library[i].quantitly_rent>>
				library[i].price;
			if(*NAME==library[i].title)
			{
					outdata<<"\n"<<library[i].ID<<"\t";
							outdata<<library[i].title<<"\t";
				outdata<<library[i].author<<"\t";
					outdata<<library[i].category<<"\t";
							outdata<<library[i].quantity<<"\t";
							library[i].quantitly_rent-=1;
				outdata<<library[i].quantitly_rent<<"\t";
				
					outdata<<library[i].price<<"\t";	
			}		
		} 
	}
	fstream infile;
	infile.open("temp.txt");
	ofstream outfile;
	outfile.open("database.txt");
	if(!infile.fail())
	{
	for(int i=0;i<counter;i++)
		{
		infile>>library[i].ID;
		outfile<<"\n"<<library[i].ID<<"\t";
			infile>>library[i].title;
			outfile<<library[i].title<<"\t";
	  			infile>>library[i].author;
	  			outfile<<library[i].author<<"\t";
   					infile>>library[i].category;
   					outfile<<library[i].category<<"\t";
		 				infile>>library[i].quantity;
		 				outfile<<library[i].quantity<<"\t";
		 					infile>>library[i].quantitly_rent;
		 					outfile<<library[i].quantitly_rent<<"\t";
							 	infile>>library[i].price;
						 		outfile<<library[i].price;
		}
	}
infile.close();
outfile.close();
	remove("temp.txt");
}






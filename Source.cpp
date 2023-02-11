#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <functional>
#include <vector>  
#include <fstream>

using namespace std;
//allcustomers class
class AllCustomers
{
public: //function prototypes for the all the member functions
	void Customerfile();
	void print_customers();
	void sort_customers(int num);
	void specific_customer();
	void add_customer();
	void Add_multiple(int num1);
	void update();
	void Delete();
	void Export_data();
	int exit_program();

private: //these private data members represent each specfic data item that is stored in the file
	vector < string > first_name;
	vector < string > last_name;
	vector < string > address;
	vector < string > city;
	vector < string > state;
	vector < string > phone_number;
	vector < int > zip_code;
	vector < int > id;
	int counter = 0; //counter keeps track of the file size for customer information
};

void AllCustomers::Customerfile()
{//temp variables
	string firstN;
	string lastN;
	string addrss;
	string cty;
	string st;
	string phone_num;
	int code;
	int number;


	ifstream infiles;
	infiles.open("Customer.txt"); //opens the input file customer

	if (!infiles) //if there is an error opening the file the program will exit
	{
		cout << "There is an error in opening the file" << endl;
		abort();
	}

	while (!infiles.eof()) //the while loop terminates at the end of the file
	{
		infiles >> firstN >> lastN;
		getline(infiles, addrss, ';');
		infiles >> cty >> st >> code >> number >> phone_num; //the first line is read into the temporary variables
		first_name.push_back(firstN); //then those individuals values are all inserted into the vector and increases the vector size
		last_name.push_back(lastN);
		address.push_back(addrss);
		city.push_back(cty);
		state.push_back(st);
		zip_code.push_back(code);
		id.push_back(number);
		phone_number.push_back(phone_num);
		counter++; //after each line is read counter increase by one which keeps track of how many lines are in the input file
	}
	infiles.close(); //closes the input file
}

void AllCustomers::print_customers()
{
	cout << "The customers names are listed below: " << endl;

	//the for loop outputs the first and last name for each position of i
	for (int i = 0; i < counter; i++)
	{
		cout << first_name.at(i) << " " << last_name.at(i) << endl;
	}

	cout << endl;
}

void AllCustomers::sort_customers(int num)
{
	vector<string> temp; //temp is meant for holding all the values in the first name vector
	vector<string> temp1; //temp1 is meant for holding all the values in the last name vector

	for (int i = 0; i < first_name.size(); i++)
	{//with the for loop we are inserting each first name from the original vector into the temp vector
		temp.push_back(first_name.at(i));
	}

	for (int i = 0; i < last_name.size(); i++)
	{//with the for loop we are inserting each last name from the original vector into the temp vector
		temp1.push_back(last_name.at(i));
	}

	if (num == 1) //if num is equal to 1 the full names are printed in ascending order
	{
		sort(temp.begin(), temp.end()); //the built in sort function quick sorts the data from begging to end
		sort(temp1.begin(), temp1.end());

		cout << endl;
		for (int i = 0; i < counter; i++)
		{ //prints the full name in ascending order
			cout << temp.at(i) << " ";
			cout << temp1.at(i) << endl;
		}

	}

	else //if num is equal to anything else the full names are printed in descending order
	{
		sort(temp.begin(), temp.end(), greater<string>()); //the built in sort function quick sorts the data from beginning to end in descending order
		sort(temp1.begin(), temp1.end(), greater<string>());

		cout << endl;
		for (int i = 0; i < counter; i++)
		{ //prints the full name in ascending order
			cout << temp.at(i) << " ";
			cout << temp1.at(i) << endl;
		}
	}
}

void AllCustomers::specific_customer()
{
	int ID;

	for (int i = 0; i < counter; i++)
	{//prints the full name and account number for each customer
		cout << first_name.at(i) << " ";
		cout << last_name.at(i) << " ";
		cout << id.at(i) << endl;
	}

	cout << "\nPlease enter the account number for the customer you want to search for: ";
	while (cout << "" && !(cin >> ID)) { //if the user inputs characters instead of intergers it will ignore the input and prompt the user again
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "you have entered a invalid input. Please try again" << endl;
		cout << "\nPlease enter the account number for the customer you want to search for: ";
	}

	for (int i = 0; i < counter; i++)
	{
		if (ID == id.at(i)) //if the user input is equal to one of the id in the vector it prints out all the info for that id
		{
			cout << first_name.at(i) << "     " << last_name.at(i) << "     " << address.at(i) << "     " << city.at(i) << "     " << state.at(i) << "     " << zip_code.at(i) << "     " << id.at(i) << "     " << phone_number.at(i);
			cout << endl << endl;
		}
	}
}

void AllCustomers::add_customer()
{//temp varaiables that are used to store user input
	string first;
	string last;
	string addr;
	string city1;
	string state1;
	string phone;
	int zip;
	int acc;

	cout << "Please enter the required information for the customers" << endl;
	cout << "Please enter the customers first name: ";
	cin >> first;

	cout << "Please enter the customer's last name: ";
	cin >> last;

	cout << "Please enter the customers address followed by a semi colon: ";
	getline(cin, addr, ';');

	cout << "Please enter the customers city followed by a semi colon: ";
	getline(cin, city1, ';');

	cout << "Please enter the abriviated version of the customers state (ex NY): ";
	cin >> state1;

	cout << "Please enter the customers zip code: ";
	while (cout << "" && !(cin >> zip)) { //if the user inputs characters instead of intergers it will ignore the input and prompt the user again
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "you have entered a invalid input. Please try again" << endl;
		cout << "Please enter the customers zip code: ";
	}

	cout << "Please enter the customer's 8 digit account number: ";
	while (cout << "" && !(cin >> acc)) {//if the user inputs characters instead of intergers it will ignore the input and prompt the user again
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "you have entered a invalid input. Please try again" << endl;
		cout << "Please enter the customer's 8 digit account number: ";
	}

	for (int i = 0; i < id.size(); i++) //if the account id that was entered already being used then it prompt the user 
	{
		if (acc == id.at(i))
		{
			cout << "That account number is taken please enter a new 8 digit number: ";
			cin >> acc;
		}
	}

	cout << "Please enter the customers phone number: ";
	cin >> phone;
	cout << endl;

	//places the user input in the back of the stack for each of the different vectors
	first_name.emplace_back(first);
	last_name.emplace_back(last);
	address.emplace_back(addr);
	city.emplace_back(city1);
	state.emplace_back(state1);
	zip_code.emplace_back(zip);
	id.emplace_back(acc);
	phone_number.emplace_back(phone);
	counter++; //counter is increased since a new line is added to the output file

	cout << "The Customer has been successfully added!! " << endl << endl;
}

void AllCustomers::Add_multiple(int num1)
{//temp varaibles used to hold user input
	string first;
	string lst;
	string add;
	string cty;
	string ste;
	int code;
	int acc;
	string phn;

	if (num1 == 0) //if the input hits 0 the base case excutes and the recurrisve function ends
	{
		cout << "\nThe customer's information has been successfully added!! " << endl << endl;
	}

	else
	{
		cout << "\nPlease enter the required information for the customers" << endl;
		cout << "Please enter the customers first name: ";
		cin >> first;
		first_name.emplace_back(first); // places the user input in the back of the stack for each of the different vectors

		cout << "Please enter the customer's last name: ";
		cin >> lst;
		last_name.emplace_back(lst);

		cout << "Please enter the customers address followed by a semi colon: ";
		getline(cin, add, ';');
		address.emplace_back(add);

		cout << "Please enter the customers city followed by a semi colon: ";
		getline(cin, cty, ';');
		city.emplace_back(cty);

		cout << "Please enter the abriviated version of the customers state (ex NY): ";
		cin >> ste;
		state.emplace_back(ste);

		cout << "Please enter the customers zip code: ";
		while (cout << "" && !(cin >> code)) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "you have entered a invalid input. Please try again" << endl;
			cout << "Please enter the customers zip code: ";
		}

		zip_code.emplace_back(code);

		cout << "Please enter the customer's 8 digit account number: ";
		while (cout << "" && !(cin >> acc)) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "you have entered a invalid input. Please try again" << endl;
			cout << "Please enter the customer's 8 digit account number: ";
		}

		for (int i = 0; i < id.size(); i++)
		{
			if (acc == id.at(i))
			{
				cout << "That account number is taken please enter a new 8 digit number: ";
				cin >> acc;
			}
		}
		id.emplace_back(acc);

		cout << "Please enter the customers phone number: ";
		cin >> phn;
		phone_number.emplace_back(phn);
		counter++;

		Add_multiple(num1 - 1); //keeps calling the same function but deincriments num1 by one so the base case is hit
	}
}

void AllCustomers::update()
{//temp variables used to read in the user input
	string first;
	string lst;
	string add;
	string cty;
	string ste;
	int ID;
	int code;
	string phn;

	for (int i = 0; i < counter; i++) //displays the customers names and account numbers for all the customers
	{
		cout << first_name.at(i) << " ";
		cout << last_name.at(i) << " ";
		cout << id.at(i) << endl;
	}

	cout << "\nPlease enter the account number for the customer you want to update: ";
	while (cout << "" && !(cin >> ID)) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "you have entered a invalid input. Please try again" << endl;
		cout << "\nPlease enter the account number for the customer you want to update: ";
	}
	cout << endl;

		for (int i = 0; i < counter; i++)
		{
			if (ID == id.at(i)) //if the user input is equal to one of the id numbers it prompts the user to enter info
			{
				cout << "Please enter the required information for the customers" << endl;
				cout << "Please enter the customers updated first name: ";
				cin >> first;

				cout << "Please enter the customers updated last name: ";
				cin >> lst;

				cout << "Please enter the customers updated address followed by a semi colon: ";
				getline(cin, add, ';');

				cout << "Please enter the customers updated city followed by a semi colon: ";
				getline(cin, cty, ';');

				cout << "Please enter the abriviated version of the customers state (ex NY): ";
				cin >> ste;

				cout << "Please enter the customers updated zip code: ";
				while (cout << "" && !(cin >> code)) {
					cin.clear();
					cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
					cout << "you have entered a invalid input. Please try again" << endl;
					cout << "Please enter the customers updated zip code: ";
				}

				cout << "Please enter the customers updated phone number: ";
				cin >> phn;
				cout << endl;

				first_name.at(i) = first; //overides the selected account information to the user input
				last_name.at(i) = lst; //example the name the user selcted is now equal to the postion that the selected user name wa found at
				address.at(i) = add;
				city.at(i) = cty;
				state.at(i) = ste;
				zip_code.at(i) = code;
				phone_number.at(i) = phn;

				cout << "The customer's information has been updated!!" << endl << endl;
			
			}
		}
}

void AllCustomers::Delete()
{
	int ID;

	for (int i = 0; i < counter; i++)
	{
		cout << first_name.at(i) << " ";
		cout << last_name.at(i) << " ";
		cout << id.at(i) << endl;
	}

	cout << endl;
	cout << "Please enter the account number for the customer you want to delete: ";
	while (cout << "" && !(cin >> ID)) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "you have entered a invalid input. Please try again" << endl;
		cout << "Please enter the account number for the customer you want to delete: ";
	}

	for (int i = 0; i < counter; i++)
	{

		if (ID == id.at(i))
		{
			first_name.erase(first_name.begin() + i); //the earse function clears the data at the selcted postion
			last_name.erase(last_name.begin() + i);
			address.erase(address.begin() + i);
			city.erase(city.begin() + i);
			state.erase(state.begin() + i);
			zip_code.erase(zip_code.begin() + i);
			phone_number.erase(phone_number.begin() + i);
			id.erase(id.begin() + i);

			counter--; //since were deleting the customers information counter needs to be decremented

			cout << "\nThe selected customers information has been deleted!! " << endl << endl;
		}
	}

}

void AllCustomers::Export_data()
{
	ofstream outfile;
	outfile.open("user.txt"); //opens the text file user.txt

	if (!outfile)
	{
		cout << "There is an error in opening the file." << endl;
		abort(); //if there is error in opening the file the program will exit
	}

	for (int i = 0; i < counter; i++) //the for loop continues until i is equal to counter
	{
		//reads each element from the vector separated by a space into a separate output file
		outfile << first_name.at(i) << " " << last_name.at(i);
		outfile << address.at(i);
		outfile << city.at(i) << "  " << state.at(i) << "  " << zip_code.at(i) << "  " << id.at(i) << "  " << phone_number.at(i) << endl;
	}

	cout << "The data was successfully exported!!" << endl << endl;
	outfile.close(); //closes the output file

}

int AllCustomers::exit_program() //full function definition for exit program
{
	exit(0); //exits from the program
}

//allpurchases class
class AllPurchases
{
public: //function protoypes for the member functions
	void Purchasefile();
	void Total_Spent();
	void add_purchase();
	void add_multiple(int num);
	void export_data();

private: //each vector represents a piece of data that is included in the input file
	vector < string > Item;
	vector < string > Date;
	vector < int > Account_Number;
	vector < double > Amount;
	int counter1 = 0; //counter keeps track of the file size
};

void AllPurchases::Purchasefile()
{
	int account;
	string item;
	string date;
	double amount;

	ifstream infile;
	infile.open("Purchase.txt"); //opens the input file 

	if (!infile) //if there is an error opening the file the program will exit
	{
		cout << "There is an error in opening the file" << endl;
		abort();
	}

	while (!infile.eof()) //the while loop terminates at the end of the file
	{
		infile >> account >> item >> date >> amount; //the first line is read into the temporary variables
		Account_Number.push_back(account);
		Item.push_back(item); //then those individuals values are all inserted into the vector and increases the vector size
		Date.push_back(date);
		Amount.push_back(amount);
		counter1++; //after each line is read counter increase by one which keeps track of how many lines are in the input file
	}
	infile.close(); //closes the input file
}

void AllPurchases::Total_Spent()
{
	double total = 0;
	cout << "The total amount for all the customers purchases are: ";

	for (int i = 0; i < Amount.size(); i++)
	{
		total += Amount.at(i); //adds together all the customers purchases from the amount vector
	}

	cout << total << endl << endl;
}

void AllPurchases::add_purchase()
{
	string item;
	string date;
	double amount;
	int acc1;
	//the user input is inputed and then placed in the back of the stack for that specfic vector
	cout << "Please enter the required information for the Purchase information" << endl;
	cout << "Please enter the Purchased Item: ";
	cin >> item;

	cout << "Please enter the date of the customer purchase in month/day/year format: ";
	cin >> date;

	cout << "Please enter the amount for the purchased item: ";
	while (cout << "" && !(cin >> amount)) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "you have entered a invalid input. Please try again" << endl;
		cout << "Please enter the amount for the purchased item: ";
	}

	cout << "Please enter the customer's 8 digit account number: ";
	while (cout << "" && !(cin >> acc1)) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "you have entered a invalid input. Please try again" << endl;
		cout << "Please enter the customer's 8 digit account number: ";
	}

	for (int i = 0; i < Account_Number.size(); i++)
	{
		if (acc1 == Account_Number.at(i))
		{
			cout << "That account number is taken please enter a new 8 digit number: ";
			cin >> acc1;
		}
	}

	cout << endl;
	//emplace_back pushes the new stats to the back of the vector
	Item.emplace_back(item);
	Date.emplace_back(date);
	Amount.emplace_back(amount);
	Account_Number.emplace_back(acc1);
	counter1++; //increases the counter that keeps track of the file size

	cout << "The customer's purchase has been added!!" << endl << endl;
}

void AllPurchases::add_multiple(int num)
{//temp variables
	string item;
	string date;
	double amnt;
	int acc1;

	if (num == 0) //base case if num hits 0 the reccurssive function is terminated
	{
		cout << "The customer's information has been successfully added!! " << endl << endl;
	}

	else
	{
		cout << "\nPlease enter the required information for the customers" << endl;

		cout << "Please enter the customers purchased item: ";
		cin >> item;
		Item.emplace_back(item);

		cout << "Please enter the date of the customers purchase in month/day/year format: ";
		cin >> date;
		Date.emplace_back(date);

		cout << "Please enter the amount of the customers purchase: ";
		while (cout << "" && !(cin >> amnt)) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "you have entered a invalid input. Please try again" << endl;
			cout << "Please enter the amount of the customers purchase: ";
		}
		Amount.emplace_back(amnt);


		cout << "Please enter the customer's 8 digit account number: ";
		while (cout << "" && !(cin >> acc1)) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "you have entered a invalid input. Please try again" << endl;
			cout << "Please enter the customer's 8 digit account number: ";
		}

		for (int i = 0; i < Account_Number.size(); i++)
		{
			if (acc1 == Account_Number.at(i))
			{
				cout << "That account number is taken please enter a new 8 digit number: ";
				cin >> acc1;
				cout << endl;
			}
		}
		Account_Number.emplace_back(acc1);
		counter1++; //counter is increased

		add_multiple(num - 1); //num is deincremented so that the reccursive function is stuck in a infinte loop
	}
}

void AllPurchases::export_data()
{
	ofstream outfile;
	outfile.open("user1.txt"); //opens the text file user.txt

	if (!outfile)
	{
		cout << "There is an error in opening the file." << endl;
		abort(); //if there is error in opening the file the program will exit
	}

	for (int i = 0; i < counter1; i++) //the for loop continues until i is equal to counter
	{
		//reads each element from the vector separated by a space into a separate output file
		outfile << Account_Number.at(i) << " " << Item.at(i) << "  " << Date.at(i) << "  " << Amount.at(i) << endl;
	}

	cout << "The data was successfully exported!!" << endl << endl;
	outfile.close();
}

int main()
{
	//These are the created objects from the all customer and all purchase class
	AllCustomers Start;
	AllPurchases Start1;
	string user_name;
	int userinput;
	int sort;
	int cust;
	int cust1;
	char car = '-';

	cout << "Welcome to Amazon's menu system " << endl;

	cout << "Enter your name: ";
	getline(cin, user_name);

	cout << "Hello " << user_name << endl << endl;

	Start.Customerfile(); //Start calls the Customer file member function that reads the data into the vectors and starts the looping menu system
	Start1.Purchasefile(); //Start1 calls the Purchase file member function that reads the data into the vectors and starts the looping menu system

	do //the menu system will output atleast once with the use of the do while loop
	{
		cout << "                        Amazon's looping menu system" << endl;
		cout << setfill('-') << setw(85) << car << endl;

		cout << "1: Please enter the #1 to print out a list of all the customers." << endl;
		cout << "2: Please enter the #2 to sort and print a list of all the customers." << endl;
		cout << "3: Please enter the #3 to print out a specific customer's account information." << endl;
		cout << "4: Please enter the #4 to print out the total spent for all the customers' purchases." << endl;
		cout << "5: Please enter the #5 to add new customers." << endl;
		cout << "6: Please enter the #6 to add multiple customers." << endl;
		cout << "7: Please enter the #7 to update a customer's information." << endl;
		cout << "8: Please enter the #8 to delete a customer's information." << endl;
		cout << "9: Please enter the #9 to add a new customer purchase." << endl;
		cout << "10: Please enter the #10 to add multiple new customer purchases." << endl;
		cout << "11: Please enter the #11 to export the customer's information." << endl;
		cout << "12: Please enter the #12 to export the customer's purchase information." << endl;
		cout << "13: Please enter the #13 to exit the program." << endl << endl;

		cout << "Please enter one of the above options or -1 to exit: ";
		while (cout << "" && !(cin >> userinput)) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "you have entered a invalid input. Please try again" << endl;
			cout << "Please enter one of the above options or -1 to exit: ";
		}
		cout << endl;

		if (userinput < -1 || userinput > 13)
		{
			cout << "Invalid selection. Try again." << endl << endl;
		}

		switch (userinput) //based on what the user inputs it will branch to that specfic case and call the function that is asscoiated with that case number
		{
		case 1:

			Start.print_customers();
			break;

		case 2:

			cout << "Please enter the #1 if you want the data to be arranged in ascending order" << endl;
			cout << "Please enter the #2 if you want the data to be arranged in descending order" << endl;
			cout << "Please enter one of the choices: ";
			while (cout << "" && !(cin >> sort)) {
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cout << "you have entered a invalid input. Please try again" << endl;
				cout << "Please enter one of the choices: ";
			}

			Start.sort_customers(sort);

			cout << endl;
			break;

		case 3:

			Start.specific_customer();
			break;

		case 4:

			Start1.Total_Spent();
			break;

		case 5:

			Start.add_customer();
			break;

		case 6:

			cout << "How many customers would you like to add: ";
			while (cout << "" && !(cin >> cust)) {
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cout << "you have entered a invalid input. Please try again" << endl;
				cout << "How many customers would you like to add: ";
			}
			Start.Add_multiple(cust);
			break;

		case 7:

			Start.update();
			break;

		case 8:

			Start.Delete();
			break;

		case 9:

			Start1.add_purchase();
			break;

		case 10:

			cout << "How many customer purchases would you like to add: ";
			while (cout << "" && !(cin >> cust1)) {
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				cout << "you have entered a invalid input. Please try again" << endl;
				cout << "How many customer purchases would you like to add: ";
			}
			Start1.add_multiple(cust1);
			break;

		case 11:

			Start.Export_data();
			break;

		case 12:

			Start1.export_data();
			break;

		case 13:
			
			Start.exit_program();
			break;
		}
	} while (userinput != -1); //if the userinput is equal to -1 the while loop is terminated

	cout << "Thank you for using the program " << user_name << "!!" << endl;

	system("PAUSE");
	return 0;
}
/*	
	This programs displays a menu from which the user selects a character that are aiases 
	for certain functions (such as printing; mean, minimum and maximum calculation; adding new values) 
	that will be performed on some given values.
*/

#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

void display ();
void print_list (vector <int> v, size_t);
vector <int> add_val(vector <int> &v);
void mean_val (vector <int> v, size_t);
void min_val (vector <int> v);
void max_val (vector <int> v);

int main(){
	vector <int> mylist {}; 	//List that is being processed 
	char choice{};
	do {
		display ();
		cin >> choice;					//user is prompted to choose a character from given list
		choice = toupper(choice);		//converts any input charecter to uppercase
		size_t size = mylist.size();
		
		if (choice == 'P')
			print_list (mylist, size);	//prints the list/vector
				
		else if (choice == 'A')
			add_val (mylist);		//promts the user to add a new value to the list
		
		else if (choice == 'M')
			mean_val (mylist, size);	//calculates the mean value of the items in the list
			
		else if (choice == 'S') 
			min_val (mylist);		//determines the minimum value
		
		else if (choice == 'L') 
			max_val (mylist);		//determines the maximum value
		
		else 
			cout << "Wrong input!!! Please try again" << endl << endl; //notifies the user in case of invalid input
		
	}while (choice != 'Q');				//terminates the program if 'q' is passed as the input
	
	return 0;
}

/*Definition of display function*/
void display (){
	cout << "\nP - Print number"<< endl;
	cout << "A - Add a number"<< endl;
	cout << "M - Display mean of the numbers" << endl; 
	cout << "S - Display the smallest number"<< endl; 
	cout << "L - The largest number" << endl;
	cout << "Q - Quit" << endl;
	cout << "\nEnter your choice: ";
}


/*Definition of print function*/
void print_list (vector <int> v, size_t s){
	if (s == 0)
		cout << "[]- This list is empty" << endl;
	else{
		cout << "[ ";
		for (auto c : v)
			cout << c << " ";
		cout << "]"<<endl;
		}
	cout << endl;
}


/*definition of add value function*/
vector <int> add_val(vector <int> &v){
	int val {};
	cout << "Please enter new value: ";
	cin >> val;
	v.push_back (val);
	cout << val << " is added" << endl << endl;
	return v;
}


/*Definition of mean calculator function*/
void mean_val (vector <int> v, size_t s){
	int sum {};
	for (auto i : v){
		sum += i;
	}
	cout << "The mean value is: "<< sum/s << endl << endl; 
}


/*Definition of minimum value determining function*/
void min_val (vector <int> v){
	int min = v.at(0);
	for (auto i : v){
		if (i <= min)
			min = i;
	}
	cout << "The min value is: " << min << endl << endl;
}


/*Definition of maximum value determining function*/
void max_val (vector <int> v){
	int max = v.at(0);
	for (auto i : v){
		if (i >= max)
			max = i;
	}
	cout << "The max value is: " << max << endl << endl;
}

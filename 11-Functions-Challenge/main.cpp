// Section 11
// Challenge 
/*
     Recall the challenge from Section 9 below.
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses uses functions.
    
    You decide how to modularize the program.
    you can use my solution which is included in this file, or modularize your solution.
    
    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it

        DO NOT move the vector object outside main and make it a global variable.
    
        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the mean and so forth
        
    Take it one function at a time and take your time.
    If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!
    
    Finally,  don't forget to use function prototypes!
    
    Good luck -- I know you can do it!
*/
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>

using namespace std;

void display_handle(const vector <int> &numbers);
void add_handle(vector <int> &numbers);
void mean_handle(const vector <int> &numbers);
void smallest_handle(const vector <int> &numbers);
void largest_handle(const vector <int> &numbers);
void search_handle(const vector <int> &numbers);
void clear_handle(vector <int> &numbers);
void quit_handle(void);
void unknown_handle(void);

void display_menu(void);
char get_selectation(void);
void display_list(const vector <int> &numbers);
double calculate_mean(const vector <int> &numbers);
int get_smallest(const vector <int> &numbers);
int get_largest(const vector <int> &numbers);
bool find(const vector <int> &numbers, const int target);



int main() {
    char menu_value{};
    vector <int> vector_list{};

    do
    {
        display_menu();
        menu_value = get_selectation();

        switch (menu_value)
        {
        case 'P': 
            /* Print numbers*/
            display_handle(vector_list);
            break;
        case 'A': 
            /* Add a number */
            add_handle(vector_list);
            break;
        case 'M':
            /* Display mean of the numbers */
            mean_handle(vector_list);
            break;
        case 'S': 
            /* Display the smallest number */
            smallest_handle(vector_list);
            break;
        case 'L': 
            /* Display the largest number  */
            largest_handle(vector_list);
            break;
        case 'F': 
            /* Search for a number in the list */
            search_handle(vector_list);
            break;
        case 'C': 
            /* Clearing out the list */
            clear_handle(vector_list);
            break;
        case 'Q': 
            /* Quit */
            quit_handle();
            break;
        default:
            unknown_handle();
            break;
        }
        cout << endl;
    }while (menu_value != 'Q');
    
    
    cout << endl;
    
    return 0;
}
/**************** function handle ******************/
void display_handle(const vector <int> &numbers)
{
    if(numbers.size())
        display_list(numbers);
    else
        cout << "[] - the list is empty" << endl;
}


void add_handle(vector <int> &numbers)
{
    int num{};
    cout << "Enter an integer to add to the list: ";
    cin >> num;
    numbers.push_back(num);
    cout << num << " added" << endl;
}

void mean_handle(const vector <int> &numbers)
{
    if(numbers.size())
        cout << "mean : " << calculate_mean(numbers) << endl;
    else
        cout << "Unable to calculate the mean - no data" << endl;
}

void smallest_handle(const vector <int> &numbers)
{
    if(numbers.size())
        cout << "The smallest number is " << get_smallest(numbers) << endl;
    else
        cout << "Unable to determine the smallest number - list is empty" << endl;
}

void largest_handle(const vector <int> &numbers)
{
    if(numbers.size())
        cout << "The largest number is " << get_largest(numbers) << endl;
    else
        cout << "Unable to determine the largest number - list is empty" << endl;
}

void search_handle(const vector <int> &numbers)
{
    if(numbers.size())
    {
        int target{};
        cout << "Enter an integer to search in the list: ";
        cin >> target;

        if(find(numbers, target))
            cout << target << " was found " << endl;
        else
            cout << target << " was not found " << endl;
    }
    else
    {
        cout << "Unable to found the num - no data" << endl;
    }
}

void clear_handle(vector <int> &numbers)
{
    numbers.clear();
    cout << "[] - the list is cleared" << endl;
}

void quit_handle(void)
{
    cout << "Goodbye" << endl;
}

void unknown_handle(void)
{
    cout << "Unknown selection, please try again" << endl;
}

/******************* functions ****************************/
void display_menu(void)
{
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Search for a number in the list " << endl;
    cout << "C - Clearing out the list" << endl;
    cout << "Q - Quit" << endl;
    cout << "Enter your choice : ";
}

char get_selectation(void)
{   
    char select_value{};
    cin >> select_value;
    return toupper(select_value);
}

void display_list(const vector <int> &numbers)
{
    cout << "[ ";
    for(auto num : numbers)
        cout << num << ' ';
    cout << ']' << endl;
}

double calculate_mean(const vector <int> &numbers)
{
    double mean{};
    for(auto v : numbers)
        mean += v;
    mean /= numbers.size();
    return mean;
}

int get_smallest(const vector <int> &numbers)
{
    int smallest_num{numbers.at(0)};
    for(auto v : numbers)
        smallest_num = (v < smallest_num ? v : smallest_num);
    return smallest_num;
}

int get_largest(const vector <int> &numbers)
{
    int largest_num{numbers.at(0)};
    for(auto v : numbers)
        largest_num = (v > largest_num ? v : largest_num);
    return largest_num;
}

bool find(const vector <int> &numbers, const int target)
{
    for(auto v : numbers)
        if(v == target)
            return true;
    return false;
}
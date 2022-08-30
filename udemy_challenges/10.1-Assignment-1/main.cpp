/* 
Write a C++ program that displays a Letter Pyramid from a user-provided std::string.

Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows:

It's much easier to understand the Letter Pyramid given examples.

If the user enters the string "ABC", then your program should display:

  A                                                                                                                    
 ABA                                                                                                                   
ABCBA 


If the user enters the string, "12345", then your program should display:

    1                                                                                                                  
   121                                                                                                                 
  12321                                                                                                                
 1234321                                                                                                               
123454321
 
*/


#include <iostream>
#include <string>

using namespace std;

int main()
{
    string letters{};
    cout << "Enters the string: ";
    getline(cin,letters);
    size_t  letters_size{letters.length()};
    string spaces(letters_size-1, ' ');

    for(size_t i{0}; i< letters_size; i++)
    {
        cout << spaces.substr(i,letters_size) << letters.substr(0,i+1) ; 
        for(int y=i-1; y>=0; y--)
            cout << letters.at(y);
        cout << endl;
    }

    return 0;
}
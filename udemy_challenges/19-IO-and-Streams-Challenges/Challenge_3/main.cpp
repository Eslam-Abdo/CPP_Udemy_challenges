// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// void search_line(string, int, int);
bool search_substring(const string word, const string keyword);
bool search_word(const string word, const string keyword);


int main() {

    cout << "Enter the substring to search for: ";
    string key_word{};
    cin >> key_word;

    ifstream in_file{"romeoandjuliet.txt"};
    if(!in_file)
    {
        cerr << "Error! when open the file." << endl;
        return 1;
    }
    string word{};
    unsigned int total_word{0};
    int  found_word{0};

    while (in_file >> word)
    {
        total_word ++;
        found_word += search_substring(word, key_word);
        /* another solution */
        // found_word += search_word(word, key_word);
    }

// love, lovely, and beloved
    // cout << boolalpha << "OUT: " << search_substring("lovely" , "love") << endl;  
    // total_word += search_substring("love" , "love");
    // total_word += search_substring("lovely" , "love");
    // total_word += search_substring("beloved" , "love");

    cout << total_word << " words were searched..." << endl;
    cout << "The substring love was found " << found_word << " times" << endl;


    in_file.close();
    cout << endl;
    return 0;
}


bool search_substring(const string word, const string keyword)
{
    return (word.find(keyword) != string::npos) ? true : false;
}

bool search_word(const string word, const string keyword)
{
    int keyword_length = keyword.length();
    int word_length = word.length();
    if(word == keyword)
        return true;
    else if(word_length <= keyword_length)
        return false;
    else
    {
        for(int i = 0; i<=(word_length-keyword_length); i++)
            if( word.compare(i,keyword_length,keyword)==0)
                return true;
    }
    return false;
}
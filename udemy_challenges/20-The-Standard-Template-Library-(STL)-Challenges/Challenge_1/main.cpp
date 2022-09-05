// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> d, d1;

    for(const auto c: s)
    {
        if(!isalpha(c))
            continue;
        // std::cout << c;
        d.push_back(toupper(c));
        d1.push_front(toupper(c));
    }
    // std::cout << std::endl;
    return (d == d1);

    /* another solution */
    // std::deque <char> d3;
    // for(const auto c: s)
    //     if(isalpha(c))
    //         d3.push_back(toupper(c));
    // char c1{}, c2{};
    // while (d3.size()>1)
    // {
    //     c1 = d3.front();
    //     c2 = d3.back();
    //     d3.pop_back();
    //     d3.pop_front();
    //     if(c1 != c2)
    //         return false;
    // }
    // return true;
    
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
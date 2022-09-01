// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double calculate_score(const string ans, const string key);
void print_score(const string name, const double score);


int main() {
    ifstream in_file{"responses.txt"};
    if(!in_file)
    {
        cerr << "Error Open the file" << endl;
        return 1;
    }
    string correct_ans{};
    in_file >> correct_ans;
    string name{} , answer{};
    double score{}, avg_score{0};
    int num_of_sudent{0};
    
    cout << setw(15) << left << "Student"
        << setw(15) << right << "Score"
        << endl;
    cout << setw(30) << setfill('-') << "" << endl;
    cout << setfill(' ');

    while (in_file >> name >> answer)
    {
        num_of_sudent++;
        score = calculate_score(answer,correct_ans);
        avg_score += score;
        print_score(name,score);
    }
    
    cout << setw(30) << setfill('-') << "" << endl;
    cout << setprecision(1) << fixed << setfill(' ');
    if(num_of_sudent!=0)
        avg_score = static_cast<double>(avg_score)/num_of_sudent;
    print_score("Average Score " , avg_score);

    in_file.close();
    cout << endl;
    return 0;
}



double calculate_score(const string ans, const string key)
{
    double score{5};
    if(ans == key) 
        return score;
    else
    {
        for(int i=0; i<key.length(); i++)
            if(ans.at(i)!= key.at(i))
                --score;
        return score;
    }
}

void print_score(const string name, const double score)
{
    cout << setw(15) << left << name
            << setw(15) << right << score
            << endl;
}

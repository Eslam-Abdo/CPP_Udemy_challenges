// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
int main() {
    ifstream in_file{"romeoandjuliet.txt"};
    ofstream out_file{"out1.txt"};
    if(!in_file)
    {
        cerr << "problem with open file" << endl;
        return 1;
    }
    if(!out_file)
    {
        cerr << "problem with create file" << endl;
        return 1;
    }
    string line{};
    int line_num{0};
    while(getline(in_file,line))
    {
        if(line != "\r")
            out_file << setw(5) << right << ++line_num
                    << setw(5) << left << "" << line << endl;
        else
        out_file << endl;
    }

    cout << " done copy files " << endl;

    in_file.close();
    out_file.close();
    cout << endl;
    return 0;
}


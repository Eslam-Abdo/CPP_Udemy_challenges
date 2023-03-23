#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"

using namespace std;

int main() {
    // test your code here

    // try{
    //     Checking_Account joe{"joe",-200};
    // }
    // catch(exception &ex)
    // {
    //     cerr << ex.what() << endl;
    // }
    // catch(...)
    // {
    //     cout << "Unkown error" << endl;
    // }

    // try{
    //     Savings_Account mary{"Mary",2000};
    //     mary.withdraw(3000);
    // }
    // catch(exception &ex)
    // {
    //     cerr << ex.what() << endl;
    // }
    // catch(...)
    // {
    //     cout << "Unkown error" << endl;
    // }
    unique_ptr<Account> acc1;
    unique_ptr<Account> acc2;
    try
    {
        acc1 = make_unique<Checking_Account>("moe" , -2000);
        cout << *acc1 << endl;
    }
    catch(const IllegalBalanceException &ex)
    {
        cerr << ex.what() << endl;
    }
    
    try
    {
        acc1 = make_unique<Checking_Account>("larry" , 1000);
        cout << *acc1 << endl;
        acc1->withdraw(500);
        cout << *acc1 << endl;
        acc1->withdraw(1000);
        cout << *acc1 << endl;
    }
    catch(const IllegalBalanceException &ex)
    {
        cerr << ex.what() << endl;
    }
    catch(const InsufficentFundsException &ex)
    {
        cerr << ex.what() << endl;

    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}


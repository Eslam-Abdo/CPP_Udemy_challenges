#ifndef _INSUFFICENT_FUNDS_EXCEPTION_H_
#define _INSUFFICENT_FUNDS_EXCEPTION_H_
#include <iostream>

class InsufficentFundsException : public std::exception
{
public:
    InsufficentFundsException() noexcept = default;
    ~InsufficentFundsException() = default;
    virtual const char *what() const noexcept
    {
        return "Couldn't withdraw from account - negative balance";
    }
};

#endif //_INSUFFICENT_FUNDS_EXCEPTION_H_
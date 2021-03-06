#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <string>
#include "Methods.h"

using namespace std;

class Operation
{
protected:
    int date;
    string strDate;
    double amount;
    int id;
    int userId;
    string description;

public:
    string getDate();
    int getIntDate();
    double getAmount();
    int getId();
    int getUserId();
    string getDescription();

    void setDate(string date);
    void setIntDate(int date);
    void setAmount(double amount);
    void setId(int id);
    void setUserId(int userId);
    void setDescription(string description);

};



#endif

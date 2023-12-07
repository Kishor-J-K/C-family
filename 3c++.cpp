#include <iostream>
using namespace std;

class account
{
public:
    string name{"sunil"};
    double balance{1000};
};

class savings_account : public account
{
public:
    double r{0.06};
};

class checking_account : public savings_account
{
public:
    double fee{1.5};
};

class trust_account : public checking_account
{
public:
    int time{0};
    void depositmoney(int deposit)
    {
        balance += balance * r;
        if (deposit >= 5000)
        {
            balance += deposit + 50;
        }
        else
        {
            balance += deposit;
        }
        cout << "\n\namount added successfully\n";
        cout << "balance= " << balance;
    }

    void withdrawal(int withdraw)
    {
        int p = balance * 0.2;
        if (withdraw >= p && time < 3)
        {
            balance -= fee;
            balance -= withdraw;
            ++time;
            cout << "amount withdrawn successfully\n";
            cout << "current balance= " << balance;
        }
        else
        {
            if (withdraw < p)
            {
                cout << "withdrawl capacity exceeded 20%";
            }
            else
            {
                cout << "more than 3 withdrawals per year are not possible";
            }
        }
    }
};

int main()
{
    trust_account a;
    int x = 0;
    int choice;
    do
    {
        cout << "press 1 for deposit and 0 for withdrawal\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "enter amount to be added\n";
            int amount;
            cin >> amount;
            a.depositmoney(amount);
            cout << "\n\n#################################################\n"
                 << endl;
        }
        else
        {
            if (choice == 0)
            {
                cout << "enter amount to be withdrawn\n";
                int withdraw;
                cin >> withdraw;
                a.withdrawal(withdraw);
                cout << "\n\n#################################################\n"
                     << endl;
            }
        }
        x = 0;
        cout << "enter 1 to continue and any other number to close\n";
        cin >> choice;
        if (choice == 1)
        {
            x = choice;
        }
    } while (x == 1);
    return 0;
}

/* Я дуже сильно відклонився від того, що скоріш за все очікувалось.
 * Я не знаю, як це зробити з тими знаннями, які "теоретично", я маю.
 */

#include <iostream>
#include <list>

using namespace std;

class Account {
public:
    Account(string name) {
        Name = name;
    }

    string Name;
    int Balance = 0;
};

list<Account> *accountsList = new list<Account>;

Account* find_user(string userName, list<Account> *accounts) {
    for (Account& account : *accounts) {
        if (account.Name == userName)
            return &account;
    }

    return nullptr;
}

void create_account(list<Account> *accounts) {
    cout << "Enter name: ";
    string userName;
    cin >> userName;

    Account* is_user_exist = find_user(userName, accounts);
    if(is_user_exist != nullptr) {
        cout << "This name is already taken!\n";
        return;
    }

    Account user(userName);
    accounts->push_back(user);
}

void raise_balance() {
    cout << "Enter your name: ";
    string userName;
    cin >> userName;

    Account* user = find_user(userName, accountsList);
    if(user == nullptr) {
        cout << "User doesn't exist\n";
        return;
    }

    cout << "Enter number to raise: ";
    int raiseNumber;
    cin >> raiseNumber;
    user->Balance += raiseNumber;
}

void withdraw_balance() {
    cout << "Enter your name: ";
    string userName;
    cin >> userName;

    Account* user = find_user(userName, accountsList);
    if(user == nullptr) {
        cout << "User doesn't exist\n";
        return;
    }

    cout << "Enter number to withdraw: ";
    int withdrawAmount;
    cin >> withdrawAmount;

    if(user->Balance < withdrawAmount) {
        cout << "You don't have enough money to withdraw!\n";
        return;
    }

    user->Balance -= withdrawAmount;
}

void check_balance() {
    cout << "Enter your name: ";
    string userName;
    cin >> userName;

    Account* user = find_user(userName, accountsList);
    if(user == nullptr) {
        cout << "User doesn't exist\n";
        return;
    }

    cout << "Balance: " << user->Balance;
}

int main() {
    int decision;
    while(true) {
        cout << "\n1 - Create account; \n2 - Raise balance; \n3 - Withdraw balance \n4 - Check balance\n";

        cin >> decision;

        switch (decision) {
            case 1:
                create_account(accountsList);
                break;

            case 2:
                raise_balance();
                break;

            case 3:
                withdraw_balance();
                break;

            case 4:
                check_balance();
                break;

            default:
                cout << "Wrong number!";
                break;
        }
    }
}

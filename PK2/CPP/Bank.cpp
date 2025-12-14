#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string ownerName;
    double balance;
public:
    BankAccount(string num, string name, double initial = 0.0) 
        : accountNumber(num), ownerName(name), balance(initial) {}
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнено: " << fixed << setprecision(2) << amount << endl;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снято: " << fixed << setprecision(2) << amount << endl;
            return true;
        }
        cout << "Недостаточно средств!" << endl;
        return false;
    }
    
    void display() const {
        cout << "Счёт: " << accountNumber << ", Владелец: " << ownerName 
             << ", Баланс: " << fixed << setprecision(2) << balance << endl;
    }
    
    double getBalance() const { return balance; }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingsAccount(string num, string name, double rate, double initial = 0.0) 
        : BankAccount(num, name, initial), interestRate(rate) {}
    
    void addInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Начислены проценты: " << fixed << setprecision(2) << interest << endl;
    }
    
    void display() const {
        BankAccount::display();
        cout << "Процентная ставка: " << fixed << setprecision(2) << interestRate * 100 << "%" << endl;
    }
};

int main() {
    // Создание базового счёта
    BankAccount account1("1234567890", "Иванов И.И.", 1000.0);
    cout << "=== Базовый счёт ===" << endl;
    account1.display();
    account1.deposit(500.0);
    account1.withdraw(200.0);
    account1.display();
    cout << endl;
    
    // Создание сберегательного счёта (5% годовых)
    SavingsAccount account2("0987654321", "Петров П.П.", 0.05, 2000.0);
    cout << "=== Сберегательный счёт ===" << endl;
    account2.display();
    account2.deposit(1000.0);
    account2.withdraw(300.0);
    account2.addInterest();
    account2.display();
    
    return 0;
}

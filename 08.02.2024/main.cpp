#include <iostream>
#include <string>
#include <cmath>

class CurrencyExchange {
    std::string currency;
    float balance;
public:
    CurrencyExchange() :currency("RUB"), balance(0.0) {}
    CurrencyExchange(std::string currency, float balance) { 
        this->currency=currency; 
        this->balance=balance < 0 ? 0 : balance;
    }
    void show() {
        std::cout << currency + ": ";
        std::cout.precision(3);
        std::cout << balance << std::endl;
    }
    void convert(std::string outCurrency) {
        if (currency == "RUB") {
            if (outCurrency == "DOL") {
                currency = "DOL";
                balance /= 89.29;
                balance = round(balance * 100) / 100;
                return;
            }
            if (outCurrency == "EUR") {
                currency = "EUR";
                balance /= 96.79;
                balance = round(balance * 100) / 100;
                return;
            }
            return;
        }
        if (currency == "DOL") {
            if (outCurrency == "RUB") {
                currency = "RUB";
                balance *= 89.29;
                balance = round(balance * 100) / 100;
                return;
            }
            if (outCurrency == "EUR") {
                currency = "EUR";
                balance /= 1.08;
                balance = round(balance * 100) / 100;
                return;
            }
            return;
        }
        if (currency == "EUR") {
            if (outCurrency == "DOL") {
                currency = "DOL";
                balance *= 1.08;
                balance = round(balance * 100) / 100;
                return;
            }
            if (outCurrency == "RUB") {
                currency = "RUB";
                balance *= 96.79;
                balance = round(balance * 100) / 100;
                return;
            }
            return;
        }
        return;
    }
};

int main()
{
    CurrencyExchange c1("DOL", 3.50);
    c1.convert("RUB");
    c1.show();
    c1.convert("DOL");
    c1.show();
    c1.convert("EUR");
    c1.show();
}


#include "Month.h"
#include <iostream>
using namespace std;

int main() {
    Month m1;
    Month m2(3);
    Month m3("Sep");

    cout << "m1 = " << m1.get_month(Month::FULL) << endl;
    cout << "m2 = " << m2.get_month(Month::ABBREV) << endl;
    cout << "m3 = " << m3.get_month(Month::NUMBER) << endl;

    cout << "Advance m2 by 5 = " << m2.advance(5).get_month(Month::FULL) << endl;
    cout << "m3 before m2? " << (m3.before(m2) ? "yes" : "no") << endl;

    Month userMonth;
    cout << "Enter a month (int/name/abbrev): ";
    cin >> userMonth;
    cout << "You entered " << userMonth.get_month(Month::FULL) << endl;

    return 0;
}

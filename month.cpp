#include "Month.h"

const vector<string> Month::monthNames =
    {"January","February","March","April","May","June",
     "July","August","September","October","November","December"};

const vector<string> Month::monthAbbrevs =
    {"Jan","Feb","Mar","Apr","May","Jun",
     "Jul","Aug","Sep","Oct","Nov","Dec"};

Month::Month() : month(1) {}
Month::Month(int monthNum) { set_month(monthNum); }
Month::Month(const string& name) { set_month(name); }

int Month::get_month() const { return month; }
string Month::get_month(DisplayType type) const {
    if (type == NUMBER) return to_string(month);
    if (type == ABBREV) return monthAbbrevs[month-1];
    return monthNames[month-1];
}

void Month::set_month(int monthNum) {
    if (monthNum < 1 || monthNum > 12) month = 1;
    else month = monthNum;
}
void Month::set_month(const string& name) {
    month = nameToNum(name);
}

void Month::input(istream& in) {
    string token;
    in >> token;
    if (isdigit(token[0])) set_month(stoi(token));
    else set_month(token);
}
void Month::output(ostream& out, DisplayType type) const {
    out << get_month(type);
}

bool Month::before(const Month& other) const { return month < other.month; }
bool Month::after(const Month& other) const { return month > other.month; }
bool Month::same(const Month& other) const { return month == other.month; }

Month Month::advance(int n) const {
    int newMonth = ((month - 1 + n) % 12 + 12) % 12 + 1;
    return Month(newMonth);
}

int Month::nameToNum(const string& name) const {
    for (int i=0; i<12; i++) {
        if (name == monthNames[i] || name == monthAbbrevs[i]) return i+1;
    }
    return 1;
}

istream& operator>>(istream& in, Month& m) { m.input(in); return in; }
ostream& operator<<(ostream& out, const Month& m) { m.output(out, Month::FULL); return out; }

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Month {
public:
    enum DisplayType { NUMBER, ABBREV, FULL };

    Month();
    Month(int monthNum);
    Month(const string& monthName);

    int get_month() const;
    string get_month(DisplayType type) const;

    void set_month(int monthNum);
    void set_month(const string& monthName);

    void input(istream& in);
    void output(ostream& out, DisplayType type) const;

    bool before(const Month& other) const;
    bool after(const Month& other) const;
    bool same(const Month& other) const;

    Month advance(int n) const;

private:
    int month;

    static const vector<string> monthNames;
    static const vector<string> monthAbbrevs;

    int nameToNum(const string& name) const;
};

istream& operator>>(istream& in, Month& m);
ostream& operator<<(ostream& out, const Month& m);



#include "DateTime.h"

#include <iomanip>
#include <sstream>
#include <ctime>

using namespace std;

DateTime DateTime::operator + (const TimeLength p) const {
    // Extract DateTime components
    int year = std::stoi(dateTime.substr(0, 4));
    int month = std::stoi(dateTime.substr(4, 2));
    int day = std::stoi(dateTime.substr(6, 2));
    int hour = std::stoi(dateTime.substr(8, 2));
    int minute = std::stoi(dateTime.substr(10, 2));

    // Extract hours and minutes from TimeLength
    int addHours = std::stoi(p.toString().substr(0, 2));
    int addMinutes = std::stoi(p.toString().substr(2, 2));

    // Add minutes and handle overflow into hours
    minute += addMinutes;
    if (minute >= 60) {
        hour += minute / 60;
        minute %= 60;
    }

    // Add hours and handle overflow into days
    hour += addHours;
    if (hour >= 24) {
        day += hour / 24;
        hour %= 24;
    }

    // Days in each month (leap year considerations for February)
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
        days_in_month[1]++; // Feb is 29 days now

    // Adjust day, month, year for overflow
    while (day > days_in_month[month - 1]) {
        day -= days_in_month[month - 1];
        month += 1;
        if (month > 12) {
            month = 1;
            year += 1;
        }
    }

    // Convert back to string format
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << year
        << std::setw(2) << std::setfill('0') << month
        << std::setw(2) << std::setfill('0') << day
        << std::setw(2) << std::setfill('0') << hour
        << std::setw(2) << std::setfill('0') << minute;

    return DateTime(oss.str().c_str());
}

std::istream & operator >> (std::istream & is, TimeLength & tl) {
    int lh, lm;
    is >> lh >> lm;

    ostringstream ostr;
    ostr << std::setw(2) << std::setfill('0') << lh <<
            std::setw(2) << std::setfill('0') << lm;

    tl.length = ostr.str();

    return is;
}

std::istream & operator >> (std::istream & is, DateTime & dt) {
    int year, month, day, hour, minute;
    is >> year >> month >> day >> hour >> minute;

    ostringstream ostr;
    ostr << std::setw(4) << std::setfill('0') << year <<
            std::setw(2) << std::setfill('0') << month << 
            std::setw(2) << std::setfill('0') << day <<
            std::setw(2) << std::setfill('0') << hour << 
            std::setw(2) << std::setfill('0') << minute;

    dt.dateTime = ostr.str();

    return is;
}

std::istream & operator >> (std::istream & is, DateTimePeriod & dtp) {

    is >> static_cast<DateTime&>(dtp);
    is >> dtp.length;

    return is;
}

bool DateTimePeriod::doesOverlapWith(const DateTimePeriod & other) const {

    DateTime thisEndTime = *this + length;
    DateTime otherEndTime = other + other.length;

    // check if *this finishes before other starts, AND other finishes before *this ends, 
    //   OR
    // other starts before *this, AND this finishes AFTER other
    if ( (thisEndTime <= other) ||
         (otherEndTime <= *this) )
        return false;

    return true;
}


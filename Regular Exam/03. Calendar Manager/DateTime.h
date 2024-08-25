#ifndef __DATETIME_H
#define __DATETIME_H

#include <iostream>
#include <string>

class TimeLength {

        std::string length;

    public:

        TimeLength() : length("0000") {}
        TimeLength(std::istream & is) { is >> *this; }

        std::string toString(void) const { return length; }

        bool operator <  (const TimeLength & other) const { return length  < other.length; }
        bool operator <= (const TimeLength & other) const { return length <= other.length; }
        bool operator >= (const TimeLength & other) const { return length >= other.length; }

        friend std::istream & operator >> (std::istream & is, TimeLength &);        
};

class DateTime {

    std::string dateTime; // YYYYMMDDHHMM

    public:

        DateTime(const char * c = "000000000000") : dateTime(c) {};
        DateTime(std::istream & is) { is >> *this; }

        bool operator <  (const DateTime & other) const { return dateTime  < other.dateTime; }
        bool operator <= (const DateTime & other) const { return dateTime <= other.dateTime; }
        bool operator >= (const DateTime & other) const { return dateTime >= other.dateTime; }

        DateTime operator + (const TimeLength p) const;

        virtual std::string toString(void) const { return dateTime; }

        friend std::istream & operator >> (std::istream & is, DateTime &);
};

class DateTimePeriod : public DateTime {

    TimeLength length;

    public:

        DateTimePeriod() = default;
        DateTimePeriod(std::istream & is) { is >> *this; }

        bool operator < (const DateTimePeriod & other) const {
            bool bRes = this->toString() < other.toString();
            return bRes;
        }

        bool doesOverlapWith(const DateTimePeriod & other) const;

        virtual std::string toString(void) const override { return DateTime::toString() + length.toString(); }

        friend std::istream & operator >> (std::istream & is, DateTimePeriod &);

};


#endif
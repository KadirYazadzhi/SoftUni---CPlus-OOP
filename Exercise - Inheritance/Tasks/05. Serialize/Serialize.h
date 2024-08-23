#ifndef SERIALIZE_H
#define SERIALIZE_H

#include "Company.h"
#include <string>
#include <vector>
#include <sstream>

class SerializableCompany : public Company {
public:
    void serialize (std::vector<byte> & output) const {
        serializeId(output);
        serializeName(output);
        serializeEmployees(output);
    }

protected:
    void serializeId(std::vector<byte> & output) const {
        output.push_back((byte)getId());
    }

    void serializeName(std::vector<byte> & output) const {
        const std::string & name = getName();
        for (char c : name) {
            output.push_back(c);
        }
        output.push_back(0);
    }

    void serializeEmployees(std::vector<byte> & output) const {
        const std::vector<std::pair<char, char>> & empl = getEmployees();

        output.push_back((byte)empl.size());
        for (const std::pair<char, char> & e : empl) {
            output.push_back(e.first);
            output.push_back(e.second);
        }
    }

};

byte * serializeToMemory(const std::string & data, size_t & bytesWritten) {
    std::vector<byte> output(1, 0);

    std::istringstream istr(data);

    SerializableCompany c;
    while (istr >> c) {
        output[0]++;

        c.serialize(output);
    }

    bytesWritten = output.size();
    byte * result = new byte[bytesWritten];
    std::copy(output.begin(), output.end(), result);

    return result;
}

#endif

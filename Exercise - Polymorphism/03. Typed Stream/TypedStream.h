#ifndef TYPEDSTREAM_H
#define TYPEDSTREAM_H

#include <sstream>
#include <vector>

template<typename T>
class TypedStream {
protected:
    std::istringstream stream;

public:
    TypedStream(const std::string & input) : stream(input) {}
    virtual ~TypedStream() = default;

    virtual TypedStream<T> & operator >> (T & i) {
        return *this;
    }

    std::vector<T> readToEnd() {
        std::vector<T> res;

        t curr;
        while (true) {
            *this >> curr;
            if ((bool) stream == false) {
                break;
            }

            res.push_back(curr);
        }

        return res;
    }
};

#endif

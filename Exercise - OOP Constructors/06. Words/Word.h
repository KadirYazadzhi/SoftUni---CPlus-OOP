#ifndef WORD_H
#define WORD_H

#include <string>

class Word {
private:
    std::string word;
    mutable int count;

public:
    Word (const std::string & word) : word(word), count(1) {

    }

    const std::string & getWord() const {
        return word;
    }

    int getCount() const {
        return count;
    }

    bool operator < (const Word & other) const {
        if (other.word == word) {
            count++;
        }

        return word < other.word;
    }

};

#endif

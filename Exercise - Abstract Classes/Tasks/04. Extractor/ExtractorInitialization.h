#ifndef EXTRACTORINITIALIZATION_H
#define EXTRACTORINITIALIZATION_H

#include <memory>
#include <sstream>
#include "Extractor.h"

class DigitsExtractor : public Extractor {
    public:
        DigitsExtractor(std::istream & istr) : Extractor(istr) {}
        virtual bool process(char symbol, std::string & output) override {
            if (symbol >= '0' && symbol <= '9') {
                output = std::string(1, symbol);
                return true;
            }

            return false;
        }
};

class NumbersExtractor : public BufferedExtractor {
    public:
        NumbersExtractor(std::istream & istr) : BufferedExtractor(istr) {}

        virtual bool shouldBuffer(char symbol) override {
            return symbol >= '0' && symbol <= '9';
        }
};

class QuotedExtractor : public BufferedExtractor {
    private:
        bool isBuffering;
    public:
        QuotedExtractor(std::istream & istr) : BufferedExtractor(istr), isBuffering(false) {}

        virtual bool shouldBuffer(char symbol) override {
            if (symbol == '"') {
                isBuffering = !isBuffering;
                return false;
            }
            else {
                return isBuffering;
            }
        }
};

std::shared_ptr<Extractor> getExtractor(const std::string & extractType, std::istringstream & lineIn) {
    switch(extractType[0]) {
        case 'd':
            return std::make_shared<DigitsExtractor>(lineIn);
            break;
        case 'n':
            return std::make_shared<NumbersExtractor>(lineIn);
            break;
        default:
            return std::make_shared<QuotedExtractor>(lineIn);
            break;
    }

    return std::shared_ptr<Extractor>();
}

#endif

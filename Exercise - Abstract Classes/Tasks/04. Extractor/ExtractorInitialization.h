#ifndef EXTRACTORINITIALIZATION_H
#define EXTRACTORINITIALIZATION_H

#include <memory>
#include <string>
#include <istream>
#include <cctype>
#include <sstream>

#include "Extractor.h"
#include "BufferedExtractor.h"

class DigitsExtractor: public Extractor {

public:
    DigitsExtractor(std::istream & istr) : Extractor(istr) {};

    virtual bool process(char symbol, std::string & output){
        if (symbol>='0' && symbol <='9'){
            output=std::string(1,symbol);
            return true;
        };
        return false;
    };
};

class NumbersExtractor: public Extractor {

    std::string result;

public:
    NumbersExtractor(std::istream & istr) : Extractor(istr) {};

protected:
    virtual bool process(char symbol, std::string & output){
        if (isdigit(symbol)) {
            result+=std::string(1,symbol);
            return false;
        }
        else if (result.size()) {
            output=result;
            result.erase();
            return true;
        };
        return false;
    };
};

class QuotesExtractor: public Extractor {

    std::string result;
    bool extracting;

public:
    QuotesExtractor(std::istream & istr) : Extractor(istr), extracting(false) {};

protected:
    virtual bool process(char symbol, std::string & output){
        if(extracting) {
            if (symbol=='"') {
                output=result;
                result.erase();
                extracting=false;
                return true;
            }
            else {
                result+=symbol;
            };
        }
        else {
            if (symbol=='"') {
                extracting=true;
            };
        };
        return false;
    };
};

std::shared_ptr<Extractor> getExtractor(const std::string & extractType, std::istream & lineIn) {

    if (extractType=="digits") {
        return std::shared_ptr<Extractor>(new DigitsExtractor(lineIn));
    }
    else if (extractType=="numbers") {
        return std::shared_ptr<Extractor>(new NumbersExtractor(lineIn));
    }
    else {
        return std::shared_ptr<Extractor>(new QuotesExtractor(lineIn));
    }


    return std::shared_ptr<Extractor>(nullptr);
};

#endif


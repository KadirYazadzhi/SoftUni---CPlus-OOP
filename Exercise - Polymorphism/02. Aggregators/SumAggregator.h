#ifndef SUMAGGREGATOR_H
#define SUMAGGREGATOR_H

#include "Aggregator.h"

class SumAggregator : public StreamAggregator {

public:
    SumAggregator(std::istream & istr) : StreamAggregator(istr) {
        aggregationResult = 0;
    }

    virtual void aggregate(int next) {
        StreamAggregator::aggregate(next);
        aggregationResult += next;
    }
};

#endif

#ifndef MINAGGREGATOR_H
#define MINAGGREGATOR_H

#include <climits>

class MinAggregator : public StreamAggregator {

public:
    MinAggregator(std::istream & istr) : StreamAggregator(istr) {
        aggregationResult = INT_MAX;
    }

    virtual void aggregate(int next) {
        StreamAggregator::aggregate(next);
        if (next < aggregationResult) {
            aggregationResult = next;
        }
    }
};

#endif

#ifndef AVERAGEAGGREGATOR_H
#define AVERAGEAGGREGATOR_H

class AverageAggregator : public StreamAggregator {
private:
    int sum;

public:
    AverageAggregator(std::istream & istr) : StreamAggregator(istr), sum(0) {
        aggregationResult = 0;
    }

    virtual void aggregate(int next) {
        StreamAggregator::aggregate(next);

        sum += next;
        aggregationResult = sum / getNumAggregated();
    }
};

#endif

#ifndef COMPARATORS_H
#define COMPARATORS_H

template<typename T> class LessThan {
    public:
        bool operator()(const T & a, const T & b) const {
            return a < b;
        }

};

template<typename T, typename Comparator>
class Reverse {
    public:
        bool operator() (const T & first, const T & second) const {
            Comparator comp;
            return !comp(first, second);
        }
};



#endif

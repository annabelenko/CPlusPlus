#ifndef UPPER_BOUNDED_COUNTER_H
#define UPPER_BOUNDED_COUNTER_H

#include "counter.h"

class UpperBoundedCounter : virtual public Counter {
protected:
    int upper_;

public:
    explicit UpperBoundedCounter(int upper) : Counter(), upper_(upper) {}

    int upperBound() const { return upper_; }

    UpperBoundedCounter& operator++() override {
        if (value_ < upper_) ++value_;
        return *this;
    }

    Counter operator++(int) override {
        Counter tmp(*this);
        ++(*this);
        return tmp;
    }

    std::ostream& print(std::ostream& os) const override {
        os << "An UpperBoundedCounter with bound: " << upper_
           << " and current value: " << value_;
        return os;
    }
};

#endif
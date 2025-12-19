#ifndef LOWER_BOUNDED_COUNTER_H
#define LOWER_BOUNDED_COUNTER_H

#include "counter.h"

class LowerBoundedCounter : virtual public Counter {
protected:
    int lower_;

public:
    explicit LowerBoundedCounter(int lower) : Counter(), lower_(lower) {}

    int lowerBound() const { return lower_; }

    LowerBoundedCounter& operator--() override {
        if (value_ > lower_) --value_;
        return *this;
    }

    Counter operator--(int) override {
        Counter tmp(*this);
        --(*this);
        return tmp;
    }

    std::ostream& print(std::ostream& os) const override {
        os << "A LowerBoundedCounter with bound: " << lower_
           << " and current value: " << value_;
        return os;
    }
};

#endif
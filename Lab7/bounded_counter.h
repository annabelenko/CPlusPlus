#ifndef BOUNDED_COUNTER_H
#define BOUNDED_COUNTER_H

#include "upper_bounded_counter.h"
#include "lower_bounded_counter.h"

class BoundedCounter : public UpperBoundedCounter, public LowerBoundedCounter {
public:
    BoundedCounter(int lower, int upper)
        : Counter(), UpperBoundedCounter(upper), LowerBoundedCounter(lower) {}

    BoundedCounter& operator++() override {
        if (value_ < upper_) ++value_;
        return *this;
    }

    BoundedCounter& operator--() override {
        if (value_ > lower_) --value_;
        return *this;
    }

    Counter operator++(int) override {
        Counter tmp(*this);
        ++(*this);
        return tmp;
    }

    Counter operator--(int) override {
        Counter tmp(*this);
        --(*this);
        return tmp;
    }

    std::ostream& print(std::ostream& os) const override {
        os << "A BoundedCounter with bounds: (" << lower_ << ", " << upper_
           << ") and current value: " << value_;
        return os;
    }
};

#endif
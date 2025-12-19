#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

class Counter {
protected:
    int value_;

public:
    Counter() : value_(0) {}

    int get() const { return value_; }
    void reset() { value_ = 0; }

    virtual Counter& operator++() { ++value_; return *this; }
    virtual Counter& operator--() { --value_; return *this; }

    virtual Counter operator++(int) { Counter tmp(*this); ++(*this); return tmp; }
    virtual Counter operator--(int) { Counter tmp(*this); --(*this); return tmp; }

    virtual ~Counter() = default;

    virtual std::ostream& print(std::ostream& os) const {
        os << "A Counter with current value: " << value_;
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const Counter& c) {
        return c.print(os);
    }
};

#endif
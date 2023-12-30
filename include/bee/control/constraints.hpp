#pragma once

#include "controller.hpp"

namespace bee {

template <typename Error>
class HasError {
public:
	virtual Error getError() = 0;
};

class HasTime {
public:
    virtual uint32_t getRuntime() = 0;
};

}
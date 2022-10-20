#pragma once

#include <exception>


class bad_stack_capacity : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return exception::what();
    }
};

class pop_out_of_index : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return exception::what();
    }
};
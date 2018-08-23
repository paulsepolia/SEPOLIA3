#pragma once

#include <memory>
#include <vector>
#include "../dense_container/dense_container.h"

namespace sepolia {

    template<typename T>
    class dense_vector : public dense_container<T> {

    public:

        explicit dense_vector<T>();

        explicit dense_vector<T>(const uint64_t &, const T & = 0);

        dense_vector<T>(const dense_vector<T> &);

        dense_vector<T>(dense_vector<T> &&) noexcept;

        virtual ~dense_vector();

        dense_vector<T> &operator=(const std::vector<T> &);

        dense_vector<T> &operator=(std::vector<T> &&);

        dense_vector<T> &operator=(const dense_vector<T> &);

        dense_vector<T> &operator=(dense_vector<T> &&) noexcept;

        dense_vector<T> &operator=(const dense_container<T> &);

        dense_vector<T> &operator=(dense_container<T> &&) noexcept;

        dense_vector<T> &operator=(const T &);
    };
}

#pragma once

#include <memory>
#include "../dense_container/dense_container.h"

namespace sepolia {

    template<typename T>
    class dense_matrix : public dense_container<T> {

    public:

        explicit dense_matrix<T>();

        explicit dense_matrix<T>(const uint64_t &, const uint64_t &);

        dense_matrix<T>(const dense_matrix<T> &);

        dense_matrix<T>(dense_matrix<T> &&) noexcept;

        virtual ~dense_matrix();

        dense_matrix<T> &operator=(const dense_matrix<T> &);

        dense_matrix<T> &operator=(dense_matrix<T> &&) noexcept;

        dense_matrix<T> &operator=(const dense_container<T> &);

        dense_matrix<T> &operator=(dense_container<T> &&) noexcept;

        dense_matrix<T> &operator=(const T &) final;
    };
}

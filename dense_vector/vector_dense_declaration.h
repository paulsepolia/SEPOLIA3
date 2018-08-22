#pragma once

#include <memory>
#include <vector>
#include "../dense_container/dense_container.h"

namespace sepolia {

    template<typename T>
    class vector_dense : public dense_container<T> {

    public:

        explicit vector_dense<T>();

        explicit vector_dense<T>(const uint64_t &, const T & = 0);

        vector_dense<T>(const vector_dense<T> &);

        vector_dense<T>(vector_dense<T> &&) noexcept;

        virtual ~vector_dense();

        vector_dense<T> &operator=(const std::vector<T> &);

        vector_dense<T> &operator=(std::vector<T> &&);

        vector_dense<T> &operator=(const vector_dense<T> &);

        vector_dense<T> &operator=(vector_dense<T> &&) noexcept;

        vector_dense<T> &operator=(const dense_container<T> &);

        vector_dense<T> &operator=(dense_container<T> &&) noexcept;

        vector_dense<T> &operator=(const T &);
    };
}

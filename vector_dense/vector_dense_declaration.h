#pragma once

#include <vector>
#include <memory>

namespace sepolia {

    template<typename T>
    class vector_dense {

    public:

        explicit vector_dense<T>();

        explicit vector_dense<T>(const uint64_t &dim, const T &val = 0);

        vector_dense<T>(const vector_dense<T> &);

        vector_dense<T>(vector_dense<T> &&) noexcept;

        virtual ~vector_dense();

        uint64_t size() const;

        void allocate(const uint64_t &);

        bool allocated() const;

        void deallocate();

        bool deallocated() const;

        vector_dense<T> &operator=(const std::vector<T> &);

        vector_dense<T> &operator=(std::vector<T> &&);

        vector_dense<T> &operator=(const vector_dense<T> &);

        vector_dense<T> &operator=(const T &);

        vector_dense<T> &operator=(vector_dense<T> &&) noexcept;

        T &operator()(const uint64_t &) const;

        T &operator[](const uint64_t &) const;

        void set(const T &);

        void set(const vector_dense<T> &);

        T *begin();

        const T *begin() const;

        T *end();

        const T *end() const;

    private:

        uint64_t _dimension;
        bool _allocated;
        std::shared_ptr<T> _vdsp;
    };
}

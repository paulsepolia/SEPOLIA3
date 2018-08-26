#pragma once

#include <memory>
#include <vector>
#include <complex>

namespace sepolia {

    template<typename T>
    class dense_container {

    public:

        explicit dense_container<T>();

        explicit dense_container<T>(const uint64_t &);

        explicit dense_container<T>(const uint64_t &, const uint64_t &);

        dense_container<T>(const dense_container<T> &);

        dense_container<T>(dense_container<T> &&) noexcept;

        virtual ~dense_container();

    public:

        void allocate(const uint64_t &);

        void allocate(const uint64_t &, const uint64_t &);

        bool allocated() const;

        void deallocate();

        bool deallocated() const;

        uint64_t size() const;

        uint64_t rows() const;

        uint64_t columns() const;

        virtual dense_container<T> &operator=(const std::vector<T> &);

        virtual dense_container<T> &operator=(std::vector<T> &&);

        dense_container<T> &operator=(const dense_container<T> &);

        virtual dense_container<T> &operator=(const T &);

        dense_container<T> &operator=(dense_container<T> &&) noexcept;

        T &operator()(const uint64_t &) const;

        T &operator()(const uint64_t &, const uint64_t &) const;

        T &operator[](const uint64_t &) const;

        dense_container<T> operator+(const dense_container<T> &) const;

        dense_container<T> operator+(const T &) const;

        template<typename T2>
        friend dense_container<T2> operator+(const T2 &,
                                             const dense_container<T2> &);

        dense_container<T> operator-(const dense_container<T> &) const;

        dense_container<T> operator-(const T &) const;

        template<typename T2>
        friend dense_container<T2> operator-(const T2 &,
                                             const dense_container<T2> &);

        dense_container<T> operator*(const dense_container<T> &) const;

        dense_container<T> operator*(const T &) const;

        template<typename T2>
        friend dense_container<T2> operator*(const T2 &,
                                             const dense_container<T2> &);

        dense_container<T> operator/(const dense_container<T> &) const;

        dense_container<T> operator/(const T &) const;

        template<typename T2>
        friend dense_container<T2> operator/(const T2 &,
                                             const dense_container<T2> &);

        dense_container<T> operator+=(const dense_container<T> &);

        dense_container<T> operator+=(const T &);

        dense_container<T> operator-=(const dense_container<T> &);

        dense_container<T> operator-=(const T &);

        dense_container<T> operator*=(const dense_container<T> &);

        dense_container<T> operator*=(const T &);

        dense_container<T> operator/=(const dense_container<T> &);

        dense_container<T> operator/=(const T &);

        dense_container<T> operator++();

        const dense_container<T> operator++(int);

        dense_container<T> operator--();

        const dense_container<T> operator--(int);

        bool operator==(const dense_container<T> &) const;

        bool operator==(const T &) const;

        template<typename T2>
        friend bool operator==(const T2 &, const dense_container<T2> &);

        bool operator!=(const dense_container<T> &) const;

        bool operator!=(const T &) const;

        template<typename T2>
        friend bool operator!=(const T2 &, const dense_container<T2> &);

        T *begin();

        const T *begin() const;

        T *end();

        const T *end() const;

        const T &at(const uint64_t &) const;

        const T &at(const uint64_t &, const uint64_t &) const;

        void swap(dense_container<T> &);

        bool empty() const;

        void set(const T &);

        void set(const dense_container<T> &);

        dense_container<T> plus(const dense_container<T> &) const;

        dense_container<T> plus(const T &) const;

        dense_container<T> subtract(const dense_container<T> &) const;

        dense_container<T> subtract(const T &) const;

        dense_container<T> times(const dense_container<T> &) const;

        dense_container<T> times(const T &) const;

        dense_container<T> divide(const dense_container<T> &) const;

        dense_container<T> divide(const T &) const;

        bool equal(const dense_container<T> &) const;

        bool equal(const T &) const;

        uint64_t _rows;
        uint64_t _columns;
        uint64_t _dimension;
        bool _allocated;
        std::shared_ptr<T> _dsp;
    };
}

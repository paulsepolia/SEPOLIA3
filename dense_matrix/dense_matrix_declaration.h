#pragma once

#include <memory>

namespace sepolia {

    template<typename T>
    class dense_matrix {

    public:

        explicit dense_matrix<T>();

        explicit dense_matrix<T>(const uint64_t &rows,
                                 const uint64_t &cols,
                                 const T &val = 0);

        dense_matrix<T>(const dense_matrix<T> &);

        dense_matrix<T>(dense_matrix<T> &&) noexcept;

        virtual ~dense_matrix();

        uint64_t rows() const;

        uint64_t columns() const;

        void allocate(const uint64_t &, const uint64_t &);

        bool allocated() const;

        void deallocate();

        bool deallocated() const;

        // operators

        dense_matrix<T> &operator=(const dense_matrix<T> &);

        dense_matrix<T> &operator=(const T &);

        dense_matrix<T> &operator=(dense_matrix<T> &&) noexcept;

        T &operator()(const uint64_t &, const uint64_t &) const;

        dense_matrix<T> operator+(const dense_matrix<T> &) const;

        dense_matrix<T> operator+(const T &) const;

        template<typename T2>
        friend dense_matrix<T2> operator+(const T2 &,
                                          const dense_matrix<T2> &);

        dense_matrix<T> operator-(const dense_matrix<T> &) const;

        dense_matrix<T> operator-(const T &) const;

        template<typename T2>
        friend dense_matrix<T2> operator-(const T2 &,
                                          const dense_matrix<T2> &);

        dense_matrix<T> operator*(const dense_matrix<T> &) const;

        dense_matrix<T> operator*(const T &) const;

        template<typename T2>
        friend dense_matrix<T2> operator*(const T2 &,
                                          const dense_matrix<T2> &);

        dense_matrix<T> operator/(const dense_matrix<T> &) const;

        dense_matrix<T> operator/(const T &) const;

        template<typename T2>
        friend dense_matrix<T2> operator/(const T2 &,
                                          const dense_matrix<T2> &);

        dense_matrix<T> operator+=(const dense_matrix<T> &);

        dense_matrix<T> operator+=(const T &);

        dense_matrix<T> operator-=(const dense_matrix<T> &);

        dense_matrix<T> operator-=(const T &);

        dense_matrix<T> operator*=(const dense_matrix<T> &);

        dense_matrix<T> operator*=(const T &);

        dense_matrix<T> operator/=(const dense_matrix<T> &);

        dense_matrix<T> operator/=(const T &);

        dense_matrix<T> operator++();

        const dense_matrix<T> operator++(int);

        dense_matrix<T> operator--();

        const dense_matrix<T> operator--(int);

        bool operator==(const dense_matrix<T> &) const;

        bool operator==(const T &) const;

        template<typename T2>
        friend bool operator==(const T2 &, const dense_matrix<T2> &);

        bool operator!=(const dense_matrix<T> &) const;

        bool operator!=(const T &) const;

        template<typename T2>
        friend bool operator!=(const T2 &, const dense_matrix<T2> &);

        T *begin();

        const T *begin() const;

        T *end();

        const T *end() const;

        const T &at(const uint64_t &, const uint64_t &) const;

        void swap(dense_matrix<T> &);

        bool empty() const;

    private:

        void set(const T &);

        void set(const dense_matrix<T> &);

        dense_matrix<T> plus(const dense_matrix<T> &) const;

        dense_matrix<T> plus(const T &) const;

        dense_matrix<T> subtract(const dense_matrix<T> &) const;

        dense_matrix<T> subtract(const T &) const;

        dense_matrix<T> times(const dense_matrix<T> &) const;

        dense_matrix<T> times(const T &) const;

        dense_matrix<T> divide(const dense_matrix<T> &) const;

        dense_matrix<T> divide(const T &) const;

        bool equal(const dense_matrix<T> &) const;

        bool equal(const T &) const;

    private:

        uint64_t _rows;
        uint64_t _columns;
        bool _allocated;
        std::shared_ptr<T> _mdsp;
    };
}

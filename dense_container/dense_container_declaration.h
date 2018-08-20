#pragma once

#include <memory>

namespace sepolia {

    template<typename T>
    class dense_container {

    protected:

        explicit dense_container<T>();

        explicit dense_container<T>(const uint64_t &,const T &val = 0);

        dense_container<T>(const dense_container<T> &);

        dense_container<T>(dense_container<T> &&) noexcept;

    public:

        virtual ~dense_container();

        void allocate(const uint64_t &);

        bool allocated() const;

        void deallocate();

        bool deallocated() const;

        // operators

        dense_container<T> &operator=(const dense_container<T> &);

        dense_container<T> &operator=(const T &);

        dense_container<T> &operator=(dense_container<T> &&) noexcept;

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

        const T &at(const uint64_t &, const uint64_t &) const;

        void swap(dense_container<T> &);

        bool empty() const;

    private:

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

    private:

        uint64_t _dimension;
        bool _allocated;
        std::shared_ptr<T> _dsp;
    };
}

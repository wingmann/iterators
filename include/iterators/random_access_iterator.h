#ifndef WINGMANN_ITERATORS_RANDOM_ACCESS_ITERATOR_H
#define WINGMANN_ITERATORS_RANDOM_ACCESS_ITERATOR_H

#include <iterator>

namespace wingmann::containers::iterators {

template<typename Type>
class random_access_iterator {
    Type* iterator_;

public:
    // Aliases
    using value_type        = Type;
    using reference         = value_type&;
    using pointer           = value_type*;
    using iterator_category = std::random_access_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using iterator_concept  = std::contiguous_iterator_tag;

    constexpr random_access_iterator(Type* iter = nullptr) : iterator_{iter}
    {
    }

    constexpr auto operator<=>(const random_access_iterator&) const = default;
    constexpr reference operator*() const noexcept
    {
        return *iterator_;
    }

    constexpr pointer operator->() const noexcept
    {
        return iterator_;
    }

    constexpr random_access_iterator& operator++() noexcept
    {
        ++iterator_;
        return *this;
    }

    constexpr random_access_iterator operator++(int) noexcept
    {
        random_access_iterator tmp(*this); ++(*this);
        return tmp;
    }

    constexpr random_access_iterator& operator--() noexcept
    {
        --iterator_;
        return *this;
    }

    constexpr random_access_iterator operator--(int) noexcept
    {
        random_access_iterator tmp(*this);
        --(*this);
        return tmp;
    }

    constexpr random_access_iterator& operator+=(const difference_type other) noexcept
    {
        iterator_ += other;
        return *this;
    }

    constexpr random_access_iterator& operator-=(const difference_type other) noexcept
    {
        iterator_ -= other;
        return *this;
    }

    friend constexpr random_access_iterator operator+(
        difference_type first,
        const random_access_iterator& other) noexcept
    {
        return other.iterator_ + first;
    }

    friend constexpr random_access_iterator operator+(
        const random_access_iterator& first,
        difference_type other) noexcept
    {
        return first.iterator_ + other;
    }

    friend constexpr random_access_iterator operator-(
        const random_access_iterator& first,
        const difference_type other) noexcept
    {
        return first.iterator_ - other;
    }

    constexpr difference_type operator-(const random_access_iterator& other) const noexcept {
        return std::distance(iterator_, other.iterator_);
    }

    constexpr reference operator[](std::size_t index) const {
        return iterator_[index];
    }

    constexpr friend bool operator==(
        const random_access_iterator& first,
        const random_access_iterator& second)
    {
        return first.iterator_ == second.iterator_;
    }
};

} // namespace wingmann::iterators

#endif // WINGMANN_ITERATORS_RANDOM_ACCESS_ITERATOR_H

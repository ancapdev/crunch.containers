// Copyright (c) 2011, Christian Rorvik
// Distributed under the Simplified BSD License (See accompanying file LICENSE.txt)

#ifndef CRUNCH_CONTAINERS_UTILITY_HPP
#define CRUNCH_CONTAINERS_UTILITY_HPP

#include <iterator>
#include <utility>

namespace Crunch { namespace Containers {

// TODO: Specialize for POD types by simple memmove
template<typename InputIt, typename ForwardIt>
ForwardIt UninitializedMove(InputIt first, InputIt last, ForwardIt dest)
{
    typedef typename std::iterator_traits<ForwardIt>::value_type DestValueType;

    ForwardIt current = dest;
    try
    {
        for (; first != last; ++first, ++current)
            new (&*current) DestValueType(std::move(*first));
    }
    catch (...)
    {
        for (; dest != current; ++dest)
            (*dest).~DestValueType();

        throw;
    }

    return current;
}

template<typename InputIt, typename ForwardIt>
ForwardIt Move(InputIt first, InputIt last, ForwardIt dest)
{
    for (; first != last; ++first, ++dest)
        *dest = std::move(*first);

    return dest;
}

template<typename Iterator>
void Destroy(Iterator first, Iterator last)
{
    typedef typename std::iterator_traits<Iterator>::value_type ValueType;
    for (; first != last; ++first)
        (*first).~ValueType();
}

template<typename Iterator, typename Allocator>
void Destroy(Iterator first, Iterator last, Allocator& allocator)
{
    for (; first != last; ++first)
        allocator.destroy(first);
}

}}

#endif
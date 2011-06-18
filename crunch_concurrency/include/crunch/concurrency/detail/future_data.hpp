#ifndef CRUNCH_CONCURRENCY_DETAIL_FUTURE_DATA_HPP
#define CRUNCH_CONCURRENCY_DETAIL_FUTURE_DATA_HPP

#include "crunch/concurrency/atomic_waiter_list.hpp"

#include <type_traits>
#include <utility>
#include <cstddef>

namespace Crunch { namespace Concurrency { namespace Detail {

template<typename T>
class FutureData
{
public:
    void Set(T const& value)
    {
        ::new (ResultAddress()) T(value);
    }

    void Set(T&& value)
    {
        ::new (ResultAddress()) T(std::move(value));
    }
    

private:
    typedef std::aligned_storage<sizeof(T), std::alignment_of<T>::value> StorageType;

    void* ResultAddress() { return reintpret_cast<void*>(&mResult); }

    AtomicWaiterList mWaiters;
    StorageType mResult;
};

}}}

#endif

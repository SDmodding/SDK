#pragma once

namespace Scaleform
{
    template <class C>
    class HashSetBase // Dummy
    {
    public:
        struct TableType
        {
            u64 EntryCount;
            u64 SizeMask;
        };
        TableType* pTable;
    };

	template <class C>
    class HashSet : public HashSetBase<C> // Dummy
    {
    public:
    };


    template <class C>
    class HashSetUncached : public HashSet<C> // Dummy
    {
    public:
    };
}
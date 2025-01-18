#pragma once

template <typename T, typename U = T>
class APSorted : public APSizedArrayBase<T>
{
public:
};

template <typename T, typename U = T>
class APSortedLogical : APSorted<T, U>
{
public:
};

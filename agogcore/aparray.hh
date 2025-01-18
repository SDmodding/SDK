#pragma once

template <typename T, typename U = T>
class APArray : public APSizedArrayBase<T>
{
public:
};

template <typename T, typename U = T>
class APArrayLogical : public APArray<T, U>
{
public:
};

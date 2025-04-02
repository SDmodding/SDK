#pragma once

template <typename T>
class APCompactArrayBase : public APArrayBase<T>
{
public:
};

template <typename T, typename U = T, int compare = 0>
class APCompactArray : public APCompactArrayBase<T>
{
public:
};

template <typename T, typename U = T>
class APCompactArrayLogical : public APCompactArray<T, U>
{
public:
};

template <typename T, typename U = T>
class APCompactArrayFree : APCompactArray<T, U>
{
public:
};

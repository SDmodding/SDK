#pragma once

template <typename T, typename U = T, int compare = 0>
class AVCompactSorted : public AVCompactArrayBase<T>
{
public:
};

template <typename T, typename U = T>
class AVCompactSortedLogical : public AVCompactSorted<T, U>
{
public:
};
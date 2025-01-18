#pragma once

template <typename T, typename U = T>
class AListNode
{
public:
	AListNode<T, U>* i_next_p;
	AListNode<T, U>* i_prev_p;
};

template <typename T, typename U = T>
class AList
{
public:
	AListNode<T, U> i_sentinel;
};
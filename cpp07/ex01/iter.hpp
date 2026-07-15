#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>  // size_t

// ─── iter ────────────────────────────────────────────────────────────────────
// Applies function f to each element of the array pointed to by ptr.
// Parameters:
//   ptr    — pointer to the first element of the array
//   length — number of elements
//   f      — any callable that accepts a (T &) or (T const &)
//
// Two overloads so iter works on both const and non-const arrays:

template <typename T, typename F>
void iter(T *ptr, std::size_t length, F f)
{
	for (std::size_t i = 0; i < length; ++i)
		f(ptr[i]);
}

template <typename T, typename F>
void iter(T const *ptr, std::size_t length, F f)
{
	for (std::size_t i = 0; i < length; ++i)
		f(ptr[i]);
}

#endif

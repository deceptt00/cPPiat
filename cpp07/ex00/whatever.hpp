#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// ─── swap ────────────────────────────────────────────────────────────────────
// Swaps the values of two objects of the same type in-place.
// T must support copy construction and assignment.

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// ─── min ────────────────────────────────────────────────────────────────────
// Returns a const reference to the smaller of a and b.
// If equal, returns b.

template <typename T>
T const &min(T const &a, T const &b)
{
	return (b < a) ? b : a;
}

// ─── max ────────────────────────────────────────────────────────────────────
// Returns a const reference to the larger of a and b.
// If equal, returns b.

template <typename T>
T const &max(T const &a, T const &b)
{
	return (b > a) ? b : a;
}

#endif

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <cstddef>  // size_t

// ─── Array<T> ────────────────────────────────────────────────────────────────
// A simple heap-allocated array template.
//
// Requirements from the subject:
//   - Default constructor: empty array (size 0)
//   - Constructor(unsigned int n): zero-initialised array of n elements
//   - Copy constructor and assignment operator (deep copy)
//   - operator[]: element access; throws std::exception if out of bounds
//   - size(): returns number of elements; does not modify the object
//   - Elements initialised by the default constructor of T

template <typename T>
class Array
{
	public:
		// ── Constructors / Destructor ────────────────────────────────────
		Array() : _data(NULL), _size(0) {}

		Array(unsigned int n) : _data(new T[n]()), _size(n) {}
		// Note: new T[n]() value-initialises each element (zero for scalars,
		// default constructor for classes). Without (), memory is uninitialised.

		Array(const Array &src) : _data(NULL), _size(0)
		{
			*this = src;
		}

		Array &operator=(const Array &src)
		{
			if (this != &src) {
				delete[] _data;
				_size = src._size;
				_data = new T[_size]();
				for (unsigned int i = 0; i < _size; ++i)
					_data[i] = src._data[i];
			}
			return *this;
		}

		~Array() { delete[] _data; }

		// ── Element access ───────────────────────────────────────────────

		T &operator[](unsigned int idx)
		{
			if (idx >= _size)
				throw std::out_of_range("Array: index out of bounds");
			return _data[idx];
		}

		T const &operator[](unsigned int idx) const
		{
			if (idx >= _size)
				throw std::out_of_range("Array: index out of bounds");
			return _data[idx];
		}

		// ── Size ─────────────────────────────────────────────────────────

		unsigned int size() const { return _size; }

	private:
		T            *_data;
		unsigned int  _size;
};

#endif

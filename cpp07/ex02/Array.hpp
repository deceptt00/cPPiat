#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <cstddef>  // size_t


template <typename T>
class Array
{
	public:
		Array() : _data(NULL), _size(0) {}

		Array(unsigned int n) : _data(new T[n]()), _size(n) {}


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


		unsigned int size() const { return _size; }

	private:
		T            *_data;
		unsigned int  _size;
};

#endif

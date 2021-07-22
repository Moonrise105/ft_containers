#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		typedef size_t size_type;
		typedef T value_type;
		typedef Alloc allocator_type;
		private:
			static const size_type INIT_CAPACITY = 10;
		public:
			explicit vector (const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _capacity(INIT_CAPACITY), _size(0)
			{
				_default_initialize();
			}
			explicit vector (size_type n, const value_type& val = value_type(),
            	const allocator_type &alloc = allocator_type())
				: _alloc(alloc)
			{
				_fill_initialize(n, val);
			}

			vector (const vector& x)
			{}

			virtual ~vector()
			{}
			vector& operator=(const vector& v)
			{}
			
			size_type size()
			{
				return _size;
			}

			size_type capacity()
			{
				return _capacity;
			}

			size_type max_size()
			{
				return _alloc.max_size();
			}

			bool empty() const
			{
				if (_size == 0)
					return true;
				else
					return false;
			}

			void reserve(size_type n)
			{
				
				if (n > _capacity) {
					value_type *data = _alloc.allocate(n * sizeof(value_type));
					for (size_type i = 0; i < _size; ++i) {
						_alloc.construct(data + i, _data[i]);
						_alloc.destroy(_data + i);
					}
					_alloc.deallocate(_data, _size);
					_capacity = n;
					_data = data;
				}
			}

			void resize(size_type n, value_type val = value_type())
			{
				if (n < _size) {
					for (size_type i = n; i < _size; ++i) {
						_alloc.destroy(_data + i);
					}
					_size = n;
				}
				else if (n > _size) {
					reserve(n);
					for (size_type i = _size; i < _capacity; ++i) {
						_alloc.construct(_data + i, val);
					}
					_size = n;
				}
			}

		private:
			void _default_initialize()
			{
				_data = _alloc.allocate(_capacity * sizeof(value_type));
			}

			void _fill_initialize(size_type n, const value_type& val)
			{
				_data = _alloc.allocate(sizeof(value_type) * n);
				for (size_type i = 0; i < n; ++i) {
					_alloc.construct(_data + i, val);
				}
				_capacity = n;
				_size = n;
				
			}
		
			allocator_type _alloc;
			size_type _size;
			size_type _capacity;
		public: //TODO MAKE PRIVATE
			value_type *_data;
	};
};

#endif /* VECTOR_HPP */

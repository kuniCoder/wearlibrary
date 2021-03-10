#pragma once
#include <vector> // Vector for matrix class

#ifdef WIN32
#undef min
#undef max
#endif

namespace wear {


    
    template < typename T > class matrix
    {
    public:
        matrix(const std::initializer_list< T >& list) : data(list)
        {}
        matrix()
        {}

    public:
        size_t size() const
        {
            return data.size();
        } // Find out the size of the matrix
        size_t max_size() const
        {
            return data.max_size();
        } // Find out the max size of the matrix
        T at(size_t idContainer)
        {
            return data[idContainer];
        } // Get the item from the container
        bool empty() const
        {
            return data.empty();
        } // Check for an empty matrix

        void push_back(T content)
        {
            data.push_back(content);
        } // Adding an element to the beginning of the matrix
        void pop_back()
        {
            data.pop_back();
        } // Deleting an element at the beginning of the matrix
        void clear()
        {
            data.clear();
        } // Delete all elements in the matrix
        void insert(size_t pos, T value)
        {
            data.insert(pos, value);
        } // Add an item by key
        void swap(matrix< T > src, matrix< T > dsc)
        {
            matrix< T > temp = src;
            src = dsc;
            dsc = temp;
        } // Swap 2 matrices

        T operator[](size_t idContainer) const
        {
            return data[idContainer];
        } // Get the item by key

        T& operator[](size_t idContainer)
        {
            if (data.size() < idContainer)
                data.resize(data.size() + idContainer);
            return data[idContainer];
        } //  Add an item by key


        void operator=(const std::initializer_list< T >& list)
        {
            data.resize(list.size());
            std::memcpy(list, data, list.size());
        } // Re-iterating the matrix

        void operator=(matrix< T > src)
        {
            if (src.size() > data.size())
                data.resize(src.size());
            std::memcpy(src, data, src.size());
        } // Copying from another matrix

        void copy(matrix< T > src)
        {
            if (src.size() > data.size())
                data.resize(src.size());
            std::memcpy(src, data, src.size());
        } // Copying from another matrix

    private:
        std::vector< T > data;
    };

} // namespace wear
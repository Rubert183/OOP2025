#include <iostream>

template <typename T> 
class Vector 
{
private:
    T* data;
    size_t size, capacity;

    void resize(size_t new_capacity) 
    {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) 
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Vector() : size(0), capacity(1) 
    {
        data = new T[capacity];
    }

    Vector(const Vector& other) : size(other.size), capacity(other.capacity) 
    {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) 
        {
            data[i] = other.data[i];
        }
    }

    Vector(Vector&& other) : data(other.data), size(other.size), capacity(other.capacity) 
    {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    ~Vector() 
    {
        delete[] data;
    }

    void insert(size_t index, const T element) 
    {
        if (index > size) 
        {
            printf("Index out of bounds\n");
            exit(1);
        }

        if (size == capacity) 
        {
            resize(capacity * 2); // principiul de la hashmaps
        }

        for (size_t ind = size; ind > index; ind--) 
        {
            data[ind] = data[ind - 1];
        }

        data[index] = element;
        size++;
    }

    void remove(size_t index) 
    {
        if (index >= size)
        {
            printf("Index out of bounds\n");
            exit(1);
        }

        for (size_t ind = index; ind < size; ind++) 
        {
            data[ind] = data[ind + 1];
        }

        size--;
    }

    void sort(bool (*cmp)(T, T)) 
    {
        T aux;
        for (size_t ind1 = 0; ind1 < size; ind1++)
        {
            for (size_t ind2 = ind1+1; ind2 <= size; ind2++)
            {
                if (!cmp(data[ind1], data[ind2]))
                {
                    aux =  data[ind1];
                    data[ind1] = data[ind2];
                    data[ind2] = aux;
                }
            }
        }
    }

    void sort() 
    {
        T aux;
        for (size_t ind1 = 0; ind1 < size; ind1++)
        {
            for (size_t ind2 = ind1+1; ind2 <= size; ind2++)
            {
                if (data[ind1] > data[ind2])
                {
                    aux =  data[ind1];
                    data[ind1] = data[ind2];
                    data[ind2] = aux;
                }
            }
        }
    }

    void print() const // pun const ca functia nu schimba datele
    {
        for (size_t i = 0; i < size; ++i) 
        {
            std::cout << data[i] << " "; 
        }
        std::cout << '\n';
    }

    T& operator[](size_t index) const
    {
        if (index >= size) 
        {
            printf("Index out of bounds\n");
            exit(1);
        }
        return data[index];
    }

    size_t get_size() const 
    {
        return size;
    }

    size_t get_capacity() const 
    {
        return capacity;
    }
};

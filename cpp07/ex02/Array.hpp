/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:54:49 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/06 00:20:40 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

template<typename T>
class Array
{
public:
    Array(); // default constructor
    explicit Array(unsigned int n); // constructor with size parameter
    Array(const Array& other); // copy constructor
    Array& operator=(const Array& other); // assignment operator
    ~Array(); // destructor

    T& operator[](unsigned int index); // subscript operator
    const T& operator[](unsigned int index) const; // subscript operator for const objects

    unsigned int size() const; // returns the size of the array

private:
    T* m_data;
    unsigned int m_size;
};

template<typename T>
Array<T>::Array() : m_data(nullptr), m_size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : m_size(n)
{
    m_data = new T[n];
}

template<typename T>
Array<T>::Array(const Array& other) : m_size(other.m_size)
{
    m_data = new T[m_size];
    for (unsigned int i = 0; i < m_size; i++)
    {
        m_data[i] = other.m_data[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] m_data;
        m_size = other.m_size;
        m_data = new T[m_size];
        for (unsigned int i = 0; i < m_size; i++)
        {
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array()
{        
    delete[] m_data;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= m_size)
    {
        throw std::exception();
    }
    return m_data[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= m_size)
    {
        throw std::exception();
    }
    return m_data[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
    return m_size;
}

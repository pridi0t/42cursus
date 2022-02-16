/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:13:18 by marvin            #+#    #+#             */
/*   Updated: 2022/02/16 01:44:24 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
    private:
        T*              arr;
        unsigned int    arr_len;

    public:
        // Constructor
        Array()
        {
            this->arr = new T[0];
            this->arr_len = 0;
        }
        
        Array(unsigned int n)
        {
            this->arr = new T[n];
            this->arr_len = n;
        }

        Array(const Array &a)
        {
            this->arr = new T[a.arr_len];
            this->arr_len = a.arr_len;
            for (int i = 0 ; i < this->arr_len ; i++)
                this->arr[i] = a.arr[i];
        }
		
		// Assignation operator overload
		Array& operator = (const Array &a)
        {
            if (this != &a) {
                if (this->arr != NULL)
                    delete [] this->arr;
                this->arr = new T[a.arr_len];
                this->arr_len = a.arr_len;
                for (unsigned int i = 0 ; i < this->arr_len ; i++)
                    this->arr[i] = a.arr[i];
            }
            return (*this);
        }
      
		// Destructor
		~Array()
        {
            delete []this->arr;
            this->arr = NULL;
        }

        // Operator overload
        T& operator[] (unsigned int idx) const {
            if (idx >= this->arr_len)
                throw ArrayException();
            return (this->arr[idx]);
        }

        int getLen() const
        {
            return (this->arr_len);
        }

        // Exception class
        class ArrayException : public std::exception {
			public:
				const char* what() const throw()
                {
                    return ("[Array] Exception");
                }
		};
};

# endif
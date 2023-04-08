#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
public:
    Span(unsigned int n);
    void addNumber(int num);

   void addNumbers(const std::vector<int>& numbers); 

    int shortestSpan() const;
    int longestSpan() const;
private:
    std::vector<int> m_numbers;
    unsigned int m_size;
};

#endif

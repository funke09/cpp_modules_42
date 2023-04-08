#include "span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : m_size(n) {}

void Span::addNumber(int num) {
    if (m_numbers.size() == m_size) {
        throw std::overflow_error("Span is full");
    }
    m_numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (m_numbers.size() < 2) {
        throw std::logic_error("Cannot find span with less than 2 numbers");
    }
    std::vector<int> sorted = m_numbers;
    std::sort(sorted.begin(), sorted.end());
    int min_span = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++) {
        int span = sorted[i] - sorted[i-1];
        if (span < min_span) {
            min_span = span;
        }
    }
    return min_span;
}

int Span::longestSpan() const {
    if (m_numbers.size() < 2) {
        throw std::logic_error("Cannot find span with less than 2 numbers");
    }
    int min = *std::min_element(m_numbers.begin(), m_numbers.end());
    int max = *std::max_element(m_numbers.begin(), m_numbers.end());
    return max - min;
}

void Span::addNumbers(const std::vector<int>& numbers) {
    if (m_numbers.size() + numbers.size() > m_size) {
        throw std::overflow_error("Not enough space in Span");
        // throw std::exception();
    }
    m_numbers.insert(m_numbers.end(), numbers.begin(), numbers.end());
}
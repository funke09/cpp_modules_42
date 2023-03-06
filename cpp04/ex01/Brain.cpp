#include "Brain.hpp"

Brain::Brain() {
    m_ideas = new std::string[s_numIdeas];
    for (int i = 0; i < s_numIdeas; i++) {
        m_ideas[i] = "No idea yet!";
    }
}

Brain::Brain(const Brain& other) {
    m_ideas = new std::string[s_numIdeas];
    for (int i = 0; i < s_numIdeas; i++) {
        m_ideas[i] = other.m_ideas[i];
    }
}

Brain::~Brain() {
    delete[] m_ideas;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < s_numIdeas; i++) {
            m_ideas[i] = other.m_ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(const std::string& idea, int index) {
    if (index >= 0 && index < s_numIdeas) {
        m_ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < s_numIdeas) {
        return m_ideas[index];
    }
    return "Invalid index!";
}

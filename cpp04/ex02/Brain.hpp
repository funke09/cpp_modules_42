#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
    public:
        Brain();
        Brain(const Brain& other);
        ~Brain();

        Brain& operator=(const Brain& other);

        void setIdea(const std::string& idea, int index);
        std::string getIdea(int index) const;

    private:
        std::string* m_ideas;
        static const int s_numIdeas = 100;
};

#endif

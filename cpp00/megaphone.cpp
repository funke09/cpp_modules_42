#include <iostream>


class megaphone
{
    private:
        std::string _message;
        /* data */
    public:
        megaphone(char *);
        megaphone(void);
        void loud(void);
        void printMessage(void);
        ~megaphone();
};


    megaphone::megaphone(char *msg)
    {
        // std::cout<< "test" << std::endl;
        _message = msg;

    }


    megaphone::megaphone()
    {
        std::getline(std::cin, _message);
    }

    megaphone::~megaphone()
    {
    }

    void megaphone::loud()
    {
        char *tmp;

        tmp = (char*)_message.c_str();
        while (*tmp)
        {
                if (*tmp >= 'a' && *tmp <= 'z')
                    std::cout << (char)(*tmp - 32);
                else std::cout << *tmp;
                tmp++;
        }
       std::cout << std::endl;
    }
    void megaphone::printMessage()
    {
       std::cout << _message << std::endl;
       
    }


int main(int ac, char **av) {
    // char str[100];
    char *msg;

    if (ac > 1)
    {
        msg = (char *)av[1];
        megaphone mega(msg);

        mega.loud();
        megaphone test;
        test.printMessage();
        
    }




    // std::cout << "Hello, World!" << std::endl;
    // std::cin >> str;
    // std::cout << "what up [" << str << "] ?" << std::endl;
    return 0;
}
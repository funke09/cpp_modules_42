#include <iostream>
class chi_haja
{
    private:
    const static int i = 100;
    public:
        static int func(int x,int y)
        {
            return x+y;
        }
        static int gettest()
        {
            return i;
        }
};

int main()
{
    int a = chi_haja::gettest();

    std::cout << a << std::endl;
    return 0;
}
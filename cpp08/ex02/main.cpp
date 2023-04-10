/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:19:15 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/10 22:19:17 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top one in the stack: " << mstack.top() << std::endl;


    mstack.pop();
    std::cout << "size of stack: " << mstack.size() << std::endl;


    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "Index: " << std::distance(mstack.begin(), it) << " Value: " << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "top one in the stack S : " << s.top() << std::endl;
    std::cout << "size of stack S : " << s.size() << std::endl;
    return 0;
}

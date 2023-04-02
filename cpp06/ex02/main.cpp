/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:17:18 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/02 22:17:20 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

extern Base* generate();
extern void identify(Base* p);
extern void identify(Base& p);

int main() {
    Base* base = generate();
    Base& base_ref = *base;

    identify(&base_ref); 

    identify(base_ref); 



    identify(base); 

    identify(*base); 
    delete base;
    return 0;
}


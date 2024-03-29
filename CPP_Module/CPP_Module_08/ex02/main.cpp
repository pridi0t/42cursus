/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:13:38 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/18 14:46:09 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "mutantstack.cpp"

int main()
{
	std::cout << "=========== std::list ===========" << std::endl;
	std::list<int> lst;
	
	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> l(lst);
	
	std::cout << "========== MutantStack ==========" << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it2 = mstack.begin();
	MutantStack<int>::iterator ite2 = mstack.end();

	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::stack<int> s(mstack);

	std::cout << "======= rbegin, rend test =======" << std::endl;
	std::list<int>::reverse_iterator rit = lst.rbegin();
	std::list<int>::reverse_iterator rite = lst.rend();
	std::cout << "1) list" << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	
	MutantStack<int>::reverse_iterator rit2 = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite2 = mstack.rend();
	std::cout << "2) mutantstack" << std::endl;
	while (rit2 != rite2)
	{
		std::cout << *rit2 << std::endl;
		++rit2;
	}

	return 0;
}

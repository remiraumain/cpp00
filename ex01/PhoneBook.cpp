/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:26:06 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/22 14:50:50 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : contactIndex(0) {}

void PhoneBook::addContact() {
	std::cout << "Adding a new contact..." << std::endl;
	if (contacts[contactIndex % 8].setContact() == 1)
	{
		contactIndex++;
	} else {
		std::cout << "Contact not added due to empty fields." << std::endl;
	}
}

void PhoneBook::searchContacts() const {
	std::cout << std::right << "|" 
	<< std::setw(10) << "Index" << "|"
	<< std::setw(10) << "First Name" << "|"
	<< std::setw(10) << "Last Name" << "|"
	<< std::setw(10) << "Nickname" << "|"
	<< std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < std::min(contactIndex, 8); i++) {
		contacts[i].displaySummary(i);
	}

	std::cout << "Enter contact index: ";
	std::string input;
	std::getline(std::cin, input);
	
	int index;
	std::stringstream ss(input);
	if (!(ss >> index) || !(ss.eof()) || index < 0 || index >= std::min(contactIndex, 8)) {
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	contacts[index].displayDetails();
}
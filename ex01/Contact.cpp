/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:16:10 by rraumain          #+#    #+#             */
/*   Updated: 2025/03/22 14:50:44 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <ios>

Contact::Contact() {}

int	Contact::setContact() {
	std::cout << "First name: ";
	std::getline(std::cin, firstname);
	if (firstname.empty()) {
		std::cout << "First name cannot be empty." << std::endl;
		return (0);
	}
	std::cout << "Last name: ";
	std::getline(std::cin, lastname);
	if (lastname.empty()) {
		std::cout << "Last name cannot be empty." << std::endl;
		return (0);
	}
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty()) {
		std::cout << "Nickname cannot be empty." << std::endl;
		return (0);
	}
	std::cout << "Phone number: ";
	std::getline(std::cin, phone_number);
	if (phone_number.empty()) {
		std::cout << "Phone number cannot be empty." << std::endl;
		return (0);
	}
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkest_secret);
	if (darkest_secret.empty()) {
		std::cout << "Darkest secret cannot be empty." << std::endl;
		return(0);
	}
	return (1);
}

void Contact::displaySummary(int index) const {
	std::cout << std::right << "|" 
	<< std::setw(10) << index << "|"
	<< std::setw(10) << (firstname.length() > 10 ? firstname.substr(0, 9) + "." : firstname) << "|"
	<< std::setw(10) << (lastname.length() > 10 ? lastname.substr(0, 9) + "." : lastname) << "|"
	<< std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|"
	<< std::endl;
}

void Contact::displayDetails() const {
	std::cout << "First name: " << firstname << std::endl;
	std::cout << "Last name: " << lastname << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

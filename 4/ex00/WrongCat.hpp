/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:58 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 20:52:04 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

class WrongCat
{
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	~WrongCat();
};

#endif

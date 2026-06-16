/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:23:25 by rexposit          #+#    #+#             */
/*   Updated: 2026/06/16 16:43:19 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		int					fixed_point_value;
		static const int	fractional_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
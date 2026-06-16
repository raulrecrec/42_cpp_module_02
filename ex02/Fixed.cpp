/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:23:28 by rexposit          #+#    #+#             */
/*   Updated: 2026/06/16 23:43:14 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	fixed_point_value = 0;
}

Fixed::Fixed(const int value)
{
	fixed_point_value = value << fractional_bits;
}

Fixed::Fixed(const float value)
{
	fixed_point_value = roundf(value * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		fixed_point_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return (fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	fixed_point_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)fixed_point_value / (1 << fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (fixed_point_value >> fractional_bits);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (fixed_point_value > other.fixed_point_value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (fixed_point_value < other.fixed_point_value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (fixed_point_value >= other.fixed_point_value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (fixed_point_value <= other.fixed_point_value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (fixed_point_value == other.fixed_point_value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (fixed_point_value != other.fixed_point_value);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	fixed_point_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	fixed_point_value++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	fixed_point_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	fixed_point_value--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2_02.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:34:29 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/21 15:43:57 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2_02.hpp"

//----------------------------------------------------------------- constructors
vect2::vect2()
{
	this->x = 0;
	this->y = 0;
}

vect2::vect2( int num1, int num2 )
{
	this->x = num1;
	this->y = num2;
}

vect2::vect2( const vect2& source ){ *this = source; }

//-------------------------------------------------------------------- operators
vect2&	vect2::operator	=	( const vect2& source )
{
	if ( this != &source )
	{
		this->x = source.x;
		this->y = source.y;
	}
	return ( *this );
}

int	vect2::operator	[]	( int index )		const
{
	if ( index == 0 )
		return ( this->x );
	return ( this->y );
}

int&	vect2::operator	[]	( int index )
{
	if ( index == 0 )
		return ( this->x );
	return ( this->y );
}

vect2	vect2::operator	-	()			const
{
	vect2 temp = *this;
	temp[0] = -temp[0];
	temp[1] = -temp[1];
	return ( temp );
}

vect2	vect2::operator	*	( int num )		const
{
	vect2 temp = *this;
	temp.x *= num;
	temp.y *= num;
	return ( temp );
}

vect2&	vect2::operator	*=	( int num )
{
	this->x *= num;
	this->y *= num;
	return ( *this );
}

vect2	vect2::operator	+	( const vect2& other )	const
{
	vect2 temp = *this;
	temp.x += other.x;
	temp.y += other.y;
	return ( temp );
}

vect2	vect2::operator	-	( const vect2& other )	const
{
	vect2 temp = *this;
	temp.x -= other.x;
	temp.y -= other.y;
	return ( temp );
}

vect2	vect2::operator	*	( const vect2& other )	const
{
	vect2 temp = *this;
	temp.x *= other.x;
	temp.y *= other.y;
	return ( temp );
}

vect2&	vect2::operator	+=	( const vect2& other )
{
	this->x += other.x;
	this->y += other.y;
	return ( *this );
}

vect2&	vect2::operator	-=	( const vect2& other )
{
	this->x -= other.x;
	this->y -= other.y;
	return ( *this );
}

vect2&	vect2::operator	*=	( const vect2& other )
{
	this->x *= other.x;
	this->y *= other.y;
	return ( *this );
}

vect2&	vect2::operator	++	()
{
	this->x += 1;
	this->y += 1;
	return ( *this );
}

vect2	vect2::operator	++	( int )
{
	vect2 temp = *this;
	++*this;
	return ( temp );
}

vect2&	vect2::operator	--	()
{
	this->x -= 1;
	this->y -= 1;
	return ( *this );
}

vect2	vect2::operator	--	( int )
{
	vect2 temp = *this;
	--*this;
	return ( temp );
}

bool	vect2::operator	==	( const vect2& other )	const
{
	if ( ( this->x == other.x ) && ( this->y == other.y ) )
		return ( true );
	return ( false );
}

bool	vect2::operator	!=	( const vect2& other )	const
{ return ( !( *this == other ) ); }

vect2::~vect2(){}

//-------------------------------------------------------- non-member functions
vect2		operator	*	( int num, const vect2& obj )
{
	vect2	temp( obj );
	temp 	*= num;
	return ( temp );
}

std::ostream&	operator	<<	( std::ostream& out, const vect2& obj )
{
	std::cout << "{" << obj[0] << ", " << obj[1] << "}";
	return ( out );
}

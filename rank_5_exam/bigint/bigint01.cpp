/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint01.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:47:23 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/06 16:36:57 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bigint01.hpp"
//constructors
bigint::bigint()
{
	this->_str = "0";
}

bigint::bigint( unsigned int num )
{
	std::stringstream	ss;
	ss << num;
	this->_str = ss.str();
}

bigint::bigint( const bigint& source )
{
	*this = source;
}

//getter
std::string	bigint::getStr() const
{
	return ( this->_str );
}

//operators

bigint&	bigint::operator	=	( const bigint& source )
{
	if ( this == &source )
		return ( *this );
	this->_str = source._str;
	return ( *this );
}

bigint	bigint::operator	+	( const bigint& other )		const
{
	bigint temp = *this;
	temp._str.clear();
	std::string result = addition( *this, other );
	temp._str = result;
	return ( temp );
}

bigint&	bigint::operator	+=	( const bigint& other )
{
	*this = *this + other;
	return ( *this );
}

bigint&	bigint::operator	++	()
{
	*this = *this + bigint( 1 );
	return ( *this );
}


bigint	bigint::operator	++	( int )
{
	bigint temp = *this;
	*this = *this + bigint( 1 );
	return ( *this );
}


bigint	bigint::operator	<<	( unsigned int n )			const
{
	bigint temp = *this;
	size_t len	= temp._str.length();
	temp._str.insert( len, n, 0 );
	return ( temp );
}

bigint	bigint::operator	>>	( unsigned int n )			const
{
	bigint temp = *this;
	size_t len	= temp._str.length();
	if ( n >= len )
		temp._str = "0";
	else
		temp._str.erase( len - n, n );
	return ( temp ); 
}

bigint&	bigint::operator	>>=	( unsigned int n )
{
	*this = *this >> n;
	return ( *this );
}

bigint&	bigint::operator	<<=	( unsigned int n )
{
	*this = *this << n;
	return ( *this );
}

bigint	bigint::operator	<<	( const bigint& other )		const
{
	bigint temp;
	temp = *this << stringToUINT( other._str );
	return ( temp );
}

bigint	bigint::operator	>>	( const bigint& other )		const
{
	bigint temp;
	temp = *this >> stringToUINT( other._str );
	return ( temp );
}

bigint&	bigint::operator	<<=	( const bigint& other )
{
	*this = *this << stringToUINT( other._str );
	return ( *this );
}

bigint&	bigint::operator	>>=	( const bigint& other )
{
	*this = *this >> stringToUINT( other._str );
	return ( *this );
}


//non_member functions
std::ostream&	operator		<<	( std::ostream& out, const bigint& obj )
{
	out << obj.getStr();
	return ( out );
}

unsigned int	stringToUINT		( std::string str )
{
	std::stringstream			ss( str );
	unsigned int				res;
	ss >> res;
	return ( res ); 
}

std::string		reverse				( const std::string& str )
{
	std::string					revStr;
	for ( size_t i = str.length(); i > 0; i++ )
	{
		revStr.push_back( str[i - 1] );
	}
	return ( revStr );
}

std::string		addition			( const bigint& obj1, const bigint& obj2 )
{
	std::string					str1 = reverse( obj1.getStr() );
	std::string					str2 = reverse( obj2.getStr() );
	std::string					result;

	size_t						len1 = str1.length();
	size_t						len2 = str2.length();

	if ( len1 > len2 )
	{
		int diff = len1 - len2;
		while ( diff > 0 )
		{
			str2.push_back( '0' );
			diff--;
		}
	}
	else if ( len2 > len1 )
	{
		int diff = len2 - len1;
		while ( diff > 0 )
		{
			str1.push_back( '0' );
			diff--;
		}
	}

	int carry = 0;
	int digit1;
	int digit2;

	size_t len = str1.length();
	for ( size_t i = 0; i < len; i++ )
	{
		digit1 = str1[i] - '0';
		digit2 = str2[i] - '0';
		int res = digit1 + digit2 + carry;

		if ( res > 9 )
		{
			carry = res / 10;
			result.push_back( ( res % 10 ) + '0' );
		}
	}
	if ( carry != 0 )
		result.push_back( carry + '0' );
	return ( reverse( result ) );
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint01.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:29:22 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/05 16:58:23 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bigint01.hpp"

//constructors
bigint::bigint()
{
    this->_str = '0';
}

bigint::bigint( unsigned int num )
{
    std::stringstream ss;
    ss << num;
    this->_str = ss.str();
}

bigint::bigint( const bigint& source )
{
    ( *this ) = source;
}

//getter
std::string bigint::getStr() const
{
    return ( this->_str );
}

//operators

bigint&	operator	=	( const bigint& source )
{
    if ( this == &source )
        return ( *this );
    this->_str = source._str;
    return ( *this );
}

//non member functions
std::ostream&	operator	<<	( std::ostream& out, const bigint& obj )
{
    out << obj.getStr();
    return( out );
}

unsigned int	stringToUINT	( std::string str )
{
    std::stringstream   ss( str );
    unsigned int        res;
    ss >> res;
    return ( res );
}

std::string		reverse			( const std::string& str)
{
    std::string         revStr;
    for ( size_t i = str.length(); i > 0 ; i--)
    {
        revStr.push_back( str[i - 1] );
    }
    return ( revStr );
}

std::string		addition		( const bigint& obj1, const bigint& obj2 )
{
    std::string         str1 = reverse( obj1.getStr() );
    std::string         str2 = reverse( obj2.getStr() );
    std::string         result;

    size_t              len1 = str1.length();
    size_t              len2 = str2.length();

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
        else
            result.push_back( res + '0' );
    }
    if ( carry != 0 )
        result.push_back( carry + '0' );
    return ( reverse( result ) );
}

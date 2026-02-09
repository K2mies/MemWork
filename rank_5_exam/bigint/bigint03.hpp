/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint03.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:33:19 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/08 13:56:30 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BIGINT_HPP
#define BIGINT_HPP

#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>

class bigint
{
  private:
    std::string _str;
  public:
    //CONSTRUCTORS
    bigint();
    bigint( unsigned int num );
    bigint( const bigint& source );

    //GETTER
    std::string getStr()                                const;

    //OPERATORS
    bigint&     operator  =   ( const bigint& source );

    bigint      operator  +   ( const bigint& other )   const;
    bigint&     operator  +=  ( const bigint& other );

    bigint&     operator  ++  ();
    bigint      operator  ++  ( int );

    bigint      operator  <<  ( unsigned int n )        const;
    bigint      operator  >>  ( unsigned int n )        const;
    bigint&     operator  <<= ( unsigned int n );
    bigint&     operator  >>= ( unsigned int n );

    bigint      operator  <<  ( const bigint& other )   const;
    bigint      operator  >>  ( const bigint& other )   const;
    bigint&     operator  <<= ( const bigint& other );
    bigint&     operator  >>= ( const bigint& other );

    bool        operator  ==  ( const bigint& other )   const;
    bool        operator  !=  ( const bigint& other )   const;
    bool        operator  <   ( const bigint& other )   const;
    bool        operator  >   ( const bigint& other )   const;
    bool        operator  <=  ( const bigint& other )   const;
    bool        operator  >=  ( const bigint& other )   const;
};

//NON_MEMBER FUNCTIONS
std::ostream&   operator  <<  ( std::ostream& out, const bigint& obj );

unsigned int    stringToUINT  ( std::string str);
std::string     reverse       ( const std::string& str );
std::string     addition      ( const bigint& obj1, const bigint& obj2 );

#endif

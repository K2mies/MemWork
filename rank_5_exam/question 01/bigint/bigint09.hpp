/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint09.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:48:57 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/10 14:03:14 by rhvidste         ###   ########.fr       */
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
  //------------------------------------------------------------------ constructors
  bigint();
  bigint( unsigned int num );
  bigint( const bigint& source );

  //------------------------------------------------------------------------ getter
  std::string getStr()                                  const;

  //-------------------------------------------------------------------- operaators  
  bigint&     operator  =   ( const bigint& source );

  bigint      operator  +   ( const bigint& other )     const;
  bigint&     operator  +=  ( const bigint& other );

  bigint&     operator  ++  ();
  bigint      operator  ++  ( int );

  bigint      operator  <<  ( unsigned int n )          const;
  bigint      operator  >>  ( unsigned int n )          const;
  bigint&     operator  <<= ( unsigned int n );
  bigint&     operator  >>= ( unsigned int n );

  bigint      operator  <<  ( const bigint& other )     const;
  bigint      operator  >>  ( const bigint& other )     const;
  bigint&     operator  <<= ( const bigint& other );
  bigint&     operator  >>= ( const bigint& other );

  bool        operator  ==  ( const bigint& other )     const;
  bool        operator  !=  ( const bigint& other )     const;
  bool        operator  <   ( const bigint& other )     const;
  bool        operator  >   ( const bigint& other )     const;
  bool        operator  <=  ( const bigint& other )     const;
  bool        operator  >=  ( const bigint& other )     const;
};

//--------------------------------------------------------- non-member functions
std::ostream& operator  <<  ( std::ostream& out, const bigint& obj );

unsigned int  strToUINT     ( std::string str );
std::string   reverse       ( const std::string& str );
std::string   addition      ( const bigint& obj1, const bigint& obj2 );

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint00.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:43:52 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/04 16:28:28 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define	BIGINT_HPP

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

class bigint
{
	private:
		std::string str;

	public:
		bigint();
		bigint( unsigned int num );
		bigint( const bigint& source );

		std::string getStr()	const;
		
		bigint&	operator	=	( const bigint& source );

		//addition
		bigint	operator	+	( const bigint& other )	const;
		bigint&	operator	+=	( const bigint& other );

		//increments
		bigint&	operator	++	(); 		//++x
		bigint	operator	++	( int );	// x++
		
		//shift with num
		bigint	operator	<<	( unsigned int n )		const;
		bigint	operator	>>	( unsigned int n )		const;
		bigint&	operator	<<=	( unsigned int n );
		bigint&	operator	>>=	( unsigned int n );

		//shift with object
		bigint	operator	<<	( const bigint& other )	const;
		bigint	operator	>>	( const bigint& other )	const;
		bigint&	operator	<<=	( const bigint& other );
		bigint& operator	>>= ( const bigint& other );

		// ==, !=, <, >, <=, >=
		bool	operator	==	( const bigint& other )	const;
		bool	operator	!=	( const bigint& other )	const;
		bool	operator	<	( const bigint& other )	const;
		bool	operator	>	( const bigint& other )	const;
		bool	operator	<=	( const bigint& other )	const;
		bool	operator	>=	( const bigint& other )	const;

		//~bigint();
};

// non member operator overlaods
std::ostream&	operator	<<	( std::ostream& out, const bigint& obj );

// non member functions
unsigned int	stringToUINT	( std::string str );
std::string		reverse			( const std::string& str );
std::string		addition		( const bigint& obj1, const bigint& obj2 );

#endif

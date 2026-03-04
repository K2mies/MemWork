/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint18.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:52:42 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/19 11:28:00 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BIGINT_HPP
#define	BIGINT_HPP

#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>

class bigint
{
private:
	std::string	_str;
public:
	//--------------------------------------------------------- constructors
	bigint();
	bigint( unsigned int num );
	bigint( const bigint& source );

	//--------------------------------------------------------------- getter
	std::string	getStr()					const;

	//------------------------------------------------------------ operators
	bigint&	operator	=	( const bigint& source );

	bigint	operator	+	( const bigint& other )		const;
	bigint&	operator	+=	( const bigint& other );

	bigint&	operator	++	();
	bigint	operator	++	( int );

	bigint	operator	<<	( unsigned int n )		const;
	bigint	operator	>>	( unsigned int n )		const;
	bigint&	operator	<<=	( unsigned int n );
	bigint&	operator	>>=	( unsigned int n );

	bigint	operator	<<	( const bigint& other )		const;
	bigint	operator	>>	( const bigint& other )		const;
	bigint&	operator	<<=	( const bigint& other );
	bigint&	operator	>>=	( const bigint& other );

	bool	operator	==	( const bigint& other )		const;
	bool	operator	!=	( const bigint& other )		const;
	bool	operator	<	( const bigint& other )		const;
	bool	operator	>	( const bigint& other )		const;
	bool	operator	<=	( const bigint& other )		const;
	bool	operator	>=	( const bigint& other )		const;
};

//--------------------------------------------------------- non-member functions
std::ostream&	operator	<<	( std::ostream& out, const bigint& obj );

unsigned int	strToUINT		( std::string str );
std::string	reverse			( const std::string& str );
std::string	addition		( const bigint& obj1, const bigint& obj2 );

#endif

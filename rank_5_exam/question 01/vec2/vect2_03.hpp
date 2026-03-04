/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2_03.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:00:38 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/22 14:26:52 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
#define VECT2_HPP

#include<iostream>

class vect2
{
private:
	int x;
	int y;
public:
	//--------------------------------------------------------- constructors
	vect2();
	vect2( int num1, int num2 );
	vect2( const vect2& source );

	//------------------------------------------------------------ operators
	vect2&	operator	=	( const vect2& source );

	int	operator	[]	( int index )			const;
	int&	operator	[]	( int index );

	vect2	operator	-	()				const;

	vect2	operator	*	( int num )			const;
	vect2&	operator	*=	( int num );

	vect2	operator	+	( const vect2& other )		const;	
	vect2	operator	-	( const vect2& other )		const;	
	vect2	operator	*	( const vect2& other )		const;	

	vect2&	operator	+=	( const vect2& other );	
	vect2&	operator	-=	( const vect2& other );	
	vect2&	operator	*=	( const vect2& other );

	vect2&	operator	++	();
	vect2	operator	++	( int );
	vect2&	operator	--	();
	vect2	operator	--	( int );

	bool	operator	==	( const vect2& other )		const;
	bool	operator	!=	( const vect2& other )		const;

	~vect2();
};

//--------------------------------------------------------- non-memner functions
vect2		operator	*	( int num, const vect2& obj );
std::ostream&	operator	<<	( std::ostream& out, const vect2& obj );

#endif

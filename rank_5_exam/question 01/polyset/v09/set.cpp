/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:43:46 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/22 15:59:24 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"searchable_array_bag.hpp"
#include"set.hpp"

set::set( searchable_bag& s_bag ) : bag ( s_bag ) {}

bool	set::has	( int value )	const
{ return ( bag.has ( value ) ); }

void	set::insert	( int value )
{
	if ( !( this->has( value ) ) )
		bag.insert( value );
}

void	set::insert	( int *data, int size )
{
	for ( int i = 0; i < size; i++ )
		this->insert( data[i] );
}

void	set::print 	()		const
{ bag.print(); }

void	set::clear	()		const
{ bag.clear(); }

const	searchable_bag&		set::get_bag()
{ return ( this->bag ); }

set::~set(){}

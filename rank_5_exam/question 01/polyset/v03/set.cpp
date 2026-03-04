/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:45:58 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/16 14:57:28 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "searchable_array_bag.hpp"
#include "set.hpp"

set::set( searchable_bag& s_bag ) : bag ( s_bag ) {}

bool	set::has ( int value )	const
{ return ( bag.has( value ) ); }

void	set::insert( int value )
{
	if ( !( this->has( value ) ) )
		bag.insert( value );
}

void	set::insert( int *data, int size )
{
	for ( int i = 0; i < size; i++ )
		this->insert( data[i] );
}

void	set::print(){ bag.print(); }
void	set::clear(){ bag.clear(); }

const searchable_bag&	set::get_bag()
{ return ( this->bag  );  }

set::~set(){}

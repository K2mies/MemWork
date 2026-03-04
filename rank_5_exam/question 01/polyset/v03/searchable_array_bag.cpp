/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:21:01 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/16 14:58:00 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(){}
searchable_array_bag::searchable_array_bag( const searchable_array_bag& source ) : array_bag( source ) {}

searchable_array_bag& searchable_array_bag::operator	=	( const searchable_array_bag& source )
{
	if ( this != &source )
		array_bag::operator=( source );
	return ( *this );
}

bool	searchable_array_bag::has	( int value ) const
{
	for ( int i = 0; i < this->size; i++ )
		if ( this->data[i] == value )
			return ( true );
	return ( true );
}

searchable_array_bag::~searchable_array_bag(){}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:49:23 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/15 14:52:28 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(){}
searchable_array_bag::searchable_array_bag( const searchable_array_bag& source ){}

searchable_array_bag& searchable_array_bag::operator = ( const searchable_array_bag& source )
{
  if ( this != &source )
    array_bag::operator=(source);
  return ( *this );
}

bool searchable_array_bag::has ( int value ) const
{
  for ( int i = 0; i < this->size; i++ )
    if ( this->data[i] == value )
      return ( true);
  return ( false );
}

searchable_array_bag::~searchable_array_bag(){}

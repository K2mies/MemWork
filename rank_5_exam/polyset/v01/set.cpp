/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:06:04 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/16 12:13:45 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"set.hpp"

set::set( searchable_bag& s_bag ) : bag( s_bag ){}

bool  set::has( int value ) const
{
  return( bag.has ( value ) );
}
void  set::insert ( int value )
{
  if ( !( this->has( value )))
    bag.insert( value );
}
void  set::insert ( int* data, int size )
{
  for ( int i = 0; i < size; i++ )
    bag.insert( data[i] );
}

void  set::print(){ bag.print(); }
void  set::clear(){ bag.clear(); }

const searchable_bag& set::get_bag()
{ return ( this->bag ); }

set::~set(){}

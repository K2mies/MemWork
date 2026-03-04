/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:57:05 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/15 15:00:00 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::search ( node* node, const int value ) const
{
  if ( node == nullptr )
    return ( false );
  if ( node->value == value )
    return ( true );
  else if ( value < node->value )
    return ( search ( node->l, value ) );
  else
    return ( search ( node->r, value ) ) ; 
}

searchable_tree_bag::searchable_tree_bag(){}
searchable_tree_bag::searchable_tree_bag( const searchable_tree_bag& source ){}

searchable_tree_bag& searchable_tree_bag::operator = ( const searchable_tree_bag& source )
{
  if ( this != &source )
    tree_bag::operator=( source );
  return ( *this );
}

bool searchable_tree_bag::has ( int value ) const
{
  return ( search ( this->tree, value) );
}

searchable_tree_bag::~searchable_tree_bag(){}

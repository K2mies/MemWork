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
#pragma once

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
  public:
    searchable_array_bag();
    searchable_array_bag( const searchable_array_bag& source );
    searchable_array_bag& operator = ( const searchable_array_bag& source );

    bool has ( int ) const;

    ~searchable_array_bag();
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:20:40 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/16 14:58:18 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include"array_bag.hpp"
#include"searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		searchable_array_bag();
		searchable_array_bag( const searchable_array_bag& source );
		searchable_array_bag& operator	=	( const searchable_array_bag& source );

		bool	has	( int value ) const;

		~searchable_array_bag();
};

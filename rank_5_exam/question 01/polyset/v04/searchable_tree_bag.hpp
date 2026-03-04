/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:17:24 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/16 21:20:45 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include"tree_bag.hpp"
#include"searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
		bool	search	( node* node, const int value )	const;
	public:
		searchable_tree_bag();
		searchable_tree_bag( const searchable_tree_bag& source );
		searchable_tree_bag&	operator	=	( const searchable_tree_bag& source );

		bool	has	( int value )	const;

		~searchable_tree_bag();
};

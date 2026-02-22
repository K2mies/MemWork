/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rvidste@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:43:46 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/22 15:59:06 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include"searchable_bag.hpp"

class set
{
	private:
		searchable_bag&	bag;
	public:
		set() = delete;
		set( const set& source ) = delete;
		set&	operator	=	( const set& source ) = delete;
		set( searchable_bag& s_bag );

		bool	has	( int value )	const;
		void	insert	( int value );
		void	insert	( int *data, int size );
		void	print 	()		const;
		void	clear	()		const;

		const	searchable_bag&		get_bag();

		~set();
};

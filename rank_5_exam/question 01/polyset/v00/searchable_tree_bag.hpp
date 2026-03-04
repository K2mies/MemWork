/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 12:51:33 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/15 12:59:45 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"tree_bag.hpp"
#include"searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
  private:
    bool search ( node* node, const int value ) const;
  public:
    searchable_tree_bag();
    searchable_tree_bag( const searchable_tree_bag& source );
    searchable_tree_bag& operator = ( const searchable_tree_bag& source );

    bool has ( int value ) const;

    ~searchable_tree_bag();
};

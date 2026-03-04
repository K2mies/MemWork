/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 13:19:19 by rhvidste          #+#    #+#             */
/*   Updated: 2026/02/15 13:27:43 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "searchable_bag.hpp"

class set
{
  private:
    searchable_bag& bag;
  public:
    set() = delete;
    set( const set& source ) = delete;
    set& operator = ( const set& source ) = delete;
    set( searchable_bag& s_bag );

    bool  has ( int value ) const;
    void  insert( int value );
    void  insert( int *data, int size );
    void  print();
    void  clear();

    const searchable_bag& get_bag();

    ~set();
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_bag.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:23:22 by fatkeski          #+#    #+#             */
/*   Updated: 2026/02/16 11:43:34 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "bag.hpp"

class searchable_bag : virtual public bag // virtual inheritance
{
 public:
	virtual bool has(int) const = 0; // verilen sayı bag'te var mı yok mu kontrolünü yapar
};

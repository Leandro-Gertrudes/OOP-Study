/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:58:35 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/06 14:17:27 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.hpp"

static Fixed cross(
    const Point& a,
    const Point& b,
    const Point& p
) {
    return (b.getX() - a.getX()) * (p.getY() - a.getY())
         - (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(
    Point const a,
    Point const b,
    Point const c,
    Point const point
) {
    Fixed ab = cross(a, b, point);
    Fixed bc = cross(b, c, point);
    Fixed ca = cross(c, a, point);

    if (ab == Fixed(0) || bc == Fixed(0) || ca == Fixed(0))
        return false;

    bool has_neg = (ab < Fixed(0)) || (bc < Fixed(0)) || (ca < Fixed(0));
    bool has_pos = (ab > Fixed(0)) || (bc > Fixed(0)) || (ca > Fixed(0));

    return !(has_neg && has_pos);
}

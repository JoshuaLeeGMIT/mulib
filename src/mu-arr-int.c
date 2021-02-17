/* mu-str.c
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdlib.h>

#include "mu-arr-int.h"

static MuArrInt * 
mu_arrint_init ()
{
    MuArrInt *array;
    array->size = 0;
    return array;
}

MuArrInt * 
mu_arrint_add (MuArrInt *array, int element)
{
    if (array == NULL)
    {
        return mu_arrint_add(mu_arrint_init, element);
    }
    
    array->size++;
    array->array = realloc(array->array, (array->size * sizeof(int)));
    memcpy((array->array + 1), &element, sizeof(element));
    return array;
}

MuArrInt * 
mu_arrint_add (MuArrInt *array, int elements[])
{
    if (array == NULL)
    {
        return mu_arrint_add(mu_arrint_init, elements);
    }
    
    int nElements = (sizeof(elements) / sizeof(elements[0]));
    array->size += nElements;
    array->array = realloc(array->array, (array->size * sizeof(int)));
    memcpy((array->array + nElements), elements, sizeof(elements));
    return array;
}

void * 
mu_arrint_free (MuArrInt *array)
{
    if (array == NULL){
        return;
    }

    free (array->array);
    free (array);
}
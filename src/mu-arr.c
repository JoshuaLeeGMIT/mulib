/* mu-arr.c
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
#include <string.h>

#include "mu-arr.h"

MuArr * 
mu_arr_new (size_t dataTypeSize)
{
    MuArr *array;
    array->dataTypeSize = dataTypeSize;
    array->len = 0;
    return array;
}

MuArr * 
mu_arr_add (MuArr *array, void *element)
{
    if (array == NULL)
    {
        return NULL;
    }
    
    array->len++;
    array->array = realloc(array->array, (array->len * array->dataTypeSize)); //realloc will automatically allocate memory
    memcpy((array->array + 1), element, array->dataTypeSize);
    return array;
}

void  
mu_arr_free (MuArr *array)
{
    if (array == NULL){
        return;
    }

    free (array->array);
    free (array);
}
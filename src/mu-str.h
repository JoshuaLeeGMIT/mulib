/* mu-str.h
 *
 * Copyright 2021 Joshua Lee <lee.son.wai@gmail.com>
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

#pragma once

#include <stdio.h>

typedef struct
{
  char  *str;   /* Pointer to the string. */
  size_t len;   /* Length of the string, not including the nul byte. */
  size_t alloc; /* Length of the string's allocation. */
} MuStr;

MuStr *         mu_str_append             (MuStr      *str,
                                           const char *append);

MuStr *         mu_str_new                (const char *init);

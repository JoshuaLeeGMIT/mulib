/* mu-str.c
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

#include <stdlib.h>
#include <string.h>

#include "mu-str.h"

#define DEF_LEN   2

static inline size_t
nearest_pow (size_t len)
{
  size_t new = 1;

  while (new < len)
    new <<= 1;

  return new;
}

static void
expand_str (MuStr *str,
            size_t len)
{
  str->alloc = nearest_pow (len);
  str->str = realloc (str->str, str->alloc);
}

MuStr *
mu_str_append (MuStr      *str,
               const char *append)
{
  size_t new_size;

  new_size = str->len + strlen (append) + 1;

  if (new_size > str->alloc)
    expand_str (str, new_size);

  strcat (str->str, append);
  str->len = strlen (str->str);

  return str;
}

MuStr *
mu_str_new (const char *init)
{
  MuStr *str;

  str = malloc (sizeof (MuStr));

  if (init == NULL || *init == '\0')
    {
      str->str = malloc (DEF_LEN);
      str->str[0] = '\0';
      str->len = 0;
      str->alloc = DEF_LEN;
    }
  else
    {
      str->str = malloc (strlen (init) + 1);
      str->len = strlen (init);
      str->alloc = strlen (init) + 1;
      strcpy (str->str, init);
    }

  return str;
}

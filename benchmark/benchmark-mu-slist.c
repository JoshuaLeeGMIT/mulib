/* benchmark-mu-slist.c
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

#include <stdio.h>
#include <stdlib.h>

#include "mu-slist.h"

int
main (int    argc,
      char **argv)
{
  int n;
  MuSList *list;

  if (argc != 2)
    return 1;

  n = strtod (*++argv, NULL);
  list = mu_slist_new ((void *) (long) 0);

  for (int i = 1; i < n; i++)
    list = mu_slist_append (list, (void *) (long) (i));

  return 0;
}

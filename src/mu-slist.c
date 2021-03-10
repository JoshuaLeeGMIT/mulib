/* mu-slist.c
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

#include "mu-slist.h"

MuSList *
mu_slist_append (MuSList *list,
                 void    *data)
{
  MuSList *new, *last;

  new = malloc (sizeof (MuSList));
  new->data = data;
  new->next = NULL;

  if (list != NULL)
    {
      last = mu_slist_get_last (list);
      last->next = new;
    }

  return list;
}

void
mu_slist_free_full (MuSList *list,
                    void (*free_func) (void *))
{
  MuSList *cur;

  if (list == NULL)
    return;

  while (list->next)
    {
      cur = list;
      list = list->next;
      free_func (cur->data);
      free (cur);
    }
}

void
mu_slist_free (MuSList *list)
{
  MuSList *cur;

  if (list == NULL)
    return;

  while (list->next)
    {
      cur = list;
      list = list->next;
      free (cur);
    }
}

MuSList *
mu_slist_get_last (MuSList *list)
{
  if (list == NULL)
    return NULL;

  while (list->next)
    list = list->next;

  return list;
}

MuSList *
mu_slist_get_nth (MuSList *list,
                  int      pos)
{
  while (pos-- > 0 && list != NULL)
    list = list->next;

  return (pos) ? NULL : list;
}

MuSList *
mu_slist_insert (MuSList *list,
                 void    *data,
                 int      pos)
{
  MuSList *insert, *tmp;

  insert = malloc (sizeof (MuSList));
  insert->data = data;

  if (list != NULL)
    {
      if ((tmp = mu_slist_get_nth (list, pos - 1)) == NULL)
        return NULL;
      insert->next = tmp->next->next;
      tmp->next = insert;
    }

  return list;
}

MuSList *
mu_slist_new (void *data)
{
  MuSList *list;

  list = malloc (sizeof (MuSList));
  list->data = data;
  list->next = NULL;

  return list;
}

MuSList *
mu_slist_prepend (MuSList *list,
                  void    *data)
{
  MuSList *new;

  new = malloc (sizeof (MuSList));
  new->data = data;
  new->next = list;

  return new;
}

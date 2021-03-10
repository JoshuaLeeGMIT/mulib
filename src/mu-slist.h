/* mu-slist.h
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

typedef struct _MuSList MuSList;

struct _MuSList
{
  void    *data;
  MuSList *next;
};

MuSList *       mu_slist_append           (MuSList *list,
                                           void    *data);

void            mu_slist_free             (MuSList *list);

void            mu_slist_free_deep        (MuSList *list,
                                           void (*free_func) (void *));

MuSList *       mu_slist_get_last         (MuSList *list);

MuSList *       mu_slist_get_nth          (MuSList *list,
                                           int      nth);

MuSList *       mu_slist_insert           (MuSList *list,
                                           void    *data,
                                           int      pos);

MuSList *       mu_slist_new              (void *data);

MuSList *       mu_slist_prepend          (MuSList *list,
                                           void    *data);

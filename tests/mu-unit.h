/* mu-unit.h
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

/* This code based on the simple unit testing framework detailed at
 * http://www.jera.com/techinfo/jtns/jtn002.html
 */

#define mu_assert(msg, test)  do \
                                { \
                                if (!(test)) \
                                  return msg; \
                                } \
                              while (0)
#define mu_run_test(test)     do \
                                { \
                                  char *msg = test(); \
                                  if (msg) \
                                    return msg; \
                                } \
                              while (0)

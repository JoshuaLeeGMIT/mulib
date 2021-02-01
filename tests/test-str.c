/* test-str.c
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
#include <string.h>

#include "mu-str.h"
#include "mu-unit.h"

static char *
new_test (void)
{
  MuStr *str;

  str = mu_str_new ("Hello, world!");

  mu_assert ("new_test fail", !strcmp (str->str, "Hello, world!"));

  return NULL;
}

static char *
append_test (void)
{
  MuStr *str;

  str = mu_str_new ("Hello, ");
  str = mu_str_append (str, "world!");

  mu_assert ("append_test fail", !strcmp (str->str, "Hello, world!"));

  return NULL;
}

static char *
run_tests (void)
{
  mu_run_test (append_test);
  mu_run_test (new_test);

  return NULL;
}

int
main (int    argc,
      char **argv)
{
  return run_tests() != NULL;
}

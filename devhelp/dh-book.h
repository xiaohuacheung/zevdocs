/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*- */
/*
 * This file is part of Devhelp.
 *
 * Copyright (C) 2002 CodeFactory AB
 * Copyright (C) 2002 Mikael Hallendal <micke@imendio.com>
 * Copyright (C) 2005-2008 Imendio AB
 * Copyright (C) 2010 Lanedo GmbH
 * Copyright (C) 2017, 2018 Sébastien Wilmet <swilmet@gnome.org>
 *
 * Devhelp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * Devhelp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Devhelp.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <glib-object.h>
#include <gio/gio.h>
#include <cairo/cairo-gobject.h>
#include <json-glib/json-glib.h>
#include <devhelp/dh-completion.h>

G_BEGIN_DECLS

#define DH_TYPE_BOOK         (dh_book_get_type ())
G_DECLARE_DERIVABLE_TYPE (DhBook, dh_book, DH, BOOK, GObject)

struct _DhBookClass {
        GObjectClass parent_class;

        /* Padding for future expansion */
        gpointer padding[12];
};


DhBook       *dh_book_new            (GFile  *index_file);
DhBook *     dh_book_new_from_json   (JsonObject *object, gint scale);
GFile        *dh_book_get_index_file (DhBook *book);
const gchar  *dh_book_get_id         (DhBook *book);
const gchar *dh_book_get_id_for_removing (DhBook *book);
cairo_surface_t* dh_book_get_icon_surface (DhBook *book);
const gchar* dh_book_get_icon_b64    (DhBook *book);
const gchar  *dh_book_get_title      (DhBook *book);
const gchar  *dh_book_get_language   (DhBook *book);
GList        *dh_book_get_links      (DhBook *book);
GNode        *dh_book_get_tree       (DhBook *book);
DhCompletion *dh_book_get_completion (DhBook *book);
gint          dh_book_cmp_by_id      (DhBook *a,
                                      DhBook *b);
gint          dh_book_cmp_by_title   (DhBook *a,
                                      DhBook *b);
G_END_DECLS


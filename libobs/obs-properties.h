/******************************************************************************
    Copyright (C) 2014 by Hugh Bailey <obs.jim@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#pragma once

#include "util/c99defs.h"

#ifdef __cplusplus
extern "C" {
#endif

enum obs_property_type {
	OBS_PROPERTY_INVALID,
	OBS_PROPERTY_BOOL,
	OBS_PROPERTY_INT,
	OBS_PROPERTY_FLOAT,
	OBS_PROPERTY_TEXT,
	OBS_PROPERTY_PATH,
	OBS_PROPERTY_LIST,
	OBS_PROPERTY_COLOR,
};

enum obs_combo_format {
	OBS_COMBO_FORMAT_INVALID,
	OBS_COMBO_FORMAT_INT,
	OBS_COMBO_FORMAT_FLOAT,
	OBS_COMBO_FORMAT_STRING
};

enum obs_combo_type {
	OBS_COMBO_TYPE_INVALID,
	OBS_COMBO_TYPE_EDITABLE,
	OBS_COMBO_TYPE_LIST,
};

struct obs_properties;
struct obs_property;
typedef struct obs_properties *obs_properties_t;
typedef struct obs_property   *obs_property_t;

/* ------------------------------------------------------------------------- */

EXPORT obs_properties_t obs_properties_create();
EXPORT void obs_properties_destroy(obs_properties_t props);

EXPORT obs_property_t obs_properties_first(obs_properties_t props);

EXPORT obs_property_t obs_properties_get(obs_properties_t props,
		const char *property);

/* ------------------------------------------------------------------------- */

EXPORT void obs_properties_add_bool(obs_properties_t props, const char *name,
		const char *description);
EXPORT void obs_properties_add_int(obs_properties_t props, const char *name,
		const char *description, int min, int max, int step);
EXPORT void obs_properties_add_float(obs_properties_t props, const char *name,
		const char *description, double min, double max, double step);
EXPORT void obs_properties_add_text(obs_properties_t props, const char *name,
		const char *description);
EXPORT void obs_properties_add_path(obs_properties_t props, const char *name,
		const char *description);
EXPORT obs_property_t obs_properties_add_list(obs_properties_t props,
		const char *name, const char *description,
		enum obs_combo_type type, enum obs_combo_format format);
EXPORT void obs_properties_add_color(obs_properties_t props, const char *name,
		const char *description);

EXPORT void obs_property_list_add_item(obs_property_t p,
		const char *name, const char *value);

/* ------------------------------------------------------------------------- */

EXPORT const char *           obs_property_name(obs_property_t p);
EXPORT const char *           obs_property_description(obs_property_t p);
EXPORT enum obs_property_type obs_property_type(obs_property_t p);

EXPORT bool                   obs_property_next(obs_property_t *p);

EXPORT int                    obs_property_int_min(obs_property_t p);
EXPORT int                    obs_property_int_max(obs_property_t p);
EXPORT int                    obs_property_int_step(obs_property_t p);
EXPORT double                 obs_property_float_min(obs_property_t p);
EXPORT double                 obs_property_float_max(obs_property_t p);
EXPORT double                 obs_property_float_step(obs_property_t p);
EXPORT enum obs_combo_type    obs_property_list_type(obs_property_t p);
EXPORT enum obs_combo_format  obs_property_list_format(obs_property_t p);

EXPORT size_t      obs_property_list_item_count(obs_property_t p);
EXPORT const char *obs_property_list_item_name(obs_property_t p, size_t idx);
EXPORT const char *obs_property_list_item_value(obs_property_t p, size_t idx);

#ifdef __cplusplus
}
#endif

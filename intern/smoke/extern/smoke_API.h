/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2009 by Daniel Genrich
 * All rights reserved.
 *
 * Contributor(s): Daniel Genrich
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file smoke/extern/smoke_API.h
 *  \ingroup smoke
 */


#ifndef SMOKE_API_H_
#define SMOKE_API_H_

#ifdef __cplusplus
extern "C" {
#endif

	
struct FLUID_3D;

// low res
// Renamed all headers so that they don't conflict with mantaflow header (they have same signature) (sebbas)
struct FLUID_3D *old_smoke_init(int *res, float dx, float dtdef, int use_heat, int use_fire, int use_colors);
void old_smoke_free(struct FLUID_3D *fluid);

void old_smoke_initBlenderRNA(struct FLUID_3D *fluid, float *alpha, float *beta, float *dt_factor, float *vorticity, int *border_colli, float *burning_rate,
						  float *flame_smoke, float *flame_smoke_color, float *flame_vorticity, float *flame_ignition_temp, float *flame_max_temp);
void old_smoke_step(struct FLUID_3D *fluid, float gravity[3], float dtSubdiv);

float *old_smoke_get_density(struct FLUID_3D *fluid);
float *old_smoke_get_flame(struct FLUID_3D *fluid);
float *old_smoke_get_fuel(struct FLUID_3D *fluid);
float *old_smoke_get_react(struct FLUID_3D *fluid);
float *old_smoke_get_color_r(struct FLUID_3D *fluid);
float *old_smoke_get_color_g(struct FLUID_3D *fluid);
float *old_smoke_get_color_b(struct FLUID_3D *fluid);
void old_smoke_get_rgba(struct FLUID_3D *fluid, float *data, int sequential);
void old_smoke_get_rgba_from_density(struct FLUID_3D *fluid, float color[3], float *data, int sequential);
float *old_smoke_get_heat(struct FLUID_3D *fluid);
float *old_smoke_get_velocity_x(struct FLUID_3D *fluid);
float *old_smoke_get_velocity_y(struct FLUID_3D *fluid);
float *old_smoke_get_velocity_z(struct FLUID_3D *fluid);

/* Moving obstacle velocity provided by blender */
void old_smoke_get_ob_velocity(struct FLUID_3D *fluid, float **x, float **y, float **z);

float *old_smoke_get_force_x(struct FLUID_3D *fluid);
float *old_smoke_get_force_y(struct FLUID_3D *fluid);
float *old_smoke_get_force_z(struct FLUID_3D *fluid);
	
int *old_smoke_get_manta_flags(struct FLUID_3D *fluid);
float *old_smoke_get_inflow_grid(struct FLUID_3D *fluid);
float *old_smoke_get_fuel_inflow(struct FLUID_3D *fluid);
void old_smoke_manta_export(struct SmokeModifierData *smd);

unsigned char *old_smoke_get_obstacle(struct FLUID_3D *fluid);

size_t old_smoke_get_index(int x, int max_x, int y, int max_y, int z);
size_t old_smoke_get_index2d(int x, int max_x, int y);
void old_smoke_dissolve(struct FLUID_3D *fluid, int speed, int log);
// wavelet turbulence functions
void old_smoke_turbulence_free(struct WTURBULENCE *wt);
void old_smoke_turbulence_step(struct WTURBULENCE *wt, struct FLUID_3D *fluid);
float *old_smoke_turbulence_get_density(struct WTURBULENCE *wt);
float *old_smoke_turbulence_get_color_r(struct WTURBULENCE *wt);
float *old_smoke_turbulence_get_color_g(struct WTURBULENCE *wt);
float *old_smoke_turbulence_get_color_b(struct WTURBULENCE *wt);
void old_smoke_turbulence_get_rgba(struct WTURBULENCE *wt, float *data, int sequential);
void old_smoke_turbulence_get_rgba_from_density(struct WTURBULENCE *wt, float color[3], float *data, int sequential);
float *old_smoke_turbulence_get_flame(struct WTURBULENCE *wt);
float *old_smoke_turbulence_get_fuel(struct WTURBULENCE *wt);
float *old_smoke_turbulence_get_react(struct WTURBULENCE *wt);
void old_smoke_turbulence_get_res(struct WTURBULENCE *wt, int *res);
int old_smoke_turbulence_get_cells(struct WTURBULENCE *wt);
void old_smoke_turbulence_set_noise(struct WTURBULENCE *wt, int type, const char *noisefile_path);
void old_smoke_initWaveletBlenderRNA(struct WTURBULENCE *wt, float *strength);
void old_smoke_dissolve_wavelet(struct WTURBULENCE *wt, int speed, int log);
/* export */
void old_smoke_export(struct FLUID_3D *fluid, float *dt, float *dx, float **dens, float **react, float **flame, float **fuel, float **heat, float **heatold,
				  float **vx, float **vy, float **vz, float **r, float **g, float **b, unsigned char **obstacles);
void old_smoke_turbulence_export(struct WTURBULENCE *wt, float **dens, float **react, float **flame, float **fuel,
							 float **r, float **g, float **b, float **tcu, float **tcv, float **tcw);

/* data fields */
int old_smoke_has_heat(struct FLUID_3D *fluid);
int old_smoke_has_fuel(struct FLUID_3D *fluid);
int old_smoke_has_colors(struct FLUID_3D *fluid);
int old_smoke_turbulence_has_fuel(struct WTURBULENCE *wt);
int old_smoke_turbulence_has_colors(struct WTURBULENCE *wt);
void old_smoke_ensure_heat(struct FLUID_3D *fluid);
void old_smoke_ensure_fire(struct FLUID_3D *fluid, struct WTURBULENCE *wt);
void old_smoke_ensure_colors(struct FLUID_3D *fluid, struct WTURBULENCE *wt, float init_r, float init_g, float init_b);

#ifdef __cplusplus
}
#endif

#endif /* SMOKE_API_H_ */

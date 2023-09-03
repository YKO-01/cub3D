/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabrahm <ylabrahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 08:30:09 by ylabrahm          #+#    #+#             */
/*   Updated: 2023/09/04 00:54:22 by ylabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "MLX42.h"

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280
// --------
#define GRID_HEIGHT 30
#define GRID_WIDTH 30
#define COLUMNS 10
#define ROWS 8
#define MAP_HEIGHT (GRID_HEIGHT * ROWS)
#define MAP_WIDTH (GRID_WIDTH * COLUMNS)
// --------
#define PLAYER_HEIGHT 8
#define PLAYER_WIDTH 8
// --------
#define FOV_ANGLE (60.0 * (M_PI / 180.0))

typedef struct player_s
{
    int x;
    int y;
    int move_speed;
    double rotation_speed;
    double rotation_angle;
} player_t;

typedef struct data_s
{
    mlx_t *mlx;
    player_t player;
    mlx_image_t *minimap;
    mlx_image_t *game;
    char map_grid[ROWS][COLUMNS];
} data_t;

typedef struct vect_s
{
    double x;
    double y;
}   vect_t;

typedef struct hitRay_s
{
    double distance;
    int h_v;
}   hitRay_t;


// ----------------- Function Prototypes --------------------

// Drawing
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int set_color(char position);

void draw_pixels_to_map(data_t *data);
void draw_player(data_t *data);
void draw_one_grid(data_t *data, int x, int y, int sq_color);
void draw_pixels_to_map(data_t *data);
void draw_map(data_t *data);
void draw_fov(data_t *data);

// hooks()
void ft_hooks(data_t *data);


// 3d
double cast_ray(data_t *data, double angle);
void draw_wall_column(data_t *data, vect_t v1, int columnHeight, int h_v);
void draw_3d_walls(data_t *data, hitRay_t ray, int ray_num);
void clear_screen(data_t *data);


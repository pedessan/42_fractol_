/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:48:42 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/21 19:04:46 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "MiniLibX/mlx.h"
//# include "MiniLibX/mlx_int.h"
# include <math.h>

/* DEFINES */
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 60
# define COLOR_INSIDE 0x000000
# define MOVE_FACTOR 0.1

/* MESSAGE COLORS */
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[1;32m"
# define FUCHSIA "\033[0;35m"
# define CYAN "\033[1;36m"
# define RED "\033[1;31m"
# define BOLD "\033[1m"

//# define FRACTAL 0x000000
//# define ESCAPE

/* valori di esempio per testare julia */
//-0.745429
//0.05

/*keys*/

# ifdef __linux__
#  define OS "linux"
#  define LETTER_KEY_LEFT 97
#  define LETTER_KEY_RIGHT 100
#  define LETTER_KEY_UP 119
#  define LETTER_KEY_DOWN 115
#  define LETTER_KEY_ACTION 101
#  define ARROW_KEY_LEFT 65361
#  define ARROW_KEY_RIGHT 65363
#  define ARROW_KEY_UP 65362
#  define ARROW_KEY_DOWN 65364
#  define SPACE_BAR 32
#  define KEY_ESC 65307

# elif __APPLE__
#  define OS "macos"
#  define LETTER_KEY_LEFT 0
#  define LETTER_KEY_RIGHT 2
#  define LETTER_KEY_UP 13
#  define LETTER_KEY_DOWN 1
#  define LETTER_KEY_ACTION 14
#  define ARROW_KEY_LEFT 123
#  define ARROW_KEY_RIGHT 124
#  define ARROW_KEY_UP 126
#  define ARROW_KEY_DOWN 125
#  define SPACE_BAR 49
#  define KEY_ESC 53
# endif

typedef struct z_win
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		x;
	int		y;
	double	re;
	double	im;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zoom;
	double	zoom_x;
	double	zoom_y;
}	t_win;

typedef struct z_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct z_complex_n
{
	double	re;
	double	im;
}	t_complex_n;

typedef struct z_julia
{
	char	*re;
	char	*im;
}	t_julia;

typedef struct z_newton
{
	t_complex_n	z;
	t_complex_n	z_sq;
	t_complex_n	z_cu;
	t_complex_n	num;
	t_complex_n	denom;
	t_complex_n	delta;
}	t_newton;

typedef struct s_fractol
{
	char		*name;
	int			needs_redraw;
	t_julia		vals;
	t_img		img;
	t_win		win;
	t_complex_n	z;
	t_complex_n	c;
	int			color;
}	t_fractol;

typedef void	(*t_setup_func)(t_fractol *, double real, double imag);
typedef int		(*t_math_func)(t_fractol *);

/* FUNCTIONS */

//parsing
//int		check_string(char *s);
int			check_string(const char *s);
//int		check_chars(char **s);
int			parsing_args(int ac, char **av);

void		print_instructions(void);

//window

//void		free_window(t_fractol *fractol);
int			close_window_hook(t_fractol *fractol);

//pixels_work

void		put_pixel(t_fractol *fractol, int x, int y, int color);
void		color_fractal_point(t_fractol *fractol, int i);
int			get_color(int i);

//fractals_setup

void		setup_mandelbrot(t_fractol *f, double real, double imag);
void		setup_julia(t_fractol *f, double real, double imag);
void		setup_newton(t_fractol *f, double real, double imag);

//fractals

void		draw_fractal(t_fractol *f, t_setup_func setup, t_math_func math);
void		mlx_hook_event(t_fractol *fractol);
void		init_values(t_fractol *fractol, char **av);
int			render_if_needed(t_fractol *fractol);
//void		fractal_render(t_fractol *fractol, char **av);
//void		julia(t_fractol *fractol, char **av);
//newton_math

t_complex_n	complex_mult(t_complex_n a, t_complex_n b);
t_complex_n	complex_sub(t_complex_n a, t_complex_n b);
t_complex_n	complex_div(t_complex_n a, t_complex_n b);
t_complex_n	complex_mult_scalar(t_complex_n a, double scalar);

void		newton(t_fractol *fractol);
void		julia(t_fractol *fractol);
void		mandelbrot(t_fractol *fractol);
int			mouse_hook(int button, int x, int y, t_fractol *fractol);

#endif

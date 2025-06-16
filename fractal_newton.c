/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_newton.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:21:18 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 17:00:25 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	newton_math(t_fractol *f)
{
	int			iter;
	double		mod;
	t_newton	cn;

	iter = 0;
	cn.z = f->z;
	while (iter < MAX_ITER)
	{
		cn.z_sq = complex_mult(cn.z, cn.z);
		cn.z_cu = complex_mult(cn.z_sq, cn.z);
		cn.num = complex_sub(cn.z_cu, (t_complex_n){1, 0});
		cn.denom = complex_mult_scalar(cn.z_sq, 3);
		if ((cn.denom.re * cn.denom.re + cn.denom.im * cn.denom.im) == 0.0)
			break ;
		cn.delta = complex_div(cn.num, cn.denom);
		cn.z = complex_sub(cn.z, cn.delta);
		mod = cn.delta.re * cn.delta.re + cn.delta.im * cn.delta.im;
		if (mod < 0.000001)
			break ;
		iter++;
	}
	f->z = cn.z;
	return (iter);
}

void	newton(t_fractol *fractol)
{
	draw_fractal(fractol, setup_newton, newton_math);
}

/* Each pixel is transformed into a complex number z.
This zz is iteratively updated using Newton's method:
z_(n+1) = z_n - (z_n^3 - 1) / (3 * z_n^2)

more explicit version:
z_{n+1} = z_n - (z_n * z_n * z_n - 1) / (3 * z_n * z_n)


If z converges to a root, the pixel is colored
with a color associated to that root.


Variable|Meaning                 |Formula        |Purpose                       
--------|------------------------|---------------|------------------------------
z_sq    |z squared               |z * z          |Used to compute f(z) and f′(z)
z_cu    |z cubed                 |z_sq * z       |Computes f(z) = z³ − 1    
num     |Numerator of Newton step|z_cu − (1 + 0i)|Numerator in delta calc.  
denom   |Derivative f′(z)        |3 * z_sq       |Denominator in delta calc.
delta   |Newton correction step  |num / denom    |Adjustment for next iter.
z       |New z value             |z − delta      |Next iteration point     
mod     |Squared magnitude delta |Re² + Im²      |Check if close to root   
 */

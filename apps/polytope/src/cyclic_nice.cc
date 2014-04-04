// Copyright (c) 2011-2014 Silke Horn
// http://solros.de/polymake/mypolytopes
// 
// This file is part of the polymake extension mypolytopes.
// 
// mypolytopes is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// mypolytopes is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with mypolytopes.  If not, see <http://www.gnu.org/licenses/>.
// 
// #include "polymake/client.h"
// #include "polymake/Rational.h"
// #include "polymake/Matrix.h"
// #include "polymake/AccurateFloat.h"
// 
// namespace polymake { namespace polytope {
// 
// Rational step(int, int);
// 
// perl::Object cyclic_nice(int d, int n)
// {
//    if ((d < 2) || (d >= n)) {
//       throw std::runtime_error("cyclic: d >= 2 and n > d required\n");
//    }
// 
//    perl::Object p("Polytope<Rational>");
//    p.set_description() << "Cyclic " << d << "-polytope on " << n << " vertices" << endl;
// 
//    Matrix<Rational> vertices(n,d+1);
//    Rational* v=concat_rows(vertices).begin();
// 
//    // and now we compute n points (x_i^1,..,x_i^d) on the momentum curve in R^d
//    Rational x=0;
//    for (int i=0;  i<n;  ++i, x+=step(i, d)) {
//       *v++ = 1;
//       Rational power_of_x(1);
//       for (int j = 1; j <= d; ++j) {
//          power_of_x *= x;
//          *v++ = power_of_x;
//       }
//    }
// 
//    p.take("CONE_AMBIENT_DIM") << d+1;
//    p.take("CONE_DIM") << d+1;
//    p.take("N_VERTICES") << n;
//    p.take("VERTICES") << vertices;
//    p.take("BOUNDED") << true;
//    return p;
// }
//    
// UserFunction4perl("# @category Producing from scratch"
//                   "# Produce a //d//-dimensional cyclic polytope with //n// points."
//                   "# Prototypical example of a neighborly polytope.  Combinatorics completely known"
//                   "# due to Gale's evenness criterion.  Coordinates are chosen on the moment curve."
//                   "# @param Int d the dimension"
//                   "# @param Int n the number of points"
//                   "# @return Polytope",
//                   &cyclic_nice, "cyclic_nice($$)");
// 
// Rational newton(int exp, Rational val, Rational x, int depth) {
// 
// 	Rational pow = 1;
// 	for (int i = 1; i<exp; ++i) {	// compute x^{exp-1}
// 		pow *= x;
// 	}
// 	Rational fpx = exp*pow;			// compute f'(x) = exp * x^{exp-1}
// 	Rational fx = x*pow - val;		// compute f(x) = x^exp - val;
// 
// 	Rational new_x = x - fx/fpx;
// 
// 	if (depth == 3) {
// 		return new_x;
// 	}
// 	return newton(exp, val, new_x, depth+1);
// }
// 
// Rational step(int j, int d) {
// 
// 	Rational pow = 1;
// 	for (int i = 1; i<=d-2; ++i) {	// compute x^{exp-1}
// 		pow *= j;
// 	}
// 
// 	return 1/pow;
// 	return 1/newton(d+j, j, 1, 0);
// }
// 
// } }
// 
// Local Variables:
// mode:C++
// c-basic-offset:3
// indent-tabs-mode:nil
// End:

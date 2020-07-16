fast_inv_sqrt: https://en.wikipedia.org/wiki/Fast_inverse_square_root
There is no C/C++ API for double type. For float type, -O2 -ffast-math will use rsqrtss to accelerate. To avoid gcc warning 'warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]', just use (double)1.0/sqrt(x) instead.

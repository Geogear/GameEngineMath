/* Inverse Square Root, quake code, taken from wikipedia */
float InverseSquareRoot(float number)
{
	const float x2 = number * 0.5F;
	const float threehalfs = 1.5F;

	union {
		float f;
		uint32_t i;
	} conv  = { .f = number };
	conv.i  = 0x5f3759df - ( conv.i >> 1 );
	conv.f  *= threehalfs - ( x2 * conv.f * conv.f );
	return conv.f;
}

/* Square Root, taken from wikipedia */
float SquareRoot(float number)
{
    union { float f; uint32_t i; } val = {number};	/* Convert type, preserving bit pattern */
	/*
	 * To justify the following code, prove that
	 *
	 * ((((val.i / 2^m) - b) / 2) + b) * 2^m = ((val.i - 2^m) / 2) + ((b + 1) / 2) * 2^m)
	 *
	 * where
	 *
	 * b = exponent bias
	 * m = number of mantissa bits
	 */
	val.i -= 1 << 23;	/* Subtract 2^m. */
	val.i >>= 1;		/* Divide by 2. */
	val.i += 1 << 29;	/* Add ((b + 1) / 2) * 2^m. */

	return val.f;	
}
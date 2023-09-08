#include <stdio.h>
#include <gmp.h>

int main() {
	// Declare variables
	mpz_t num1, num2, result;

	// Initialize variables
	mpz_init(num1);
	mpz_init(num2);
	mpz_init(result);

	// Set values
	mpz_set_str(num1, "123456789", 10);
	mpz_set_str(num2, "987654321", 10);

	// Perform arithmetic operations
	mpz_add(result, num1, num2);     // Addition
	gmp_printf("Addition: %Zd\n", result);

	mpz_sub(result, num1, num2);     // Subtraction
	gmp_printf("Subtraction: %Zd\n", result);

	mpz_mul(result, num1, num2);     // Multiplication
	gmp_printf("Multiplication: %Zd\n", result);

	mpz_div(result, num1, num2);     // Division (integer division)
	gmp_printf("Division: %Zd\n", result);

	// Clear and free resources
	mpz_clear(num1);
	mpz_clear(num2);
	mpz_clear(result);

	return 0;
}

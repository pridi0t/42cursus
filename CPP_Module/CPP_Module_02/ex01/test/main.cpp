#include <iostream>
#include <cmath>

using namespace std;

void	print_bit(float input)
{
	void *v;

	v = &input;
	cout << "===============================================" << endl;
	for (int i = 31 ; i >= 0 ; i--) {
		if ((*((int *)v) & (1 << i)) == 0)
			cout << "0";
		else
			cout << "1";
		
		if (i == 31 || i == 23)
			cout << "\t";
	}
	cout << endl << "[sign]\t[Exponent]\t[Mantissa]";
	cout << endl << "===============================================" << endl;
}

int		main(void)
{
	float	input;
	float	cinput;
	int		fix;

	cout << "input value(float) : ";
	cin >> input;

	print_bit(input);

	cout << endl << "after << 8" << endl;
	fix = roundf(input * pow(2, 8));
	cout << "fix : " << fix << endl;
	print_bit(fix);

	cinput = ((double)fix / pow(2, 8));
	cout << "cinput : " << cinput << endl;
	print_bit(cinput);
	return 0;
}

#include "polynomial.h"
#include <locale.h>

enum Choice 
{ 
	A_plus_B = 1, 
	A_minus_B, 
	B_minus_A, 
	A_mult_B, 
	Const_mult, 
	Quit1 = 1, 
	Quit2 = 6,
	A_mult_Const = 1, 
	B_mult_Const =2,
};

void shortLine()
{
	cout << "______________________________" << endl;
}

void longLine()
{
	cout << "____________________________________________________________________________" << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Правила пользования: " << endl;
	cout << "1) Сначала вы должны ввести количество мономов в полиноме" << endl;
	cout << "2) Дальше для каждого монома вводится его степень" << endl;
	cout << "3) Введите коэффициент монома" << endl;
	cout << "4) Повторяйте шаги 2) и 3) до тех пор, пока не появится меню выбора операций" << endl;
	cout << "5) Выберите операцию над мономами" << endl;
	cout << "!!!Заметьте: " << endl;
	cout << "Количество сотен отвечает за степень у 'x'" << endl;
	cout << "Количество десятков - степень 'y'" << endl;
	cout << "Количество единиц - степень z" << endl;
	cout << "Максимальная степень - 999!!!" << endl;
	
	longLine();

	size_t choice, quit1 = 1, quit2;

	while (quit1)
	{
		try
		{
			Polynomial A, B;
			quit2 = 1;

			cout << "Введите первый полином(A)" << endl;
			A.setPolynomial();

			shortLine();

			cout << "Введите второй полином(B)" << endl;
			B.setPolynomial();

			while (quit2)
			{
				shortLine();
				cout << "Выберите операцию: " << endl;
				cout << "1) C = A + B" << endl;
				cout << "2) C = A - B" << endl;
				cout << "3) C = B - A" << endl;
				cout << "4) C = A * B" << endl;
				cout << "5) Polynomial * const" << endl;
				cout << "6) Выйти из меню выбора операций" << endl;
				cout << "Ваш выбор: ";
				cin >> choice;
				shortLine();
				cout << "Полином А: ";
				A.getPolynomial();
				cout << "Полином B: ";
				B.getPolynomial();

				switch (choice) {
				case Choice::A_plus_B:
				{
					cout << "Полином C = A + B: ";
					(A + B).getPolynomial();
					break;
				}
				case Choice::A_minus_B:
				{
					cout << "Полином C = A - B: ";
					(A - B).getPolynomial();
					break;
				}
				case Choice::B_minus_A:
				{
					cout << "Полином C = B - A: ";
					(B - A).getPolynomial();
					break;
				}
				case Choice::A_mult_B:
				{
					cout << "Полином C = A * B: ";
					(A * B).getPolynomial();
					break;
				}
				case Choice::Const_mult:
				{
					double var;

					cout << "Введите константу: ";
					cin >> var;

					cout << "Выберите операцию: " << endl;
					cout << "1) C = A * const" << endl;
					cout << "2) C = B * const" << endl;
					cout << "3) Вернуться к выбору операций" << endl;
					cout << "Ваш выбор: ";
					cin >> choice;

					shortLine();

					switch (choice) {
					case Choice::A_mult_Const:
					{
						cout << "Полином C = A * const: ";
						(A * var).getPolynomial();
						break;
					}

					case Choice::B_mult_Const:
					{
						cout << "Полином C = B * const: ";
						(A * var).getPolynomial();
						break;
					}

					default:
					{
						break;
					}}

					break;
				}

				case Choice::Quit2:
				{
					quit2 = 0;
					break;
				}
				default:
				{
					cout << "Повторите попытку" << endl;
					break;
				}}
			}

			shortLine();
			cout << "Хотите выйти из программы?" << endl;
			cout << "1) Выйти" << endl;
			cout << "2) Ввести новые полиномы" << endl;
			cout << "Ваш выбор: ";
			cin >> choice;

			switch (choice) {
			case Choice::Quit1:
			{
				quit1 = 0;
				break;
			}
			default:
			{
				shortLine();
				break;
			}}
		}

		catch (const string msg)
		{
			cout << endl;
			shortLine();
			cout << msg << endl;
			shortLine();
		}
	}
}
#include "polynomial.h"
#include <locale.h>

#ifdef _WIN64
#include <windows.h>
#endif

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

enum Colors 
{ 
	Black = 0,
	Blue = 1,
	Green,
	LightBlue,
	Red,
	White = 7,
	UltraGreen = 10,
	Coral = 12,
	UltraWhite = 15
};

#ifdef _WIN64
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

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
#ifdef _WIN64
	SetConsoleTextAttribute(console_color, Coral);
#endif
	cout << "   !!!Заметьте: " << endl;
	cout << "   Количество сотен отвечает за степень у 'x'" << endl;
	cout << "   Количество десятков - степень 'y'" << endl;
	cout << "   Количество единиц - степень z" << endl;
	cout << "   Максимальная степень - 999!!!" << endl;
#ifdef _WIN64
	SetConsoleTextAttribute(console_color, White);
#endif
	cout << "3) Введите коэффициент монома" << endl;
	cout << "4) Повторяйте шаги 2) и 3) до тех пор, пока не появится меню выбора операций" << endl;
	cout << "5) Выберите операцию над мономами" << endl;
	
	longLine();

	size_t choice, quit1 = 1, quit2;

	while (quit1)
	{
		Polynomial A, B;
		try
		{
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
				
#ifdef _WIN64
				SetConsoleTextAttribute(console_color, Green);
#endif

				cout << "Полином А: ";
				A.getPolynomial();
				cout << "Полином B: ";
				B.getPolynomial();

				switch (choice) {
				case Choice::A_plus_B:
				{
					cout << "C = A + B: ";
					(A + B).getPolynomial();
					break;
				}
				case Choice::A_minus_B:
				{
					cout << "C = A - B: ";
					(A - B).getPolynomial();
					break;
				}
				case Choice::B_minus_A:
				{
					cout << "C = B - A: ";
					(B - A).getPolynomial();
					break;
				}
				case Choice::A_mult_B:
				{
					cout << "C = A * B: ";
					(A * B).getPolynomial();
					break;
				}
				case Choice::Const_mult:
				{
#ifdef _WIN64
					SetConsoleTextAttribute(console_color, White);
#endif
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

#ifdef _WIN64
					SetConsoleTextAttribute(console_color, Green);
#endif

					switch (choice) {
					case Choice::A_mult_Const:
					{
						cout << "C = A * const: ";
						(A * var).getPolynomial();
						break;
					}

					case Choice::B_mult_Const:
					{
						cout << "C = B * const: ";
						(A * var).getPolynomial();
						break;
					}

					default:
					{
						break;
					}}
					
#ifdef _WIN64
					SetConsoleTextAttribute(console_color, White);
#endif

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

#ifdef _WIN64
				SetConsoleTextAttribute(console_color, White);
#endif
			}

			shortLine();
			cout << "Хотите выйти из программы?" << endl;
			cout << "1) Выйти" << endl;
			cout << "2) Продолжить" << endl;
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
#ifdef _WIN64
			SetConsoleTextAttribute(console_color, White);
#endif
			cout << endl;
			shortLine();
#ifdef _WIN64
			SetConsoleTextAttribute(console_color, Red);
#endif
			cout << msg << endl;
#ifdef _WIN64
			SetConsoleTextAttribute(console_color, White);
#endif
			shortLine();
		}
	}
}
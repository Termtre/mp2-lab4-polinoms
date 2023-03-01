#include "polynomial.h"
#include <locale.h>

#ifdef _WIN64 or _WIN32
#include <windows.h>
#endif

void polynomialEnter()
{
	size_t degree, size;
	double coef;

	cout << "������� ���������� ������� � ��������: ";
	cin >> size;

	for (size_t i = 0; i < size; i++)
	{
		cout << "������� ������� ������: ";
		cin >> degree;

		cout << "������� ����������� ������: ";
		cin >> coef;
	}
}

enum class Choice { A_plus_B = 1, A_minus_B, B_minus_A, A_mult_B, A_mult_Const, B_mult_Const, Quit1 = 1, Quit2 = 7 };
enum Colors { Black = 0, Blue = 1, Green, LightBlue, Red, White = 7, UltraGreen = 10, Coral = 12, UltraWhite = 15 };
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� �����������: " << endl;
	cout << "1) ������� �� ������ ������ ���������� ������� � ��������" << endl;
	cout << "2) ������ ��� ������� ������ �������� ��� �������" << endl;
#ifdef _WIN64 or _WIN32
	SetConsoleTextAttribute(console_color, Coral);
#endif
	cout << "   !!!��������: " << endl;
	cout << "   ���������� ����� �������� �� ������� � 'x'" << endl;
	cout << "   ���������� �������� - ������� 'y'" << endl;
	cout << "   ���������� ������ - ������� z" << endl;
	cout << "   ������������ ������� - 999!!!" << endl;
#ifdef _WIN64 or _WIN32
	SetConsoleTextAttribute(console_color, White);
#endif
	cout << "3) ������� ����������� ������" << endl;
	cout << "4) ���������� ���� 2) � 3) �� ��� ���, ���� �� �������� ���� ������ ��������" << endl;
	cout << "5) �������� �������� ��� ��������" << endl;
	
	cout << "____________________________________________________________________________" << endl << endl;

	size_t choice, quit1 = 1, quit2;
	Choice temp;
	while (quit1)
	{
		try
		{
			quit2 = 1;
			cout << "������� ������ �������(A)" << endl;
			polynomialEnter();

			cout << "______________________________" << endl;

			cout << "������� ������ �������(B)" << endl;
			polynomialEnter();

			while (quit2)
			{
				cout << "______________________________" << endl;
				cout << "�������� ��������: " << endl;
				cout << "1) C = A + B" << endl;
				cout << "2) C = A - B" << endl;
				cout << "3) C = B - A" << endl;
				cout << "4) C = A * B" << endl;
				cout << "5) C = A * const" << endl;
				cout << "6) C = B * const" << endl;
				cout << "7) ����� �� ���� ������ ��������" << endl;
				cout << "��� �����: ";
				cin >> choice;
				cout << "______________________________" << endl;

				temp = static_cast<Choice>(choice);
				
				switch (temp) {
				case Choice::A_plus_B:
				{
					cout << "C = A + B: " << endl;
					throw "This is wrong. Try again";
					break;
				}
				case Choice::A_minus_B:
				{
					cout << "C = A - B: " << endl;
					break;
				}
				case Choice::B_minus_A:
				{
					cout << "C = B - A: " << endl;
					break;
				}
				case Choice::A_mult_B:
				{
					cout << "C = A * B: " << endl;
					break;
				}
				case Choice::A_mult_Const:
				{
					cout << "C = A * const: " << endl;
					break;
				}
				case Choice::B_mult_Const:
				{
					cout << "C = B * const: " << endl;
					break;
				}
				case Choice::Quit2:
				{
					quit2 = 0;
					break;
				}
				default:
				{
					cout << "��������� �������" << endl;
					break;
				}}
			}

			cout << "������ ����� �� ���������?" << endl;
			cout << "1) �����" << endl;
			cout << "2) ����������" << endl;
			cout << "��� �����: ";
			cin >> choice;
			temp = static_cast<Choice>(choice);

			switch (temp) {
			case Choice::Quit1:
			{
				quit1 = 0;
				break;
			}
			default:
			{
				cout << "______________________________" << endl;
				break;
			}}
		}

		catch (const char* msg)
		{
			cout << "______________________________" << endl;
#ifdef _WIN64 or _WIN32
			SetConsoleTextAttribute(console_color, Red);
#endif
			cout << msg << endl;
#ifdef _WIN64 or _WIN32
			SetConsoleTextAttribute(console_color, White);
#endif
			cout << "______________________________" << endl;
		}
	}
}
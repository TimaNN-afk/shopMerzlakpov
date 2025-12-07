#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <unordered_set>

//------------------------------------- Учётки --------------------------------------------
size_t userSize = 3;
size_t staffCount = 1;
std::string userStatus[3]{ "Супер администратор",  "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "sup", "ad", "us" };
std::string* passArr = new std::string[userSize]{ "1", "1", "1" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[1], userStatus[2] };
long double  * bonusArr = new  long double  [userSize] {0.0, 0.0, 0.0};
unsigned int* userIdArr = new unsigned int[userSize] {1, 2, 3};
unsigned int currentId = 0;
std::string currentStatus;


void ChangeUsers();
void ShowUsers(int mode = 0);
void AddNewUser();
void ChangePass();
void DeleteUser();


//-----------------------------------------------------------------------------------------

//------------------------------------- Склад ---------------------------------------------
size_t storageSize = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
long double* priceArr = nullptr;

bool isStorageCreated = false;

void CreateStorage();
void BuildStorage();
void ShowStorage(int mode = 0);
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();


void ChangeStorange();
void AddNewItem();
void ChangeName();
void DeleteItem();

void StorageReturner();

template<typename ArrType>
void FillArray(ArrType* dinamicArray, ArrType* staticArray, size_t arraySize);
//-----------------------------------------------------------------------------------------

//------------------------------------- Продажи -------------------------------------------
size_t checkSize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
long double* priceArrCheck;
long double* totalPriceArrCheck;

long double cashIncome = 0.0;
long double bankIncome = 0.0;
long double cash = 990000;

void Selling();
void CheckArrAppend();
void PrintCheck(long double  & totalSum);

//-----------------------------------------------------------------------------------------

//------------------------------------- Служебные -----------------------------------------
std::unordered_set<char> loginSymbols;
std::unordered_set<char> passSymbols;
bool isLoginSetCreated = false;
bool isPassSetCreated = false;

void Start();
bool Login();
bool Logout();
void ShowIncome();
void IsLoginSetCreated();
void IsPassSetCreated();
bool CheckLogin(const std::string& str);
bool CheckPass(const std::string& str);
void SnowSuperAdminMenu();
bool IsNumber(const std::string& str);
inline void GetLine (std::string& str);
inline void Err(int time = 1500);
//-----------------------------------------------------------------------------------------

int main() // Магазин видеокарт
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	delete[] loginArr, passArr, statusArr;
	if (isStorageCreated)
	{
		delete[] idArr, nameArr, countArr, priceArr, bonusArr, userIdArr;
	}
	return 0;
}
void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::cout << "ID\t" << std::left << std::setw(60) << "Название товара" << std::left << std::setw(10) << "Кол-во" << std::left << "Цена\n";
		std::cout << std::fixed << std::setprecision(2);
		for (int i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << std::left << std::setw(10) << countArr[i] << std::left << priceArr[i] << "\n";
		}
		system("pause");
		system("cls");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(60) << "Название товара" << std::left << std::setw(10) << "Кол-во\n";
		std::cout << std::fixed << std::setprecision(2);
		for (int i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << std::left << std::setw(10) << countArr[i] << "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(60) << "Название товара" << std::left << "Цена\n";
		std::cout << std::fixed << std::setprecision(2);
		for (int i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << std::left << priceArr[i] << "\n";
		}
	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << std::setw(60) << "Название товара\n";
		for (int i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << "\t" << std::endl;
		}
	}
}

void CreateStorage()
{
	const int staticSize = 10;

	unsigned int id[staticSize]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::string name[staticSize]
	{
		"Видеокарта AmdAsusPrime RTX 2090 - 4 gb", "Видеокарта AmdAsusPrime RTX 4060 ti super - 8 gb",
		"Видеокарта AmdAsusPrime RTX 5070 ti MegaSuper - 32 gb", "Видеокарта AmdAsusPrime RTX 5090 ti UltraSupersi - 64 gb",
		"Видеокарта AmdAsusPrime RTX 2010 - 2 gb", "Видеокарта AmdAsusPrime RTX A5000 - 48 gb",
		"Видеокарта AmdAsusPrime RTX 5060 ti MegaSuper - 24 gb", "Видеокарта AmdAsusPrime RTX 5070 - 8 gb",
		"Видеокарта AmdAsusPrime RTX 2050 ti super - 16 gb", "Видеокарта AmdAsusPrime RTX 5080 - 16 gb",
	};
	unsigned int count[staticSize]{ 3, 4, 2, 1, 10, 2, 3, 5, 6, 4 };
	long double price[staticSize]{ 25999.99, 44999.99, 144999.99, 699999.99, 19999.99, 999999.99, 59999.99, 114999.999, 28999.99, 117999.99 };

	if (isStorageCreated)
	{
		delete[] idArr, nameArr, countArr, priceArr;
	}

	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	countArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	priceArr = new long double [storageSize];

	isStorageCreated = true;

	FillArray(idArr, id, storageSize);
	FillArray(nameArr, name, storageSize);
	FillArray(countArr, count, storageSize);
	FillArray(priceArr, price, storageSize);
}

void Start()
{
	std::string choose;
	std::cout << "\n\n\n\t\t\t3dMaps\n\n\n";
	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			while (true)
			{
				std::cout << "Выберите склад\n1- Готовый склад\n2 - Создать новый\nВвод: ";
				GetLine (choose);
				if (choose == "1")
				{
					system("cls");
					if (!isStorageCreated)
					{
						CreateStorage();
					}
					SnowSuperAdminMenu();

				}
				else if (choose == "2")
				{
					if (!isStorageCreated)
					{
						BuildStorage();
					}
					system("cls");
					SnowSuperAdminMenu();
				}
				else
				{
					Err();
				}
			}
			// Открытие + создание склада
		}
		else if (currentStatus == userStatus[1])
		{

			if (!isStorageCreated)
			{
				CreateStorage();
			}
			// Открытие + создание склада
		}
		else if (currentStatus == userStatus[2])
		{
			if (!isStorageCreated)
			{
				CreateStorage();
			}
			// Открытие + создание склада
		}
	}
	else
	{
		system("cls");
		std::cout << "Завершения работы программы" << std::endl << std::endl;
	}
}

bool Login()
{
	std::string login, pass;

	while (true)
	{
		std::cout << "Введите логин: ";
		GetLine (login);
		std::cout << "Введите пароль: ";
		GetLine (pass);
		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}
		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				system("cls");
				std::cout << "Пользователь: " << loginArr[i] << "\n\nДобро пожаловать!\n\n";
				std::cout << "Ваш статус: " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				currentId = userIdArr[i];
				return true;
			}
		}

	}
}

inline void GetLine (std::string& str)
{
	std::getline(std::cin, str, '\n');
}

inline void Err(int time)
{
	std::cout << "Некоректный ввод" << std::endl << std::endl;
	Sleep(time);
	system("cls");
}

template<typename ArrType>
void FillArray(ArrType* dinamicArray, ArrType* staticArray, size_t arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		dinamicArray[i] = staticArray[i];
	}
}

void SnowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу" << std::endl;
		std::cout << "2 - Показать склад" << std::endl;
		std::cout << "3 - Пополнить склад" << std::endl;
		std::cout << "4 - Списать товар" << std::endl;
		std::cout << "5 - Изменить цену" << std::endl;
		std::cout << "6 - Редактировать склад" << std::endl;
		std::cout << "7 - Редактировать персонал" << std::endl;
		std::cout << "8 - Отчет о прибыли" << std::endl;
		std::cout << "0 - Закрыть смену" << std::endl;

		std::cout << "Ввод: ";
		GetLine (choose);
		if (choose == "1" && storageSize > 0)
		{
			void Selling();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ShowStorage();
		}
		else if (choose == "3" && storageSize > 0)
		{
			AddStorageItem();
		}
		else if (choose == "4" && storageSize > 0)
		{
			RemoveStorageItem();
		}
		else if (choose == "5" && storageSize > 0)
		{
			ChangeStorange();
		}
		else if (choose == "6")
		{
			ChangeStorange();
		}
		else if (choose == "7")
		{
			ChangeUsers();
		}
		else if (choose == "8")
		{
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (Logout())
			{
				break;
			}
		}
		else
		{
			if (storageSize < 1)
			{
				std::cout << "Склад пуст\n";
			}
			Err();
		}
	}
}

void AddStorageItem()
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода: ";
		GetLine (chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операция пополнения товара!" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
		std::cout << "Введите кол-во товара для пополнения: ";
		GetLine (chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > 20)
			{
				std::cout << "Некорректный id или кол-во\nМаксимальное кол-во 20";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(50) << nameArr[id] << "\t" << countArr[id] << " ---> " << countArr[id] + count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2- Нет\nВвод: ";
				GetLine (choose);
				if (choose == "1")
				{
					countArr[id] += count;
					std::cout << "Товар успешно пополнен\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена пополнения товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void RemoveStorageItem()
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода: ";
		GetLine (chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операция списания товара!" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
		std::cout << "Введите кол-во товара для списания: ";
		GetLine (chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > countArr[id])
			{
				std::cout << "Некорректный id или кол-во\nМаксимальное кол-во 20";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(50) << nameArr[id] << "\t" << countArr[id] << " ---> " << countArr[id] - count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2- Нет\nВвод: ";
				GetLine (choose);
				if (choose == "1")
				{
					countArr[id] -= count;
					std::cout << "Товар успешно списан\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена списания товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangePrice()
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;
	long double  newPrice = 0.0;
	while (true)
	{
		system("cls");
		ShowStorage(2);
		std::cout << "Введите ID товара или \"exit\" для выхода: ";
		GetLine (chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операция изменение цены!" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
		std::cout << "Введите новую цену товара: ";
		GetLine (chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stod(chooseId) - 1;
			count = std::stod(chooseCount);

			if (id < 0 || id > storageSize - 1 || newPrice < 0.0 || newPrice > 999999.99)
			{
				std::cout << "Некорректная цена\nМаксимальное цена - " << 999999.99 << "\n\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(50) << nameArr[id] << "\t" << priceArr[id] << " ---> " << newPrice << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2- Нет\nВвод: ";
				GetLine (choose);
				if (choose == "1")
				{
					countArr[id] -= count;
					std::cout << "Цена успешно изменена\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена изменения цены\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Ошибка длины числа. Максимум девятизначные числа!\n\n";
		Sleep(1500);
		return false();
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Введенные данные не являются числом!\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}
void BuildStorage()
{
	while (true)
	{
		std::string choose;
		AddNewItem();
		if (storageSize == 0)
		{
			system("cls");
			std::cout << "Вы уверены что хотите оставить склад пустым?\n1 - Да\n2 - Нет\nВвод: ";
			GetLine(choose);
			if (choose == "1")
			{
				break;
			}
			else if (choose == "2")
			{
				continue;
			}
			else
			{
				Err();
				Sleep(1500);
				continue;
			}
		}
		else
		{
			ShowStorage();
			break;
		}
	}
}
void ChangeStorange()
{
	system("cls");
	std::string choose;
	while (true)
	{
		std::cout << "1 - Добавить новый товар" << std::endl;
		std::cout << "2 - Изменить название товара" << std::endl;
		std::cout << "3 - Удалить товар" << std::endl;
		std::cout << "0 - Выйти из редактора" << std::endl;

		std::cout << "Ввод: ";
		GetLine (choose);
		if (choose == "1")
		{
			AddNewItem();
		}
		else if (choose == "2" && storageSize > 0)
		{
			ChangeName();
		}
		else if (choose == "3" && storageSize > 0)
		{
			DeleteItem();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (storageSize < 1)
			{
				std::cout << "Склад пустой\n";
			}
			Err();
		}
	}
}

void AddNewItem()
{
	std::string newName, newPrice, newCount, choose;
	long double price = 0.0;
	unsigned int count = 0;
	bool exit;

	while (true)
	{
		exit = true;
		while (true)
		{
			system("cls");
			std::cout << "\tДобавление нового товара";
			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращение операции\n\n";
			std::cout << "Введите название нового товара: ";
			GetLine (newName);
			if (newName == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n";
				Sleep(1488);
				exit = false;
				break;
			}

			if (newName.size() <= 0 || newName.size() >= 60)
			{
				std::cout << "Ошибка имени. Максимальная длина 60 символов\n";
				Sleep(1500);
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара";
			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращение операции\n\n";
			std::cout << "Введите кол-во нового товара: ";
			GetLine (newPrice);
			if (newName == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n";
				Sleep(1488);
				exit = false;
				break;
			}

			if (IsNumber(newCount))
			{
				count = std::stoi(newCount);
				if (count > 20 || count < 0)
				{
					std::cout << "Ошибка максимального кол-во товара. Не более 20 ед\n";
					Sleep(1500);
				}
				Sleep(1500);
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "\tДобавление нового товара";
			std::cout << "\tДобавление нового товара!\n\nВведите \"exit\" для прекращение операции\n\n";
			std::cout << "Введите цену нового товара: ";
			GetLine (newPrice);
			if (newName == "exit")
			{
				std::cout << "Операция добавления товара прервана!\n";
				Sleep(1488);
				exit = false;
				break;
			}

			if (IsNumber(newCount))
			{
				count = std::stod(newPrice);
				if (price > 99999999.99 || price < 0)
				{
					std::cout << "Ошибка цены товара. Не более 99999999.99 руб\n";
					Sleep(1500);
				}
				Sleep(1500);
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "Новый товар: " << newName << std::endl;
			std::cout << "Кол-во" << count << std::endl;
			std::cout << "Цена" << price << std::endl;
			std::cout << "Подтвердить?\n1- Да\nНет\nВвод: ";
			GetLine (choose);
			if (choose == "1")
			{
				storageSize++;
				unsigned int* idArrTemp = new unsigned int[storageSize];
				std::string* nameArrTemp = new std::string[storageSize];
				unsigned int* countArrTemp = new unsigned int[storageSize];
				long double* priceArrTemp = new long double[storageSize];

				FillArray(idArrTemp, idArr, storageSize - 1);
				FillArray(nameArrTemp, nameArr, storageSize - 1);
				FillArray(countArrTemp, countArr, storageSize - 1);
				FillArray(priceArrTemp, priceArr, storageSize - 1);

				idArrTemp[storageSize - 1] = storageSize;
				nameArrTemp[storageSize - 1] = newName;
				countArrTemp[storageSize - 1] = count;
				priceArrTemp[storageSize - 1] = price;

				std::swap(idArr, idArrTemp);
				std::swap(nameArr, nameArrTemp);
				std::swap(countArr, countArrTemp);
				std::swap(priceArr, priceArrTemp);

				delete[] idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
				std::cout << "Идет подготова... ";
				Sleep(2000);
				std::cout << "Товар успешно добавлен\n\n";
				Sleep(1500);
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена\n\n";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}

		}

		if (exit == false)
		{
			break;
		}
	}
}

void ChangeName()
{
	std::string chooseId, newName, choose;
	unsigned int id = 0;

	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите ID товара или \"exit\" для выхода: ";
		GetLine (chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции смены названия\n";
			Sleep(1500);
			break;
		}
		std::cout << "Введите новое название товара: ";
		GetLine (newName);

		if (newName.size() <= 0 || newName.size() >= 60)
		{
			std::cout << "Ошибка имени. Максимальная длина 60 символов\n";
			Sleep(1500);
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID!\n";
				Sleep(1500);
			}
			else
			{
				std::cout << nameArr[id] << " --> " << newName << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nввод: ";
				GetLine (choose);
				if (choose == "1")
				{
					nameArr[id] = newName;
					std::cout << "Смена названия завершена\n";
					Sleep(1500);
					break;
				}
				else if (true)
				{
					std::cout << "Отмена операции\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}
void DeleteItem()
{
	std::string chooseId, choose;
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		ShowStorage(3);
		std::cout << "\nВведите ID товара для удаление или \"exit\" для выхода: ";
		GetLine (chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операции удаления товара\n";
			Sleep(1500);
			break;
		}
		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1501);
			}
			else
			{
				std::cout << "Товар на удаление: " << nameArr[id] << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
				GetLine (choose);
				if (choose == "1")
				{
					storageSize--;
					unsigned int* idArrTemp = new unsigned int[storageSize];
					std::string* nameArrTemp = new std::string[storageSize];
					unsigned int* countArrTemp = new unsigned int[storageSize];
					long double * priceArrTemp = new long double [storageSize];

					for (int i = 0, c = 0; i < storageSize; i++, c++)
					{
						if (id == c)
						{
							c++;
						}
						idArrTemp[i] = i + 1;
						nameArrTemp[i] = nameArr[c];
						countArrTemp[i] = countArr[c];
						priceArrTemp[i] = priceArr[c];
					}

					std::swap(idArr, idArrTemp);
					std::swap(nameArr, nameArrTemp);
					std::swap(countArr, countArrTemp);
					std::swap(priceArr, priceArrTemp);

					delete[] idArrTemp, nameArrTemp, countArrTemp, priceArrTemp;
					std::cout << "Идет подготова... ";
					Sleep(2000);
					std::cout << "Товар успешно удален\n\n";
					Sleep(1500);
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangeUsers()
{
	if (!isLoginSetCreated)
	{
		IsLoginSetCreated();
	}
	if (!isPassSetCreated)
	{
		IsPassSetCreated();
	}
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Добавить нового пользователя" << std::endl;
		std::cout << "2 - Показать пользователей" << std::endl;
		std::cout << "3 - Изменить пароль пользователя" << std::endl;
		std::cout << "4 - Удалить пользователя" << std::endl;
		std::cout << "0 - Выйти из редактора" << std::endl;

		std::cout << "Ввод: ";
		GetLine (choose);
		if (choose == "1")
		{
			AddNewUser();
		}
		else if (choose == "2" && userSize > 1)
		{
			ShowUsers();
		}
		else if (choose == "3" && userSize > 1)
		{
			ChangePass();
		}
		else if (choose == "4" && userSize > 1)
		{
			DeleteUser();
		}
		else if (choose == "0")
		{
			system("cls");
			break;
		}
		else
		{
			if (userSize < 2)
			{
				std::cout << "Пользователи отсутствуют\n";
			}
			Err();
		}
	}
}

void ShowUsers(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "№\t" << std::left << std::setw(12) << "Логин\t\t" << "   Пароль\t\t\t" << "Роль\n";

		for (int i = 1; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(9) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t" << statusArr[i] << std::endl;
		}
		system("pause");
	}
	else if (mode == 1)
	{
		std::cout << "№\t" << std::left << std::setw(12) << "Логин\t\t" << "   Пароль\t\t\t" << "Роль\n";

		for (int i = 0; i < userSize; i++)
		{
			std::cout << i << "\t" << std::left << std::setw(9) << loginArr[i] << "\t\t" << passArr[i] << "\t\t\t" << statusArr[i] << std::endl;
		}
		system("pause");
	}
}

void IsLoginSetCreated()
{
	for (char i = '0'; i <= '9'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		loginSymbols.insert(i);
	}
	isLoginSetCreated = true;
}
void IsPassSetCreated()
{
	for (char i = '!'; i <= '&'; i++)
	{
		passSymbols.insert(i);
	}
	for (char i = '('; i <= '+'; i++)
	{
		passSymbols.insert(i);
	}
	for (char i = '/'; i <= '~'; i++)
	{
		passSymbols.insert(i);
	}

	isPassSetCreated = true;
}

bool CheckLogin(const std::string& str)
{
	if (str.size() < 5 || str.size() > 20)
	{
		std::cout << "Ошибка длины логика" << std::endl;
		Sleep(1500);
		return false;
	}
	for (char sym : str)
	{
		if (!loginSymbols.count(sym))
		{
			std::cout << "Некорректный логин" << std::endl;
			Sleep(1500);
			return false;
		}
	}
	for (int i = 0; i < userSize; i++)
	{
		if (str == nameArr[i])
		{
			std::cout << "Такой пользователь уже существует\n";
			Sleep(1500);
			return false;
		}
	}
}

bool CheckPass(const std::string& str)
{
	int numCount = 0, symCount = 0;;
	if (str.size() < 8 || str.size() > 30)
	{
		std::cout << "Ошибка длины логика" << std::endl;
		Sleep(1500);
		return false;
	}
	std::unordered_set<char> specialSymbols{ '!','@','#','$','%','^','&','*','(',')','-','_','=','+','/','?','|','\\','\"','\'',',','.','<','>','~','`',':',';','{','}','[',']' };

	for (char sym : str)
	{
		if (!passSymbols.count(sym))
		{
			std::cout << "Некорректный пароль" << std::endl;
			Sleep(1500);
			return false;
		}
		if (std::isdigit(sym))
		{
			numCount++;
		}
		if (specialSymbols.count(sym))
		{
			symCount++;
		}
	}
	if (numCount > 2 && symCount > 2)
	{
		return true;
	}
	else
	{
		std::cout << "Минимум 3 символа и 3 цифры!" << std::endl;
		return false;
	}
}

void AddNewUser()
{
	std::string newLogin, newPass, newRole, choose;
	bool exit = true;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::cout << "Введите логин нового пользователя \"exit\" для выхода: ";
			GetLine (newLogin);
			if (newLogin == "exit")
			{
				std::cout << "Отмена добавления нового пользователя" << std::endl;
				Sleep(1502);
				exit = false;
				break;
			}
			if (CheckLogin(newLogin))
			{
				break;
			}
			else
			{
				std::cout << "Допустимые символы a-z, A-Z, 0-9,\n\n ";
				Sleep(1500);
			}
		}
		while (true)
		{
			system("cls");
			std::cout << "Введите пароль нового пользователя \"exit\" для выхода: ";
			GetLine (newPass);
			if (newLogin == "exit")
			{
				std::cout << "Отмена добавления нового пользователя" << std::endl;
				Sleep(1502);
				exit = false;
				break;
			}
			if (CheckPass(newPass))
			{
				break;
			}
			else
			{
				std::cout << "Допустимые символы a-z, A-Z, 0-9,\n\n ";
				Sleep(1500);
			}
		}
		while (true)
		{
			system("cls");
			std::cout << "Введите роль для нового пользователя \"exit\" для выхода\n ";
			std::cout << "1 - Администратор\n2 - Сотрудник\nВвод: ";
			GetLine (choose);
			if (newLogin == "exit")
			{
				std::cout << "Отмена добавления нового пользователя" << std::endl;;
				Sleep(1502);
				exit = false;
				break;
			}
			if (choose == "1")
			{
				newRole = userStatus[1];
				break;
			}
			else if (choose == "2")
			{
				newRole = userStatus[2];
				break;
			}
			else
			{
				Err();
			}
		}
		while (true)
		{
			system("cls");
			std::cout << "Пользователь: " << newLogin << std::endl;
			std::cout << "Парль: " << newPass << std::endl;
			std::cout << "Роль: " << newRole << std::endl;
			std::cout << "Подтвердить?\n1 - Да\2 - Нет\nВвод: ";
			GetLine (choose);
			if (choose == "1")
			{
				userSize++;
				if (newRole == userStatus[2])
				{
					staffCount++;
				}
				std::string* loginArrTemp = new std::string[userSize];
				std::string* passArrTemp = new std::string[userSize];
				std::string* statusArrTemp = new std::string[userSize];
				long double * bonusArrTemp = new long double [userSize];
				unsigned int* userIdArrTemp = new unsigned int[userSize];

				FillArray(loginArrTemp, loginArr, userSize - 1);
				FillArray(passArrTemp, passArr, userSize - 1);
				FillArray(statusArrTemp, statusArr, userSize - 1);
				FillArray(bonusArrTemp, bonusArr, userSize - 1);
				FillArray(userIdArrTemp, userIdArr, userSize - 1);

				loginArrTemp[userSize - 1] = newLogin;
				passArrTemp[userSize - 1] = newPass;
				statusArrTemp[userSize - 1] = newRole;
				bonusArrTemp[userSize - 1] = 0.0;
				userIdArrTemp[userSize - 1] = userSize;

				std::swap(loginArr, loginArrTemp);
				std::swap(passArr, passArrTemp);
				std::swap(statusArr, statusArrTemp);
				std::swap(bonusArr, bonusArrTemp);
				std::swap(userIdArr, userIdArrTemp);

				delete[] loginArrTemp, passArrTemp, statusArrTemp;
				std::cout << "Идет подготовка...";
				Sleep(2000);
				std::cout << "Пользватель испешно добавлен!\n\n";
				Sleep(1500);
				exit = false;
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена" << std::endl;
				Sleep(1500);
			}
			else
			{
				Err();
			}
		}
		if (exit == false)
		{
			break;
		}
	}
}

void ChangePass()
{
	system("cls");
	std::string newPass1, newPass2, choose;
	int userId = 0, isAdmin = 0;

	while (true)
	{
		if (currentStatus == userStatus[0])
		{
			ShowUsers(1);
			isAdmin = 0;
		}
		else
		{
			ShowUsers();
			isAdmin = 1;
		}
		std::cout << "\nВыберете номер пользователя для смены пароля или \"exit\" для выхода: ";
		GetLine(choose);
		if (choose == "exit")
		{
			std::cout << "Отмена операции!";
			Sleep(1500);
			break;
		}
		else if (IsNumber(choose))
		{
			userId = std::stoi(choose);
			if (userId < isAdmin || userId > userSize - 1)
			{
				std::cout << "Такого пользователя нет\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			Err();
			continue;
		}

		while (true)
		{
			system("cls");
			if (currentStatus == userStatus[1] && statusArr[userId] == userStatus[1])
			{
				std::cout << "Нельзя менять пароль админу!\n";
				Sleep(1500);
				break;
			}

			std::cout << "Введите новый пароль для пользователя " << loginArr[userId] << ": ";
			GetLine(newPass1);
			std::cout << "Подтвердите новый пароль для пользователя " << loginArr[userId] << ": ";
			GetLine(newPass2);

			if (CheckPass(newPass1) && CheckPass(newPass2))
			{
				if (newPass1 == newPass2 && newPass1 != passArr[userId] && newPass2 != passArr[userId])
				{
					passArr[userId] = newPass1;
					std::cout << "Успешно\n";
					Sleep(1500);
					break;
				}
				else
				{
					std::cout << "Повторите попытку\n";
					Sleep(1200);
				}
			}
		}
	}
}

void DeleteUser()
{
	std::string chooseId, checkPass, choose;
	int userId, isAdmin = 1;
	while (true)
	{
		if (currentStatus == userStatus[0] && userSize < 2)
		{
			std::cout << "Нет доступных пользователей для удаления" << std::endl;
			Sleep(1500);
			return;
		}
		else if (currentStatus == userStatus[1] && staffCount < 1)
		{
			std::cout << "Нет доступных пользователей для удаление" << std::endl;
			Sleep(1500);
			return;
		}

		ShowUsers();
		std::cout << "\nВыберите номер пользователя для удаления или \"exit\" для выхода: ";
		GetLine (choose);
		if (choose == "exit")
		{
			std::cout << "Отмена удаление пользователя!\n";
			Sleep(1500);
			break;
		}

		else if (IsNumber(choose))
		{
			userId = std::stoi(choose);
			if (userId < isAdmin || userId > userSize - 1)
			{
				std::cout << "Пользователя с таким номером не существует" << std::endl;
				Sleep(1500);
				break;
			}
			while (true)
			{
				system("cls");
				if (currentStatus == userStatus[1] && statusArr[userId] == userStatus[1])
				{
					std::cout << "Нельзя удалять администратора" << std::endl;
					Sleep(1500);
					break;
				}

				std::cout << "Удаление пользователя: " << loginArr[userId] << "\n\n";
				std::cout << "Для подтверждения введите пароль супер администратра \"exit\" для выхода: ";
				GetLine(checkPass);
				if (checkPass == "exit")
				{
					std::cout << "Отмена удаление пользователя: " << loginArr[userId] << "\n";
					Sleep(1500);
					break;
				}
				else if (checkPass == passArr[0])
				{
					if (statusArr[userId] == userStatus[2])
					{
						staffCount--;
					}
					userSize--;
					std::string* loginArrTemp = new std::string[userSize];
					std::string* passArrTemp = new std::string[userSize];
					std::string* statusArrTemp = new std::string[userSize];
					long double * bonusArrTemp = new long double [userSize];
					unsigned int* userIdArrTemp = new unsigned int[userSize];

					for (int i = 0, c = 0; i < userSize; i++, c++)
					{
						if (userId == c)
						{
							c++;
						}
						loginArrTemp[i] = loginArr[i];
						passArrTemp[i] = passArr[c];
						statusArrTemp[i] = statusArr[c];
						bonusArrTemp[i] = bonusArr[c];
						userIdArrTemp[i] = i + 1;
					}

					std::swap(loginArr, loginArrTemp);
					std::swap(passArr, passArrTemp);
					std::swap(statusArr, statusArrTemp);
					std::swap(bonusArr, bonusArrTemp);
					std::swap(userIdArr, userIdArrTemp);

					delete[] loginArrTemp, passArrTemp, statusArrTemp;
					std::cout << "Идет подготовка...";
					Sleep(2000);
					std::cout << "Пользватель испешно добавлен!\n\n";
					Sleep(1500);
					break;
				}
				else
				{
					Err();
				}
			}
		}
		else
		{
			Err();
		}
	}
}

void Selling()
{
	std::string chooseId, chooseCount, chooseMoney, choose;
	unsigned int id = 0, count = 0;
	int index = -1;
	long double money = 0, totalSum = 0;
	bool isFirst = false;

	while (true)
	{
		ShowStorage();
		std::cout << "\nВведите ID товара для покупки или \"exit\" для завершения выбора товаров: ";
		GetLine (chooseId);
		if (chooseId == "exit")
		{
			if (isFirst == false)
			{
				std::cout << "Выход без покупок\n";
				Sleep(1500);
				break;
			}

			PrintCheck(totalSum);

			std::cout << "Подтвердить покупку?\n1 - Да\n2 - Добавить ещё товара\n3 - Отмена\nВвод: ";
			GetLine (choose);
			if (choose == "1")
			{
				while (true)
				{
					system("cls");
					std::cout << "Выберете способ оплаты\n1 - Наличными\n2 - Безнал\nВвод: ";
					GetLine (choose);
					if (choose == "1")
					{
						std::cout << "К оплате: " << totalSum << "\n\n";
						std::cout << "Введите кол-во наличных: ";
						GetLine (chooseMoney);
						if (IsNumber(chooseMoney))
						{
							money = std::stod(chooseMoney);
							if (money < totalSum)
							{
								std::cout << "Недостаточно средств!\n";
								Sleep(1500);
								continue;
							}
							else if (money - totalSum > cash)
							{
								std::cout << "У нас нет сдачи.\n";
								Sleep(1500);
								continue;
							}
							else
							{
								std::cout << "Ваши: " << money << "\n\n";
								Sleep(400);
								std::cout << "Оплата прошла успешно. Сдача: " << money - totalSum << "рублей\n";
								Sleep(2000);
								cash += totalSum;
								cashIncome += totalSum;
								bonusArr[currentId] += totalSum;
								system("cls");
								break;
							}
						}
					}
					else if (choose == "2")
					{
						std::cout << "Приложите карту\n\n";
						Sleep(1500);
						if (rand() % 10 <= 2)
						{
							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Beep(500, 400);
								Sleep(800);
							}
							std::cout << "\nСоединения нет.\n\n";
						}
						else
						{

							for (size_t i = 0; i < 5; i++)
							{
								std::cout << i + 1 << "\t";
								Beep(500, 400);
								Sleep(800);
							}
							std::cout << "\nОплата принята.\n\n";
							Sleep(2000);
							bankIncome += totalSum;
							bonusArr[currentId] += totalSum;
							system("cls");
							break;
						}
					}
					else if (choose == "EvilEye")
					{
						std::cout << "Rainbow оплатила ваши покупки.";
						Sleep(1500);
						system("cls");
						break;
					}
					else
					{
						Err();
					}
					delete[]idArrCheck;
					delete[]nameArrCheck;
					delete[]countArrCheck;
					delete[]priceArrCheck;
					delete[]totalPriceArrCheck;

					idArrCheck = nullptr;
					nameArrCheck = nullptr;
					countArrCheck = nullptr;
					priceArrCheck = nullptr;
					totalPriceArrCheck = nullptr;
					checkSize = 0;
					break;
				}
			}
			else if (choose == "2")
			{
				continue;
			}
			else if (choose == "3")
			{
				std::cout << "Отмена покупки!\n";

				Sleep(1500);
				StorageReturner();
				system("cls");
				return;
			}
			else if (choose == "EvilEye")
			{

			}
			else
			{
				Err();
			}

			delete[]idArrCheck;
			delete[]nameArrCheck;
			delete[]countArrCheck;
			delete[]priceArrCheck;
			delete[]totalPriceArrCheck;
		}
		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id <  0 || id > storageSize - 1)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}

		std::cout << "\nВведите кол-во товара или \"exit\" для выбора другого товара: ";
		GetLine (chooseCount);
		if (chooseCount == "exit")
		{
			std::cout << "Отмена покупки: " << nameArr[id] << "\n";
			Sleep(1500);
			continue;
		}
		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount);
			if (count <  1 || count > countArr[id])
			{
				std::cout << "Ошибка кол-ва: " << nameArr[id] << "\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}

		CheckArrAppend();
		if (isFirst == false)
		{
			isFirst = true;
		}
		index++;
		idArrCheck[index] = idArr[id];
		nameArrCheck[index] = nameArr[id];
		priceArrCheck[index] = priceArr[id];
		countArrCheck[index] = count;
		totalPriceArrCheck[index] = count * priceArr[id];
		countArr[id] -= count;
		totalSum += totalPriceArrCheck[index];

		std::cout << "\nТовар добавлен в чек\n\n";
		Sleep(1000);
	}
}

void CheckArrAppend()
{
	checkSize++;
	int* idArrCheckTemp = new int[checkSize];
	std::string* nameArrCheckTemp = new std::string[checkSize];
	unsigned int* countArrCheckTemp = new unsigned int[checkSize];
	long double * priceArrCheckTemp = new long double [checkSize];
	long double * totalPriceArrCheckTemp = new long double [checkSize];

	FillArray(idArrCheckTemp, idArrCheck, checkSize - 1);
	FillArray(nameArrCheckTemp, nameArrCheck, checkSize - 1);
	FillArray(countArrCheckTemp, countArrCheck, checkSize - 1);
	FillArray(priceArrCheckTemp, priceArrCheck, checkSize - 1);
	FillArray(totalPriceArrCheckTemp, totalPriceArrCheck, checkSize - 1);

	std::swap(idArrCheckTemp, idArrCheck);
	std::swap(nameArrCheckTemp, nameArrCheck);
	std::swap(countArrCheckTemp, countArrCheck);
	std::swap(priceArrCheckTemp, priceArrCheck);
	std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);

	delete[] idArrCheckTemp;
	delete[] nameArrCheckTemp;
	delete[] countArrCheckTemp;
	delete[] priceArrCheckTemp;
	delete[] totalPriceArrCheckTemp;
}

void PrintCheck(long double& totalSum)
{
	system("cls");
	std::cout << "№\t" << "ID\t" << std::left << std::setw(40) << "Название товара\t\t" <<
		"Цена за ед\t" << "Кол-во\t" << "Итого\n";

	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i + 1 << idArrCheck[i] << "\t" << std::left << std::setw(40) << nameArrCheck[i]
			<< "\t\t"  << priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\t" << totalPriceArrCheck[i] << "\n";
	}
	std::cout << "\nИтого к оплате: " << std::left << std::setw(10) << totalSum << std::left << std::setw(10) << "\n\n";
}

void StorageReturner()
{
	for (size_t i = 0; i < checkSize; i++)
	{
		countArr[idArrCheck[i] - 1] += countArrCheck[i];
	}
	delete[]idArrCheck;
	delete[]nameArrCheck;
	delete[]countArrCheck;
	delete[]priceArrCheck;
	delete[]totalPriceArrCheck;

	idArrCheck = nullptr;
	nameArrCheck = nullptr;
	countArrCheck = nullptr;
	priceArrCheck = nullptr;
	totalPriceArrCheck = nullptr;
	checkSize = 0;
}

void ShowIncome()
{
	system("cls");
	std::cout << "Текущая прибль  за смену\n\n";
	std::cout << "Наличный расчет: " << cashIncome << std::endl;
	std::cout << "Безналичный расчет: " << bankIncome << std::endl;
	std::cout << "Итого: " << bankIncome + cashIncome << std::endl << std::endl;
	std::cout << "Сумма ваших продаж: " << bonusArr[currentId] << std::endl << std::endl;

	system("pause");
	system("cls");
}

bool Logout()
{
	std::string choose;
	system("cls");
	while (true)
	{
		std::cout << "Для подтверждение выхода из пользователя введите свой пароль или \"exit\" для возврата в меню: ";
		GetLine (choose);
		if (choose == "exit")
		{
			system("cls");
			return false;
		}
		else if (choose == passArr[currentId - 1] || choose == passArr[0])
		{
			system("cls");
			return true;
		}
		else
		{
			Err();
		}
	}
}

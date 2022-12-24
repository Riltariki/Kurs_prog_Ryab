#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>

#define _USE_MATH_DEFINES



//Functions
float** athlet_changes(float** Stat_fl, int N);
float** initialization_athlet(float** Stat_fl, int N);
float** athlet_random(float** Stat_fl, int N);
float** athlet_statistic(float** Stat_fl, int N);
float athlet_results(float** Stat_fl, int N);

void Data_research(float** Stat_fl, int N, int K);

float** Sort(float** Stat_fl, int N);

float** dynamic_array_alloc_float(size_t N, size_t M);
void dynamic_array_free(float** B);

void table_display(float** Stat_fl, int N);

int End_session();

int load_file(float** Stat_fl, int N);
int save_file(float** Stat_fl, int N);
//


void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float** float_data = dynamic_array_alloc_float(99, 6);

	int n = 1, count, end = 0, sort = 0, selection, selection_2;

	for (int k = 0; k < 99; k++) {
		initialization_athlet(float_data, k);
	}

	system("cls");

	while (1)
	{

		printf("\n\nФункции:\n");
		printf("1) Атлеты.\n2) Заполнить таблицу случайными значениями.\n3) Показать таблицу.\n4) Сортировка.\n5) Загрузить таблицу из файла.\n6) Сохранить таблицу в файл.\n7) Изменить количество атлетов.\n8) Выход.\n\n");
		printf("Выберите дальнейшую функцию > ");
		scanf_s("%d", &selection);
		printf("\n");
		system("cls");
		switch (selection)
		{
		case 1:
			printf("\n\n1) Редактировать параметры атлета.\n2) Поиск атлета по параметрам.\n\n");
			printf("Введите нужную вам функцию > ");
			scanf_s("%d", &selection);
			system("cls");
			switch (selection) {
			case 1:
				printf("\n\nВведите место нужного вам атлета: \n\n");
				for (int j = 0; j < n; j++) {
					printf("%d)\n", j + 1);
				}
				printf("\nВведите номер места > ");
				scanf_s("%d", &selection);
				system("cls");
				while (1) {
					printf("\n\nВведите дальнейшую функцию:\n\n");
					printf("1) Редактировать параметры атлета.\n2) Посмотреть характеристики атлета.\n4) Выход.\n\n");
					printf("Выберите номер функции > ");
					scanf_s("%d", &selection_2);
					printf("\n");
					printf("----------------------------------------------------\n\n");
					switch (selection_2)
					{
					case 1:
						athlet_changes(float_data, (selection - 1));
						system("cls");
						athlet_statistic(float_data, (selection - 1));
						break;
					case 2:
						system("cls");
						athlet_statistic(float_data, (selection - 1));
						break;
					case 4:
						system("cls");
						break;
					default:
						printf("\n\nНеправильно введена функция.");
						break;
					} if (selection_2 == 4) {
						break;
					}
				}
				break;
			case 2:
				printf("\n\nФункции:\n");
				printf("1) Поиск атлета с лучшими результатами по рывку.\n2) Поиск атлета с худшими результатами по рывку.\n3) Поиск атлета с лучшими результатами по толчку.\n4) Поиск атлета с худшими результатами по толчку.\n\n");
				printf("Выберите номер функции > ");
				scanf_s("%d", &selection_2);
				system("cls");
				printf("\n\n-----------------------------------------------\n");
				Data_research(float_data, n, selection_2);
				printf("-----------------------------------------------\n\n");
				break;
			} 
			break;
		case 2:
			printf("\n\nВсе значения таблицы сбросяться!\n\n");
			printf("Вы уверены,что хотите продолжить?\n");
			printf("1) Да\n2) Нет\n");
			printf("Команда > ");
			scanf("%d", &selection);
			switch (selection) {
			case 1:
				athlet_random(float_data, n);
				break;
			case 2:
				break;
			default:
				break;
			} system("cls");
			break;
		case 3:
			table_display(float_data, n);
			end = End_session();
			break;
		case 4:
			printf("\n\nВключить сортировку таблицы по очкам?\n1) Да\n2) Нет\n");
			printf("Команда > ");
			scanf_s("%d", &selection);
			switch (selection) {
			case 1:
				sort = 1;
				break;
			case 2:
				sort = 0;
				break;
			default:
				printf("\n\nНеправильно введена функция.");
				end = End_session();
				break;
			}
			system("cls");
			break;
		case 5:
			n = load_file(float_data, n); 
			break;
		case 6:
			save_file(float_data, n);
			break;
		case 7:
			printf("\n\nВведите количество атлетов > ");
			scanf_s("%d", &n);
		case 8:
			end = End_session();
			break;
		default:
			printf("\n\nНеправильно введена функция.");
			end = End_session();
			break;
		}
		if (end == 1) {
			break;
		}
		if (sort == 1) {
			Sort(float_data, n);
		}
	}

	dynamic_array_free(float_data);

	return 0;
}








//Function for changing athlet data
float** athlet_changes(float** Stat_fl, int N) {

	Stat_fl[N][0] = N + 1;
	printf("\n\nВведите возраст атлета > ");
	scanf_s("%d", &Stat_fl[N][1]);
	printf("Введите вес атлета > ");
	scanf_s("%f", &Stat_fl[N][2]);
	printf("Введите толчок атлета > ");
	scanf_s("%f", &Stat_fl[N][3]);
	printf("Введите рывок атлета > ");
	scanf_s("%f", &Stat_fl[N][4]);
	printf("\n");
	return Stat_fl;
}



//Function for athlet initialization
float** initialization_athlet(float** Stat_fl, int N) {

	for (int i = 0; i < N; i++) {
		Stat_fl[i][0] = i + 1;
		Stat_fl[i][1] = 0;
		Stat_fl[i][2] = 0;
		for (int j = 2; j < 5; j++) {
			Stat_fl[i][j + 1] = 0;
		}
	}
	return Stat_fl;
}



//Function for randomize athlet's data
float** athlet_random(float** Stat_fl, int N) {

	for (int i = 0; i < N; i++) {
		Stat_fl[i][0] = i + 1;
		Stat_fl[i][1] = 15 + rand() % 40;;
		Stat_fl[i][2] = 50 + rand() % 90;;
		for (int j = 2; j < 4; j++) {
			Stat_fl[i][j+1] = 140 + rand() % 300;
		}
	}
	return Stat_fl;
}




//Function for showing athlet's data
float** athlet_statistic(float** Stat_fl, int N) {
	printf("\n\nДанные об атлете:\n\n");
	printf("Номер атлета > %d\nВозраст > %d\nВес > %.1f\nТолчок > %.1f\nРывок > %.1f\nСумма очков > %.1f\n\n", 
		Stat_fl[N][0], Stat_fl[N][1], Stat_fl[N][2], Stat_fl[N][3], Stat_fl[N][4], athlet_results(Stat_fl,N));
}




//Function for resulting summary points of the athlet
float athlet_results(float** Stat_fl, int N) {

	float A = 0.751945030;
	float b = 175.508;
	Stat_fl[N][5] = (Stat_fl[N][3] + Stat_fl[N][4]) * pow(10, A * pow(log10(Stat_fl[N][2] / b), 2));
	return Stat_fl[N][5];

}




//Function for researching athlet from his data
void Data_research(float** Stat_fl, int N, int K) {

	float temp[1][6];


	switch (K) {
	case 1:
		for (int k = 0; k < 5; k++) {
			temp[0][k] = Stat_fl[0][k];
		}
		for (int i = 0; i < N-1; i++) {
			if (temp[0][3] < Stat_fl[i + 1][3]) {
				for (int j = 0; j < 5; j++) {
					temp[0][j] = Stat_fl[i+1][j];
				}
			}
		}
		break;
	case 2:
		for (int k = 0; k < 5; k++) {
			temp[0][k] = Stat_fl[0][k];
		}
		for (int i = 0; i < N-1; i++) {
			if (temp[0][3] > Stat_fl[i + 1][3]) {
				for (int j = 0; j < 5; j++) {
					temp[0][j] = Stat_fl[i+1][j];
				}
			}
		}
		break;
	case 3:
		for (int k = 0; k < 5; k++) {
			temp[0][k] = Stat_fl[0][k];
		}
		for (int i = 0; i < N-1; i++) {
			if (temp[0][4] < Stat_fl[i + 1][4]) {
				for (int j = 0; j < 5; j++) {
					temp[0][j] = Stat_fl[i+1][j];
				}
			}
		}
		break;
	case 4:
		for (int k = 0; k < 5; k++) {
			temp[0][k] = Stat_fl[0][k];
		}
		for (int i = 0; i < N-1; i++) {
			if (temp[0][4] > Stat_fl[i + 1][4]) {
				for (int j = 0; j < 5; j++) {
					temp[0][j] = Stat_fl[i+1][j];
				}
			}
		}
		break;
	}
	printf("|№%8s|%17s|%17s|\n", "Номер", "Рывок", "Толчок");
	printf("-----------------------------------------------\n");
	printf("|№%8.0f|%17.2f|%17.2f|\n", temp[0][0], temp[0][3], temp[0][4]);
	return 0;
}




//Function for sorting arrays
float** Sort(float** Stat_fl, int N) {
	{
		float temp_stat_fl[99][6];

		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (athlet_results(Stat_fl,j) < athlet_results(Stat_fl, j+1))
				{
					for (int k = 0; k < 6; k++) {
						temp_stat_fl[j][k] = Stat_fl[j][k];
					}
					for (int k = 0; k < 6; k++) {
						Stat_fl[j][k] = Stat_fl[j + 1][k];
					}
					for (int k = 0; k < 6; k++) {
						Stat_fl[j + 1][k] = temp_stat_fl[j][k];
					}
				}
			}
		}
	} return Stat_fl;
}




//Function for allocation of memory for a dynamic array float
float** dynamic_array_alloc_float(size_t N, size_t M)
{
	float** A = (float**)malloc(N * sizeof(float*));
	for (int i = 0; i < N; i++) {
		A[i] = (float*)malloc(M * sizeof(float));
	}
	return A;
}




//Function for allocation of memory for a dynamic array int
int** dynamic_array_alloc(size_t N, size_t M)
{
	int** A = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		A[i] = (int*)malloc(M * sizeof(int));
	}
	return A;
}



//Function for clearing dynamic arrays
void dynamic_array_free(float** B) {
	for (int i = 0; i < 100; i++) {
		free(B[i]);
	}
	free(B);
}




//Function for showing athlets results
void table_display(float** Stat_fl, int N) {

	printf("\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("|%7s|%10s|%17s|%17s|%17s|%17s|%17s|\n", "Место", "Номер", "Возраст", "Вес", "Рывок", "Толчок", "Сумма очков");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < N; i++) {
		printf("|%7d|", (i + 1));
		printf("|№%8.0f|", Stat_fl[i][0]);
		printf("|%16.0f|", Stat_fl[i][1]);
		for (int j = 2; j < 5; j++) {
			printf("|%16.1f|", Stat_fl[i][j]);
		}
		printf("|%16.1f|", athlet_results(Stat_fl, i));
		printf("\n");
	}
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n");
}




//Function for ending program
int End_session() {

	int N;
	printf("\n\n");
	printf("Завершить программу?\n1) Да\n2) Нет\n");
	printf("Команда > ");
	scanf_s("%d", &N);
	printf("\n\n");
	system("cls");

	return N;
}




//Function for loading data from .txt files into program
int load_file(float** Stat_fl, int N) {
	FILE* file;
	char* fname[20];
	char reading[20], txt[5] = ".txt";
	int count = 0;

	printf("Введите название файла > ");
	scanf("%s", fname);
	strcat(fname, txt);
	file = fopen(fname, "r");
	printf("\n\n");

	while (fscanf(file, "%f%f%f%f%f", &(Stat_fl[count][0]), &(Stat_fl[count][1]), &(Stat_fl[count][2]), &(Stat_fl[count][3]), &(Stat_fl[count][4])) != EOF) {
		count++;
	}

	printf("\n\n");
	N = count;
	fclose(file);
	return N;
}




//Function for saving data into .txt file
int save_file(float** Stat_fl, int N) {
	FILE* file;
	char* fname[20];
	char reading[20], txt[5] = ".txt";

	printf("Введите название файла > ");
	scanf("%s", fname);
	strcat(fname, txt);
	file = fopen(fname, "w");

	for (int i = 0; i < N; i++) {
		fprintf(file, "%.2f %.2f %.2f %.2f %.2f\n", Stat_fl[i][0], (Stat_fl[i][1]), (Stat_fl[i][2]), (Stat_fl[i][3]), (Stat_fl[i][4]));
	}

	fclose(file);
	return N;
}


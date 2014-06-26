#include <stdio.h>

struct Data {
	int dia;
	int mes;
	int ano;
};

typedef struct Data Data;

Data lerData() {
	Data data;
	scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
	return data;
}

void escreverData(Data data) {
	printf("%d/%d/%d\n", data.dia, data.mes, data.ano);
}

int main() {
	Data data1, data2;

	printf("Digite duas datas: ");
	data1 = lerData();
	data2 = lerData();

	if(data1.ano > data2.ano)
		escreverData(data2);
	else if(data2.ano > data1.ano)
		escreverData(data1);
	else if(data1.mes > data2.mes)
		escreverData(data2);
	else if(data2.mes > data1.mes)
		escreverData(data1);
	else if(data1.dia > data2.dia)
		escreverData(data2);
	else
		escreverData(data1);

	return 0;
}

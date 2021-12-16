#include <stdio.h>
#include <memory>

typedef struct Data {

	int x=0, y=0;

}Data;

void SetPx(Data* p) {

	int count = -1;

	for (int i = 0; i < 2; i++) {
		if (count == 0 && i > 0 && i != 2) {
			p[3].x = p[i - 1].x;
		}
		else if (count == 0 && i == 2)
			p[3].x = p[i].x;
		count = 0;

		for (int j = i + 1; j < 3; j++) {
			if (p[i].x == p[j].x)
				count++;
		}
	}

}

void SetPy(Data* p) {

	int count = -1;

	for (int i = 0; i < 3; i++) {
		if (count == 0 && i > 0 && i!=2) {
			p[3].y = p[i - 1].y;
		}
		else if(count == 0 && i == 2)
			p[3].y = p[i].y;
		count = 0;

		for (int j = i + 1; j < 3; j++) {
			if (p[i].y == p[j].y)
				count++;
		}
	}

}

int main() {

	int count = -1;
	Data* p = NULL;

	p = (Data*)malloc(sizeof(Data) * 4);

	p[0] = { 3,1 };
	p[1] = { 1,1 };
	p[2] = { 1,2 };
	p[3] = { 0,0 };

	SetPx(p);
	SetPy(p);

	printf("%d %d", p[3].x,p[3].y);

	return 0;
}
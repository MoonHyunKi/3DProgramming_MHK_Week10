#pragma once
#include <iostream>
using namespace std;

class vec3 {	//vec3 Ŭ���� ����
public:
	float v[3][1] = { {2},{2},{1} };	// Vector�� �迭�� ����
	float v_col = sizeof(v[0]) / sizeof(float);  // �� ���Ͱ��� ũ��
	float v_row = sizeof(v) / sizeof(v[0]);  // �� ���Ͱ��� ũ��
	float p[3][3] = { 0 };				// ���� ����� ����� ����
private:
};

class mat3 {	//mat3 Ŭ���� ����
public:
	float Tr[3][3] = {	// 3*3 Translate ����, 3,5��ŭ �̵��� �Ÿ� ���� 
		{1,0,3},
		{0,1,5},
		{0,0,1}
	};

	float Sc[3][3] = {	// 3*3 Scale ����, 2�� Ű�� ũ�� ����
		{2,0,0},
		{0,2,0},
		{0,0,1}
	};

	float Pi = 3.14;	//������
	float cos30 = 0.15;		// cos30�� ��
	float sin30 = 0.5;		// sin30�� ��

	float Rt[3][3] = {	// 3*3 Rotate ����, 30�� ���� �� ����
		{cos30, -sin30, 0},
		{sin30, cos30, 0},
		{0,0,1}
	};
private:
};

void header()
{
	float a[3][3] = { 0 };		// ���� ��İ� �����͸� �����ϱ� ���� ���
	float b[3][3] = { 0 };		// ���� ��İ� �����͸� �����ϱ� ���� ���

	mat3 Translate, Rotate, Scale;	// mat3 ���� TSR�� �������� ���� ����
	vec3 Vector, P;					// vec3 ���� Vector, P�� �������� ���� ����

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				a[i][j] += Scale.Sc[i][k] * Translate.Tr[k][j]; 
				// Scale ��� * Translate ��� = ��� a ����
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				b[i][j] += Rotate.Rt[i][k] * a[k][j];
				// Rotate ��� * ���� ��� a(SC * TR) = ��� b ����
			}
		}
	}

	for (int i = 0; i < Vector.v_row; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < Vector.v_col; k++) {
				P.p[i][j] += Vector.v[i][k] * b[k][j];
				// Vector ��� * ���� ��� b(Tr * SC * Rt) = vec3 p ��� ����
			}
		}
	}

	printf("vec3 p�� ���� : ");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << P.p[i][j];
			if (j < 2) {
				cout << " ";
			}
		}
	}
}

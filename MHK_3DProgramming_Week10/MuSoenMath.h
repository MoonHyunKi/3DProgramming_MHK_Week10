#pragma once
#include <iostream>
using namespace std;

class vec3 {	//vec3 클래스 생성
public:
	float v[3][1] = { {2},{2},{1} };	// Vector값 배열로 정렬
	float v_col = sizeof(v[0]) / sizeof(float);  // 행 벡터값의 크기
	float v_row = sizeof(v) / sizeof(v[0]);  // 열 벡터값의 크기
	float p[3][3] = { 0 };				// 최종 결과값 저장용 선언
private:
};

class mat3 {	//mat3 클래스 생성
public:
	float Tr[3][3] = {	// 3*3 Translate 정의, 3,5만큼 이동한 거리 삽입 
		{1,0,3},
		{0,1,5},
		{0,0,1}
	};

	float Sc[3][3] = {	// 3*3 Scale 정의, 2배 키운 크기 삽입
		{2,0,0},
		{0,2,0},
		{0,0,1}
	};

	float Pi = 3.14;	//원주율
	float cos30 = 0.15;		// cos30의 값
	float sin30 = 0.5;		// sin30의 값

	float Rt[3][3] = {	// 3*3 Rotate 정의, 30도 돌린 값 삽입
		{cos30, -sin30, 0},
		{sin30, cos30, 0},
		{0,0,1}
	};
private:
};

void header()
{
	float a[3][3] = { 0 };		// 추후 행렬곱 데이터를 삽입하기 위한 행렬
	float b[3][3] = { 0 };		// 추후 행렬곱 데이터를 삽입하기 위한 행렬

	mat3 Translate, Rotate, Scale;	// mat3 안의 TSR을 가져오기 위한 변수
	vec3 Vector, P;					// vec3 안의 Vector, P를 가져오기 위한 변수

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				a[i][j] += Scale.Sc[i][k] * Translate.Tr[k][j]; 
				// Scale 행렬 * Translate 행렬 = 행렬 a 삽입
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				b[i][j] += Rotate.Rt[i][k] * a[k][j];
				// Rotate 행렬 * 위의 행렬 a(SC * TR) = 행렬 b 삽입
			}
		}
	}

	for (int i = 0; i < Vector.v_row; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < Vector.v_col; k++) {
				P.p[i][j] += Vector.v[i][k] * b[k][j];
				// Vector 행렬 * 위의 행렬 b(Tr * SC * Rt) = vec3 p 행렬 삽입
			}
		}
	}

	printf("vec3 p의 값은 : ");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << P.p[i][j];
			if (j < 2) {
				cout << " ";
			}
		}
	}
}

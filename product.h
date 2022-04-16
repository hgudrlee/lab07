#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 제품 정보
typedef struct {
    char name[30];
    char info[30]; 
    char weight[30];
    int price;
    int type;
} Product;

int createProduct(Product *p, int cnt); // 제품을 추가하는 함수
int readProduct(Product p); // 하나의 제품 출력 함수
int listProduct(Product *p, int cnt); // 모든 제품 출력 함수
int updateProduct(Product *p, int cnt); // 제품 정보 수정
int deleteProduct(Product *p, int cnt); // 제품 삭제

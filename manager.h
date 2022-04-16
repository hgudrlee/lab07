#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

int selectMenu(); // 메뉴 선택 함수
int loadData(Product *p); // File에서 데이터 불러오는 함수
void saveProduct(Product *p, int cnt); // File 저장 함수
void searchProduct(Product *p, int cnt); // 제품 검색 유형 함수
void searchInfo(Product *p, int cnt); // 제품 설명 검색 함수
void searchPrice(Product *p, int cnt); // 제품 가격 검색 함수
void searchAddress(Product *p, int cnt); // 제품 배송 유형 검색 함수

#include <stdio.h>


#define SHIFT 5 ////�ƶ�5��λ,�������൱�ڳ���32,�����൱�ڳ���32ȡ��
#define MASK 0x1F //16�����µ�31

/*
 * ��λ����������"|"������,i&MASK�൱��mod����
 * m mod n ���㣬��n = 2��X���ݵ�ʱ��,m mod n = m&(n-1)
 */
void set(int bitmap[],int i) {
	bitmap[i >> SHIFT] |= (1 << (i & MASK));
}

/* ���λ��������&~������ */
void clear(int bitmap[],int i) {
	bitmap[i >> SHIFT] &= ~(1 << (i & MASK));
}

/* ����λ������&������ */
int test(int bitmap[],int i) {
	return bitmap[i >> SHIFT] & (1 << (i & MASK));
}

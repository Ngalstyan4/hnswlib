#include <stdlib.h>
#include <stdio.h>
#include "hnsw_interface.h"

int main() {

//	float v1[8]{1,2,3,4, 5, 6, 7, 8 };
//	float v2[8]{10,20,30,40, 50, 60, 70, 80};

	float* v1 = (float*)malloc(sizeof(float) * 800);
	float* v2 = (float*)malloc(sizeof(float) * 800);

	int num_found;
	float dists[10];
	unsigned long labels[10];
	printf("haha\n");

	void* hnsw = hnsw_new(800, 5000, 16, 10);
	hnsw_add(hnsw, v1, 5);
	printf("haha\n");
	printf("hah %da\n", hnsw_size(hnsw));
	hnsw_add(hnsw, v2, 10);
	printf("haha\n");
	//hnsw_search(hnsw, v1, 10, &num_found, dists, labels);
	printf("found %d .\n\n", num_found);

	//printf("found %d. dists %f %f labels %ld %ld\n", num_found, dists[0], dists[1], labels[0], labels[1]);
	return 0;

}

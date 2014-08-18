//
//  MergeSort.c
//  MergeSort
//
//  Created by Troy Chmieleski on 8/17/14.
//  Copyright (c) 2014 Troy Chmieleski. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "MergeSort.h"

typedef enum {
	false = 0,
	true = 1
} bool;

typedef struct {
	int *array;
	int count;
	int firstIndex;
	bool isEmpty;
} Queue;

void sortSubArray(int input[], int low1, int high1, int low2, int high2, int *numberOfComparisons);
bool hasFewerThanTwoItems(int low, int high);
int findMidPoint(int low, int high);
void merge(int input[], int low1, int high1, int low2, int high2, int *numberOfComparisons);
void sortMergedArrayWithSortedQueues(int input[], int index, Queue queueOne, Queue queueTwo, int *numberOfComparisons);
int smallestItemFromSortedQueues(Queue *queueOne, Queue *queueTwo, int *numberOfComparisons);
int min(int integerOne, int integerTwo);
void populateQueue(Queue *queue, int input[], int low, int high);
int first(Queue queue);
int dequeue(Queue *queue);
bool isAtLeastOneItemInQueues(Queue queueOne, Queue queueTwo);
void didCompare(int *numberOfComparisons);

void swapItemsAtIndices(int input[], int firstIndex, int secondIndex);

void mergeSort(int input[], int count) {
	int low1 = 0;
	int high1 = findMidPoint(low1, count - 1);
	int low2 = high1 + 1;
	int high2 = count - 1;
	int numberOfComparisons = 0;
	
	sortSubArray(input, low1, high1, low2, high2, &numberOfComparisons);
	mergeSortCompletion(&numberOfComparisons);
}

void sortSubArray(int input[], int low1, int high1, int low2, int high2, int *numberOfComparisons) {
	if (hasFewerThanTwoItems(low1, high1) && hasFewerThanTwoItems(low2, high2)) {
		merge(input, low1, high1, low2, high2, numberOfComparisons);
		
		return;
	}
	
	int midPoint1 = findMidPoint(low1, high1);
	sortSubArray(input, low1, midPoint1, midPoint1 + 1, high1, numberOfComparisons);
	int midPoint2 = findMidPoint(low2, high2);
	sortSubArray(input, low2, midPoint2, midPoint2 + 1, high2, numberOfComparisons);
	merge(input, low1, high1, low2, high2, numberOfComparisons);
}

bool hasFewerThanTwoItems(int low, int high) {
	bool hasFewerThanTwoItems = (high - low <= 0) ? true : false;
	
	return hasFewerThanTwoItems;
}

int findMidPoint(int low, int high) {
	int midPoint = (int)floor((double)(high - low)/2.0) + low;
	
	return midPoint;
}

void merge(int input[], int low1, int high1, int low2, int high2, int *numberOfComparisons) {
	int sortedIndex = low1;
	int countOne = high1 - low1 + 1;
	int countTwo = high2 - low2 + 1;
	int sortedArrayOne[countOne];
	int sortedArrayTwo[countTwo];
	Queue queueOne = {.array = sortedArrayOne};
	Queue queueTwo = {.array = sortedArrayTwo};
	
	populateQueue(&queueOne, input, low1, high1);
	populateQueue(&queueTwo, input, low2, high2);
	sortMergedArrayWithSortedQueues(input, sortedIndex, queueOne, queueTwo, numberOfComparisons);
}

void sortMergedArrayWithSortedQueues(int input[], int index, Queue queueOne, Queue queueTwo, int *numberOfComparisons) {
	while (isAtLeastOneItemInQueues(queueOne, queueTwo)) {
		int smallestItem = smallestItemFromSortedQueues(&queueOne, &queueTwo, numberOfComparisons);
		input[index] = smallestItem;
		index++;
	}
}

int smallestItemFromSortedQueues(Queue *queueOne, Queue *queueTwo, int *numberOfComparisons) {
	int smallestItemFromFirstSortedQueue = first(*queueOne);
	int smallestItemFromSecondSortedQueue = first(*queueTwo);
	int smallestItem = min(smallestItemFromFirstSortedQueue, smallestItemFromSecondSortedQueue);
	didCompare(numberOfComparisons);
	
	if (smallestItem == smallestItemFromFirstSortedQueue) {
		dequeue(queueOne);
	}
	
	else {
		dequeue(queueTwo);
	}
	
	return smallestItem;
}

int min(int integerOne, int integerTwo) {
	int min = (integerOne < integerTwo) ? integerOne : integerTwo;
	
	return min;
}

void populateQueue(Queue *queue, int input[], int low, int high) {
	int count = high - low + 1;
	
	for (int i = 0, index = low; i < count; i++, index++) {
		queue->array[i] = input[index];
	}
	
	queue->count = count;
	queue->isEmpty = (count > 0) ? false : true;
}

int dequeue(Queue *queue) {
	int firstItem = first(*queue);
	queue->count--;
	queue->firstIndex++;
	
	if (queue->count == 0) {
		queue->isEmpty = true;
	}
	
	return firstItem;
}

int first(Queue queue) {
	int firstIndex = queue.firstIndex;
	int firstItem = (queue.isEmpty == true) ? INT_MAX : queue.array[firstIndex];
	
	return firstItem;
}

bool isAtLeastOneItemInQueues(Queue queueOne, Queue queueTwo) {
	bool isAtLeastOneItemInQueues = queueOne.isEmpty == false || queueTwo.isEmpty == false;
	
	return isAtLeastOneItemInQueues;
}

void didCompare(int *numberOfComparisons) {
	(*numberOfComparisons)++;
}
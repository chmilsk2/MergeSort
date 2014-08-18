//
//  MergeSorter.m
//  MergeSort
//
//  Created by Troy Chmieleski on 8/17/14.
//  Copyright (c) 2014 Troy Chmieleski. All rights reserved.
//

#import "MergeSorter.h"
#import "MergeSort.h"

static MergeSorter *object = nil;

@interface MergeSorter ()

@end

@implementation MergeSorter

- (instancetype)init {
	self = [super init];
	
	if (self) {
		object = self;
	}
	
	return self;
}

- (NSArray *)sort:(NSArray *)input {
	int count = (int)input.count;
	int cIntArray[count];
	[self populateCIntArray:cIntArray fromIntegerArray:input];
	mergeSort(cIntArray, count);
	NSArray *output = [self integerArrayFromCIntArray:cIntArray count:count];
	
	return output;
}

- (void)populateCIntArray:(int [])cIntArray fromIntegerArray:(NSArray *)integerArray {
	[integerArray enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
		NSNumber *number = (NSNumber *)obj;
		int integer = number.intValue;
		cIntArray[idx] = integer;
	}];
}

- (NSArray *)integerArrayFromCIntArray:(int [])cIntArray count:(int)count {
	NSMutableArray *intArray = [NSMutableArray arrayWithCapacity:count];
	
	for (NSUInteger i = 0; i < count; i++) {
		int integer = cIntArray[i];
		[intArray addObject:@(integer)];
	}
	
	return [intArray copy];
}

- (void)printMergeSortBenchMarksWithNumberOfComparisons:(NSInteger)numberOfComparisons {
	NSLog(@"number of comparisons: %ld", numberOfComparisons);
}

void mergeSortCompletion(int *numberOfComparisons) {
	[object printMergeSortBenchMarksWithNumberOfComparisons:*numberOfComparisons];
}

@end

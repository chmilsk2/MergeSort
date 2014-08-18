//
//  MergeSortViewController.m
//  MergeSort
//
//  Created by Troy Chmieleski on 8/17/14.
//  Copyright (c) 2014 Troy Chmieleski. All rights reserved.
//

#import "MergeSortViewController.h"
#import "MergeSorter.h"

@implementation MergeSortViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	
	NSArray *input = [self inputIntegerArray];
	[self printIntegerArray:input];
	MergeSorter *mergeSorter = [MergeSorter new];
	NSArray *output = [mergeSorter sort:input];
	[self printIntegerArray:output];
}

- (NSArray *)inputIntegerArray {
	NSMutableArray *inputIntegerArray = [NSMutableArray array];
	
	NSInteger count = 4;
	
	for (NSInteger i = count; i >= 0; i--) {
		int integer = arc4random_uniform((u_int32_t)count);
		integer = (int)i;
		[inputIntegerArray addObject:@(integer)];
	}
	
	return [inputIntegerArray copy];
}

- (void)printIntegerArray:(NSArray *)integerArray {
	NSMutableString *integerArrayString = [NSMutableString string];
	
	NSInteger index = 0;
	
	for (NSNumber *number in integerArray) {
		[integerArrayString appendString:[NSString stringWithFormat:@"%ld", number.integerValue]];
		
		if (index != integerArray.count - 1) {
			[integerArrayString appendString:@", "];
		}
		
		index++;
	}
	
	NSLog(@"%@", integerArrayString);
}


@end

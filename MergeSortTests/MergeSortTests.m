//
//  MergeSortTests.m
//  MergeSort
//
//  Created by Troy Chmieleski on 8/17/14.
//  Copyright (c) 2014 Troy Chmieleski. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "MergeSorter.h"

@interface MergeSortTests : XCTestCase

@property (nonatomic, strong) MergeSorter *mergeSorter;

@end

@implementation MergeSortTests

- (void)setUp {
    [super setUp];

	_mergeSorter = [MergeSorter new];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testMergeSortWithInputElementsInDescendingOrder {
	NSArray *input = @[@2, @1, @0];
	NSArray *output = [_mergeSorter sort:input];
	NSArray *expectedOutput = [self expectedSortedOutputWithInput:input];
	
	XCTAssertEqualObjects(output, expectedOutput, @"sorted output does not match expected sorted output");
}

- (NSArray *)expectedSortedOutputWithInput:(NSArray *)input {
	NSSortDescriptor *sortDescriptor = [NSSortDescriptor sortDescriptorWithKey:@"self" ascending:YES];
	NSArray *expectedOutput = [input sortedArrayUsingDescriptors:@[sortDescriptor]];
	
	return expectedOutput;
}

@end

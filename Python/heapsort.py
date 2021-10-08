#!/usr/bin/env python3

"""Minimal way to write heapsort in python"""
# Importing module
from heapq import heappush,heappop

# Heap Function
def heap_sort(array):
    heap = []
    for element in array:
        heappush(heap, element)
    
    ordered = []
    # Element left in the top heap
    while heap:
        ordered.append(heappop(heap))

    return ordered

# Input array
array = [1, 30, 4, 21, 100000,27,9,16,35,18]
print('Sorted heap is:',heap_sort(array))
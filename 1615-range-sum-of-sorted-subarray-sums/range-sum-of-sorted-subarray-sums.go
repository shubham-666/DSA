package main

import (
	"container/heap"
)

const MOD int64 = 1000000007

type Item struct {
	sum int64
	end int
}

type MinHeap []Item

func (h MinHeap) Len() int {
	return len(h)
}

func (h MinHeap) Less(i, j int) bool {
	return h[i].sum < h[j].sum
}

func (h MinHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.(Item))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)

	item := old[n-1]
	*h = old[:n-1]

	return item
}

func rangeSum(nums []int, n int, left int, right int) int {
	pq := &MinHeap{}
	heap.Init(pq)

	// Put all one-element subarrays into heap
	for i := 0; i < n; i++ {
		heap.Push(pq, Item{
			sum: int64(nums[i]),
			end: i,
		})
	}

	var ans int64 = 0

	for count := 1; count <= right; count++ {

		// Smallest subarray sum
		item := heap.Pop(pq).(Item)

		if count >= left {
			ans = (ans + item.sum) % MOD
		}

		// Extend the subarray
		if item.end+1 < n {
			heap.Push(pq, Item{
				sum: item.sum + int64(nums[item.end+1]),
				end: item.end + 1,
			})
		}
	}

	return int(ans)
}
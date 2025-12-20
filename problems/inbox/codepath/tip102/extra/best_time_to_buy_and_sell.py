def maximize_profit(prices):
	if not prices:
		return -1
	buy, sell, profit = 0, 1, -1
	while sell < len(prices):
		if prices[sell] < prices[buy]:
			buy = sell
		else:
			profit = max(prices[sell] - prices[buy], profit)
		sell += 1
	return profit


if __name__ == "__main__":
	arr = [4, 3, 2, 1, 0]
	print(maximize_profit(arr))

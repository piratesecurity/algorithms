"""
A classic example of an optimization problem involves making change using the fewest coins. Suppose you are a programmer for a vending machine manufacturer. Your company wants to streamline effort by giving out the fewest possible coins in change for each transaction.

"""

def print_change(last_coin,ip):
	str1="Those coins are :"
	while ip>0:
		str1 =str1+ str(last_coin[ip])+ "   " 
		ip=ip-last_coin[ip]
	print str1

def makeChange(coins,min_coins,last_coin,total_money):
	for money in range(1,total_money+1):
		local_min=money
		if money in coins:
			min_coins[money]=1
			last_coin[money]=money
		else:
			for coin in [ c for c in coins if c <= money ]:
				if (local_min> (min_coins[money-coin]+1)):
					local_min=min_coins[money-coin]+1
					last_coin[money]=coin
			min_coins[money]=local_min
	print "Number of coins dispatched are :" +str(min_coins[total_money])	
	print_change(last_coin,total_money)

def main():
	# coins which are there in vending machine
	coins=[1,5,10,25]
	total_money=input("Enter Money to recive from Vendor M/C :")
	min_coins=[0]*(total_money+1)
	last_coin=[0]*(total_money+1)
	makeChange(coins,min_coins,last_coin,total_money)

main()

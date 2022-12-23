from cs50 import get_float

count = 0
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break
    
# round up to the nearest whole number
cent = round(change * 100)

# checking if more than 25 cents
while cent >= 25:
    cent = cent - 25
    count += 1

# checking if more than 10 cents
while cent >= 10:
    cent = cent - 10
    count += 1

# checking if more than 5 cents
while cent >= 5:
    cent = cent - 5
    count += 1

# checking if more than 1 cent
while cent >= 1:
    cent = cent - 1
    count += 1

print(count)
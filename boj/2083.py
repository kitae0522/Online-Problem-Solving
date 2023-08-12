while True:
	name, age, weight = input().split()
	age, weight = map(int, (age, weight))
	if name == '#' or not age or not weight:
		break
	print(name, "Senior" if age > 17 or weight >= 80 else "Junior")
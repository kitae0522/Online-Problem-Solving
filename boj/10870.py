import math
print([(lambda n: int((((1/2)*(1+math.sqrt(5)))**n-(2/(1+math.sqrt(5))) **
      n*math.cos(math.pi*n))/math.sqrt(5)))(i) for i in range(21)][int(input())])

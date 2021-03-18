import os

file_list = os.listdir(os.path.join("boj/"))
for i in file_list:
	print(os.path.splitext(i)[0], os.path.splitext(i)[1][1:])
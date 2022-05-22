class NQueens:
    def __init__(self, n: int) -> None:
        self.ans = 0
        self.__n = n
        self.__col_set = set()
        self.__diag_set1 = set()
        self.__diag_set2 = set()
        
        for x in range(n):
            self.__bt(0, x, 0)

    def __check(self, row: int, col: int, diag1, diag2) -> bool:
        if row == self.__n or col == self.__n:
            return False
        if col in self.__col_set:
            return False
        if diag1 in self.__diag_set1:
            return False
        if diag2 in self.__diag_set2:
            return  False
        return True

    def __bt(self, row: int, col: int, cnt: int) -> None:
        diag1_info = row-col
        diag2_info = row+col
        
        if self.__check(row, col, diag1_info, diag2_info):
            cnt += 1
            if cnt == self.__n:
                self.ans += 1
                return
            
            self.__col_set.add(col)
            self.__diag_set1.add(diag1_info)
            self.__diag_set2.add(diag2_info)
            
            for x in range(self.__n):
                self.__bt(row+1, x, cnt)
                
            self.__diag_set2.remove(diag2_info)
            self.__diag_set1.remove(diag1_info)
            self.__col_set.remove(col)
            cnt = 0
        return

nq = NQueens(int(input()))
print(nq.ans)
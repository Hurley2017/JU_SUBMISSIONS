def odd_squares(n):
    return n**2

def odd(n):
    return n%2 != 0

def main():
    n = int(input("Enter the number of elements in the list: "))
    l = []
    for i in range(n):
        l.append(int(input("Enter the element ", i, ":")))
    print("The list is: ", l)
    print("The odd squares of the list are: ", list(map(odd_squares,list(filter(odd,l)))))

main()

# class Solution:
#     def countNegatives(self, grid: List[List[int]]) -> int:
#         count = 0
#         for i in range(len(grid)):
#             for j in range(len(grid[i])-i):
#                 if grid[i][j] < 0:
#                     count = count + len(grid) - j
#         return count 